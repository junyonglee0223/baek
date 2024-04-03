//정수 삼각형
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<vector<int>> triangle(N, vector<int>());
    vector<vector<int>> dp(N, vector<int>(N, 0));

    // 삼각형 입력 받기
    for (int i = 0; i < N; i++) {
        for (int j = 0; j <= i; j++) {
            int tmp;
            cin >> tmp;
            triangle[i].push_back(tmp);
            // 첫 번째 행의 경우 dp 초기화
            if (i == 0) {
                dp[i][j] = tmp;
            }
        }
    }

    // 동적 프로그래밍으로 각 단계의 최대 합 계산
    for (int i = 1; i < N; i++) {
        for (int j = 0; j <= i; j++) {
            if (j == 0) {
                dp[i][j] = dp[i-1][j] + triangle[i][j];
            } else if (j == i) {
                dp[i][j] = dp[i-1][j-1] + triangle[i][j];
            } else {
                dp[i][j] = max(dp[i-1][j-1], dp[i-1][j]) + triangle[i][j];
            }
        }
    }

    // 마지막 행에서 최대값 찾기
    int ans = *max_element(dp[N-1].begin(), dp[N-1].end());
    cout << ans << endl;

    return 0;
}
