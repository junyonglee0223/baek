//g13172번 Σ
#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'
typedef long long ll;
const ll MOD = 1000000007;


ll gcd(ll a, ll b){
    if(a > b)return gcd(b, a);
    if(b%a == 0)return a;
    return gcd(a, b%a);
}
ll find_reverse_source(ll x){
    //x ^ (MOD - 2)
    ll n = MOD - 2;
    ll ret = 1;
    ll n_x = x;
    while(n){
        if(n%2){
            ret *= n_x;
            ret %= MOD;
        }
        n_x = (n_x * n_x) % MOD;
        n >>= 1;
    }
    return ret;
}

void solution_sigma(){
    ll answer = 0;
    int D, N, S;
    cin>>D;
    for(int i = 0; i<D; i++){
        cin>>N>>S;

        if(S%N == 0){
            answer += S;
            answer %= MOD;
            continue;
        }
        //S/N -> add to answer

        ll gcd_N_S = gcd(N, S);
        N /= gcd_N_S;
        S /= gcd_N_S;

        ll rev_N = find_reverse_source(N);

        answer += (S * rev_N)%MOD;
        answer %= MOD;
    }
    cout<<answer<<endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    solution_sigma();
    return 0;
}

/*

1
3 7

->333333338

*/