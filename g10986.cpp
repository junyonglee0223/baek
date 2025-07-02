//g10986 나머지 합
#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;
void solution_rest_sum_v2(){
    int N, M; cin>>N>>M;
    vector<ll>rest_cnt(M, 0);
    vector<ll>arr(N);
    vector<ll>rest_sum(N, 0);


    for(int i = 0; i<N; i++){
        cin>>arr[i];
        
        rest_sum[i] = (i == 0) ? arr[i] % M : (rest_sum[i-1] + arr[i])%M;
        rest_cnt[rest_sum[i]]++;
    }
    ll answer = rest_cnt[0];
    for(int i = 0; i<M; i++){
        if(rest_cnt[i]<=1)continue;
        ll x = rest_cnt[i];
        answer += (x * (x-1))/2;
    }
    cout<<answer<<endl;
}
/*
나머지가 같은 구간인 경우는 해당 구간 내부에 M의 배수인 구간이 존재한다는 의미
    엄밀히 말해서는 선택한 구간 사이가 M의 배수라는 의미임

애초에 M의 배수인 지점과 같이 합산하면 전체 구간 개수를 확인할 수 있을까?

같은 나머지 set에 존재하는 개수에서 중복없이 두개를 선택하면 되는 문제 아닌가?
헷갈리면 안되는 부분이 이미 M의 배수인 set도 조합하면 M 배수 set이기 때문에 
계산에 포함해야 한다.

long long 고려해서 계산해야 함

*/

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solution_rest_sum_v2();

    return 0;
}


/*
5 3
1 2 3 1 2
*/
/*
7
*/

