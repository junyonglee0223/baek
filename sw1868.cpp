//sw1868 파핑파핑 지뢰찾기
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
// char g = &apos;b&apos;;
// char var[256] = &quot;ABCDEFG&quot;;
// long long AB = 12345678901234567L;
// cout << a;                           // int 변수 1개 출력하는 예제
// cout << b << &quot; &quot; << c;               // float 변수 2개 출력하는 예제
// cout << d << &quot; &quot; << e << &quot; &quot; << f;   // double 변수 3개 출력하는 예제
// cout << g;                           // char 변수 1개 출력하는 예제
// cout << var;                         // 문자열 1개 출력하는 예제
// cout << AB;                          // long long 변수 1개 출력하는 예제
/////////////////////////////////////////////////////////////////////////////////////////////

#include<iostream>
#include<vector>
#include <string>
#include <algorithm>
#include <queue>
#include<climits>
using namespace std;

#define endl '\n'

int dx[8] = {1, 1, 0, -1, -1, -1, 0, 1};
int dy[8] = {0, 1, 1, 1, 0, -1, -1, -1};

bool is_range(int x, int y, int N) {
	return x >= 0 && x < N && y >= 0 && y < N;
}

void init_board(vector<vector<int>>&board) {
	int N = board.size();
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (board[i][j] != -1)continue;
			for (int d = 0; d < 8; d++) {
				int nx = i + dx[d];
				int ny = j + dy[d];
				if (is_range(nx, ny, N) && board[nx][ny] != -1) {
					board[nx][ny]++;
				}
			}
		}
	}
}


void bfs_zero(int sx, int sy, vector<vector<int>>& board, vector<vector<bool>>& opened) {
    int N = board.size();
    queue<pair<int,int>> q;
    opened[sx][sy] = true;
    q.push({sx,sy});
    while (!q.empty()) {
        auto [x,y] = q.front(); q.pop();
        for(int d=0; d<8; d++){
            int nx = x + dx[d], ny = y + dy[d];
            if (nx<0||nx>=N||ny<0||ny>=N) continue;
            if (opened[nx][ny]) continue;
            opened[nx][ny] = true;
            if (board[nx][ny]==0) {
                q.push({nx,ny});
            }
        }
    }
}


int solution_popping_v1() {
	int N; cin >> N;

	vector<vector<int>>board(N, vector<int>(N));
	for (int i = 0; i < N; i++) {
		string str; cin >> str;
		for (int j = 0; j < N; j++) {
			if (str[j] == '*') {
				board[i][j] = -1;
			}
			else {
				board[i][j] = 0;
			}
		}
	}


	init_board(board);

	vector<vector<bool>>opened_board(N, vector<bool>(N, false));

    int ret = 0;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if (!opened_board[i][j] && board[i][j]==0) {
            bfs_zero(i, j, board, opened_board);
            ret++;
            }
        }
    }

    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if (!opened_board[i][j] && board[i][j]>0) ret++;
        }
    }

	return ret;
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
	//freopen(&quot;input.txt&quot;, &quot;r&quot;, stdin);
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
		int ret = solution_popping_v1();
		cout <<"#"<< test_case<<" "<< ret << endl;

	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
/*
2
3
..*
..*
**.
5
..*..
..*..
.*..*
.*...
.*...
*/