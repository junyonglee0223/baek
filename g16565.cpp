//g16565번 N포커
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int>pacto52;
vector<int>invPacto52;
vector<int>comb52;

vector<vector<int>>nonFour;

const int MOD = 10007;
int N;

int powVal(int x, int n){
    int ret = 1;
    int tmp = x % MOD;
    while(n){
        if(n%2){
            ret *= tmp;
            ret %= MOD;
        }
        tmp *= tmp;
        tmp %= MOD;
        n = (n >> 1);
    }
    return ret;
}

int main(){
    cin>>N;
    pacto52.resize(53, 0);
    pacto52[0] = 1;
    for(int i = 1; i<=52; i++){
        pacto52[i] = (pacto52[i-1] * i) % MOD;
    }

    invPacto52.resize(53, 0);
    for(int i = 0; i<=52; i++){
        invPacto52[i] = powVal(pacto52[i], MOD - 2);
    }

    comb52.resize(53, 0);
  for (int i = 0; i <= 52; i++) {
    comb52[i] = pacto52[52];
    comb52[i] = comb52[i] * invPacto52[i] % MOD;
    comb52[i] = comb52[i] * invPacto52[52 - i] % MOD;
   }


    nonFour.resize(max(N+1, 4), vector<int>(13, 0));
    nonFour[0][0] = 1;
    nonFour[1][0] = 4;
    nonFour[2][0] = 6;
    nonFour[3][0] = 4;

    for(int i = 4; i<=N; i++)
        nonFour[i][0] = 0;

    for(int i = 0; i<=N; i++){
        for(int j = 1; j<=12; j++){
            nonFour[i][j] = nonFour[i][j-1];
            if(i >= 1)
                nonFour[i][j] = (nonFour[i][j] + nonFour[i-1][j-1] * 4) %MOD;
            if(i >= 2)
                nonFour[i][j] = (nonFour[i][j] + nonFour[i-2][j-1] * 6) %MOD;
            if(i >= 3)
                nonFour[i][j] = (nonFour[i][j] + nonFour[i-3][j-1] * 4) %MOD;
        }
    }

    int answer = (comb52[N] - nonFour[N][12] + MOD) % MOD;
    cout<<answer<<"\n";
}
