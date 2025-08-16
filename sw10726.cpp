//sw 이진수 표현
#include<iostream>

using namespace std;

string solution_binary_expression(){
    int N, M; cin>>N>>M;
    M = ( M & ((1<<N) - 1));
    int ret = 0;
    for(int i = 0; i<N; i++){
        if((M & (1 << i)) != 0)ret++;
    }
    if(ret == N)return "ON";
    return "OFF";
}

int main(int argc, char** argv)
{
	int test_case;
	int T;

	cin>>T;

	for(test_case = 1; test_case <= T; ++test_case)
	{
        string ret = solution_binary_expression();
        cout<<"#"<<test_case<<" "<<ret<<endl;
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}