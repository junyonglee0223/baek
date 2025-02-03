//s32202 풀이 전달
#include <iostream>
using namespace std;

typedef long long ll;
const ll MOD = 1000000007;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    ll answer = 0;

    ll first = 3;
    ll second = 8;

    int N; cin>>N;

    for(int i = 3; i<=N; i++){
        ll tmp = (first + second) % MOD;
        tmp *= 2;
        tmp %= MOD;
        if(i % 2)first = tmp;
        else second = tmp;
    }

    if(N % 2)answer = first;
    else answer = second;

    cout<<answer<<'\n';
}
/*
각 줄마다의 상태가 존재함
짝에게 해답을 듣는 경우를 1로 설정한다면 해당 경우 - 1로 표현 - count 2
그 외의 경우 - 0으로 표현 - 둘다 듣는 경우 - 1
1은 연속해서 나와도 되지만 0은 연속할 수 없음

long long으로 해서 계산에 문제 생기지 않도록 사전 구현

상태를 저장해서 진행해야 하는지???
setting 보다 최종 value가 더 중요함

1, 01(10) 타일을 놓는 방식이라고 생각하면 됨
a(n) = (a(n-1) + a(n-2)) * 2

a(0) = 1
a(1) = 3
a(2) = 8
a(3) = 22



*/
