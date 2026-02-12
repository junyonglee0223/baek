#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;

int N;
vector<ll>ARR;

void solution_one_three_mo_divide_v1(){

    const ll NEG = -(1LL << 60);

    auto add = [&](int seg, ll x) -> ll {
        return (seg % 2 == 0) ? x : 0;
    };

    vector<ll>dp(6, NEG);

    ll ret = 0;
    dp[0] = add(0, ARR[0]);
    dp[1] = add(1, ARR[0]);

    ret = max(ret, dp[0]);
    ret = max(ret, dp[1]);

    for(int i = 1; i<N; i++){
        vector<ll>ndp(6, NEG);

        if(dp[0] != NEG) ndp[0] = max(ndp[0], dp[0] + add(0, ARR[i]));

        for(int k = 1; k<6; k++){
            if(dp[k] != NEG) 
                ndp[k] = max(ndp[k], dp[k] + add(k, ARR[i]));
            if(dp[k-1] != NEG) 
                ndp[k] = max(ndp[k], dp[k-1] + add(k, ARR[i]));

        }

        dp = ndp;

        ret = max(ret, dp[0]);
        ret = max(ret, dp[2]);
        ret = max(ret, dp[4]);
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

    N = n;
    ARR = arr;

    solution_one_three_mo_divide_v1();

    return 0;
}