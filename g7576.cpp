//토마토
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define endl '\n'

#define x first
#define y second

typedef pair<int,int> p;
int N, M;
vector<vector<int>> tomato;
vector<vector<int>> dist;
queue<p> q;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    cin >> M >> N;
    tomato.resize(N, vector<int>(M));
    dist.resize(N, vector<int>(M, -1));

    bool all_ripe = true;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> tomato[i][j];
            if (tomato[i][j] == 1) {
                q.push({i, j});
                dist[i][j] = 0;
            }
            if (tomato[i][j] == 0) {
                all_ripe = false;
            }
        }
    }

    if (all_ripe) {
        cout << 0 << endl;
        return 0;
    }

    while (!q.empty()) {
        int nowX = q.front().x;
        int nowY = q.front().y;
        q.pop();

        for (int d = 0; d < 4; d++) {
            int nxtX = nowX + dx[d];
            int nxtY = nowY + dy[d];
            if (nxtX < 0 || nxtX >= N || nxtY < 0 || nxtY >= M) continue;
            if (tomato[nxtX][nxtY] == -1) continue;

            if (dist[nxtX][nxtY] == -1) {
                q.push({nxtX, nxtY});
                dist[nxtX][nxtY] = dist[nowX][nowY] + 1;
            }
        }
    }

    int ret = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (tomato[i][j] == 0 && dist[i][j] == -1) {
                cout << -1 << endl;
                return 0;
            }
            ret = max(ret, dist[i][j]);
        }
    }

    cout << ret << endl;
    return 0;
}




