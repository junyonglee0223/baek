//도로포장
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <climits>
using namespace std;

typedef pair<int,int>p;
int N, M, K;
vector<vector<p>>graph;
vector<vector<long long>>minDist;

struct Compare{
    bool operator()(const vector<long long>& a, const vector<long long>& b){
        return a[0] > b[0];
    }
};

long long dijkstra(){
    priority_queue<vector<long long>, vector<vector<long long>>, Compare>pq;
    pq.push({0, 0, 1});
    minDist[1][0] = 0;

    while(!pq.empty()){
        long long now = pq.top()[2];
        long long useK = pq.top()[1];
        long long cost = pq.top()[0];
        pq.pop();

        if(cost > minDist[now][useK])continue;

        for(auto nxtNode : graph[now]){
            long long nxt = nxtNode.first;
            long long dist = nxtNode.second;
            if(useK < K){
                if(cost < minDist[nxt][useK+1]){
                    minDist[nxt][useK+1] = cost;
                    pq.push({cost, useK+1, nxt});
                }
            }
            if(cost + dist < minDist[nxt][useK]){
                minDist[nxt][useK] = cost+dist;
                pq.push({cost+dist, useK, nxt});
            }
        }
    }
    long long answer = LLONG_MAX;
    for(int i = 0; i<=K; i++){
        answer = min(answer, minDist[N][i]);
    }
    return answer;
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin>>N>>M>>K;
    graph.resize(N+1);
    minDist.resize(N+1, vector<long long>(K+1, LLONG_MAX));

    for(int i = 0; i<M; i++){
        int a, b, c;
        cin>>a>>b>>c;

        graph[a].push_back({b, c});
        graph[b].push_back({a, c});
    }


    long long answer = dijkstra();
    cout<<answer<<endl;
    
}
