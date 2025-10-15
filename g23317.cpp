//g23317 구슬 굴리기
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;

ll solution_rolling_circle() {
	int n, m; cin >> n >> m;
	vector<vector<ll>>dp(n, vector<ll>(n, 0));
	dp[0][0] = 1;
	for (int i = 1; i < n; i++) {
		for (int j = 0; j <= i; j++) {
			if(i > j)
				dp[i][j] += dp[i - 1][j];
			if (j > 0)
				dp[i][j] += dp[i - 1][j - 1];
		}
	}
	ll ret = 1;
	int pre_a = 0, pre_b = 0;
	vector<pair<int, int>>arrs;
	for (int i = 0; i < m; i++) {
		int a, b; cin >> a >> b;
		arrs.push_back({ a, b });
	}
	sort(arrs.begin(), arrs.end());

	for (int i = 0; i < m; i++) {
		int a = arrs[i].first;
		int b = arrs[i].second;

		int dist_a = a - pre_a;
		int dist_b = b - pre_b;
		if (dist_a == 0 && dist_b == 0)continue;
		if (dist_a <= 0 || dist_b < 0 || dist_a < dist_b)return 0;

		ret *= dp[a - pre_a][b - pre_b];
		pre_a = a, pre_b = b;
	}

	int last = n - 1 - pre_a;

	ll tmp = 0;
	for (int i = 0; i <= last; i++) {
		tmp += dp[last][i];
	}
	ret *= tmp;
	return ret;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	//cout << solution_rolling_circle() << "\n";

	int T; cin >> T;
	while (T--) {
		cout << solution_rolling_circle() << "\n";
	}

	return 0;
}

/*
2
7
2
3 2
5 2
30
2
0 0
0 0
*/
/*
6
536870912
*/