//g12024 사각형 찾기 
#include <iostream>
#include <vector>
using namespace std;

long long solution_find_rectangle() {
	int N; cin >> N;
	vector<vector<int>>board(N, vector<int>(N, 0));

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> board[i][j];
		}
	}

	vector<vector<int>>d_board(N, vector<int>(N, 0));
	for (int k = 0; k < N; k++) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				//i, i 연결된 경우는 없음
				if (board[i][k] == 0 || board[k][j] == 0)continue;
				if (i == j)continue;

				d_board[i][j]++;
			}
		}
	}

	//전체 재탐색하며 2길이 연결된
	long long ret = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (d_board[i][j] == 0)continue;
			//cout << i << " " << j << " " << d_board[i][j] << "\n";
			ret += (long long)(d_board[i][j]) * (d_board[i][j] - 1);
		}
	}
	return ret;
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	/*int T; cin >> T;
	while (T--)
	{
		cout << solution_find_rectangle() << "\n";
	}*/

	cout << solution_find_rectangle() << "\n";

	return 0;
}




/*
4
0 1 0 1
1 0 1 0
0 1 0 1
1 0 1 0
*/
/*
8
*/

/*
6
5
0 1 1 1 1
1 0 1 1 1
1 1 0 1 0
1 1 1 0 1
1 1 0 1 0
4
0 1 1 1
1 0 1 1
1 1 0 1
1 1 1 0

3
0 1 1
1 0 1
1 1 0
4
0 1 1 1
1 0 1 1
1 1 0 0
1 1 0 0

5
0 1 0 1 1
1 0 1 0 0
0 1 0 1 1
1 0 1 0 0
1 0 1 0 0

5
0 1 1 1 1
1 0 1 1 1
1 1 0 1 1
1 1 1 0 1
1 1 1 1 0
*/
/*
72
24
0
8
24
120
*/

/*
양방향 인접 행렬
N <= 250
길이 4짜리 다른 cycle 개수

A(i, i) = 1 인 경우는 없음

길이 2짜리 map 다시 만듬
O(N^3)
(0, i) -> (i, 0)

총 개수 반환 방법



*/