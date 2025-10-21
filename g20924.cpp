//g20924 트리의 기둥과 가지
#include <iostream>
#include <vector>
#include <string>
#include <climits>
#include <algorithm>
#include <queue>
#include <functional>
using namespace std;


typedef pair<int, int>pii;
vector<vector<pii>>adj;
vector<bool>node_visited;
int max_dist = 0;

void dfs_tree(int cur, int sum_d) {
	for (auto nxt_n : adj[cur]) {
		int nxt = nxt_n.first;
		int c_n_dist = nxt_n.second;
		if (node_visited[nxt])continue;
		max_dist = max(max_dist, sum_d + c_n_dist);
		node_visited[nxt] = true;
		dfs_tree(nxt, sum_d + c_n_dist);
	}
}


void solution_tree() {
	adj.clear();
	node_visited.clear();
	max_dist = 0;
	int n, r; cin >> n >> r;


	adj.resize(n + 1);
	node_visited.resize(n + 1, false);
	for (int i = 0; i < n - 1; i++) {
		int a, b, c; cin >> a >> b >> c;
		adj[a].push_back({ b, c });
		adj[b].push_back({ a, c });
	}

	int start = r;
	node_visited[start] = true;
	int main_d = 0;
	while (true) {
		int cur_cnt = 0;
		pii tmp;
		for (auto nxt_n : adj[start]) {
			if (node_visited[nxt_n.first])continue;
			cur_cnt++;
			tmp = nxt_n;
		}
		if (cur_cnt > 1|| cur_cnt == 0)break;
		

		main_d += tmp.second;
		start = tmp.first;
		node_visited[start] = true;
	}

	//for (int i = 1; i <= n; i++) {
	//	cout << adj[i].size() << " ";
	//}
	//cout << endl;
	//cout << start << " " << main_d << endl;

	//auto dfs = [&](int cur, int sum_d) -> void {
	//	for (auto nxt_n : adj[cur]) {
	//		int nxt = nxt_n.first;
	//		int c_n_dist = nxt_n.second;
	//		if (node_visited[nxt])continue;
	//		max_dist = max(max_dist, sum_d + c_n_dist);
	//		node_visited[nxt] = true;
	//		dfs(nxt, sum_d + c_n_dist);
	//	}
	//};

	dfs_tree(start, 0);

	cout << main_d << " " << max_dist << "\n";
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	solution_tree();


	//int t; cin >> t;
	//while (t--) {
	//	cout << "!!!!!!!!!!!!!!!!!!!!" << endl;
	//	solution_tree();
	//}


	return 0;
}


/*
4
12 1
1 2 1
2 3 2
3 4 3
4 5 1
5 6 2
6 7 1
5 8 1
4 9 2
4 10 3
10 11 1
10 12 3
9 1
1 2 5
2 3 4
3 4 2
2 5 5
1 6 8
1 7 6
7 8 7
7 9 1
4 1
1 2 100
2 3 10
3 4 1
1 1
*/

/*
6 6
0 13
111 0
0 0
*/