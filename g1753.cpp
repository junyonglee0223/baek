//최단거리
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define endl '\n'
#define INF 200001
typedef pair<int,int> p;

int V, E, start;
vector<vector<p>>graph;

int main(){
    //입출력 최적화 하지 않으면 시간초과 발생한다.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>V>>E>>start;
    graph.resize(V+1);


    for(int i = 0; i<E; i++){
        int s, d, w;
        cin>>s>>d>>w;
        graph[s].push_back({d, w});
    }
    
    vector<int> dist(V+1, INF);
    priority_queue<p, vector<p>, greater<p>>pq;
    dist[start] = 0;
    pq.push({0, start});

    while(!pq.empty()){
        int now = pq.top().second;
        int cost = pq.top().first;
        pq.pop();
        for(auto nxt_node : graph[now]){
            int nxt = nxt_node.first;
            int nxt_cost = nxt_node.second;
            if(dist[nxt] > cost + nxt_cost){
                dist[nxt] = cost + nxt_cost;
                pq.push({dist[nxt], nxt});
            }
        }
    }

    for(int i = 1; i<=V; i++){
        if(dist[i] == INF){
            cout<<"INF"<<endl;
        }
        else{
            cout<<dist[i]<<endl;
        }
    }

}






