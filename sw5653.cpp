//SW5653_StemCellCulture.java
#include<iostream>
#include<vector>
#include<queue>
#include<set>
#include<algorithm>
using namespace std;
	
typedef pair<int, int> p;

struct NODE {
	int x, y, live, time;
	NODE(int _x, int _y, int _live, int _time) {
		x = _x; y = _y; live = _live; time = _time;
	}
	NODE() {}
};

struct NODE_LAG_CMP {
	bool operator () (const NODE &a, const NODE & b) {
		return a.live > b.live;
	}
}node_lag_cmp;
int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };
set<p>visited;

int solution_stemcellculture() {
	visited.clear();
	int N, M, K; cin >> N >> M >> K;
	vector<vector<int>>board(N, vector<int>(M, 0));

	queue<NODE>que;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> board[i][j];
			if (board[i][j] > 0) {
				que.push(NODE(i, j, board[i][j], 0));
				visited.insert({ i, j });
			}
		}
	}

	for (int k = 1; k <= K; k++) {
		//////////////////////////////////////
		//cout<<"time: " << k << " " << que.size() << endl;
		vector<NODE>be_update;
		int qsize = que.size();
		for (int i = 0; i < qsize; i++) {
			NODE cur = que.front(); que.pop();
			if (cur.time + cur.live + 1 == k) {
				//cout << "\t type 1" << endl;
				for (int d = 0; d < 4; d++) {
					int nx = cur.x + dx[d];
					int ny = cur.y + dy[d];
					if (visited.find({ nx, ny }) != visited.end())continue;
					//more logic needs
					be_update.push_back(NODE(nx, ny, cur.live, k));
				}
				if(cur.time + cur.live + cur.live > k)
					que.push(cur);
			}
			else if (cur.time + cur.live + cur.live <= k) {
				//cout << "\t type 2" << endl;
				continue;
			}
			else {
				//cout << "\t type 3" << endl;
				que.push(cur);
			}
		}
		sort(be_update.begin(), be_update.end(), node_lag_cmp);
		for (auto ele : be_update) {
			if (visited.find({ ele.x, ele.y }) == visited.end()) {
				//////////////////////////////
				//cout << "\t" << ele.x << " " << ele.y << " "<<ele.live << endl;
				visited.insert({ ele.x, ele.y });
				que.push(ele);
			}

		}
		//cout << "----------------------------------------------" << endl;
	}


	return que.size();

	//int ret = 0;
	//while (!que.empty()) {
	//	NODE cur = que.front(); que.pop();
	//	if (cur.time + cur.live + cur.live >= K)continue;
	//	ret++;
	//}
	//return ret;

}

int main(int argc, char** argv)
{

	int test_case;
	int T;

	cin >> T;
	for (test_case = 1; test_case <= T; ++test_case)
	{
		cout <<"#"<<test_case<<" "<< solution_stemcellculture() << "\n";
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
/*
비활성, 활성
사망 세가지 상태
K시가 후 300
N, M 50이하
range 존재 x

node로 만들어서 que에 넣는 방식으로 구현
K가 300 이하니까 K 단위로 que 내부 전부 뺴서 확인하는 방법

각 시간마다 활성될 경우 동시에 차지하는 경우가 존재하기 때문에
que 한바퀴 돌동안 전부 저장하고 반영하는 방식

time(생성) time + live(활성) time + live + 1(번식) time + live + live(삭제)

*/

/*
5
2 2 10
1 1
0 2
5 5 19
3 2 0 3 0
0 3 0 0 0
0 0 0 0 0
0 0 1 0 0
0 0 0 0 2
9 10 37
0 0 0 0 0 0 0 0 3 0
0 0 0 0 0 0 0 0 5 3
0 0 2 0 0 0 0 4 0 0
3 0 0 0 0 0 4 0 0 0
0 0 0 0 0 3 5 0 0 2
0 0 0 0 0 0 0 0 0 5
0 0 0 0 0 0 0 0 2 3
0 0 0 0 0 0 0 0 0 0
0 0 2 2 0 0 0 0 0 0
*/
/*
1
9 10 37
0 0 0 0 0 0 0 0 3 0
0 0 0 0 0 0 0 0 5 3
0 0 2 0 0 0 0 4 0 0
3 0 0 0 0 0 4 0 0 0
0 0 0 0 0 3 5 0 0 2
0 0 0 0 0 0 0 0 0 5
0 0 0 0 0 0 0 0 2 3
0 0 0 0 0 0 0 0 0 0
0 0 2 2 0 0 0 0 0 0
*/

/*

#1 22
#2 36
#3 90
#4 164
#5 712
*/
