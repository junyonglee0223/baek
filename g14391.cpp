//g14391 종이 조각
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int N, M;
int answer = 0;
//vector<string>board;
vector<vector<int>>board;

void dfs_paper(int status, int idx, int sum) {
	if (idx == N * M) {
		answer = max(answer, sum);
		return;
	}
	if ((status & (1 << idx)) != 0) {
		dfs_paper(status, idx + 1, sum);
		return;
	}
	

	int x = idx / M;
	int y = idx % M;

	int nxt_status = status;
	int nxt_num = board[x][y];
	for (int len = 1; y + len < M; len++) {
		int nxt_idx = x * M + y + len;
		if ((status & (1 << nxt_idx)) != 0) {
			break;
		}
		nxt_status |= (1 << nxt_idx);
		nxt_num *= 10;
		nxt_num += board[x][y + len];
		dfs_paper(nxt_status, idx + len + 1, sum + nxt_num);
	}

	nxt_status = status;
	nxt_num = board[x][y];
	for (int len = 1; x + len < N; len++) {
		int nxt_idx = (x+len) * M + y;
		if ((status & (1 << nxt_idx)) != 0) {
			break;
		}
		nxt_status |= (1 << nxt_idx);
		nxt_num *= 10;
		nxt_num += board[x+len][y];
		dfs_paper(nxt_status, idx + 1, sum + nxt_num);
	}



	dfs_paper((status | (1 << idx)), idx + 1, sum + (board[x][y]));
}

int solution_paper_partition() {
	board.clear();
	answer = 0;

	cin >> N >> M;
	board.resize(N, vector<int>(M, 0));
	for (int i = 0; i < N; i++) {
		string str; cin >> str;

		for (int j = 0; j < M; j++) {
			board[i][j] = str[j] - '0';
		}
	}

	dfs_paper(0, 0, 0);
   return answer;
}

int main() {
	ios_base::sync_with_stdio(false);

	cout << solution_paper_partition() << "\n";

	//int t; cin >> t;
	//while (t--) {
	//	cout << solution_paper_partition() << "\n";
	//}


}
/*
4

2 3
123
312
2 2
99
11
4 3
001
010
111
100
1 1
8
*/