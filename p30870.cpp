//p30870 사이클 없는 그래프 만들기
#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<climits>
using namespace std;

struct EDGE{
    int t, a, b;
};
struct EDGE_CMP{
    bool operator()(EDGE e1, EDGE e2){
        return e1.t > e2.t;
    }
}edge_cmp;

int find_parents(int cur, vector<int>&parents){
    if(cur != parents[cur]){
        int p = find_parents(parents[cur], parents);
        parents[cur] = p;
    }
    return parents[cur];
}

int solution_create_no_cycle(){
    int N, M, K;
    cin>>N>>M>>K;

    vector<vector<int>>adj(N+1);
    vector<pair<int,int>>init_edges;

    for(int i = 0; i<M; i++){
        int a, b; cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
        init_edges.push_back({a, b});
    }

    vector<int>dist(N+1, INT_MAX);
    queue<pair<int,int>>que;

    for(int i = 0 ; i<K; i++){
        int ele; cin>>ele;
        que.push({1, ele});
        dist[ele] = 1;
    }
    while(!que.empty()){
        int cur = que.front().second;
        int cur_t = que.front().first;
        que.pop();

        for(auto nxt : adj[cur]){
            if(dist[nxt] <= cur_t + 1)continue;
            dist[nxt] = cur_t + 1;
            que.push({cur_t + 1, nxt});
        }
    }

    vector<EDGE>edge_group;
    for(auto e : init_edges){
        int a = e.first;
        int b = e.second;
        int t = min(dist[a], dist[b]);
        edge_group.push_back({t, a, b});
    }


    sort(edge_group.begin(), edge_group.end(), edge_cmp);

    vector<int>parents(N+1);
    for(int i = 0; i<=N; i++){
        parents[i] = i;
    }

    int ret = 0;
    for(auto edge : edge_group){
        int x = edge.a;
        int y = edge.b;
        int p_x = find_parents(x, parents);
        int p_y = find_parents(y, parents);
        if(p_x == p_y){
            ret = edge.t;
            break;
        }
        parents[p_x] = p_y;
    }

    return ret;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout<<solution_create_no_cycle()<<"\n";

    return 0;
}