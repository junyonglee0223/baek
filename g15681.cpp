//g15681 트리와 쿼리
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define endl '\n'
int N, R, Q;
vector<vector<int>>adj;
vector<int>ranks;
vector<int>sub_cnt;

void setting_ranks(){
    ranks[R] = 0;
    queue<pair<int,int>>q;
    q.push({R, 0});

    while(!q.empty()){
        int now = q.front().first;
        int now_rank = q.front().second;
        q.pop();


        for(int nxt : adj[now]){
            if(ranks[nxt] == -1){
                ranks[nxt] = now_rank + 1;
                q.push({nxt, now_rank + 1});
            }
        }
    }
}

int dfs_sub_tree(int now){
    sub_cnt[now] = 1;
    for(auto nxt : adj[now]){
        if(ranks[nxt] > ranks[now]){
            sub_cnt[now] += dfs_sub_tree(nxt);
        }
    }
    return sub_cnt[now];
}

void solution_tree_and_query(){
    cin>>N>>R>>Q;

    adj.resize(N+1);
    ranks.resize(N+1, -1);
    sub_cnt.resize(N+1, 0);


    for(int i = 0; i<N-1; i++){
        int a, b; cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    setting_ranks();

    dfs_sub_tree(R);
    

    for(int i = 0; i<Q; i++){
        int query; cin>>query;
        cout<<sub_cnt[query]<<endl;
    }
}

/*
setting ranks of all nodes
after that dfs to find sybtree count


*/
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solution_tree_and_query();
    return 0;
}


/*

9 5 3
1 3
4 3
5 4
5 6
6 7
2 3
9 6
6 8
5
4
8


9
4
1


*/