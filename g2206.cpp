//벽 부수고 이동하기
#include <iostream>
#include <vector>
#include <queue>
#include <string>
using namespace std;

#define endl '\n'
#define INF 1e9

int N, M;
vector<vector<int>> board;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

bool isRange(int x, int y) {
    return (x >= 0) && (y >= 0) && (x < N) && (y < M);
}

int bfs() {
    queue<pair<pair<int, int>, pair<int, int>>> q; // ((x, y), (dist, wall_removed))
    vector<vector<vector<int>>> visited(N, vector<vector<int>>(M, vector<int>(2, INF)));

    q.push({{0, 0}, {1, 0}});
    visited[0][0][0] = 1;

    while (!q.empty()) {
        int x = q.front().first.first;
        int y = q.front().first.second;
        int dist = q.front().second.first;
        int wall_removed = q.front().second.second;
        q.pop();

        if (x == N - 1 && y == M - 1) {
            return dist;
        }

        for (int d = 0; d < 4; d++) {
            int nx = x + dx[d];
            int ny = y + dy[d];

            if (isRange(nx, ny)) {
                if (board[nx][ny] == 0 && visited[nx][ny][wall_removed] == INF) {
                    visited[nx][ny][wall_removed] = dist + 1;
                    q.push({{nx, ny}, {dist + 1, wall_removed}});
                } else if (board[nx][ny] == 1 && wall_removed == 0 && visited[nx][ny][1] == INF) {
                    visited[nx][ny][1] = dist + 1;
                    q.push({{nx, ny}, {dist + 1, 1}});
                }
            }
        }
    }

    return -1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;
    board.resize(N, vector<int>(M, 0));

    for (int i = 0; i < N; i++) {
        string tmp;
        cin >> tmp;
        for (int j = 0; j < M; j++) {
            if (tmp[j] == '1') {
                board[i][j] = 1;
            }
        }
    }

    int ans = bfs();
    cout << ans << endl;

    return 0;
}
