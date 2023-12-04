#include <bits/stdc++.h>
using namespace std;

#define MAXN 26
#define INF 100000001

bool check_boundary(int n, int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < n;
}

int solution(vector<vector<int>> board) {
    int n = board.size();
    int dist[MAXN][MAXN][4];
    fill(&dist[0][0][0], &dist[0][0][0] + MAXN*MAXN*4, INF);
    int dx[4] = { 1, 0, -1, 0 };
    int dy[4] = { 0, 1, 0, -1 };

    dist[0][0][0] = dist[0][0][1] = dist[0][0][2] = dist[0][0][3] = 0;
    priority_queue<pair<pair<int, int>, pair<int, int>>, vector<pair<pair<int, int>, pair<int, int>>>, greater<>> pq;
    for (int i = 0; i < 4; i++) {
        pq.push({ {0, i}, {0, 0} });
    }

    while (!pq.empty()) {
        auto now_q = pq.top();
        pq.pop();
        int cost = now_q.first.first;
        int d = now_q.first.second;
        int x = now_q.second.first;
        int y = now_q.second.second;

        if (cost > dist[x][y][d]) continue;

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (!check_boundary(n, nx, ny) || board[nx][ny] == 1) continue;
            if ((i + 2) % 4 == d)continue;


            int nxt_cost = cost + (i == d ? 100 : 600);

            if (nxt_cost < dist[nx][ny][i]) {
                dist[nx][ny][i] = nxt_cost;
                pq.push({ {nxt_cost, i}, {nx, ny} });
            }
        }
    }
    
    return min({dist[n - 1][n - 1][0], dist[n - 1][n - 1][1], dist[n - 1][n - 1][2], dist[n - 1][n - 1][3]});
}
