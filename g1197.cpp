#include <iostream>
#include <vector>
#include <queue>
using namespace std;

typedef pair<int,int> p;


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int N, M;
    cin>>N>>M;
    vector<vector<p>>graph(N+1);
    for(int i = 0; i<M; i++){
        int a, b, c;
        cin>>a>>b>>c;
        graph[a].push_back({b, c});
        graph[b].push_back({a, c});
    }
    vector<bool>visited(N+1, false);
    priority_queue<p, vector<p>, greater<p>>pq;
    // for(int i = 1; i<=N; i++){
    //     pq.push({0, i});
    // }
    pq.push({0, 1});
    int total_cost = 0;

    while(!pq.empty()){
        int cost = pq.top().first;
        int now = pq.top().second;
        pq.pop();
        if(visited[now])continue;
        visited[now] = true;
        total_cost += cost;
        for(auto nxt_node : graph[now]){
            int nxt = nxt_node.first;
            int edge = nxt_node.second;
            if(!visited[nxt]){
                cout<<now<<" "<<nxt<<" "<<edge<<endl;//test
                pq.push({edge, nxt});
            }
        }
    }

    cout<<total_cost<<endl;
}

/*
3 3
1 2 1
2 3 2
1 3 3
*/