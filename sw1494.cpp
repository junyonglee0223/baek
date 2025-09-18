#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;


int N;
ll answer;
vector<vector<pll>>board;
vector<pll>dots;


ll count_bit(ll num) {
	ll ret = 0;
	while (num) {
		if (num & 1) {
			ret++;
		}
		num >>= 1;
	}
	return ret;
}

ll sum_vec(ll state) {
	pll plus_vec = { 0, 0 };
	pll minus_vec = { 0, 0 };

	for (int i = 0; i < N; i++) {
		if ((state & (1 << i)) == 0) {
			minus_vec = { minus_vec.first - dots[i].first, minus_vec.second - dots[i].second };
		}
		else {
			plus_vec = { plus_vec.first + dots[i].first, plus_vec.second + dots[i].second };
		}
	}
	ll first = plus_vec.first + minus_vec.first;
	ll second = plus_vec.second + minus_vec.second;
	return first * first + second * second;
}


ll solution_counselor() {
	answer = LLONG_MAX;
	dots.clear();
	cin >> N;
	board.resize(N, vector<pll>(N));
	for (int i = 0; i < N; i++) {
		ll a, b; cin >> a >> b;
		dots.push_back({ a, b });
	}
	ll ret = LLONG_MAX;
	for (int i = 0; i < (1 << N); i++) {
		if (count_bit(i) == N / 2) {
			ret = min(ret, sum_vec(i));
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
		cout << "#" << test_case << " " << solution_counselor() << "\n";
	}
	return 0;
}
/*
N 20이하니까 전체 dist board 만들어서 저장하면 됨
좌표 계산 미리 해둠
1,000,000 배열 가능한지?
dp 사용하지 말고 그냥 돌릴까?
 10 ^ 6 * 20
20,000,000 배열이 감당 가능한지?


선택을 해야 함
교란 순열?
내 자신을 선택해서는 안됨

좌표값 기준은 2 * 10 ^ 10까지 이므로 long long 사용한다.
용량은 256으로 정해져있고

MB -> 1024 kb -> 1,048,576B
우선 dp 사용하지 말고 진행한 다음
dp 사용해서 메모리 아슬아슬 하지만 해본다.


문제 이해를 다시해야 됨
벡터 합 크기의 최소를 구하는 문제임
(x, y) -> (a, b)

가능한 벡터의 합을 최소로 하려면 절댓값 크기를
가능한 작게 만들어야 함
기존 로직은 그대로 유지하자


현재코드는 시간초과가 발생한다 보다 더 최적화 된 방안이 있었음 한다.

*/
/*
2
4
6 0
3 3
-7 2
-4 -1
2
-100000 100000
100000 -100000
*/

/*
1
2
-100000 100000
100000 -100000
*/
/*
#1 0
#2 80000000000
*/
