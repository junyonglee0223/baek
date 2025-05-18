//g1947 선물 전달
#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;
const ll MOD = 1000000000;

vector<ll> dp;


void set_derangement(){
    dp.resize(1000001);
    dp[1] = 0;
    dp[2] = 1;
    dp[3] = 2;
    for(int i = 4; i<=1000000; i++){
        dp[i] = (dp[i-1] + dp[i-2]) * (i-1);
        dp[i] %= MOD;
    }
}

void solution_send_gift(){
    int n; cin>>n;
    cout<<dp[n]<<endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    set_derangement();

    solution_send_gift();
    
    // int T; cin>>T;
    // while(T--){
    //     solution_send_gift();
    // }

    return 0;
}

/*
4
5
4
2
21
*/
/*
44
9
2
50944540
*/