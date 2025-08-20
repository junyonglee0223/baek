//p17384 대진표
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;


string build(int L, int x) {
	if (x <= 0)return string(L, '.');
	if (x >= L)return string(L, '#');
	if (x <= L / 2) {
		return build(L / 2, x) + build(L / 2, 0);
	}

	int xx = 1;
	while (xx * 2 <= L / 2 && xx * 4 <= x) xx <<= 1;
	if (x - xx > L / 2) xx = x - L / 2;


	return build(L / 2, x - xx) + build(L / 2, xx);
}

void solution_create_table_v1() {
	int n; cin >> n;
	int L = 1;
	while (L < n) 
		L = (L << 1);
	cout << build(L, n) << "\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	//init();

	int T; cin >> T;
	while (T--) {
		solution_create_table_v1();
	}
//	solution_create_table()_v1;
	return 0;
}

/*
키보드를 바꾸게 돼서 기분이 너무 좋당
참가자 수는 10 ^ 6 이하이다.
각각 우승을 위해 치뤄야 할 경기 수가 최소가 되도록 구현해야 함

각각의 구간 합의 차이가 최소가 되도록 설정하는 것과 동치이다.
전체 구간은 N <= 2^K인 2^K개이다.

이게 dp로 해결해야 할 문제인가?
N을 절반으로 나눠 배정하는 방식이다. 즉 미리 계산이 가능하다.

 5 -> 8
 (x, y) y = upper_bi(x)이다. 

 내림차순으로 슬롯이 앞에 있는 걸 우선으로 고른다는 의미 파악
 슬롯의 번호를 내림차순 정렬이다.
 최대한 왼쪽을 우선으로 할당해야 한다는 의미이다.

 2*N+1 -> N+1, N으로 쪼갠다

 5, 6, 7, 8 -> 8
 3, 2, 3, 3, 4, 3, 4, 4 





*/

/*
3
3
5
9
*/
/*
###.
###.##..
###.##..####....
*/

