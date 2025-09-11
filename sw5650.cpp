//sw5650 핀볼게임

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
int N;
vector<vector<int>> A, px, py;

int reflect_dir(int d, int t) {
	static int nd[5][4] = {
		{1,3,0,2},
		{2,3,1,0},
		{2,0,3,1},
		{3,2,0,1},
		{2,3,0,1}
	};
	return nd[t - 1][d];
}

int play(int sx, int sy, int sd) {
	int x = sx, y = sy, d = sd, score = 0;
	while (true) {
		x += dx[d]; y += dy[d];
		int cell = A[x][y];
		if (cell == -1) return score;
		if (x == sx && y == sy) return score;
		if (1 <= cell && cell <= 5) {
			d = reflect_dir(d, cell);
			score++;
			continue;
		}
		if (cell >= 6) {
			int nx = px[x][y], ny = py[x][y];
			x = nx; y = ny;
			continue;
		}
	}
}

int solve() {
	cin >> N;
	A.assign(N + 2, vector<int>(N + 2, 5));
	px.assign(N + 2, vector<int>(N + 2, -1));
	py.assign(N + 2, vector<int>(N + 2, -1));
	vector<pair<int, int>> holes[11];

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> A[i][j];
			if (A[i][j] > 5) holes[A[i][j]].push_back({ i,j });
		}
	}
	for (int id = 6; id <= 10; id++) {
		if (holes[id].size() == 2) {
			auto a = holes[id][0], b = holes[id][1];
			px[a.first][a.second] = b.first;  py[a.first][a.second] = b.second;
			px[b.first][b.second] = a.first;  py[b.first][b.second] = a.second;
		}
	}

	int best = 0;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (A[i][j] != 0) continue;
			for (int d = 0; d < 4; d++) {
				int s = play(i, j, d);
				if (best < s) best = s;
			}
		}
	}
	return best;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T; cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		cout << "#" << tc << " " << solve() << "\n";
	}
	return 0;
}
