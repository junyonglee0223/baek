//s11055 Increasing Subsequence Sum
#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
using namespace std;

typedef pair<int, int> p;
int dp[1002];
int arr[1001];
int N;

int get_increase_arr(int idx) {
	if (idx > N)return 0;
	int& ret = dp[idx];
	if (ret != -1)return dp[idx];

	ret = arr[idx];
	for (int nxt = idx + 1; nxt <= N; nxt++) {
		if (arr[nxt] > arr[idx]) {
			ret = max(ret, arr[idx] + get_increase_arr(nxt));
		}
	}
	return ret;
}

int solution_partition_arr() {
	cin >> N;
	for (int i = 1; i <= N; i++)
		cin >> arr[i];
	arr[0] = 0;
	for (int i = 0; i <= N; i++) {
		dp[i] = -1;
	}

	return get_increase_arr(0);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout << solution_partition_arr() << "\n";

	/////////////////////////////////////
	//for (int i = 0; i <= N; i++) {
	//	cout << dp[i] << " ";
	//}
	//cout << endl;
	/////////////////////////////

	return 0;
}
/*
10
1 100 2 50 60 3 5 6 7 8
*/
/*
113
*/
/*
크기에 대한 이진탐색으로 해결 가능한지 여부 판단
*/