//sw1949 등산로 조성
#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<string>
#include<queue>
using namespace std;

#define MAX_N 8
int N, K;
vector<vector<int>>board;
int dp[MAX_N][MAX_N][2];
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };


int dfs_max(int x, int y, bool flag, vector<vector<bool>>&visited) {
	//int ret = dp[x][y][flag];
	//if (ret != -1)return ret;
	//ret = 1;
	int ret = 1;

	for (int d = 0; d < 4; d++) {
		int nx = x + dx[d];
		int ny = y + dy[d];
		if (nx < 0 || nx >= N || ny < 0 || ny >= N)continue;
		if (visited[nx][ny])continue;
		if (board[nx][ny] < board[x][y]) {
			visited[nx][ny] = true;
			int nxt_ret = dfs_max(nx, ny, flag, visited);
			ret = max(ret, 1 + nxt_ret);
			visited[nx][ny] = false;
		}
		else {
			if (!flag) {
				int gap = board[nx][ny] - board[x][y];
				if (gap >= K)continue;

				//for (int down = 1; down <= K; down++) {
				int down = gap + 1;
				board[nx][ny] -= down;
				visited[nx][ny] = true;
				int nxt_ret = dfs_max(nx, ny, !flag, visited);
				ret = max(ret, 1 + nxt_ret);
				visited[nx][ny] = false;
				board[nx][ny] += down;

				//}
			}
		}
	}
	return ret;
}

int solution_hiking_trail() {
	board.clear();

	cin >> N >> K;
	board.resize(N, vector<int>(N, 0));
	int max_v = 0;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> board[i][j];
			max_v = max(max_v, board[i][j]);
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			dp[i][j][0] = -1;
			dp[i][j][1] = -1;
		}
	}

	int ret = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (board[i][j] != max_v)continue;
			vector<vector<bool>>visited(N, vector<bool>(N, false));
			visited[i][j] = true;
			ret = max(ret, dfs_max(i, j, false, visited));

			//int tmp = dfs_max(i, j, false, visited);
			//cout << i << " " << j << " " << tmp << endl;
		}
	}

	return ret;
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);


	int T; cin >> T;
	for (int test_case = 1; test_case <= T; ++test_case)
	{
		int ret = solution_hiking_trail();
		cout << "#" << test_case << " " << ret << "\n";

	}
	return 0;
}

/*
코드에 문제가 있음
dp로 flag 사용 여부를 dp로 저장했는데 해당 구간과 이전 구간이
루트가 겹치는 로직상 문제 있음
*/
/*
10
5 1
9 3 2 3 2
6 3 1 7 5
3 4 8 9 9
2 3 7 7 7
7 6 5 5 8
3 2
1 2 1
2 1 2
1 2 1
*/
/*
3
4 4
8 3 9 5
4 6 8 5
8 1 5 1
4 9 5 5
4 1
6 6 1 7
3 6 6 1
2 4 2 4
7 1 3 4
5 5
18 18 1 8 18
17 7 2 7 2
17 8 7 4 3
17 9 6 5 16
18 10 17 13 18
*/