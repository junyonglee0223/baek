//g19587 객실 배치
#include<iostream>
#include<vector>
using namespace std;

//a(x) = 2 * a(x-1) + a(x-2)
typedef long long ll;
const ll MOD = 1000000007;

typedef vector<vector<ll>> MATRIX;

MATRIX mat_multiply(MATRIX a, MATRIX b) {
	MATRIX ret = { {0, 0}, {0, 0} };
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			for (int k = 0; k < 2; k++) {
				ret[i][j] += ((a[i][k] * b[k][j]) % MOD);
				ret[i][j] = (ret[i][j] + MOD) % MOD;
			}
		}
	}
	return ret;
}

MATRIX mat_pow(MATRIX a, ll x) {
	MATRIX ret = { {1, 0}, {0, 1} };
	MATRIX tmp = a;

	while (x) {
		if (x & 1) {
			ret = mat_multiply(ret, a);
		}
		a = mat_multiply(a, a);
		x >>= 1;
	}
	return ret;
}

ll solution_set_room() {
	ll N; cin >> N;

	if(N<=2){
		if (N == 1)return 3;
		if (N == 2)return 7;
	}

	MATRIX start = { {7, 3}, {3, 1} };
	MATRIX unit = { {2, 1}, {1, 0} };

	ll pow_cnt = N - 2;

	unit = mat_pow(unit, pow_cnt);
	start = mat_multiply(start, unit);
	return start[0][0];
}

/*
a0 = 1
a1 = 3
a2 = 7
a3 = 17
a4 = 41
a5 = 99
[7, 3]		[2, 1]
[3, 1]		[1, 0]

[17, 10]
[7, 3]
*/
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cout << solution_set_room() << "\n";

	return 0;
}
/*
2
1
5
*/
/*
3
99
*/
/*
dp[i][0] <- dp[i-1][0] + dp[i-1][1] + dp[i-1][2];
dp[i][1] <- dp[i-1][0] + dp[i-1][2]
dp[i][2] <- dp[i-1][0] + dp[i-1][1]
dp[0][1][2] <- 3 * dp[0] + 2 * dp[1] + 2 * dp[2]

ax <- 2 * a(x-1) + dp[x-1][0]
(i, 0) <- (i-1, 0) + (i-2, 0) + (i-2, 2) + (i-2, 0) + (i-2, 1)

(i+1, 0) <- (i, 0) + 2 * (i-1, 0) + (i-1, 1) + (i-1, 2)
(i, 0) <- (i-1, 0) + 2 * (i-2, 0) + (i-2, 1) + (i-2, 2)

(i+1, 0) - (i, 0) <- (i, 0) - (i-1, 0) + 2 * ((i-1, 0) - (i-2, 0)) + 2 * (i-2, 0)
(i+1, 0) <- 2 * (i, 0) + (i-1, 0)
a(x) = 2 * a(x-1) + a(x-2)
*/