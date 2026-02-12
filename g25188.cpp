#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;

int N;
vector<ll>ARR;
vector<ll>ARRSUM;
vector<vector<ll>>DPARR;

ll dfs_arr_v1(int idx, int cnt){

    if(cnt >= 6)return 0;

    ll& ret = DPARR[idx][cnt];
    if(ret != -1)return ret;
    ret = 0;

    if(cnt % 2 == 0){
        ll cur_last = ARRSUM[N-1] - (idx == 0 ? 0 : ARRSUM[idx-1]);
        ret = max(ret, cur_last);
    }

    for(int nxt = idx+1; nxt < N; nxt++){
        if(cnt % 2 == 0){
            ll seg_sum = ARRSUM[nxt-1] - (idx == 0 ? 0 : ARRSUM[idx-1]);
            ll nxt_seg = seg_sum + dfs_arr_v1(nxt, cnt+1);
            ret = max(ret, nxt_seg);
        }else{
            ll nxt_sum = dfs_arr_v1(nxt, cnt+1);
            ret = max(ret, nxt_sum);
        }
    }
    return ret;
}


void solution_one_three_mo_divide(){
    DPARR.resize(N, vector<ll>(6, -1));
    for(int i = 0; i<N; i++){
        for(int j = 0; j<6; j++){
            DPARR[i][j] = -1;
        }
    }

    ll ret = dfs_arr_v1(0, 0);
    for(int i = 1; i<N; i++){
        ret = max(ret, dfs_arr_v1(i, 2));
    }

    cout<<ret<<"\n"; 
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin>>n;
    vector<ll> arr(n, 0);
    for(int i = 0; i<n; i++){
        cin>>arr[i];
    }

    vector<ll>arrSum(n, 0);
    arrSum[0] = arr[0];
    for(int i = 1; i<n; i++){
        arrSum[i] = arrSum[i-1] + arr[i];
    }

    N = n;
    ARR = arr;
    ARRSUM = arrSum;

    solution_one_three_mo_divide();

    return 0;
}