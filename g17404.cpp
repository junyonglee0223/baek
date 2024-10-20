#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
vector<vector<int>> dp;
vector<vector<int>> cost;

int main() {
    cin >> N;
    cost.resize(N, vector<int>(3, 0));
    dp.resize(3, vector<int>(3, 1001));

    for (int i = 0; i < N; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        cost[i][0] = a;
        cost[i][1] = b;
        cost[i][2] = c;
    }

    dp[0][0] = cost[0][0];
    dp[1][1] = cost[0][1];
    dp[2][2] = cost[0][2];


    for (int i = 1; i < N; i++) {
        vector<vector<int>>nxt = dp;
        nxt[0][0] = min(dp[0][1], dp[0][2]) + cost[i][0];
        nxt[0][1] = min(dp[0][0], dp[0][2]) + cost[i][1];
        nxt[0][2] = min(dp[0][0], dp[0][1]) + cost[i][2];

        nxt[1][0] = min(dp[1][1], dp[1][2]) + cost[i][0];
        nxt[1][1] = min(dp[1][0], dp[1][2]) + cost[i][1];
        nxt[1][2] = min(dp[1][0], dp[1][1]) + cost[i][2];

        nxt[2][0] = min(dp[2][1], dp[2][2]) + cost[i][0];
        nxt[2][1] = min(dp[2][0], dp[2][2]) + cost[i][1];
        nxt[2][2] = min(dp[2][0], dp[2][1]) + cost[i][2];

        dp = nxt;

    }

    int answer = 1000001;
    for(int i = 0; i<3; i++){
        for(int j = 0; j<3; j++){
            if(i != j)
                answer = min(answer, dp[i][j]);
        }
    }


    cout << answer << endl;
    return 0;
}
