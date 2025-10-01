//g2611 자동차 경주
#include <string>
#include <vector>
#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

typedef pair<int, int>pii;

void solution_car_racing() {
	int N, M; cin >> N >> M;
	vector<vector<pii>>adj(N);
	vector<vector<pii>>rev_adj(N);

	for (int i = 0; i < M; i++) {
		int a, b, c; cin >> a >> b >> c;
		a--; b--;
		adj[a].push_back({ b, c });
		rev_adj[b].push_back({ a, c });
	}

	vector<int>scores(N, 0);
	/*priority_queue<pii>pq;
	pq.push({ 0, 0 });
*/
	queue<pii>que;
	que.push({ 0, 0 });
	while (!que.empty()) {
		pii cur_node = que.front(); que.pop();
		int cur = cur_node.second;
		int cur_cost = cur_node.first;
		if (cur_cost < scores[cur])continue;

		for (auto nxt_pii : adj[cur]) {
			int nxt = nxt_pii.first;
			int nxt_cost = cur_cost + nxt_pii.second;
			if (scores[nxt] < nxt_cost) {
				scores[nxt] = nxt_cost;
				if(nxt != 0)
					que.push({ nxt_cost, nxt });
			}
		}
	}


	vector<int> trace;
	int max_cost = scores[0];
	int cur_cost = scores[0];
	scores[0] = 0;
	int cur = 0;
	while (cur_cost) {
		//cout << cur_cost << endl;////////////////////////////////
		for (auto nxt_pii : rev_adj[cur]) {
			int nxt = nxt_pii.first;
			int nxt_cost = cur_cost - nxt_pii.second;
			if (scores[nxt] == nxt_cost) {
				trace.push_back(nxt);
				cur = nxt;
				cur_cost = nxt_cost;
				break;
			}
		}
	}
	reverse(trace.begin(), trace.end());
	trace.push_back(0);

	cout << max_cost << "\n";
	for (auto ele : trace) {
		cout << ele + 1 << " ";
	}
	cout << "\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	solution_car_racing();

	return 0;
}

/*
8
13
1 2 5
1 3 4
2 5 2
2 6 1
3 6 3
5 6 7
5 8 9
6 8 3
4 1 6
6 4 8
7 4 5
6 7 2
8 7 4
*/

/*
32
1 2 5 6 8 7 4 1
*/