//sw4193 수영대회 결승전
/////////////////////////////////////////////////////////////////////////////////////////////
// 기본 제공코드는 임의 수정해도 관계 없습니다. 단, 입출력 포맷 주의
// 아래 표준 입출력 예제 필요시 참고하세요.
// 표준 입력 예제
// int a;
// float b, c;
// double d, e, f;
// char g;
// char var[256];
// long long AB;
// cin >> a;                            // int 변수 1개 입력받는 예제
// cin >> b >> c;                       // float 변수 2개 입력받는 예제 
// cin >> d >> e >> f;                  // double 변수 3개 입력받는 예제
// cin >> g;                            // char 변수 1개 입력받는 예제
// cin >> var;                          // 문자열 1개 입력받는 예제
// cin >> AB;                           // long long 변수 1개 입력받는 예제
/////////////////////////////////////////////////////////////////////////////////////////////
// 표준 출력 예제
// int a = 0;                            
// float b = 1.0, c = 2.0;               
// double d = 3.0, e = 0.0; f = 1.0;
// char g = 'b';
// char var[256] = "ABCDEFG";
// long long AB = 12345678901234567L;
// cout << a;                           // int 변수 1개 출력하는 예제
// cout << b << " " << c;               // float 변수 2개 출력하는 예제
// cout << d << " " << e << " " << f;   // double 변수 3개 출력하는 예제
// cout << g;                           // char 변수 1개 출력하는 예제
// cout << var;                         // 문자열 1개 출력하는 예제
// cout << AB;                          // long long 변수 1개 출력하는 예제
/////////////////////////////////////////////////////////////////////////////////////////////

#include<iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

#define endl '\n'

struct SWIM_STAT {
	SWIM_STAT(int _x, int _y, int _t) {
		x = _x;
		y = _y;
		t = _t;
	}
	int x, y, t;
};

bool is_range(int x, int y, int n) {
	return x >= 0 && x < n && y >= 0 && y < n;
}

int dx[5] = { 0, 1, 0, -1, 0 };
int dy[5] = { 0, 0, 1, 0, -1 };


int solution_final_swimming() {
	int n; cin >> n;
	vector<vector<int>>board(n, vector<int>(n, 0));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> board[i][j];
		}
	}
	int sx, sy, gx, gy;
	cin >> sx >> sy >> gx >> gy;
	if (sx == gx && sy == gy)return 0;

	vector<vector<vector<bool>>>visited(n, vector<vector<bool>>(n, vector<bool>(3, false)));
	queue<SWIM_STAT>q;
	q.push(SWIM_STAT(sx, sy, 0));
	visited[sx][sy][0] = true;

	int ret = INT_MAX;
	bool end_flag = false;
	while (!q.empty() && !end_flag) {
		SWIM_STAT cur = q.front();
		q.pop();
		int x = cur.x;
		int y = cur.y;
		int t = cur.t;
		for(int d = 0; d < 5; d++) {
			int nx = x + dx[d];
			int ny = y + dy[d];
			int nt = t + 1;
			if (!is_range(nx, ny, n))continue;
			if (visited[nx][ny][nt % 3])continue;
			if (board[nx][ny] == 1)continue;
			if (d == 0) {
				visited[nx][ny][nt % 3] = true;
				q.push({ nx, ny, nt });
			}
			else {
				if (board[nx][ny] == 2 && (t % 3) != 2) continue;
				visited[nx][ny][nt % 3] = true;
				q.push({ nx, ny, nt });
				if (nx == gx && ny == gy) {
					ret = min(ret, nt);
					return ret;
				} 
			}

		}
	}
	return (ret == INT_MAX ? -1 : ret);
}

int main(int argc, char** argv)
{
	int test_case;
	int T;
	/*
	   아래의 freopen 함수는 input.txt 를 read only 형식으로 연 후,
	   앞으로 표준 입력(키보드) 대신 input.txt 파일로부터 읽어오겠다는 의미의 코드입니다.
	   //여러분이 작성한 코드를 테스트 할 때, 편의를 위해서 input.txt에 입력을 저장한 후,
	   freopen 함수를 이용하면 이후 cin 을 수행할 때 표준 입력 대신 파일로부터 입력을 받아올 수 있습니다.
	   따라서 테스트를 수행할 때에는 아래 주석을 지우고 이 함수를 사용하셔도 좋습니다.
	   freopen 함수를 사용하기 위해서는 #include <cstdio>, 혹은 #include <stdio.h> 가 필요합니다.
	   단, 채점을 위해 코드를 제출하실 때에는 반드시 freopen 함수를 지우거나 주석 처리 하셔야 합니다.
	*/
	//freopen("input.txt", "r", stdin);
	cin >> T;
	/*
	   여러 개의 테스트 케이스가 주어지므로, 각각을 처리합니다.
	*/
	for (test_case = 1; test_case <= T; ++test_case)
	{

		/////////////////////////////////////////////////////////////////////////////////////////////
		/*
			 이 부분에 여러분의 알고리즘 구현이 들어갑니다.
		 */
		 /////////////////////////////////////////////////////////////////////////////////////////////
		int ret = solution_final_swimming();
		cout << "#" << test_case << " " << ret << endl;

	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}

/*
3
5
0 0 0 0 0
0 0 0 1 0
0 0 0 1 0
2 2 1 1 0
0 0 0 0 0
4 0
2 0
6
0 0 0 0 0 0
0 1 1 0 0 0
0 0 0 1 2 0
1 1 0 1 0 1
0 0 0 1 0 1
0 0 0 2 0 1
5 0
2 5
6
0 0 0 0 0 0
0 0 0 0 0 0
1 0 1 1 1 0
1 0 0 0 0 0
1 0 1 1 1 0
0 0 2 0 2 0
5 0
3 5
*/