//RGB 거리
#include <iostream>
#include <algorithm>
#include <vector>
#include <climits> // for INT_MAX
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<vector<int>> color_cost(N, vector<int>(3));
    vector<int> dp(3, 0);

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> color_cost[i][j];
        }
    }

    for (int j = 0; j < 3; j++) {
        dp[j] = color_cost[0][j];
    }

    for (int i = 1; i < N; i++) {
        vector<int> prev_dp = dp; 
        for (int j = 0; j < 3; j++) {
            dp[j] = min(prev_dp[(j+1)%3], prev_dp[(j+2)%3]) + color_cost[i][j];
        }
    }

    int ans = min({dp[0], dp[1], dp[2]});
    cout << ans << endl;
    return 0;
}

