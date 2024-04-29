//파도반 수열
#include <iostream>
#include <vector>
using namespace std;

vector<long long> precompute_wave_array() {
    vector<long long> dp(101, 0);
    dp[1] = dp[2] = dp[3] = 1;
    dp[4] = dp[5] = 2;

    for (int i = 6; i <= 100; i++) {
        dp[i] = dp[i-1] + dp[i-5];
    }
    return dp;
}

int main() {
    int T; cin >> T;
    vector<long long> dp = precompute_wave_array();

    while (T--) {
        int N; cin >> N;
        cout << dp[N] << endl;
    }
    return 0;
}
