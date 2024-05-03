//특정한 최단 경로
#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

#define MAX_N 801
#define INF INT_MAX
typedef pair<int, int> p;

int N, E;
vector<p> graph[MAX_N];

int min_cost_dijkstra(int src, int dst) {
    if(src == dst)return 0;
    priority_queue<p, vector<p>, greater<p>> pq;
    vector<int> dist(N + 1, INF);

    pq.push({0, src});
    dist[src] = 0;

    while (!pq.empty()) {
        int nowCost = pq.top().first;
        int now = pq.top().second;
        pq.pop();

        if (now == dst) {
            return dist[dst];
        }

        if (nowCost > dist[now]) continue;

        for (auto nxt_node : graph[now]) {
            int nxt = nxt_node.first;
            int tmp_dist = nxt_node.second;

            if (nowCost + tmp_dist < dist[nxt]) {
                dist[nxt] = nowCost + tmp_dist;
                pq.push({dist[nxt], nxt});
            }
        }
    }
    return dist[dst];
}

int main() {
    cin >> N >> E;
    for (int i = 0; i < E; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        graph[a].push_back({b, c});
        graph[b].push_back({a, c});
    }
    int v1, v2; cin >> v1 >> v2;

    int dist_1_v1 = min_cost_dijkstra(1, v1);
    int dist_1_v2 = min_cost_dijkstra(1, v2);
    int dist_v1_v2 = min_cost_dijkstra(v1, v2);
    int dist_v1_N = min_cost_dijkstra(v1, N);
    int dist_v2_N = min_cost_dijkstra(v2, N);

    int route1 = dist_1_v1 + dist_v1_v2 + dist_v2_N;
    int route2 = dist_1_v2 + dist_v1_v2 + dist_v1_N;

    int ans = min(route1, route2);

    if (ans >= INF) {
        cout << "-1\n";
    } else {
        cout << ans << endl;
    }
    return 0;
}
