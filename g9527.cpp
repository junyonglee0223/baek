#include <iostream>
#include <vector>
using namespace std;

#define endl '\n'
#define MAXN 55
vector<long long>power2;


long long getOneCnt(long long n){
    long long ret = n&1;
    for(int i = MAXN-1; i>0; i--){
        if((n & (1LL << i))){
            ret += power2[i-1] + (n - (1LL << i) + 1);
            n -= (1LL<<i);
        }
    }
    return ret;
}

void solution_count_V2(){
    long long A, B; cin>>A>>B;
    
    power2.resize(MAXN+1, 0);

    power2[0] = 1;
    for(int i = 1; i<MAXN; i++){
        power2[i] = power2[i-1] * 2 + (1LL << i);
    }

    cout<<getOneCnt(B) - getOneCnt(A-1)<<endl;

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solution_count_V2();
    return 0;
}