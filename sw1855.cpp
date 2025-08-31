//sw1855 영준이의 BFS
#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
typedef long long ll;

int MAX_LOG;
int V; 
vector<vector<int>> parents;
vector<int> depth; 
vector<vector<int>> adj;

int find_closest_parents(int n1, int n2) {
    int original_n1 = n1, original_n2 = n2;
    if (depth[n1] < depth[n2]) {
        swap(n1, n2);
    }
    int dist = depth[n1] - depth[n2];

    for (int i = 0; i < MAX_LOG; i++) {
        if ((dist & (1 << i)) != 0) {
            n1 = parents[n1][i];
        }
    }
    if (n1 == n2)return n1;

    for (int i = MAX_LOG - 1; i >= 0; i--) {
        if (parents[n1][i] != parents[n2][i]) {
            n1 = parents[n1][i];
            n2 = parents[n2][i];
        }
    }

    return parents[n1][0];
}

ll solution_Youngjun_s_bfs() {
    cin >> V;
    MAX_LOG = 0;
    while ((1 << MAX_LOG) <= V)MAX_LOG++;

    parents.clear();
    depth.clear();
    adj.clear();
    
    parents.resize(V + 1, vector<int>(MAX_LOG, -1));
    depth.resize(V + 1, -1);
    adj.resize(V + 1);
    
    for (int i = 0; i < V - 1; i++) {
        int a;
        cin >> a;
        adj[a].push_back(i + 2);
        parents[i + 2][0] = a;
    }
    for (int i = 1; i <= V; i++) {
        sort(adj[i].begin(), adj[i].end());
    }
    int root = 1;
    depth[root] = 0;
    vector<int> bfs_order;
    queue<int> q;
    q.push(root);
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
            if (tmp_parent == -1) continue;
            parents[node][i] = parents[tmp_parent][i - 1];
        }
    }
    ll ret = 0; 
    for (int i = 1; i < bfs_order.size(); i++) {
        int prev = bfs_order[i - 1];
        int cur = bfs_order[i];
        int lca = find_closest_parents(prev, cur);
        ret += (ll)(depth[prev] + depth[cur] - 2 * depth[lca]);  
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        ll ret = solution_Youngjun_s_bfs();
        cout << "#" << t << " " << ret << "\n";
    }
    return 0;
}