//p28403 K번째 스페이드 찾기
#include<iostream>
#include<vector>
#include<string>
using namespace std;



void solution_find_kth_spade() {
	int n; cin >> n;
	string str; cin >> str;


	vector<int>input(n + 1, 0);
	vector<int>cumsum(n + 2, 0);

	for (int i = 0; i < n; i++) {
		if (str[i] == 'H') {
			input[i + 1] = 0;
		}
		else {
			input[i + 1] = 1;
		}
		cumsum[i + 2] = cumsum[i + 1] + input[i + 1];
	}

	//SEGTREE sgt(n + 1, input);

	vector<int>ret(n + 1, 0);
	for (int i = 1; i <= n; i++) {
		int idx = 1;
		int left = i;
		int tmp = 0;
		while (left && idx <= n) {
			int nxt_idx = idx + left;
			if (nxt_idx > n)nxt_idx = n + 1;
			if (nxt_idx - idx < left)break;
			//int count_one = sgt.query(idx, nxt_idx - 1);
			int count_one = cumsum[nxt_idx] - cumsum[idx];

			left -= count_one;
			idx = nxt_idx;
			tmp++;
		}
		ret[i] = tmp;
	}

	for (int i = 1; i <= n; i++) {
		cout << ret[i] << " ";
	}
	cout << "\n";
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	solution_find_kth_spade();

	//int T; cin >> T;
	//while (T--) {
	//	solution_find_kth_spade();
	//}

	return 0;
}


/*
전략은 이렇다
K만큼을 건너뛰고 그 사이에 1이 있다면 
그만큼을 제외한 만큼을 뛰어가면서 탐색한다.

K를 1 - N까지 탐색하면
N^2 안에 탐색된다.

세그먼트를 사용하면 logN에 가능해서 최종 NlogN안에 탐색이 가능해서
제한 시간 안에서 풀이가 가능하다.


*/


/*
3
10
HSHHHHHHSH
10
SSHHSSHHHS
10
SSSSSSSSSS
*/
/*
2 8 5 3 2 1 1 1 1 1
1 1 3 2 5 3 2 1 1 1
1 1 1 1 1 1 1 1 1 1
*/
