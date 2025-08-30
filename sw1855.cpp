//1855 영준이의 BFS
#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

long long solution_Youngjun_s_bfs() {
    int V;
    cin >> V;

    int MAX_LOG = 0;
    while ((1 << MAX_LOG) <= V) MAX_LOG++;

    vector<vector<int>> parents(V + 1, vector<int>(MAX_LOG, -1));
    vector<int> depth(V + 1, -1);
    vector<vector<int>> adj(V + 1);

    parents[1][0] = -1;
    for (int i = 0; i < V - 1; i++) {
        int a;
        cin >> a;
        adj[a].push_back(i + 2);
        parents[i + 2][0] = a;
    }

    for (int i = 1; i <= V; i++) {
        sort(adj[i].begin(), adj[i].end());
    }

    vector<int> bfs_order;
    queue<int> q;
    q.push(1);
    depth[1] = 0;

    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        bfs_order.push_back(cur);

        for (int nxt : adj[cur]) {
            depth[nxt] = depth[cur] + 1;
            q.push(nxt);
        }
    }

    for (int i = 1; i < MAX_LOG; i++) {
        for (int node = 1; node <= V; node++) {
            int tmp_parent = parents[node][i - 1];
            if (tmp_parent != -1) {
                parents[node][i] = parents[tmp_parent][i - 1];
            }
        }
    }

    auto findLCA = [&](int u, int v) -> int {
        if (depth[u] < depth[v]) swap(u, v);

        int diff = depth[u] - depth[v];
        for (int i = 0; i < MAX_LOG; i++) {
            if ((diff >> i) & 1) {
                u = parents[u][i];
            }
        }

        if (u == v) return u;

        for (int i = MAX_LOG - 1; i >= 0; i--) {
            if (parents[u][i] != parents[v][i]) {
                u = parents[u][i];
                v = parents[v][i];
            }
        }
        return parents[u][0];
    };

    long long ret = 0;
    for (int i = 1; i < bfs_order.size(); i++) {
        int prev = bfs_order[i - 1];
        int cur = bfs_order[i];
        int lca = findLCA(prev, cur);
        ret += (long long)depth[prev] + depth[cur] - 2LL * depth[lca];
    }

    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    for (int t = 1; t <= T; t++) {
        long long ret = solution_Youngjun_s_bfs();
        cout << "#" << t << " " << ret << "\n";
    }

    return 0;
}