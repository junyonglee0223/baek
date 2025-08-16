//g1256 사전
#include <iostream>
#include<string>
using namespace std;

typedef long long ll;
const int MAXN = 200;
const int MAXV = 1000000001;//1e9+1 mapping
int _C[MAXN+1][MAXN+1];

void solution_init(){
    for(int i = 0; i<=MAXN;i++){
        _C[i][0] = _C[i][i] = 1;
        for(int j = 1; j<i; j++){
            ll v = (ll)_C[i-1][j] + _C[i-1][j-1];
            if(v >= MAXV)v = MAXV;
            _C[i][j] = (int)v;
        }
    }
}

string solution_dictionary(){
    int N, M, K; cin>>N>>M>>K;

    if(_C[N+M][N] < K)return "-1";

    string ret = "";

    while(N && M){
        int cntAFirst = _C[N+M-1][N-1];
        if(cntAFirst >= K){
            ret.push_back('a');
            N--;
        }else{
            ret.push_back('z');
            M--;
            K -= cntAFirst;
        }

    }
    while(N--){
        ret += 'a';
    }
    while(M--){
        ret += 'z';
    }

    return ret;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solution_init();
    
    cout << solution_dictionary()<<"\n";

    // int T; cin>>T;
    // while(T--){
    //     cout<< solution_dictionary()<<"\n";
    // }

    return 0;
}


/*
4
2 2 2
2 2 6
10 10 1000000000
7 4 47
*/
/*
azaz
zzaa
-1
aaazazaazaz
*/

/*
n + m 개의 워드 개수가 정해져 있다.
조합이랑 유사한데
미리 i, j로 만들 수 있는 가짓수를 계산해 놓는 방법이 있을 것 같다
간단하게 두개로 해본다
aazz -> 1 총 6가지 가능


*/