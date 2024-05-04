//연구소
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

typedef pair<int, int> p;
int N, M;
vector<vector<int>> lab;
vector<p> virus;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int lab_bfs(int a, int b, int c) {
    vector<vector<int>> tmp_lab = lab;
    vector<p> wallPositions = {{a / M, a % M}, {b / M, b % M}, {c / M, c % M}};

    for (auto& pos : wallPositions) {
        if (tmp_lab[pos.first][pos.second] != 0) {
            return 0; 
        }
        tmp_lab[pos.first][pos.second] = 1;
    }

    queue<p> tmpQ;
    for (auto& v : virus) {
        tmpQ.push(v);
    }

    while (!tmpQ.empty()) {
        p front = tmpQ.front();
        tmpQ.pop();
        int now_x = front.first;
        int now_y = front.second;
        for (int i = 0; i < 4; i++) {
            int nxt_x = now_x + dx[i];
            int nxt_y = now_y + dy[i];
            if (nxt_x >= 0 && nxt_x < N && nxt_y >= 0 && nxt_y < M && tmp_lab[nxt_x][nxt_y] == 0) {
                tmp_lab[nxt_x][nxt_y] = 2;
                tmpQ.push({nxt_x, nxt_y});
            }
        }
    }

    int cnt = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (tmp_lab[i][j] == 0) {
                cnt++;
            }
        }
    }
    return cnt;
}

int main() {
    cin >> N >> M;
    lab.resize(N, vector<int>(M));

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> lab[i][j];
            if (lab[i][j] == 2) {
                virus.push_back({i, j});
            }
        }
    }

    int ans = 0;
    for (int i = 0; i < N * M - 2; i++) {
        if (lab[i / M][i % M] != 0) continue;
        for (int j = i + 1; j < N * M; j++) {
            if (lab[j / M][j % M] != 0) continue;
            for (int k = j + 1; k < N * M; k++) {
                if (lab[k / M][k % M] != 0) continue;
                ans = max(ans, lab_bfs(i, j, k));
            }
        }
    }
    cout << ans << endl;
}
