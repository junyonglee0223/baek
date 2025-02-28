//g11505 구간 곱 구하기
#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007
typedef long long ll;
ll arr[1000001];
ll * tree;

ll init(int node, int start, int end){
    if(start == end)return tree[node] = arr[start];
    int mid = start + (end - start)/2;
    return tree[node] = 
    (init(2 * node, start, mid) * init(2*node + 1, mid + 1, end))%MOD;
}

ll mul(int node, int start, int end, int left, int right){
    if(start > right || end < left)return 1;
    if(left <= start && end <= right)return tree[node];
    int mid = start + (end - start)/2;
    return (mul(2* node, start, mid, left, right)
    *mul(2*node+1, mid+1, end, left, right))%MOD;
}

ll update(int node, int start, int end, int idx, ll val){
    if(idx>end||idx<start)return tree[node];
    if(start==end)return tree[node] = val;
    int mid = start + (end - start)/2;
    return tree[node] =
    (update(2*node, start, mid, idx, val)
    *update(2*node+1, mid+1, end, idx, val))%MOD;
}
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int num, m, k, height, a;
    ll b, c, big, small;
    cin>>num>>m>>k;
    height = ceil(log2(num));
    tree = new ll[(1<<(height+1))];
    for(int i = 0; i < num; i++)
        cin>>arr[i];
    init(1, 0, num - 1);
    for(int i = 0; i < m+k; i++){
        cin>>a>>b>>c;
        if(a==1){
            arr[b-1] = c;
            update(1, 0, num -1, b-1, c);
        }
        else{
            big = b > c ? b : c;
            small =  b > c ? c : b;
            cout<<mul(1 , 0, num - 1, small - 1 , big - 1)<<'\n';
        }
    }
    return 0;
}