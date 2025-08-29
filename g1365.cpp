//g1365 꼬인 전깃줄
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int solution_twisting_line() {
	int n; cin >> n;
	vector<int>arr(n);
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	int max_n = 0;
	vector<int>vec;
	
	for (int i = 0; i < n; i++) {
		if (vec.empty() || vec.back() < arr[i]) {
			vec.push_back(arr[i]);
		}
		else {
			int idx = lower_bound(vec.begin(), vec.end(), arr[i]) - vec.begin();
			vec[idx] = arr[i];
		}
	}
	max_n = max(max_n, (int)vec.size());	

	return n - max_n;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cout << solution_twisting_line() << "\n";

	return 0;
}
/*
4
2 3 4 1
*/
/*
예제 출력 1
1
*/
/*
설계에 문제가 있었다.
최대 증가, 감소만 따지면 동시에 존재하는 부분을 놓치게 된다.
////\\\\////
8, 4 -> 12 - 8 = 4 현재 로직
12 - 12 = 0 이 정답임

N이 10,000 이기 때문에 이차원 배열 설정 불가능 dp[][]x
inc, dec 배열 만들어서 관리하는 방법
누적합으로 / \ | 세가지 상태 관리가 필수
0 1 2 3
1 2 3 0
위 방법은 적절하지 않은게 incr 과정에서도 cross가 발생할 수 있다.
실패!

그냥 기존에 최대 배열을 미리 구한 다음 역방향이면서 겹치지 않는 것들을 추가하면 최대일까
그건 아님 전체 최대가 부분 최대임을 보장하지 못함
실패!


그냥 최대 증가 수열인데 역방향 검사가 문제였다.
역방향은 모든 간선이 겹친다. 내가 생각한 역방향 역시 그냥 최대 증가 수열이었음
*/