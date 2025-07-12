//sw2819 격자판의 숫자 이어 붙이기
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
#include<vector>
#include<set>
using namespace std;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

bool is_range(int x, int y){
    return x >= 0 && x < 4 && y >= 0 && y < 4;
}

void dfs_num(int x, int y, string cur, set<string>& ret, vector<vector<char>>&st_board){
    if(cur.size() == 7){
        ret.insert(cur);
        return;
    }

    cur += st_board[x][y];

    int n = st_board.size();
    for(int d = 0; d<4; d++){
        int nx = x + dx[d];
        int ny = y + dy[d];
        if(!is_range(nx, ny))continue;
        dfs_num(nx, ny, cur, ret, st_board);
    }
    return;
}

int solution_add_num_in_board(){
    int n = 4;
    vector<vector<int>>board(n, vector<int>(n));
    vector<vector<char>>st_board(n, vector<char>(n));
    
    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            cin>>board[i][j];
            st_board[i][j] = board[i][j] + '0';
        }
    }

    set<string>ret;
    string str = "";
    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            dfs_num(i, j, str, ret, st_board);
        }
    }
    


    return ret.size();
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
	cin>>T;
	/*
	   여러 개의 테스트 케이스가 주어지므로, 각각을 처리합니다.
	*/
	for(test_case = 1; test_case <= T; ++test_case)
	{

		/////////////////////////////////////////////////////////////////////////////////////////////
		/*
			 이 부분에 여러분의 알고리즘 구현이 들어갑니다.
		 */
		/////////////////////////////////////////////////////////////////////////////////////////////

        cout<<"#"<<test_case<<" "<<solution_add_num_in_board()<<endl;

	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
/*
1
1 1 1 1
1 1 1 2
1 1 2 1
1 1 1 1
*/