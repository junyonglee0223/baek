//g1450 냅색문제
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

typedef long long ll;

ll solution_knapsack_problem(){
    ll N, C; cin>>N>>C;
    ll half = N / 2;

    ll NA = half;
    ll NB = N - NA;
    
    vector<ll>A(NA); vector<ll>B(NB);
    for(int i = 0; i<NA; i++){
        cin>>A[i];
    }
    for(int i = 0; i<NB; i++){
        cin>>B[i];
    }

    vector<ll>SA;
    SA.reserve((1 << NA));
    for(int i = 0; i<(1 << NA); i++){
        ll tmp_ret = 0;
        for(int j = 0; j<NA; j++){
            if((i & (1 << j)) != 0){
                tmp_ret += A[j];
            }
        }
        if(tmp_ret <= C)
            SA.push_back(tmp_ret);
    }

    vector<ll>SB;
    SB.reserve((1 << NB));
    for(int i = 0; i<(1 << NB); i++){
        ll tmp_ret = 0;
        for(int j = 0; j<NB; j++){
            if((i & (1 << j)) != 0){
                tmp_ret += B[j];
            }
        }
        if(tmp_ret <= C)
            SB.push_back(tmp_ret);
    }

    sort(SB.begin(), SB.end());

    ll ret = 0;
    for(auto ele : SA){
        ll left = C - ele;
        auto it = upper_bound(SB.begin(), SB.end(), left);
        ret += (it - SB.begin());
    }
    return ret;
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cout<<solution_knapsack_problem()<<"\n";

    return 0;
}
/*
N은 30 이하
무게는 10^9 이하로 무게의 범위가 상당히 크다
C가 주어질 때 해당 C 무게 이하로 가방을 채울 수 있는 방법의 수

선택을 기준으로 생각
C를 기준으로 생각
N을 기준으로 생각

1 1 1 1 1 ...
전체 합? 2 ^ 30 이하 가짓수 
같은 1이여도 다르다


*/
/*
예제 입력 1 
2 1
1 1
예제 출력 1 
3
예제 입력 2 
1 1
1
예제 출력 2 
2
예제 입력 3 
1 2
1
예제 출력 3 
2
예제 입력 4 
2 1
2 2
예제 출력 4 
1
예제 입력 5 
2 2
1 1
예제 출력 5 
4
예제 입력 6 
30 30
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
예제 출력 6 
1073741824
*/