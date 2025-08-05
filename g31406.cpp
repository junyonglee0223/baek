//g31406 트리 탐색기(Easy)
#include <bits/stdc++.h>
using namespace std;

int dfs_folder(int cur, int& cnt, int moving,
               const vector<vector<int>>& adj,
               const vector<bool>& is_toggle) {
    if (cur != 1) {
        ++cnt;
        if (cnt == moving) return cur;
    }

    if (!is_toggle[cur]) return -1; 

    for (int nxt : adj[cur]) {
        int got = dfs_folder(nxt, cnt, moving, adj, is_toggle);
        if (got != -1) return got;
    }
    return -1;
}

int get_folder(int& moving,
               const vector<vector<int>>& adj,
               const vector<bool>& is_toggle) {
    if (moving < 1) moving = 1;

    int cnt = 0;
    int ret = dfs_folder(1, cnt, moving, adj, is_toggle);
    if (ret != -1) return ret;

    if (cnt == 0) {
        moving = 1;
        return 1;
    }
    int cnt2 = 0;
    ret = dfs_folder(1, cnt2, cnt, adj, is_toggle);
    moving = cnt;
    return ret == -1 ? 1 : ret;
}

void solution_tree_searching_easy() {
    int N, Q; 
    cin >> N >> Q;

    vector<vector<int>> adj(N + 1);
    for (int u = 1; u <= N; ++u) {
        int c; cin >> c;
        for (int j = 0; j < c; ++j) {
            int v; cin >> v;
            adj[u].push_back(v);
        }
    }

    vector<bool> is_toggle(N + 1, false);
    is_toggle[1] = true;

    int moving = 1;
    int position = get_folder(moving, adj, is_toggle);
    if (position == -1) position = 1;

    for (int i = 0; i < Q; ++i) {
        string cmd; 
        cin >> cmd;

        if (cmd == "toggle") {
            is_toggle[position] = !is_toggle[position];
            continue;
        }

        if (cmd == "move") {
            long long x; 
            cin >> x;

            long long want = (long long)moving + x;
            if (want < 1) want = 1;
            moving = (int)want;

            position = get_folder(moving, adj, is_toggle);
            cout << position << "\n";
            continue;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solution_tree_searching_easy();
    return 0;
}
