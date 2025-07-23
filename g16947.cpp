//g16947 서울 지하철 2호선
#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

int n;
vector<vector<int>>adj;
vector<int>node_idx;
int global_cnt = 0;

int dfs_station(int cur, int par, vector<bool>&visited) {
	node_idx[cur] = global_cnt++;

	for (auto nxt : adj[cur]) {
		if (nxt == par)continue;
		if (visited[nxt]) {
			node_idx[cur] = min(node_idx[cur], node_idx[nxt]);
		}
		else {
			visited[nxt] = true;
			node_idx[cur] = min(node_idx[cur], dfs_station(nxt, cur, visited));
		}
	}
	return node_idx[cur];
}


void solution_subway_dist_v2() {
	adj.clear();
	node_idx.clear();
	global_cnt = 0;

	cin >> n;
	adj.resize(n + 1);
	node_idx.resize(n + 1, -1);

	for (int i = 0; i < n; i++) {
		int a, b; cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	vector<bool>visited(n + 1, false);

    visited[1] = true;
	dfs_station(1, 0, visited);

	vector<vector<int>>idx_group(n+1);

	for (int i = 1; i <= n; i++) {
		idx_group[node_idx[i]].push_back(i);
	}


	queue<pair<int, int>>q;
	vector<int>ret_tmp(n + 1, -1);
	//ret.resize(n + 1, -1);

	for (auto v_ele : idx_group) {
		if (v_ele.size() < 3)continue;
		for (auto ele : v_ele) {
			q.push({ 0, ele });
			ret_tmp[ele] = 0;
		}
	}

	while (!q.empty()) {
		int cur_dist = q.front().first;
		int cur = q.front().second;
		q.pop();

		for (auto nxt : adj[cur]) {
			if (ret_tmp[nxt] != -1)continue;
			q.push({ cur_dist + 1, nxt });
			ret_tmp[nxt] = cur_dist + 1;
		}
	}

	for (int i = 1; i <= n; i++) {
		cout << ret_tmp[i] << " ";
	}
	cout << endl;
}

void solution_subway_dist() {
	cin >> n;
	adj.clear();
	adj.assign(n + 1, {});
	for (int i = 0; i < n; i++) {
		int a, b; cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	vector<int> degree(n + 1);
	for (int i = 1; i <= n; i++) {
		degree[i] = adj[i].size();
	}

	queue<int> q;
	vector<bool> inCycle(n + 1, true);
	for (int i = 1; i <= n; i++) {
		if (degree[i] == 1) {
			inCycle[i] = false;
			q.push(i);
		}
	}
	while (!q.empty()) {
		int u = q.front(); q.pop();
		for (int v : adj[u]) {
			if (!inCycle[v]) continue;
			if (--degree[v] == 1) {
				inCycle[v] = false;
				q.push(v);
			}
		}
	}

	vector<int> dist(n + 1, -1);
	for (int i = 1; i <= n; i++) {
		if (inCycle[i]) {
			dist[i] = 0;
			q.push(i);
		}
	}
	while (!q.empty()) {
		int u = q.front(); q.pop();
		for (int v : adj[u]) {
			if (dist[v] == -1) {
				dist[v] = dist[u] + 1;
				q.push(v);
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		cout << dist[i] << ' ';
	}
	cout << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	//int T; cin >> T;
	//while (T--) {
		solution_subway_dist();
		//solution_subway_dist_v2();
		/*
		for (int i = 1; i <= n; i++) {
			cout << ret[i] << " ";
		}
		cout << endl;
		*/
	//}
	return 0;
}

/*
7
5
4
1 3
4 3
4 2
1 2
6
1 2
3 4
6 4
2 3
1 3
3 5
51
1 2
2 3
3 4
4 5
5 6
6 7
7 8
8 9
9 10
10 11
11 12
12 13
13 14
14 15
15 16
16 17
17 18
18 19
19 20
20 21
21 22
22 23
23 24
24 25
25 26
26 27
27 28
28 29
29 30
30 31
31 32
32 33
33 34
34 35
35 36
36 37
37 38
38 39
39 40
40 41
41 42
42 43
43 1
11 44
44 45
45 46
46 47
34 48
48 49
49 50
50 51
38
1 2
2 3
3 4
4 5
5 6
6 1
1 7
7 8
8 9
9 10
10 11
11 12
12 13
13 14
14 15
15 16
16 17
17 18
18 19
19 20
20 21
21 22
22 23
23 24
24 25
25 26
26 27
27 28
28 29
29 30
30 31
31 32
32 33
33 34
34 35
35 36
36 37
37 38
12
1 3
3 4
4 5
5 6
6 7
7 8
8 4
2 3
7 9
9 12
7 10
10 11
6
1 2
2 3
3 4
3 5
4 6
5 6
5
1 2
2 3
2 4
3 5
4 5
*/
/*
0 0 0 0
0 0 0 1 1 2
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 2 3 4 1 2 3 4
0 0 0 0 0 0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29 30 31 32
2 2 1 0 0 0 0 0 1 1 2 2
2 1 0 0 0 0
1 0 0 0 0
*/
/*

*/