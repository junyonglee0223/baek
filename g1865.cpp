//웜홀
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

#define INF 1e9

struct Edge {
    int u, v, w;
};

bool bellman_ford(int N, const vector<Edge>& edges) {
    vector<int> dist(N + 1, INF);
    dist[0] = 0; 

    for (int i = 0; i < N; ++i) {
        for (const auto& edge : edges) {
            if (dist[edge.u] != INF && dist[edge.u] + edge.w < dist[edge.v]) {
                dist[edge.v] = dist[edge.u] + edge.w;
            }
        }
    }

    for (const auto& edge : edges) {
        if (dist[edge.u] != INF && dist[edge.u] + edge.w < dist[edge.v]) {
            return true; 
        }
    }

    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T; 
    cin >> T;
    while (T--) {
        int N, M, W;
        cin >> N >> M >> W;

        vector<Edge> edges;

        for (int i = 0; i < M; i++) {
            int s, d, t;
            cin >> s >> d >> t;
            edges.push_back({s, d, t});
            edges.push_back({d, s, t});
        }

        for (int i = 0; i < W; i++) {
            int s, d, t;
            cin >> s >> d >> t;
            edges.push_back({s, d, -t});
        }

        for (int i = 1; i <= N; ++i) {
            edges.push_back({0, i, 0});
        }

        if (bellman_ford(N, edges)) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }

    return 0;
}
