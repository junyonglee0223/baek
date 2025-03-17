//p13537 수열과 쿼리 1
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define endl '\n'

vector<int>seg_tree[4 * 100000 + 5];
vector<int>arr(100001);


vector<int> m_merge(vector<int>&v1, vector<int>&v2){
    vector<int>::iterator it1 = v1.begin();
    vector<int>::iterator it2 = v2.begin();

    vector<int>ret;

    while(it1 != v1.end() && it2 != v2.end()){
        if(*it1 < *it2){
            ret.push_back(*it1);
            it1++;
        }
        else{
            ret.push_back(*it2);
            it2++;
        }
    }
    while(it1 != v1.end()){
        ret.push_back(*it1);
        it1++;
    }
    while(it2 != v2.end()){
        ret.push_back(*it2);
        it2++;
    }
    return ret;
}

void build_seg(int node, int src, int dst){
    if(src > dst)return;
    if(src == dst){
        seg_tree[node].push_back(arr[src]);
        return;
    }
    int mid = (src + dst)/2;
    build_seg(node * 2, src, mid);
    build_seg(node * 2 + 1, mid + 1, dst);

    //seg_tree[node] = m_merge(seg_tree[node * 2], seg_tree[node * 2 + 1]);
    seg_tree[node].resize(seg_tree[node * 2].size() + seg_tree[node * 2 + 1].size());
    merge(seg_tree[node * 2].begin(), seg_tree[node * 2].end(),
         seg_tree[node * 2 + 1].begin(), seg_tree[node * 2 + 1].end(),seg_tree[node].begin()); 
    return;
}

int query(int node, int src, int dst, int start, int end, int k){
    if(src > end || dst < start)return 0;
    if(start <= src && dst <= end){
        int pos = upper_bound(seg_tree[node].begin(), seg_tree[node].end(), k) 
                    - seg_tree[node].begin();
        return seg_tree[node].size() - pos;
    }
    int mid = (src + dst) / 2;
    return query(node * 2, src, mid, start, end, k) 
        + query(node * 2 + 1, mid+1, dst, start, end, k);
}   


void solution_sequences_queries(){

    int N; cin>>N;


    for(int i = 0; i<N; i++){
        // int x; cin>>x;
        // arr.push_back(x);
        cin>>arr[i];
    }

    build_seg(1, 0, N-1);

    int Q; cin>>Q;
    while(Q--){
        int i, j, k;
        cin>>i>>j>>k;
        i--; j--;
        cout<<query(1, 0, N-1, i, j, k)<<endl;
    }
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solution_sequences_queries();

    return 0;
}

/*
5
5 1 2 3 4
3
2 4 1
4 4 4
1 5 2
*/