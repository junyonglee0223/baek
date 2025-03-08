//s6064 카잉 달력
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;

int gcd(int x, int y){
    if(x > y)swap(x, y);
    if(y%x == 0)return x;
    return gcd(x, y%x);
}
int divided_ret(int x, int n){
    if(x % n == 0)return n;
    return x % n;
}

int calc_year(int m, int n, int x, int y){
    int ret = -1;
    int e = gcd(m, n);
    int max_n = e * (m / e) * (n / e);
    //1 - m
    //1 - n
    int cand_num = x;
    for(int i = cand_num; i<=max_n; i += m){
        if(divided_ret(i, n) == y){
            ret = i;
            return ret;
        }
    }
    // for(int i = 1; i<=max_n; i++){
    //     if(divided_ret(i, m) == x && divided_ret(i, n) == y){
    //         ret = i;
    //         return ret;
    //     }
    // }
    return ret;
}

void solution_kaing_calender(){
    int T; cin>>T;
    while(T--){
        int m, n, x, y;
        cin>>m>>n>>x>>y;
        cout<<calc_year(m, n, x, y)<<endl;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solution_kaing_calender();

    return 0;
}

