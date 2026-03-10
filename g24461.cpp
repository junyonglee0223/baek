#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

vector<int> findTrunk(int n, const vector<pair<int, int>>& edges) {
    vector<vector<int>> adj(n);
    vector<int> degree(n, 0);

    for (const auto& e : edges) {
        int a = e.first;
        int b = e.second;
        adj[a].push_back(b);
        adj[b].push_back(a);
        degree[a]++;
        degree[b]++;
    }

    queue<int> q;
    for (int i = 0; i < n; i++) {
        if (degree[i] == 1) {
            q.push(i);
        }
    }

    vector<bool> removed(n, false);

    while ((int)q.size() > 2) {
        int sz = q.size();
        vector<int> nextLeaves;

        for (int i = 0; i < sz; i++) {
            int cur = q.front();
            q.pop();

            removed[cur] = true;

            for (int nxt : adj[cur]) {
                if (removed[nxt]) {
                    continue;
                }
                degree[nxt]--;
                if (degree[nxt] == 1) {
                    nextLeaves.push_back(nxt);
                }
            }
        }

        for (int v : nextLeaves) {
            q.push(v);
        }
    }

    vector<int> trunk;
    for (int i = 0; i < n; i++) {
        if (!removed[i]) {
            trunk.push_back(i);
        }
    }

    sort(trunk.begin(), trunk.end());
    return trunk;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<pair<int, int>> edges;
    edges.reserve(n - 1);

    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        edges.push_back({a, b});
    }

    vector<int> ans = findTrunk(n, edges);

    for (int i = 0; i < (int)ans.size(); i++) {
        if (i) {
            cout << ' ';
        }
        cout << ans[i];
    }
    cout << '\n';

    return 0;
}