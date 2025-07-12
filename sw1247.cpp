//sw1247 최적 경로
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
#include<algorithm>
#include<climits>
using namespace std;

#define endl '\n'

struct DOT{
    int x, y;
    DOT(int _x, int _y){
        this->x = _x;
        this->y = _y;
    }
};

int visited_cnt(int visited){
    int ret = 0;
    while(visited){
        if((visited & 1) == 1){
            ret++;
        }
        visited = (visited >> 1);
    }
    return ret;
}


int dfs_travel_v1(int visited, int idx, int dist, int gx, int gy, vector<DOT>&places){
    int n = places.size();
    if(visited_cnt(visited) == n){
        return dist + abs(places[idx].x - gx) + abs(places[idx].y - gy);
    }

    int min_dist = INT_MAX;
    for(int i = 0; i<n; i++){
        if((visited & (1 << i)) == 0){
            visited |= (1 << i);
            int tmp = abs(places[idx].x - places[i].x) + abs(places[idx].y - places[i].y);

            min_dist = min(min_dist, dfs_travel_v1(visited, i, dist + tmp, gx, gy, places));

            visited ^= (1 << i);
        }
    }
    return min_dist;
}


int solution_optimized_path(){
    int n; cin>>n;
    int sx, sy, gx, gy;
    cin>>sx>>sy>>gx>>gy;

    vector<DOT>places;
    places.push_back(DOT(sx, sy));
    int visited = (1 << 0);
    
    for(int i = 0; i<n; i++){
        int a, b; cin>>a>>b;
        places.push_back(DOT(a, b));
    }

    return dfs_travel_v1(visited, 0, 0, gx, gy, places);
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

        cout<<"#"<<test_case<<" "<<solution_optimized_path()<<endl;

	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}


/*
10
5
0 0 100 100 70 40 30 10 10 5 90 70 50 20
6
88 81 85 80 19 22 31 15 27 29 30 10 20 26 5 14
10
39 9 97 61 35 93 62 64 96 39 36 36 9 59 59 96 61 7 64 43 43 58 1 36
*/