//g17250 은하철도
#include <iostream>
#include <vector>
using namespace std;

int N, M;
vector<int>parents;
vector<int>ranks;
vector<int>sumvalues;

int find_parents(int cur) {
	if (cur == parents[cur])return cur;
	return parents[cur] = find_parents(parents[cur]);
}

int union_find(int a, int b) {
	int pa = find_parents(a);
	int pb = find_parents(b);

	if (pa == pb)return sumvalues[pa];

	if (ranks[pa] > ranks[pb]) {
		parents[pb] = pa;
		sumvalues[pa] += sumvalues[pb];
		return sumvalues[pa];
	}
	if (ranks[pa] < ranks[pb]) {
		parents[pa] = pb;
		sumvalues[pb] += sumvalues[pa];
		return sumvalues[pb];
	}
	parents[pa] = pb;
	ranks[pb]++;
	sumvalues[pb] += sumvalues[pa];
	return sumvalues[pb];
}

void solution_galaxy_trail() {
	parents.clear();
	ranks.clear();
	sumvalues.clear();
	
	cin >> N >> M;
	parents.resize(N + 1, 0);
	ranks.resize(N + 1, 0);
	sumvalues.resize(N + 1, 0);

	for (int i = 1; i <= N; i++) {
		parents[i] = i;
		cin >> sumvalues[i];
	}

	for (int i = 0; i < M; i++) {
		int a, b; cin >> a >> b;
		cout << union_find(a, b) << "\n";
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	solution_galaxy_trail();

	//int T; cin >> T;
	//while (T--) {
	//	solution_galaxy_trail();
	//}
	return 0;
}

/*
2
5 4
3
9
10
11
15
1 2
2 3
4 5
4 3
5 4
3
1
4
15
9
1 2
3 1
2 3
2 4
*/
/*
12
22
26
48

4
8
8
23
*/

/*
N, M이 주어짐
value 주어짐
각각의 index가 연결되면
서로 다른 index와 연결된 value 개수의 합산을 출력함

같은 value를 연결하는 cmd가 왔을 경우의 처리방법 생각

유니온 파인드 사용해서 합산을 관리함
다만 합산 배열을 따로 저장해야 하고 해당 로직이 중요
유니온 파인드는 하위 모든 노드의 루트 부모를 설정하지 않는다.

배열 - i를 루트로 할 경우 합산 값을 저장



*/