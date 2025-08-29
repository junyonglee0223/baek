//g2099 the game of death
#include<iostream>
#include<vector>
using namespace std;

typedef vector<vector<int>> MAT;

int N, K, M;

MAT mat_multiply(MAT a, MAT b) {
	MAT ret(N, vector<int>(N, 0));

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < N; k++) {
				if (a[i][k] == 1 && b[k][j] == 1) {
					ret[i][j] = 1;
				}
			}
		}
	}
	return ret;
}

MAT mat_pow(MAT a, int x) {
	MAT ret(N, vector<int>(N, 0));
	for (int i = 0; i < N; i++)ret[i][i] = 1;
	while (x) {
		if (x & 1) {
			ret = mat_multiply(ret, a);
		}
		a = mat_multiply(a, a);
		x /= 2;
	}
	return ret;
}

void solution_the_game_of_death() {
	cin >> N >> K >> M;
	MAT adj(N, vector<int>(N, 0));

	for (int i = 0; i < N; i++) {
		int a, b; cin >> a >> b;
		a--; b--;
		adj[i][a] = 1;
		adj[i][b] = 1;
	}

	MAT mat_ret = mat_pow(adj, K);

	for (int i = 0; i < M; i++) {
		int a, b; cin >> a >> b;
		a--; b--;
		if (mat_ret[a][b] == 0) {
			cout << "life" << "\n";
		}
		else {
			cout << "death" << "\n";
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	solution_the_game_of_death();
	return 0;
}



/*

더 게임 오브 데스랑 같은 상황이다.
N <= 200, K <= 1,000,000
N명의 사람, K -> K 번 타고 가서 도착
M -> 관계 개수 <= 1,000,000


i -> a, b
a 부터 시작해서 b까지 가능한지 판단
K 횟수가 굉장히 많기 때문에 사이클을 만들거나 
dp로 이동한 경로 저장하는 방식이 있을 것 같다.

N의 개수가 200이라 다소 작아 이 점을 이용
전체 bfs 탐색으로 현재에서 몇회 후 임의의 노드로 가는지 계산
최단 거리를 기록해야 하는 이유 생각

과정이 행렬과 유사하다.



그래프와 유사한 느낌이다.
이전의 트리처럼 활용하려고 했는데 parents가 여러개 있을 수 있어 
기존 그래프와는 구조적으로 다름



*/

/*
4 2 3
2 4
1 3
4 1
2 2
4 1
1 4
1 1
*/

/*
death
life
death
*/