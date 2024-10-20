#include <iostream>
#include <vector>
#include <map>
using namespace std;

vector<int>seg_tree;
map<int,int>key_idx;
int N, M;

int update(int node, int start, int end, int idx, int value){
    if(start>end)return 0;
    if(end < idx || idx < start)return seg_tree[node];
    if(start == end){
        return seg_tree[node] = value;
    }

    int mid = (start+end)/2;
    return seg_tree[node] = update(node*2, start, mid, idx, value) + 
    update(node*2+1, mid+1, end, idx, value);
}

int query(int node, int start, int end, int q_s, int q_e){
    if(start>end)return 0;
    if(end < q_s || q_e < start)return 0;
    if(q_s<=start && end<=q_e)return seg_tree[node];
    int mid = (start + end)/2;
    return query(node*2, start, mid, q_s, q_e) 
    + query(node*2+1, mid+1, end, q_s, q_e);
}

// void print_tree(int node, int start, int end){
//     if(start>end)return;
//     if(start == end){
//         cout<<seg_tree[node]<<" ";
//         return;
//     }
//     int mid = (start + end)/2;
//     print_tree(node*2, start, mid);
//     print_tree(node*2+1, mid+1, end);
//     return;
// }

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int T; cin>>T;
    while(T--){
        cin>>N>>M;
        seg_tree.clear();
        key_idx.clear();

        seg_tree.resize(4*(N+M+1), 0);
        int max_idx = N+M-1;
        for(int i = 1; i<=N; i++){
            key_idx[i] = N - i;
            update(1, 0, max_idx, N-i, 1);
        }

        for(int i = 0; i<M; i++){
            // print_tree(1, 0, max_idx);//test
            // cout<<endl;//test
            int ele; cin>>ele;
            int idx = key_idx[ele];
            cout<<query(1, 0, max_idx, idx+1, max_idx)<<" ";
            update(1, 0, max_idx, idx, 0);
            update(1, 0, max_idx, N+i, 1);
            key_idx[ele] = N+i;
        }
        cout<<endl;
    }
}

