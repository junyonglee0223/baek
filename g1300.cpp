//g1300 K번째 수
#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
using namespace std;

#define MAX_V 1000000000
typedef long long ll;

int solution_find_kth(){
    int N, K; cin>>N>>K;
    ll left = 1, right = MAX_V;
    while(left < right){
        ll mid = (left + right) >> 1;
        ll cur_cnt = 0;
        for(int i = 1; i<=N; i++){
            cur_cnt += min((ll)N, (mid / i));
            if(cur_cnt >= K)break;
        }

        if(cur_cnt >= K){
            right = mid;
        }else{
            left = mid + 1;
        }
    }
    return (int)left;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cout<<solution_find_kth()<<"\n";

    return 0;
}

/*
3
7
*/
/*
6
*/

/*
N, K 주어진다.
N -> 10^5
K -> 10^9 보다 작음

(1, 1), (1, 2), ... , (1, N)
...
(N, 1), ...,        , (N, N)

N * N개 주어진다.
이를 1차원 배열로 정렬한다.
K번쨰 인덱스를 찾으면 된다

우선 배열 인덱스 곱으로 저장하기 때문에 동일 인덱스 N개 제외하고 최소 2개씩 
같은 숫자가 존재한다.

(1, 1), (1, 2), (1, 3), (1, 4)
(2, 1), (2, 2), (2, 3), (2, 4)
(3, 1), (3, 2), (3, 3), (3, 4)
(4, 1), (4, 2), (4, 3), (4, 4)

1, 2, 3 -> 1, 2, 3, 2, 4, 6, 3, 6, 9
1, 2, 2, 3, 3, 4, 6, 6, 9

대각선 탐색
N -> 1, 2, ..., N-1, N, N-1, ..., 1

N까지 누적합
1, 3, 5, ..., N^2

1, 3, 6, 10, 13, 15, 16
해당 인덱스를 찾고 배열 새로 만들고 거기서 찾으면 시간안에 될 듯하다.

해당 배열에서 mid / i인 개수를 찾으면 됨
나머지는 이분 탐새그올 개수 카운팅





*/