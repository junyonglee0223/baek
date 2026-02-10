#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;
ll NUM;
vector<ll>prims;
int N;


ll solution_counting_pow(){
    ll ret = 0;
    for(int i = 0; i<prims.size(); i++){
        ll prim_ele = prims[i];
        for(ll j = prim_ele; j<=NUM; j*=prim_ele){
            ret += (NUM / j);
        }
    }
    return ret;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin>>N;
    for(int i = 0; i<N; i++){
        int ele; cin>>ele;
        prims.push_back(ele);
    }
    cin>>NUM;
    cout<<solution_counting_pow()<<"\n";

    return 0;
}

/*
2
2 3
100
*/
/*
-> 145
*/

/*
NUM까지의 모든 배수의 개수를 구해야 함
1, ... , NUM

N <= 2*10^5

10^12 (NUM)

시초는 안나는데 타입 문제로 시초가 발생하는 듯 함

*/