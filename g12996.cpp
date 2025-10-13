//g12996 Acka
#include<iostream>
#include<vector>
using namespace std;

#define MAX_N 51
int N;
int dp[MAX_N][MAX_N][MAX_N][MAX_N];
const int MOD = 1000000007;

void init() {
	for (int i = 0; i < MAX_N; i++) {
		for (int j = 0; j < MAX_N; j++) {
			for (int k = 0; k < MAX_N; k++) {
				for (int l = 0; l < MAX_N; l++) {
					dp[i][j][k][l] = -1;
				}
			}
		}
	}
}

int dp_create(int idx, int a, int b, int c) {

	int& ret = dp[idx][a][b][c];
	//cout << "init ret : " << ret << endl;//test
	if (idx == 0)
		return (a == 0 && b == 0 && c == 0) ? 1 : 0;
	
	if (ret != -1)return ret;
	ret = 0;
	int tmp = 0;
	if (a > 0) {
		tmp += dp_create(idx - 1, a - 1, b, c);
		tmp %= MOD;
	}if (b > 0) {
		tmp += dp_create(idx - 1, a, b - 1, c);
		tmp %= MOD;
	}if (c > 0) {
		tmp += dp_create(idx - 1, a, b, c - 1);
		tmp %= MOD;
	}if (a > 0 && b > 0) {
		tmp += dp_create(idx - 1, a - 1, b - 1, c);
		tmp %= MOD;
	}if (c > 0 && b > 0) {
		tmp += dp_create(idx - 1, a, b - 1, c - 1);
		tmp %= MOD;
	}if (a > 0 && c > 0) {
		tmp += dp_create(idx - 1, a - 1, b, c - 1);
		tmp %= MOD;
	}if (a > 0 && b > 0 && c > 0) {
		tmp += dp_create(idx - 1, a - 1, b - 1, c - 1);
		tmp %= MOD;
	}
	//cout << idx << " " << a << " " << b << " " << c << " " << ret<<endl;//test
	return ret = tmp;
}

int solution_acka() {
	init();
	cin >> N;
	int a, b, c; cin >> a >> b >> c;

	return dp_create(N, a, b, c);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cout << solution_acka() << "\n";
	//int T; cin >> T;
	//while (T--) {
	//	cout << solution_acka() << "\n";
	//}


	return 0;
}

/*
5
3 1 1 1
3 3 1 1
50 10 10 10
18 12 8 9
50 25 25 25
*/
/*

6
9
0
81451692
198591037
*/