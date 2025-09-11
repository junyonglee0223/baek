//sw3281 0/1 knapsack
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<queue>
using namespace std;

#define MAX_N 101
#define MAX_K 1001

int dp[MAX_N][MAX_K];
vector<int>v, c;
int N, K;

int dfs_knap(int cur, int left) {
	int& ret = dp[cur][left];
	if (ret != -1)return ret;
	ret = c[cur];
	left -= v[cur];
	for (int i = cur + 1; i <= N; i++) {
		if (left >= v[i]) {
			ret = max(ret, c[cur] + dfs_knap(i, left));
		}
	}
	return ret;
}

int solutoin_01knapsack() {
	cin >> N >> K;
	for (int i = 0; i < MAX_N; i++) {
		for (int j = 0; j < MAX_K; j++) {
			dp[i][j] = -1;
		}
	}

	v.assign(N+1, 0);
	c.assign(N+1, 0);

	v[0] = c[0] = 0;
	for (int i = 1; i <= N; i++) {
		cin >> v[i] >> c[i];
	}

	return dfs_knap(0, K);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int T; cin >> T;
	for (int test_case = 1; test_case <= T; test_case++) {
		cout << "#" << test_case << " " << solutoin_01knapsack() << "\n";
	}
	return 0;
}


/*
1
4 5
1 2
3 2
4 4
2 3
*/