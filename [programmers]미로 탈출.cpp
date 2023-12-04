#include<bits/stdc++.h>
#define INF 0x3f3f3f3f
using namespace std;
int dist[1001][1025];
struct edge{
    int to;
    int cost;
    bool normal;   
    edge(int t, int c, bool b): to(t), cost(c), normal(b) {}
};
vector<edge> vertex[1001];
map<int,int> tr;

bool isTrap(int idx){
    return tr.find(idx) != tr.end();
}

bool isReverse(int bitmask, int idx){
    return isTrap(idx) && (bitmask & (1 << tr[idx]));
}

bool isPossible(int from, edge e, int bitmask){
    int to = e.to;
 
    if (!isTrap(from) && !isTrap(to)) {
        return e.normal;
    }
 
    if (isReverse(bitmask, from) ^ isReverse(bitmask, to)) {
        return !e.normal;
    } else {
        return e.normal;
    }
}

int solution(int n, int start, int end, vector<vector<int>> roads, vector<int> traps) {
    int answer = INF;
    for (int i = 0; i < 1001; i++) {
        fill(dist[i], dist[i] + 1025, INF);
    }

    for (int i = 0; i < traps.size(); i++) {
        tr[traps[i]] = i;
    }

    for (auto& road : roads) {
        int from = road[0], to = road[1], cost = road[2];
        vertex[from].emplace_back(to, cost, true);
        vertex[to].emplace_back(from, cost, false);
    }

    dist[start][0] = 0;
    queue<pair<int, int>> q;
    q.push({start, 0});

    while (!q.empty()) {
        int cur = q.front().first;
        int bitmask = q.front().second;
        q.pop();

        for (auto& e : vertex[cur]) {
            if (isPossible(cur, e, bitmask)) {
                int next = e.to;
                int next_cost = dist[cur][bitmask] + e.cost;
                int nextBitmask = bitmask;

                if (isTrap(next)) {
                    nextBitmask ^= (1 << tr[next]);
                }

                if (dist[next][nextBitmask] > next_cost) {
                    dist[next][nextBitmask] = next_cost;
                    q.push({next, nextBitmask});
                }
            }
        }
    }

    for (int i = 0; i < (1 << traps.size()); i++) {
        answer = min(answer, dist[end][i]);
    }

    return answer;
}
