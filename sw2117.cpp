#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;

typedef pair<int, int>p;
vector<int>MAX_COST;
vector<p>houses;


int N, M;
void init() {
	MAX_COST.resize(41);
	for (int i = 1; i <= 40; i++) {
		MAX_COST[i] = (i * i + (i - 1)*(i - 1));
	}
}

int get_dist(p a, p b) {
	return abs(b.first - a.first) + abs(b.second - a.second);
}

int pos_house(int size) {
	int ret = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			int cur_cnt = 0;
			for (auto home : houses) {
				int cur_dit = get_dist(home, { i, j });
				if (cur_dit < size)cur_cnt++;
			}
			ret = max(ret, cur_cnt);
		}
	}
	return ret;
}


int solution_smarthomeservice() {
	houses.clear();

	cin >> N >> M;
	vector<vector<int>>board(N, vector<int>(N));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> board[i][j];
			if (board[i][j] == 1)
				houses.push_back({ i, j });
		}
	}
	int ret = 0;
	for (int size = 40; size >= 1; size--) {
		if (MAX_COST[size] > houses.size() * M)continue;
		int cur_cnt = pos_house(size);
		if (MAX_COST[size] <= M * cur_cnt) {
			ret = max(ret, cur_cnt);
		}
	}

	return ret;
}


int main(int argc, char** argv)
{
	int test_case;
	int T;

	cin >> T;
	init();

	for (test_case = 1; test_case <= T; ++test_case)
	{
		cout << "#" << test_case << " " << solution_smarthomeservice() << "\n";
	}
	return 0;
}
/*
N 5 - 20 이하 - 집 개수
M 1 - 10
총 비용이 크지는 않다.
5 - 200 사이의 비용이 주어지고
이익을 볼 수 있는 구간 중 최대 집을 커버해야 함
1, 5, 13, 25, 41 ...
K*K + (K-1) * (K-1)

149162536

N이 작기 때문에 보드를 탐색할게 아니라 집을 기준으로 한다.
영역이 저렇게 되있는거는 맨하튼 거리 탐색을 하라는 거다.
K-1 거리 이면 체크 되는 방식
서비스는 한개만 운영되는 건지?

가능한 최대 범위가 40까지 이다.





*/
/*

10
8 3
0 0 0 0 0 1 0 0
0 1 0 1 0 0 0 1
0 0 0 0 0 0 0 0
0 0 0 1 0 1 0 0
0 0 1 1 0 0 0 0
0 0 0 0 0 0 0 0
0 0 0 0 1 0 1 0
1 0 0 0 0 0 0 0
*/

/*
#1 5
#2 4
#3 24
#4 48
#5 3
#6 65
#7 22
#8 22
#9 78
#10 400
*/
