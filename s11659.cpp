//구간 합 구하기 4
#include <iostream>
#include <vector>
using namespace std;

#define endl '\n'

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int N, M;
    cin>>N>>M;
    
    vector<int>num(N+1, 0);
    vector<int>sum_num(N+1, 0);

    for(int i = 1; i<=N; i++){
        int ele; cin>>ele;
        num[i] = ele;
        sum_num[i] = sum_num[i-1] + num[i];
    }
    
    for(int t = 0; t<M; t++){
        int a, b; cin>>a>>b;
        cout<<sum_num[b] - sum_num[a-1]<<endl;
    }
}


