//ATM
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int>line;

int main(){
    int N; cin>>N;
    for(int i = 0; i<N; i++){
        int ele; cin>>ele;
        line.push_back(ele);
    }
    sort(line.begin(), line.end());
    vector<int>sum(N, 0);
    int ans = line[0];
    sum[0] = line[0];
    for(int i = 1; i<N; i++){
        sum[i] += (sum[i-1] + line[i]);
        ans += sum[i];
    }
    cout<<ans<<"\n";
}

