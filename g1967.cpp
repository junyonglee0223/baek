//트리의 지름
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define endl '\n'

typedef pair<int, int> p;

int N;
vector<vector<p>> graph;
int maxDist = 0;
int furthestNode = 0;

void dfs(int node, int dist, vector<bool>& visited) {
    visited[node] = true;
    if (dist > maxDist) {
        maxDist = dist;
        furthestNode = node;
    }
    for (auto& nxtNode : graph[node]) {
        int nxt = nxtNode.first;
        int weight = nxtNode.second;
        if (!visited[nxt]) {
            dfs(nxt, dist + weight, visited);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    graph.resize(N + 1);

    for (int i = 0; i < N - 1; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        graph[a].push_back({b, c});
        graph[b].push_back({a, c}); 
    }

    vector<bool> visited(N + 1, false);
    dfs(1, 0, visited);

    maxDist = 0;
    fill(visited.begin(), visited.end(), false);
    dfs(furthestNode, 0, visited);

    cout << maxDist << endl;

    return 0;
}
