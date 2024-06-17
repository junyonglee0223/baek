//숨바꼭질 3
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

#define endl '\n'
#define INF 1e9
#define MAXRANGE 100001
typedef pair<int, int> p;
int N, M;
vector<int>dist(MAXRANGE, INF);

int dijkstra_find(){
    priority_queue<p, vector<p>, greater<p>>pq;
    dist[N] = 0;
    pq.push({0, N});
    while(!pq.empty()){
        int now = pq.top().second;
        int cost = pq.top().first;
        pq.pop();

        if(now == M){
            return dist[M];
        }

        if(now*2 < MAXRANGE && dist[now*2] > cost){
            dist[now*2] = cost;
            pq.push({cost, now*2});
        }
        if(now+1 < MAXRANGE && dist[now+1] > cost+1){
            dist[now+1] = cost+1;
            pq.push({cost+1, now+1});
        }
        if(now-1 >= 0 && dist[now-1] > cost+1){
            dist[now-1] = cost+1;
            pq.push({cost+1, now-1});
        }
    }
    return INF;
}



int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>N>>M;

    vector<bool>visited(MAXRANGE, false);
    cout<<dijkstra_find()<<endl;
}

