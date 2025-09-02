#include<iostream>
#include<vector>
#include<algorithm>
#include<functional>
using namespace std;

static int N, M, C;
static int A[10][10];
static int sq[10];

int best;

int bestBlockDFS(const int r, const int c) {
	int pick[5];
	for (int k = 0; k < M; ++k) pick[k] = A[r][c + k];

	int best = 0;
	function<void(int, int, int)> dfs = [&](int idx, int sum, int gain) {
		if (sum > C) return;
		if (idx == M) {
			if (gain > best) best = gain;
			return;
		}
		int s2 = sum + pick[idx];
		if (s2 <= C) dfs(idx + 1, s2, gain + sq[pick[idx]]);

		dfs(idx + 1, sum, gain);
	};
	dfs(0, 0, 0);
	return best;
}

int solution_honey_harvest() {

	cin >> N >> M >> C;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> A[i][j];
		}
	}
	int L = N - M + 1;
	vector<vector<int>>val(N, vector<int>(L, 0));

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < L; j++) {
			val[i][j] = bestBlockDFS(i, j);
		}
	}


	int top1 = 0, top2 = 0;
	for (int i = 0; i < N; ++i) {
		int rowBest = 0;
		for (int j = 0; j < L; ++j) if (val[i][j] > rowBest) rowBest = val[i][j];

		if (rowBest >= top1) {
			top2 = top1;
			top1 = rowBest;
		}
		if (rowBest < top1 && rowBest > top2) top2 = rowBest;
	}
	int twoRows = top1 + top2;

	int ans = twoRows;

	return ans;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	for (int i = 0; i <= 9; ++i) sq[i] = i * i;

	int T;
	if (!(cin >> T)) return 0;
	for (int tc = 1; tc <= T; ++tc) {
		int ans = solution_honey_harvest();
		cout << "#" << tc << " " << ans << "\n";
	}
	return 0;
}

/*

10
4 2 13
6 1 9 7
9 8 5 8
3 4 5 3
8 2 6 7
3 3 10
7 2 9
6 6 6
5 5 7
*/