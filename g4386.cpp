//별자리 만들기
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

struct Edge {
    int u, v;
    double weight;
};

struct Star {
    double x, y;
};

int find(vector<int>& parent, int u) {
    if (parent[u] == u) return u;
    return parent[u] = find(parent, parent[u]);
}

void unionSet(vector<int>& parent, vector<int>& rank, int u, int v) {
    u = find(parent, u);
    v = find(parent, v);
    if (u != v) {
        if (rank[u] < rank[v]) swap(u, v);
        parent[v] = u;
        if (rank[u] == rank[v]) rank[u]++;
    }
}

double kruskal(int n, vector<Edge>& edges) {
    sort(edges.begin(), edges.end(), [](const Edge& a, const Edge& b) {
        return a.weight < b.weight;
    });

    vector<int> parent(n), rank(n, 0);
    for (int i = 0; i < n; ++i) parent[i] = i;

    double totalWeight = 0;
    for (Edge& edge : edges) {
        if (find(parent, edge.u) != find(parent, edge.v)) {
            totalWeight += edge.weight;
            unionSet(parent, rank, edge.u, edge.v);
        }
    }
    return totalWeight;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(2);
    cout << fixed;

    int n;
    cin >> n;
    vector<Star> stars(n);
    for (int i = 0; i < n; ++i) {
        cin >> stars[i].x >> stars[i].y;
    }

    vector<Edge> edges;
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            double dist = sqrt(pow(stars[i].x - stars[j].x, 2) + pow(stars[i].y - stars[j].y, 2));
            edges.push_back({i, j, dist});
        }
    }

    double result = kruskal(n, edges);
    cout << result << endl;

    return 0;
}
