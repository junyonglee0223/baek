//피보나치 수 6
#include <iostream>
#include <vector>
using namespace std;

#define endl '\n'
#define MOD 1000000007

typedef long long ll;
typedef vector<vector<ll>> matrix;

matrix fibo_multiple(matrix& a, matrix& b){
    int n = a.size();
    matrix ret(n, vector<ll>(n));
    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            ret[i][j] = 0;
            for(int k = 0; k<n; k++){
                ret[i][j] += (a[i][k] * b[k][j]);
                ret[i][j] %= MOD;
            }
        }
    }
    return ret;
}

/*문제에서 범위를 얼마나 설정하는냐에 따라 long long을 고려해야
할 수도 있다.*/
matrix fibo_pow(matrix& m, ll n){
    matrix ret = {{1, 0}, {0, 1}};
    while(n > 0){
        if(n%2){
            ret = fibo_multiple(ret, m);
        }
        m = fibo_multiple(m, m);
        n/=2;
    }
    return ret;
}

ll fibonacci(ll n){
    if(n == 0)return 0;
    if(n == 1)return 1;
    matrix ret = {{1, 1}, {1, 0}};
    ret = fibo_pow(ret, n-1);
    return ret[0][0];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    ll n;
    cin >> n;
    cout << fibonacci(n) << endl;
    
    return 0;
}
