//g2225 합분해

#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;
const ll MOD = 1000000000;

void solution_sum_decomposition_v1(){
    int N, K; cin>>N>>K;
    int dp[201][201];
    dp[0][0] = 1;

    for(int k = 1; k <= K; ++k){
        for(int i = 0; i <= N; ++i){
            dp[k][i] = dp[k-1][i];
            if(i > 0){
                dp[k][i] = (dp[k][i] + dp[k][i-1]) % MOD;
            }
        }
    }

    cout << dp[K][N] << "\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    //solution_sum_decomposition();
    solution_sum_decomposition_v1();

    // int T; cin>>T;
    // while(T--){
    //     solution_sum_decomposition_v1();
    // }


    return 0;
}



/*
2
20 2
6 4
*/
/*
21
84
*/

/*

10^9 나머지를 구하면 된다.
N 주어지고 0 - N 수로 K를 만드는 가짓수이다.
N, K 는 0 이상 200 이하의 정수이다.

팩토리얼 역으로 된 것도 구해야 한다.
MOD 사용해서 역원을 미리 구하려고 한다.

MOD에 대한 역원은 어떻게 구하면 되냐
a ^ (p - 1) === 1 (mod p)
라고 페르마의 소정리를 알고 있다.
a ^ (p - 2) === 1/a (mod p)
라고 추정할 수 있다. 
즉 MOD - 2 만큼의 나머지 곱 연산을 해야 한다.

또다른 문제는 순서쌍을 어떻게 구하냐는 것이다.

i, j
에 대한 점화식을 생각해야 한다.
i-1, j
i ,j-1

i-1, j-1
두개를 같이 공존해서 사용해야 하는데 방법을 생각해봐
삼중 for문을 활용하지 않는 이상 불가능할 것 같은데 다른 방법 없나?



*/