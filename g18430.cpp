#include <bits/stdc++.h>
using namespace std;

int n, m;
int a[5][5];
bool used[5][5];
int best = 0;

const int dx1[4] = {-1, -1,  1, 1};
const int dy1[4] = { 0,  0,  0, 0};
const int dx2[4] = { 0,  0,  0, 0};
const int dy2[4] = {-1,  1, -1, 1};

inline bool inside(int x, int y) {
    return 0 <= x && x < n && 0 <= y && y < m;
}

void dfs(int idx, int sum) {
    if (idx == n * m) {
        best = max(best, sum);
        return;
    }

    int x = idx / m;
    int y = idx % m;

    dfs(idx + 1, sum);

    if (used[x][y]) return;

    for (int t = 0; t < 4; t++) {
        int x1 = x + dx1[t], y1 = y + dy1[t];
        int x2 = x + dx2[t], y2 = y + dy2[t];

        if (!inside(x1, y1) || !inside(x2, y2)) continue;
        if (used[x1][y1] || used[x2][y2]) continue;

        used[x][y] = used[x1][y1] = used[x2][y2] = true;
        int val = a[x][y] * 2 + a[x1][y1] + a[x2][y2];
        dfs(idx + 1, sum + val);
        used[x][y] = used[x1][y1] = used[x2][y2] = false;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) cin >> a[i][j];
    }

    memset(used, 0, sizeof(used));
    dfs(0, 0);

    cout << best << "\n";
    return 0;
}


/*
3 3
32 83 75
24 96 56
71 88 12
*/
/*
-> 632
*/


/*
방향이 4가지 가능한 점
dfs 탐색, 백트래킹 활용


*/