#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;


int N, M;
vector<int>cost_arr;
vector<int>memory_arr;

vector<vector<int>>costCache;

int selectApp(int idx, int cost){
    if(cost < 0) return -1e9;
    if(idx == N)return 0;
    
    int& ret = costCache[idx][cost];
    if(ret != -1)return ret;
    ret = selectApp(idx+1, cost);

    if(cost >= cost_arr[idx])
        ret = max(ret, memory_arr[idx] + selectApp(idx+1, cost - cost_arr[idx]));

    return ret;
}


int main(){
    cin>>N>>M;
    cost_arr.resize(N, 0);
    memory_arr.resize(N, 0);

    for(int i = 0; i<N; i++)
        cin>>memory_arr[i];
    int total_cost = 0;
    for(int i = 0; i<N; i++){
        cin>>cost_arr[i];
        total_cost += cost_arr[i];
    }
        
    costCache.resize(101, vector<int>(total_cost + 1, -1));
    
    int answer = 1e9;
    for(int i = 0; i<=total_cost; i++){
        if(selectApp(0, i) >= M){
            answer = i;
            break;
        }
    }
    cout<<answer<<endl;

}