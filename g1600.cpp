//g1600 말이 되고픈 원숭이
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<queue>
#include<climits>
using namespace std;

#define MAX_N 201
#define MAX_K 32

int K, W, H;
vector<vector<int>>board;
//{-2, -1}, {-1, -2}, {-1, 2}, {-2, 1}
//{2, -1}, {1, -2}, {1, 2}, {2, 1}
int h_dx[8] = { -2, -1, -1, -2, 2, 1, 1, 2 };
int h_dy[8] = { -1, -2, 2, 1, -1, -2, 2, 1 };
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

struct NODE {
	int c, x, y, used;
	NODE(int _c, int _x, int _y, int _u) {
		c = _c; x = _x; y = _y; used = _u;
	}
	NODE() {}
};
struct NODE_CMP {
	bool operator() (const NODE &a, const NODE &b) {
		return a.c > b.c;
	}
};

bool is_range(int x, int y) {
	return x >= 0 && x < W && y >= 0 && y < H;
}

int solution_monkey_like_horse() {
	board.clear();
	cin >> K;
	cin >> H >> W;
	board.resize(W, vector<int>(H, 0));

	for (int i = 0; i < W; i++) {
		for (int j = 0; j < H; j++) {
			cin >> board[i][j];
		}
	}
	int dist[MAX_N][MAX_N][MAX_K];
	for (int i = 0; i < W; i++) {
		for (int j = 0; j < H; j++) {
			for (int k = 0; k <= K; k++) {
				dist[i][j][k] = INT_MAX;
			}
		}
	}


	//가중치 없으니 01bfs 로도 해결 가능하다.

	priority_queue<NODE, vector<NODE>, NODE_CMP>pq;
	dist[0][0][0] = 0;
	pq.push(NODE(0, 0, 0, 0));
	while (!pq.empty()) {
		NODE cur = pq.top(); pq.pop();
		int cx = cur.x;
		int cy = cur.y;
		int ccost = cur.c;
		int cused = cur.used;
		if (ccost != dist[cx][cy][cused])continue;
		if (cx == W - 1 && cy == H - 1) {
			return dist[cx][cy][cused];
		}

		//K 미만이어야 접근할 수 있다.
		if (cused < K) {
			for (int d = 0; d < 8; d++) {
				int nx = cx + h_dx[d];
				int ny = cy + h_dy[d];
				if (!is_range(nx, ny) || board[nx][ny] == 1)continue;
				int nused = cused + 1;
				int ncost = ccost + 1;
				if (dist[nx][ny][nused] <= ncost)continue;
				dist[nx][ny][nused] = ncost;
				pq.push(NODE(ncost, nx, ny, nused));
			}
		}
		for (int d = 0; d < 4; d++) {
			int nx = cx + dx[d];
			int ny = cy + dy[d];
			if (!is_range(nx, ny) || board[nx][ny] == 1)continue;
			int nused = cused;
			int ncost = ccost + 1;
			if (dist[nx][ny][nused] <= ncost)continue;
			dist[nx][ny][nused] = ncost;
			pq.push(NODE(ncost, nx, ny, nused));
		}
	}
	return -1;
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout << solution_monkey_like_horse() << "\n";

	//int T; cin >> T;
	//for (int test_case = 1; test_case <= T; test_case++) {
	//	cout << "#" << test_case << " " << solution_monkey_like_horse() << "\n";
	//}


	return 0;
}


/*
2
1
4 4
0 0 0 0
1 0 0 0
0 0 1 0
0 1 0 0
2
5 2
0 0 1 1 0
0 0 1 1 0
*/

/*
4
-1
*/
/*
어처구니 없게 priority_queue를 사용했다.
이 문제는 bfs로 해결 가능하다
즉 현재 시간복잡도가 최적이 아니다.
*/