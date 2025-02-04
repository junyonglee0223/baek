//s1389 케빈 베이컨의 6단계 법칙
#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <queue>
using namespace std;

int N, M;
vector<vector<int>>adj;

int findKelivin(int start){
    vector<bool>visited(N+1, false);
    queue<pair<int,int>>q;

    int ret = 0;
    q.push({0, start});
    visited[start] = true;

    while(!q.empty()){
        int nowDist = q.front().first;
        int now = q.front().second;
        ret += nowDist;
        q.pop();
        
        for(auto nxt : adj[now]){
            if(visited[nxt] == false){
                visited[nxt] = true;
                q.push({nowDist + 1, nxt});
            }
        }
    }

    return ret;
}


int main(){
    
    cin>>N>>M;
    adj.resize(N+1);

    for(int i = 0; i<M; i++){
        int a, b; cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    
    int answer = INT_MAX;
    int answerIdx = N+1;
    for(int i = 1; i<=N; i++){

        int tmp = findKelivin(i);
        if(answer > tmp){
            answer = tmp;
            answerIdx = i;
        }
    }
    cout<<answerIdx<<"\n";
}