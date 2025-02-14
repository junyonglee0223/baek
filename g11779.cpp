//g11779 최소비용 구하기2
#include <iostream>
#include <vector>
#include <climits>
#include <queue>
#include <algorithm>
using namespace std;


#define endl '\n'

typedef pair<int,int> p;
int N, M;
int SRC, DST;
vector<vector<p>> adj;
vector<vector<p>> rev_adj;


vector<int>min_bus_cost;
vector<int>par_node;


void find_min_cost(){
    vector<bool>vistied(N+1, false);
    priority_queue<p, vector<p>, greater<p>> pq;

    pq.push({0, SRC});
    //vistied[SRC] = true;

    while(!pq.empty()){
        int now = pq.top().second;
        int now_cost = pq.top().first;
        pq.pop();

        if(now_cost > min_bus_cost[now])continue;

        // //test
        // cout<<now<<" "<<now_cost<<endl;
        // //test

        for(auto nxt_node : adj[now]){
            int nxt = nxt_node.first;
            int dist = nxt_node.second;

            //if(vistied[nxt] == true)continue;
            int nxt_cost = now_cost + dist;
            if(nxt_cost < min_bus_cost[nxt]){
                min_bus_cost[nxt] = nxt_cost;
                par_node[nxt] = now;    
                //vistied[nxt] = true;
                pq.push({nxt_cost, nxt});
            }
        }
    }
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin>>N>>M;
    adj.resize(N+1);
    rev_adj.resize(N+1);

    for(int i = 0; i<M; i++){
        int a, b, c;
        cin>>a>>b>>c;
        adj[a].push_back({b, c});
        rev_adj[b].push_back({a, c});
    }
    cin>>SRC>>DST;

    par_node.resize(N+1, N+1);
    par_node[SRC] = 0;

    min_bus_cost.resize(N+1, INT_MAX);
    min_bus_cost[SRC] = 0;

    find_min_cost();
    
    vector<int>route;
    int now = DST;
    while(now != SRC){
        route.push_back(now);
        now = par_node[now];
    }
    route.push_back(SRC);
    
    
    reverse(route.begin(), route.end());

    

    cout<<min_bus_cost[DST]<<endl;
    cout<<route.size()<<endl;
    for(auto ele : route){
        cout<< ele <<" ";
    }

  
}
