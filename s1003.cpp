//피보나치 함수
#include <iostream>
using namespace std;

#define endl '\n'
int fibo_cnt[41][2];

int main(){
    for(int i = 0; i<41; i++)
        for(int j = 0; j<2; j++)
            fibo_cnt[i][j] = -1;
    fibo_cnt[0][0] = 1;
    fibo_cnt[0][1] = 0;
    fibo_cnt[1][0] = 0;
    fibo_cnt[1][1] = 1;

    for(int i = 2; i<41; i++){
        fibo_cnt[i][0] = fibo_cnt[i-1][0] + fibo_cnt[i-2][0];
        fibo_cnt[i][1] = fibo_cnt[i-1][1] + fibo_cnt[i-2][1];
    }
   
    int T; cin>>T;
    while(T--){
        int N; cin>>N;
        cout<<fibo_cnt[N][0]<<" "<<fibo_cnt[N][1]<<endl;
    }
}
