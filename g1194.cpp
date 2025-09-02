#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

#define MAX_K 6
#define MAX_N 50
int N, M;
char board[MAX_N][MAX_N];
int cnt_b[MAX_N][MAX_N][(1 << MAX_K)];
int sx, sy;

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

bool is_range(int x, int y) {
	return x >= 0 && x < N && y >= 0 && y < M;
}
bool is_small_alphabet(char c) {
	return 'a' <= c && c <= 'f';
}
bool is_large_alphabet(char c) {
	return 'A' <= c && c <= 'F';
}

struct NODE {
	int key, x, y;
	NODE() {}
	NODE(int _key, int _x, int _y) {
		key = _key;
		x = _x;
		y = _y;
	}
};

int solution_go_4_the_moon() {

	cin >> N >> M;


	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			for (int k = 0; k < (1 << MAX_K); k++) {
				cnt_b[i][j][k] = -1;
			}
		}
	}
	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			char c; cin >> c;
			board[i][j] = c;
			if (c == '0') {
				board[i][j] = '.';
				sx = i; sy = j;
			}
		}
	}

	queue<NODE>que;

	cnt_b[sx][sy][0] = 0;
	que.push(NODE(0, sx, sy));
	while (!que.empty()) {
		NODE cur = que.front(); que.pop();
		int cx = cur.x;
		int cy = cur.y;
		int ckey = cur.key;

		for (int d = 0; d < 4; d++) {
			int nx = cx + dx[d];
			int ny = cy + dy[d];
			if (!is_range(nx, ny) || board[nx][ny] == '#' || cnt_b[nx][ny][ckey] != -1)continue;
			char nbc = board[nx][ny];
			if (nbc == '.') {
				cnt_b[nx][ny][ckey] = cnt_b[cx][cy][ckey] + 1;
				que.push(NODE(ckey, nx, ny));
			}
			else if (nbc == '1') {
				return cnt_b[cx][cy][ckey] + 1;
			}
			else {
				if (is_small_alphabet(nbc)) {
					int alpha = nbc - 'a';
					int nkey = (ckey | (1 << alpha));
					cnt_b[nx][ny][nkey] = cnt_b[cx][cy][ckey] + 1;
					que.push(NODE(nkey, nx, ny));
				}
				else {
					int alpha = nbc - 'A';
					if ((ckey & (1 << alpha)) != 0) {
						cnt_b[nx][ny][ckey] = cnt_b[cx][cy][ckey] + 1;
						que.push(NODE(ckey, nx, ny));
					}
				}

			}

		}

	}


	return -1;

}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout << solution_go_4_the_moon() <<"\n";


	//int T;
	//if (!(cin >> T)) return 0;
	//for (int tc = 1; tc <= T; ++tc) {
	//	int ans = solution_go_4_the_moon();
	//	////////////////////////////////////////////////
	//	//for (int k = 0; k < (1 << MAX_K); k++) {
	//	//	cout << "------------------------------------------" << endl;
	//	//	cout << k << endl;
	//	//	for (int i = 0; i < N; i++) {
	//	//		for (int j = 0; j < M; j++) {
	//	//			cout << cnt_b[i][j][k] << " ";
	//	//		}
	//	//		cout << endl;
	//	//	}
	//	//	cout << "------------------------------------------" << endl;

	//	//}
	//	////////////////////////////////////////////////

	//	cout << "#" << tc << " " << ans << "\n";
	//}
	return 0;
}

/*
bfs로 이동하는게 기본적일 듯 한데
열쇠를 가지면 문을 열 수 있다는 점이 추가되었다.
visited 3차원으로 하되
51 * 51 * 64 = 166464
배열 안에 설정하면 된다.



*/

/*
8
1 7
f0.F..1
5 5
....1
#1###
.1.#0
....A
.1.#.
7 8
a#c#eF.1
.#.#.#..
.#B#D###
0....F.1
C#E#A###
.#.#.#..
d#f#bF.1
3 4
1..0
###.
1...
3 5
..0..
.###.
..1.A
4 5
0....
.#B#A
.#.#.
b#a#1
1 11
c.0.C.C.C.1
3 6
###...
#0A.1a
###...
*/
/*

7
-1
55
3
6
19
12
-1*/