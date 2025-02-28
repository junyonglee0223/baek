//g15824 너 봄에는 캡사이신이 맛있단다
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;


#define endl '\n'
#define MAX_N 300001
const long long MOD = 1000000007;

long long pow_2[MAX_N];

void solution_capsaicin_degree(){
    int N; cin>>N;
    vector<long long>menus;

    pow_2[0] = 1;
    for(int i = 0; i<N-1; i++){
        pow_2[i+1] = (pow_2[i] * 2)%MOD;
    }

    menus.resize(N);

    for(int i = 0; i<N; i++){
        cin>>menus[i];
    }
    sort(menus.begin(), menus.end());

    long long answer = 0;
    for(int i = 0; i<N; i++){
        long long max_sum = (menus[i] * pow_2[i])%MOD;
        long long min_sum = (menus[i] * pow_2[N - i - 1])%MOD;
        answer += (max_sum - min_sum)%MOD;
        answer %= MOD;
    }
    answer = (answer + MOD)%MOD;
    cout<<answer<<endl;

}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    solution_capsaicin_degree();

    // int T; cin>>T;
    // while(T--){
    //     solution_capsaicin_degree();
    // }
    return 0;
}

/*
2
3
5 2 8
6
1 4 5 5 6 10
*/