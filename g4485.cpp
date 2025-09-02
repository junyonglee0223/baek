#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<climits>
using namespace std;

typedef pair<int, int>p;


struct NODE {
	int c, x, y;
	NODE(int _c, int _x, int _y) {
		c = _c;
		x = _x;
		y = _y;
	}
	NODE() {}
};

struct NODE_CMP {
	bool operator()(const NODE &a, const NODE &b) {
		return a.c > b.c;
	}
};

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };
int N;

bool is_range(int x, int y) {
	return x >= 0 && x < N &&  y >= 0 && y < N;
}
int solution_green_zelda(int t) {
	N = t;
	vector<vector<int>>board(N, vector<int>(N, 0));
	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> board[i][j];
		}
	}
	priority_queue<NODE, vector<NODE>, NODE_CMP>pq;
	vector<vector<int>>dist(N, vector<int>(N, INT_MAX));

	dist[0][0] = board[0][0];
	pq.push(NODE(dist[0][0], 0, 0));

	while (!pq.empty()) {
		NODE cur = pq.top(); pq.pop();
		int cx = cur.x;
		int cy = cur.y;
		int cc = cur.c;
		if (dist[cx][cy] < cc)continue;

		for (int d = 0; d < 4; d++) {
			int nx = cx + dx[d];
			int ny = cy + dy[d];
			if (!is_range(nx, ny))continue;

			int nc = cc + board[nx][ny];
			if (dist[nx][ny] > nc) {
				dist[nx][ny] = nc;
				pq.push(NODE(nc, nx, ny));
			}
		}
	}

	return dist[N-1][N-1];
}


int main(int argc, char** argv)
{
	int test_case;
	int T;

	cin >> T;

	for (test_case = 1; ; ++test_case)
	{
		if (T == 0)break;
		int ret = solution_green_zelda(T);
		cout << "Problem " << test_case << ": " << ret << "\n";
		cin >> T;
	}
	return 0;
}
/*
N, M <=50
2500개 노드로 만들지 아니면 board를 그대로 활용할지 문제

조건문만 잘 만들면 노드로 만들 필요는 없다.
bfs로 이동하면 된다.


*/

/*
3
5 5 4
3 9 1
3 2 7
5
3 7 2 0 1
2 8 0 9 1
1 2 1 8 1
9 8 9 2 0
3 6 5 1 5
7
9 0 5 1 1 5 3
4 1 2 1 6 5 3
0 7 6 1 6 8 5
1 1 7 8 3 2 3
9 4 0 7 6 4 1
5 8 3 2 4 8 3
7 4 8 4 8 3 4
0
*/