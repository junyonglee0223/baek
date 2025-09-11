// JUN9205_Wegbier.cpp
#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <cstdlib>
using namespace std;

typedef pair<int, int> p;

int calc_dist(int sx, int sy, int dx, int dy) {
	return abs(sx - dx) + abs(sy - dy);
}

#define MAX_B 20

bool solution_wegbier() {
	int N; cin >> N;
	int sx = 0, sy = 0, gx = 0, gy = 0;

	vector<p> pnts;

	for (int i = 0; i < N + 2; i++) {
		int a, b; cin >> a >> b;
		if (i == 0) { sx = a; sy = b; }
		if (i == N + 1) { gx = a; gy = b; }
		if (i > 0 && i < N + 1) { pnts.push_back({ a, b }); }
	}

	int psize = (int)pnts.size();
	vector<char> visited(psize, 0);

	queue<p> que;
	que.push({ sx, sy });

	while (!que.empty()) {
		p cur = que.front(); que.pop();
		int cx = cur.first;
		int cy = cur.second;

		int goal_distance = calc_dist(cx, cy, gx, gy);
		int need_beers_goal = (goal_distance + 49) / 50;
		if (MAX_B >= need_beers_goal) return true;

		for (int i = 0; i < psize; i++) {
			if (visited[i]) continue;
			int nx = pnts[i].first;
			int ny = pnts[i].second;

			int cur_dist = calc_dist(cx, cy, nx, ny);
			if (cur_dist == 0) continue;
			int need_beers = (cur_dist + 49) / 50;
			if (MAX_B < need_beers) continue;

			visited[i] = 1;
			que.push({ nx, ny });
		}
	}
	return false;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T; cin >> T;
	for (int tc = 1; tc <= T; ++tc) {
		bool ok = solution_wegbier();
		if (ok) cout << "happy\n";
		if (!ok) cout << "sad\n";
	}
	return 0;
}
