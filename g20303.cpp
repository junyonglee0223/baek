//g20303 할로윈의 양아치
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M, K;
vector<int>candies;
vector<vector<int>>adj;

vector<int>childGroup;
vector<int>childGroupCandies;

pair<int,int> makeChildGroup(int now, vector<bool>&visited){
    pair<int,int>ret = {0, 0};
    for(auto nxt : adj[now]){
        if(visited[nxt] == false){
            visited[nxt] = true;
            pair<int,int> tmp = makeChildGroup(nxt, visited);
            ret.first += (tmp.first + 1);
            ret.second += (tmp.second + candies[nxt]);
        }
    }
    return ret;
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin>>N>>M>>K;
    candies.resize(N+1, 0);
    for(int i = 1; i<=N; i++){
        cin>>candies[i];;
    }

    adj.resize(N+1);
    for(int i = 0; i<M; i++){
        int a, b; cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    vector<bool>visited(N+1, false);
    for(int i = 1; i<=N; i++){
        if(visited[i] == false){
            visited[i] = true;
            pair<int,int> tmpRet = makeChildGroup(i, visited);
            childGroup.push_back(tmpRet.first + 1);
            childGroupCandies.push_back(tmpRet.second + candies[i]);
        }
    }

    int GN = childGroup.size();

    vector<int>dp(K+1, 0);
    int answer = 0;

    for(int i = 0; i<GN; i++){
        for(int j = K-1; j >= childGroup[i]; j--){
            dp[j] = max(dp[j], dp[j - childGroup[i]] + childGroupCandies[i]);
            answer = max(answer, dp[j]);
        }
    }


    cout<<answer<<'\n';
}
