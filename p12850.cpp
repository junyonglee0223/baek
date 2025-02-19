//p12850 본대 산책2
#include <iostream>
#include <vector>
using namespace std;

#define endl '\n'

typedef vector<vector<long long>> matrix;
const long long MOD = 1000000007;
const int N = 8;

matrix mat_multiple(matrix &a, matrix &b){
    matrix ret(N, vector<long long>(N, 0));
    for(int k = 0; k<N; k++){
        for(int i = 0; i<N; i++){
            for(int j = 0; j<N; j++){
                ret[i][j] += (a[i][k] * b[k][j])%MOD;
                ret[i][j] %= MOD;
            }
        }
    }
    return ret;
}

matrix mat_power(matrix &x, long long n){
    matrix ret(N, vector<long long>(N, 0));
    for(int i = 0; i<N; i++)
        ret[i][i] = 1;
     
    matrix tmp = x;

    while(n){
        if(n%2){
            ret = mat_multiple(ret, tmp);
            n -= 1;
        }
        tmp = mat_multiple(tmp, tmp);
        n >>= 1;
    }
    return ret;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    matrix x = {
        {0, 1, 1, 0, 0, 0, 0, 0},
        {1, 0, 1, 1, 0, 0, 0, 0},
        {1, 1, 0, 1, 1, 0, 0, 0},
        {0, 1, 1, 0, 1, 1, 0, 0},
        {0, 0, 1, 1, 0, 1, 1, 0},
        {0, 0, 0, 1, 1, 0, 0, 1},
        {0, 0, 0, 0, 1, 0, 0, 1},
        {0, 0, 0, 0, 0, 1, 1, 0}
    };
    long long n; 
    cin>>n;

    matrix answer = mat_power(x, n);
    cout<< answer[0][0] <<endl;
    return 0;
}

