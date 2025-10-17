//g12852 1로 만들기 2
#include <iostream>
#include <vector>
#include <string>
#include <climits>
#include <algorithm>
#include <queue>
using namespace std;

#define MAX_N 10000001
typedef pair<int, int> p;

void solution_making_one_2() {
	int n; cin >> n;
	vector<int>dp(n + 1, MAX_N);

	queue<p>que;
	dp[1] = 0;
	que.push({0, 1});

	while (!que.empty()) {
		p cur_node = que.front(); que.pop();
		int cur = cur_node.second;
		int cost = cur_node.first;
		if (dp[cur] < cost)continue;

		int nxt = 3 * cur;
		if (nxt <= n && dp[nxt] > cost + 1) {
			dp[nxt] = cost + 1;
			que.push({ dp[nxt], nxt });
		}
		nxt = 2 * cur;
		if (nxt <= n && dp[nxt] > cost + 1) {
			dp[nxt] = cost + 1;
			que.push({ dp[nxt], nxt });
		}
		nxt = cur+1;
		if (nxt <= n && dp[nxt] > cost + 1) {
			dp[nxt] = cost + 1;
			que.push({ dp[nxt], nxt });
		}
	}


	cout << dp[n] << "\n";
	vector<int>ret;
	ret.push_back(n);
	while (n > 1) {
		if (n % 3 == 0 && dp[n / 3] == dp[n] - 1) {
			ret.push_back(n / 3);
			n = n / 3;
			continue;
		}
		if (n % 2 == 0 && dp[n / 2] == dp[n] - 1) {
			ret.push_back(n / 2);
			n = n / 2;
			continue;
		}
		ret.push_back(n - 1);
		n = n - 1;
	}
	for (int i = 0; i < ret.size(); i++) {
		cout << ret[i] << " ";
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);


	solution_making_one_2();

	//int T; cin >> T;
	//while (T--) {
	//	cout << solution_path_game() << "\n";
	//}

	return 0;
}



/*
2
2
10
*/

/*
1
2 1
3
10 9 3 1
*/