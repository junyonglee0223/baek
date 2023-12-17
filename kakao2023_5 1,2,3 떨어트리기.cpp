/*
#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

int drop(vector<vector<int>> &tree, vector<int> &road) {
    // x번 노드가 현재 road[x]번째 자식노드를 가리키고 있다.
    int node = 1;
    while (!tree[node].empty()) {
        int nx = tree[node][road[node]];
        road[node] = (road[node] + 1) % tree[node].size();
        node = nx;
    }
    return node;
}

vector<int> solution(vector<vector<int>> edges, vector<int> target) {
    vector<vector<int>> tree(edges.size() + 2);
    for (auto e : edges)
        tree[e[0]].push_back(e[1]);

    // 가장 번호가 작은 노드를 가리키는 간선을 초기 길로 설정한다는 조건을 위해 정렬한다.
    for (int i = 0; i < tree.size(); i++)
        sort(tree[i].begin(), tree[i].end());

    vector<int> road(tree.size(), 0), stacked(tree.size(), 0), simulation;
    vector<bool> enough(tree.size(), 0);

    int cnt = 0;
    for (int i = 0; i < target.size(); i++)
        if (target[i] <= stacked[i] * 3)
            enough[i] = 1, cnt++;

    while (cnt < target.size()) {
        int x = drop(tree, road) - 1;
        simulation.push_back(x), stacked[x]++;

        if (target[x] < stacked[x]) return {-1}; // 과하게 쌓인 경우.
        if (target[x] <= stacked[x] * 3)
            if (!enough[x])
                cnt++, enough[x] = 1; // 충분히 쌓인 경우.
    }

    vector<int> result;
    for (auto i : simulation) {
        int x = max(1, target[i] - (stacked[i] - 1) * 3);
        target[i] -= x;
        stacked[i]--;
        result.push_back(x);
    }
    return result;
}

*/