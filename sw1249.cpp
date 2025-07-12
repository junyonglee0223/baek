//sw1249 보급로
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
#include <queue>
#include <vector>
#include <string>
#include <climits>

using namespace std;

struct STAT_PATH {
	int cost, x, y;
	STAT_PATH(int _x, int _y, int _cost) {
		x = _x; y = _y; cost = _cost;
	}
};
struct COMPARE_STAT {
	bool operator()(const STAT_PATH& a, const STAT_PATH& b) {
		return a.cost > b.cost;
	}
};
bool is_range(int x, int y, int n) {
	return x >= 0 && x < n && y >= 0 && y < n;
}
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int solution_supplement_path_v1() {
	int n; cin >> n;
	vector<vector<int>>board(n, vector<int>(n));
	for (int i = 0; i < n; i++) {
		string str; cin >> str;

		for (int j = 0; j < n; j++) {
			board[i][j] = str[j] - '0';
		}
	}

	priority_queue<STAT_PATH, vector<STAT_PATH>, COMPARE_STAT>pq;
	vector<vector<int>>dist(n, vector<int>(n, INT_MAX));
	pq.push(STAT_PATH(0, 0, 0));
	dist[0][0] = 0;
	while (!pq.empty()) {
		STAT_PATH cur = pq.top();
		pq.pop();
		int cx = cur.x;
		int cy = cur.y;
		int cost = cur.cost;
		if (cost > dist[cx][cy])continue;
		if (cx == n - 1 && cy == n - 1)break;

		for (int d = 0; d < 4; d++) {
			int nx = cx + dx[d];
			int ny = cy + dy[d];
			if (is_range(nx, ny, n) == false)continue;
			int nxt_cost = cost + board[nx][ny];
			if (nxt_cost < dist[nx][ny]) {
				dist[nx][ny] = nxt_cost;
				pq.push(STAT_PATH(nx, ny, nxt_cost));
			}
		}
	}
	return dist[n - 1][n - 1];
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
		int ret = solution_supplement_path_v1();
		cout << "#" << test_case << " " << ret << "\n";

	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}