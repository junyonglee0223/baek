//s24392 영재의 징검다리
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

typedef long long ll;
const ll MOD = 1000000007;
int N, M;
ll solution_youngjaes_stepping_stones() {
	cin >> N >> M;
	vector<vector<int>>board(N, vector<int>(M));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> board[i][j];
		}
	}

	vector<ll>dp(M, 0);
	for (int i = 0; i < M; i++) {
		if (board[N - 1][i] == 1)
			dp[i] = 1;
	}

	for (int i = N - 2; i >= 0; i--) {
		vector<ll>n_dp(M, 0);
		for (int j = 0; j < M; j++) {
			if (board[i][j] == 0)continue;
			n_dp[j] = dp[j];
			if (j > 0)
				n_dp[j] += dp[j - 1];
			if (j < M - 1)
				n_dp[j] += dp[j + 1];
			n_dp[j] %= MOD;
		}
		dp = n_dp;
	}

	ll sum = 0;
	for (int i = 0; i < M; i++) {
		sum = (sum + dp[i]) % MOD;
	}
	return sum;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);


	cout << solution_youngjaes_stepping_stones() << "\n";

	//int T; cin >> T;
	//while (T--) {
	//	cout << solution_youngjaes_stepping_stones() << "\n";
	//}

	return 0;
}

/*
3
3 2
0 1
1 0
0 1
5 5
1 0 1 0 1
0 0 1 1 1
1 0 1 0 0
0 1 1 0 1
1 0 1 0 1
4 4
1 1 1 1
1 0 0 1
1 0 0 1
1 1 1 1

*/
/*
1
9
8
*/