//g9376 탈옥
#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<climits>
using namespace std;

typedef pair<int, int> p;
int N, M;
vector<vector<char>> board;
int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };

bool is_range(int x, int y) {
    if (x < 0) return false;
    if (x > N + 1) return false;
    if (y < 0) return false;
    if (y > M + 1) return false;
    return true;
}

struct NODE {
    int t, x, y;
    NODE(int _t, int _x, int _y) {
        t = _t; x = _x; y = _y;
    }
    NODE() {}
};
struct NODE_CMP {
    bool operator()(NODE &a, NODE &b) {
        return a.t > b.t;
    }
};

void print_vec(vector<vector<int>>&vec) {
    int R = vec.size(); int C = vec[0].size();
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            int val = vec[i][j];
            if (val == INT_MAX) {
                cout << "*" << " ";
                continue;
            }
            cout << val << " ";
        }
        cout << "\n";
    }
}

vector<vector<int>> dijkstra01(int sx, int sy){
    vector<vector<int>> dist(N + 2, vector<int>(M + 2, INT_MAX));
    priority_queue<NODE, vector<NODE>, NODE_CMP> pq;
    dist[sx][sy] = 0;
    pq.push(NODE(0, sx, sy));
    while(!pq.empty()){
        NODE cur = pq.top(); pq.pop();
        int ct = cur.t, cx = cur.x, cy = cur.y;
        if(dist[cx][cy] < ct) continue;
        for(int d = 0; d < 4; d++){
            int nx = cx + dx[d];
            int ny = cy + dy[d];
            if(!is_range(nx, ny)) continue;
            if(board[nx][ny] == '*') continue;
            int nt = ct;
            if(board[nx][ny] == '#') nt++;
            if(dist[nx][ny] > nt){
                dist[nx][ny] = nt;
                pq.push(NODE(nt, nx, ny));
            }
        }
    }
    return dist;
}

int solution_jailbreak() {
    cin >> N >> M;
    board.assign(N + 2, vector<char>(M + 2, '.'));
    vector<p> start;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            cin >> board[i][j];
            if (board[i][j] == '$') start.push_back({ i, j });
        }
    }
    if (start.size() > 0) board[start[0].first][start[0].second] = '.';
    if (start.size() > 1) board[start[1].first][start[1].second] = '.';

    auto d0 = dijkstra01(0, 0);
    auto d1 = dijkstra01(start[0].first, start[0].second);
    auto d2 = dijkstra01(start[1].first, start[1].second);

    int ans = INT_MAX;
    for(int i = 0; i <= N + 1; i++){
        for(int j = 0; j <= M + 1; j++){
            if(board[i][j] == '*') continue;
            if(d0[i][j] == INT_MAX) continue;
            if(d1[i][j] == INT_MAX) continue;
            if(d2[i][j] == INT_MAX) continue;
            long long s = 0LL + d0[i][j] + d1[i][j] + d2[i][j];
            if(board[i][j] == '#') s -= 2;
            if(s < ans) ans = (int)s;
        }
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T; cin >> T;
    while (T--) {
        cout << solution_jailbreak() << "\n";
    }
    return 0;
}
