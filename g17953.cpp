//g17953  디저트
#include <iostream>
#include <vector>
#include <string>
#include <climits>
#include <algorithm>
#include <queue>
using namespace std;


int solution_disert() {
	int n, m; cin >> n >> m;

	vector<vector<int>>arr(m, vector<int>(n));
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
		}
	}
	//vector<vector<int>>cache(m, vector<int>(m, 0));
	vector<int>cache(m, 0);

	for (int i = 0; i < n; i++) {
		vector<int>new_cache(m, 0);

		for (int j = 0; j < m; j++) {
			int tmp = 0;
			for (int k = 0; k < m; k++) {
				tmp = max(tmp, cache[k] + ((j == k && i > 0) ? arr[j][i] / 2 : arr[j][i]));
			}
			new_cache[j] = tmp;
		}
		cache = new_cache;
		//for (int j = 0; j < m; j++) {
		//	cout << cache[j] << " ";
		//}
		//cout << endl;
	}
	int ret = 0;
	for (int i = 0; i < m; i++) {
		ret = max(ret, cache[i]);
	}
	return ret;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cout << solution_disert() << "\n";

	//int T; cin >> T;
	//while (T--) {
	//	cout << solution_disert() << "\n";
	//}


	return 0;
}


/*
2
3 2
2 6 7
3 8 5
4 3
8 12 3 8
1 2 6 10
1 5 4 5
*/

/*

17
28
1-2-1 순으로 2 + 8 + 7 = 17이 최댓값이 된다.
1-1-2-1 순으로 8 + (12 / 2) + 6 + 8 = 28이 최댓값이 된다.
n <= 10^5, m <= 10

*/