//g1456 거의 소수
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

typedef long long ll;

void solution_almost_prime_number(){
    ll A, B; cin>>A>>B;

    ll max_n = sqrt(B);
    vector<bool>is_prime(max_n+1, true);
    is_prime[0] = false;
    is_prime[1] = false;

    for(ll i = 2; i*i<=max_n; i++){
        if(is_prime[i] == true){
            for(ll x = i * i; x <= max_n; x += i){
                is_prime[x] = false;
            }
        }
    }
    int answer = 0;
    for(ll i = 2; i<=max_n; i++){
        if(is_prime[i] == false)continue;
        for(ll x = i*i; x <= B;){
            if(x >= A)answer++;
            if(x > B / i)
                break;
            x *= i;
        }
    }
    cout<<answer<<endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solution_almost_prime_number();

    // int T; cin>>T;
    // while(T--){
    //     solution_almost_prime_number();
    // }

    return 0;
}


/*
3
1 1000
1 10
5324 894739
*/

/*
25
3
183
*/

/*
## 문제

어떤 수가 소수의 N제곱(N ≥ 2) 꼴일 때, 그 수를 거의 소수라고 한다.

두 정수 A와 B가 주어지면, A보다 크거나 같고, B보다 작거나 같은 거의 소수가 몇 개인지 출력한다.

## 입력

첫째 줄에 왼쪽 범위 A와 오른쪽 범위 B가 공백 한 칸을 사이에 두고 주어진다.

## 출력

첫째 줄에 총 몇 개가 있는지 출력한다.

## 제한

1 ≤ A ≤ B ≤ 10^14
*/

/*
해당 문제 솔루션 생각해 봐야 함
주어지는 정수 범위가 10^14 이기 떄문에 1차원 배열 활용도 불가할 수 있다
단지 map 활용하는 방식도 생각중인데 map도 개수 많아지면 문제 발생하지 않나?

---
1
소수 체인을 미리 만들고 해당 소수들을 제곱하는 방식으로 map에 등록한 후 
map에 등록하고 size 반환하는 방식을 생각 중이다.
그러면 A, B 주어진 이후 계산이 진행되어야 함

10^14까지 소수를 우선 구하는 것도 일인가??

아니면 소인수분해를 직접 해서 판단해야 할까?
이 방법을 사용하면 A ~ B 사이의 모든 수를 탐색해야 하기 때문에
시간 초과가 무조건 발생한다.
---
---
2
B 이하의 소수를 우선 구하는 거도 일인데...?
소수의 제곱이라는 특성을 사용하면 방법이 있을 것 같기도...?
a^(x) === a (mod p)
근데 a^x 인지를 애초에 모르기 때문에
이 방법도 쉽지 않음
---



*/