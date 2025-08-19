//g16566 카드 게임
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int find_parents(int cur, vector<int>&parents) {
	int p = cur;
	if (cur != parents[cur]) {
		p = find_parents(parents[cur], parents);
		parents[cur] = p;
	}
	return parents[cur];
}

void solution_card_game() {
	int N, M, K; cin >> N >> M >> K;
	vector<int>cards(M);
	for (int i = 0; i < M; i++) {
		cin >> cards[i];
	}
	sort(cards.begin(), cards.end());
	vector<int>parents(M);
	for (int i = 0; i < M; i++) {
		parents[i] = i;
	}

	for (int cmd = 0; cmd < K; cmd++) {
		int ele; cin >> ele;
		auto it = upper_bound(cards.begin(), cards.end(), ele);

		/*조건에 민수가 내지 못하는 경우는 없다고 함*/
		
		int cur_idx = it - cards.begin();


		int p_idx = find_parents(cur_idx, parents);
		cout << cards[p_idx] << "\n";
		if (p_idx < M - 1) {
			parents[p_idx] = find_parents(p_idx + 1, parents);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	solution_card_game();

	return 0;
}

/*
예제 입력 1
10 7 5
2 5 3 7 8 4 9
4 1 1 3 8
예제 출력 1
5
2
3
4
9
*/