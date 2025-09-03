//sw5215 햄버거 다이어트
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

#define MAX_N 21
#define MAX_L 10001

int dp[MAX_N][MAX_L];
vector<int>calories;
vector<int>scores;
int N, L;

int get_burger(int idx, int left) {
	if (dp[idx][left] != -1)return dp[idx][left];
	
	int &ret = dp[idx][left];
	if (ret != -1)return ret;
	ret = 0;
	for (int nxt = idx + 1; nxt <= N; nxt++) {
		if (left - calories[nxt] >= 0) {
			ret = max(ret, scores[nxt] + get_burger(nxt, left - calories[nxt]));
		}
	}	
	return ret;
}

int solution_hamburger_diet() {
	for (int i = 0; i < MAX_N; i++) {	
		for (int j = 0; j < MAX_L; j++) {
			dp[i][j] = -1;
		}
	}
	cin >> N >> L;
	calories.resize(N + 1, 0);
	scores.resize(N + 1, 0);

	for (int i = 1; i <= N; i++) {
		int a, b; cin >> a >> b;
		calories[i] = b;
		scores[i] = a;
	}
	return get_burger(0, L);


}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int T; cin >> T;
	for (int test_case = 1; test_case <= T; test_case++) {
		cout << "#" << test_case << " " << solution_hamburger_diet() << "\n";
	}

	return 0;
}