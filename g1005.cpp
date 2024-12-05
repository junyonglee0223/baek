#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N, K;
int W;
vector<int> D, indegree, timeRequired;
vector<vector<int>>adj;
int main(){
    int T; cin>>T;
    while (T--){
        cin>>N>>K;
        D = vector<int>(N+1);
        indegree = vector<int>(N+1, 0);
        timeRequired = vector<int>(N+1, 0);

        adj = vector<vector<int>>(N+1);

        for(int i = 1; i<=N; i++)cin>>D[i];
        for(int i = 0; i<K; i++){
            int X, Y;
            cin>>X>>Y;
            adj[X].push_back(Y);
            indegree[Y]++;
        }
        cin>>W;
        queue<int>q;
        for(int i = 1; i<=N; i++){
            if(indegree[i] == 0){
                q.push(i);
                timeRequired[i] = D[i];
            }
        }
        while(!q.empty()){
            int now = q.front();
            q.pop();
            for(int nxt : adj[now]){
                timeRequired[nxt] = max(timeRequired[nxt], timeRequired[now] + D[nxt]);
                if(--indegree[nxt]==0){
                    q.push(nxt);
                }
            }
        }
        cout<<timeRequired[W]<<endl;
    }
}