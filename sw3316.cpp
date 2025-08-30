//sw3316_동아리실 관리하기
#include<iostream>
#include<vector>
using namespace std;

typedef long long ll;
const ll MOD = 1000000007;


int char2int(char c) {
	return c - 'A';
}

vector<ll> update_dp(vector<ll>dp, int x) {
	vector<ll>ret((1 << 4), 0);

	//i는 ret에 대한 status
	for (int i = 1; i < (1 << 4); i++) {
		if ((i & (1 << x)) == 0)continue;
		//j는 이전 dp에 대한 status
		for (int j = 0; j < (1 << 4); j++) {
			if (dp[j] == 0)continue;
			if ((i & j)!= 0) {
				ret[i] = (ret[i] + dp[j]) % MOD;
			}
		}
	}
	return ret;
}

ll solution_club_management() {
	string input_str; cin >> input_str;

	//dp 초기화
	int n = input_str.size();
	vector<ll>dp((1 << 4), 0);

	int x = char2int(input_str[0]);
	//처음에는 담당자 참여나 A가 있어야 함
	for (int i = 1; i < (1 << 4); i++) {
		if ((i & (1 << x)) != 0 && (i & 1)) {
			dp[i] = 1;
		}
	}
	for (int i = 1; i < n; i++) {
		char c = input_str[i];
		dp = update_dp(dp, char2int(c));
	}

	ll ret = 0;


	for (int i = 0; i < (1 << 4); i++) {
		if (dp[i] != 0) {
			ret = (ret + dp[i]) % MOD;
		}
	}
	return ret;
}


int main(int argc, char** argv)
{
	int test_case;
	int T;

	cin >> T;
	for (test_case = 1; test_case <= T; ++test_case)
	{
		ll ret = solution_club_management();
		cout << "#" << test_case << " " << ret << "\n";
	}
	return 0;
}

/*
2
BC
ADCBBACDCBCBACBDCABDCBA
*/
/*
#1 29
#2 88253169
*/

/*
a, b, c, d
총 4명이 있다.

각각의 위치 character는 담당자를 의미하고
필참이다.
하루에 참여 가능한 인원은 최대 15 
즉 하루에 여러명 참여도 가능하다.

AA -> 경우에는 모두가 참여가 가능하다. 나머지 3명 모두 선택 8가지
AB
	전날 b가 나올 경우 -> 4 * 
	안나올 경우

이전 경우의 수가 다음 경우의 수가 영향을 미치게 된다.

이전 상태를 정의해두고 15가지
윈도우 슬라이딩으로 계산하면 될 듯 하다.

15가지 이전 상태가 존재한다.
관리자 추가된다.

현재 상태를 새로 구현하고
담당자가 추가된 상태에만 업데이트 한다.
ex) A(0)
0001
0011
0101
1001
0111
1011
1101
1111

각각의 영역에 어떤 값을 추가할지가 중요하다.
이전 상태에서 값이 0이 아닌 위치에서 현재 배열과 연산으로 0이 아닌 것은
합하는 방식을 사용한다.


*/