//2*n 타일링
#include <iostream>
using namespace std;


int N;
const int MOD = 10007;
int dp[1001];

int main(){
    cin>>N;
    //dp[0] = 1;
    dp[1] = 1;
    dp[2] = 2;
    for(int i = 3; i<=N; i++){
        dp[i] = dp[i-1] + dp[i-2];
        dp[i] %= MOD;
    }
    cout<<dp[N]<<"\n";
}