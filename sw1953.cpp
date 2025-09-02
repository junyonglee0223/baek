#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<queue>
using namespace std;

typedef pair<int, int>p;

int N, M, R, C, L;
vector<vector<int>>board;

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

/*
1 
-> 0(하): 1, 2, 4, 7
-> 1(우): 1, 3, 6, 7
-> 2(상): 1, 2, 5, 6
-> 3(좌): 1, 3, 4, 5
2
-> 0(하): 1, 2, 4, 7
-> 1(우): 
-> 2(상): 1, 2, 5, 6
-> 3(좌): 
3
-> 0(하): 
-> 1(우): 1, 3, 6, 7
-> 2(상):
-> 3(좌): 1, 3, 4, 5
4 
-> 0(하): 
-> 1(우): 1, 3, 6, 7
-> 2(상): 1, 2, 5, 6
-> 3(좌): 
5
-> 0(하): 1, 2, 4, 7
-> 1(우): 1, 3, 6, 7
-> 2(상): 
-> 3(좌): 
6
-> 0(하): 1, 2, 4, 7
-> 1(우): 
-> 2(상): 
-> 3(좌): 1, 3, 4, 5
7
-> 0(하): 
-> 1(우): 
-> 2(상): 1, 2, 5, 6
-> 3(좌): 1, 3, 4, 5

*/

bool is_connect(int type, int n_type, int dir) {
	
	if (type == 1) {
		if (dir == 0) {
			if (n_type == 1 || n_type == 2 || n_type == 4 || n_type == 7)return true;
			return false;
		}
				
		if (dir == 1) {
			if (n_type == 1 || n_type == 3 || n_type == 6 || n_type == 7)return true;
			return false;
		}
				
		if (dir == 2) {
			if (n_type == 1 || n_type == 2 || n_type == 5 || n_type == 6)return true;
			return false;
		}
				
		if (dir == 3) {
			if (n_type == 1 || n_type == 3 || n_type == 4 || n_type == 5)return true;
			return false;
		}
	}
	if (type == 2) {
		if (dir == 0) {
			if (n_type == 1 || n_type == 2 || n_type == 4 || n_type == 7)return true;
			return false;
		}
				
		if (dir == 1) {
			return false;
		}
				
		if (dir == 2) {
			if (n_type == 1 || n_type == 2 || n_type == 5 || n_type == 6)return true;
			return false;
		}
				
		if (dir == 3) {
			return false;
		}
	}
	if (type == 3) {
		if (dir == 0) {
			return false;
		}
				
		if (dir == 1) {
			if (n_type == 1 || n_type == 3 || n_type == 6 || n_type == 7)return true;
			return false;
		}
				
		if (dir == 2) {
			return false;
		}
				
		if (dir == 3) {
			if (n_type == 1 || n_type == 3 || n_type == 4 || n_type == 5)return true;
			return false;
		}
	}
		
	if (type == 4) {
		if (dir == 0) {
			return false;
		}
				
		if (dir == 1) {
			if (n_type == 1 || n_type == 3 || n_type == 6 || n_type == 7)return true;
			return false;
		}
				
		if (dir == 2) {
			if (n_type == 1 || n_type == 2 || n_type == 5 || n_type == 6)return true;
			return false;
		}
				
		if (dir == 3) {
			return false;
		}
	}
		
	if (type == 5) {
		if (dir == 0) {
			if (n_type == 1 || n_type == 2 || n_type == 4 || n_type == 7)return true;
			return false;
		}
				
		if (dir == 1) {
			if (n_type == 1 || n_type == 3 || n_type == 6 || n_type == 7)return true;
			return false;
		}
				
		if (dir == 2) {
			return false;
		}
				
		if (dir == 3) {
			return false;
		}
	}
		
	if (type == 6) {
		if (dir == 0) {
			if (n_type == 1 || n_type == 2 || n_type == 4 || n_type == 7)return true;
			return false;
		}
				
		if (dir == 1) {
			return false;
		}
				
		if (dir == 2) {
			return false;
		}
				
		if (dir == 3) {
			if (n_type == 1 || n_type == 3 || n_type == 4 || n_type == 5)return true;
			return false;
		}
	}
			
	if (type == 7) {
		if (dir == 0) {
			return false;
		}
		if (dir == 1) {
			return false;
		}
		if (dir == 2) {
			if (n_type == 1 || n_type == 2 || n_type == 5 || n_type == 6)return true;
			return false;
		}
		if (dir == 3) {
			if (n_type == 1 || n_type == 3 || n_type == 4 || n_type == 5)return true;
			return false;
		}
	}
}

bool is_range(int x, int y) {
	return x >= 0 && x < N &&  y >= 0 && y < M;
}


int solution_fugitive_arrest() {
	board.clear();

	cin >> N >> M >> R >> C >> L;
	board.resize(N, vector<int>(M, 0));

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> board[i][j];
		}
	}

	vector<vector<int>>cnt_b(N, vector<int>(M, -1));
	queue<p>que;
	vector<p>ret;
	que.push({ R, C });
	cnt_b[R][C] = 0;
	

	while (!que.empty()) {
		int cx = que.front().first;
		int cy = que.front().second;
		
		ret.push_back(que.front());
		que.pop();

		for (int d = 0; d < 4; d++) {
			int nx = cx + dx[d];
			int ny = cy + dy[d];
			if (!is_range(nx, ny) || cnt_b[nx][ny] != -1)continue;
			if (!is_connect(board[cx][cy], board[nx][ny], d))continue;
			cnt_b[nx][ny] = cnt_b[cx][cy] + 1;
			if (cnt_b[nx][ny] >= L)continue;
			que.push({ nx, ny });
		}
	}
	return ret.size();
}


int main(int argc, char** argv)
{
	int test_case;
	int T;

	//freopen("input.txt", "r", stdin);
	cin >> T;
	/*
	   여러 개의 테스트 케이스가 주어지므로, 각각을 처리합니다.
	*/
	for (test_case = 1; test_case <= T; ++test_case)
	{
		int ret = solution_fugitive_arrest();
		cout << "#" << test_case << " " << ret << "\n";
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
/*
N, M <=50
2500개 노드로 만들지 아니면 board를 그대로 활용할지 문제

조건문만 잘 만들면 노드로 만들 필요는 없다.
bfs로 이동하면 된다.


*/

/*

5
5 6 2 1 3
0 0 5 3 6 0
0 0 2 0 2 0
3 3 1 3 7 0
0 0 0 0 0 0
0 0 0 0 0 0
5 6 2 2 6
3 0 0 0 0 3
2 0 0 0 0 6
1 3 1 1 3 1
2 0 2 0 0 2
0 0 4 3 1 1
*/