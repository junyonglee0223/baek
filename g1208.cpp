//부분수열의 합 2

#include <iostream>
#include <map>
#include <vector>
using namespace std;

typedef long long ll;
int N, S;
vector<int>nums;
map<int,int> mp;
ll ans;

void partSumLeft(int idx, int sum){

    if(idx == N/2){
        mp[sum]++;
        return;
    }
    partSumLeft(idx+1, sum + nums[idx]);
    partSumLeft(idx+1, sum);
}

void partSumRight(int idx, int sum){
    if(idx == N){
        ans += mp[S - sum];
        return;
    }
    partSumRight(idx+1, sum);
    partSumRight(idx+1, sum + nums[idx]);
}




int main(){
    cin>>N>>S;
    for(int i = 0; i<N; i++){
        int e; cin>>e;
        nums.push_back(e);
    }
    partSumLeft(0, 0);
    partSumRight(N/2, 0);
    if(S == 0) ans --;
    cout<<ans<<endl;
}


