//g10473 인간대포
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>
#include <climits>

//#include <bits/stdc++.h>

using namespace std;

#define MAX_N 100
typedef pair<double, double>pdd;

#define SPEED 5
#define FLY_DISTANCE 50

int N;
double dist_time[MAX_N][MAX_N][2];
vector<pdd>spots;

double calc_dist(pdd a, pdd b) {
	return sqrt(pow(b.first - a.first, 2) + pow(b.second - a.second, 2));
}

double calc_time(double dist, int type) {
	if (type > 0) {
		return 2 + abs(dist - 50) / SPEED;
	}
	return dist / SPEED;
}

double solution_human_cannon() {
	double start_x, start_y, end_x, end_y;
	cin >> start_x >> start_y >> end_x >> end_y;

	spots.push_back({ start_x, start_y });
	int l_n; cin >> l_n;

	for (int i = 0; i < l_n; i++) {
		double a, b; cin >> a >> b;
		spots.push_back({ a, b });
	}
	spots.push_back({ end_x, end_y });

	N = l_n + 2;

	for (int i = 0; i < N; i++) {
		//비효율적이지만 우선 진행
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < 2; k++) {
				dist_time[i][j][k] = 0;
			}
			if (i == j)dist_time[i][j][0] = dist_time[i][j][1] = 0;
			else {
				dist_time[i][j][0] = dist_time[i][j][1] = calc_time(calc_dist(spots[i], spots[j]), 0);
				if (i != 0 && i != N - 1) {
					dist_time[i][j][1] = calc_time(calc_dist(spots[i], spots[j]), 1);
				}
			}
		}
	}

	//초기화 수정 필요한지?
	vector<double> min_time(N, (double)INT_MAX);
	
	queue<pdd>que;
	min_time[0] = 0;
	que.push({ 0, 0 });
	while (!que.empty()) {
		pdd cur_pdd = que.front(); que.pop();
		int cur = cur_pdd.second;
		double cost = cur_pdd.first;
		if (min_time[cur] < cost)continue;

		for (int nxt = 1; nxt < N; nxt++) {
			double t1 = cost + dist_time[cur][nxt][0];
			double t2 = cost + dist_time[cur][nxt][1];

			double tmp_t = min(t1, t2);
			if (min_time[nxt] > tmp_t) {
				min_time[nxt] = tmp_t;
				que.push({ min_time[nxt], nxt });
			}
		}
	}
	return min_time[N - 1];
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout << solution_human_cannon() << "\n";
	return 0;
}


/*
normal   속도는 5
대포 50m, 2초

500이하 개로 주어짐
가장 빨리 가는 것이 목적임
n+2 원소 2차원 배열 설정


*/

/*

25.0 100.0
190.0 57.5
4
125.0 67.5
75.0 125.0
45.0 72.5
185.0 102.5
*/
/*
19.984901
*/