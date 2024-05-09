//숨바꼭질
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

#define MAX_RANGE 100001

int src, dst;

int find_min_path_bfs(int s, int d) {
    queue<int> q;
    int cost[MAX_RANGE];
    for (int i = 0; i < MAX_RANGE; i++) {
        cost[i] = -1;
    }
    cost[s] = 0;
    q.push(s);

    while (!q.empty()) {
        int now = q.front();
        q.pop();
        if (now == d) {
            return cost[d];
        }

        if (now + 1 < MAX_RANGE && cost[now + 1] == -1) {
            cost[now + 1] = cost[now] + 1;
            q.push(now + 1);
        }

        if (now - 1 >= 0 && cost[now - 1] == -1) {
            cost[now - 1] = cost[now] + 1;
            q.push(now - 1);
        }
        if (now * 2 < MAX_RANGE && cost[2 * now] == -1) {
            cost[2 * now] = cost[now] + 1;
            q.push(now * 2);
        }
    }
    return -1;
}

int main() {
    cin >> src >> dst;

    int ans = 0;
    if (src >= dst) {
        ans = src - dst;
    } else {
        ans = find_min_path_bfs(src, dst);
    }
    cout << ans << endl;
}
