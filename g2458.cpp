//g2458 키 순서
#include <iostream>
#include <vector>
using namespace std;

int N, M;


void dfs_adj(int now, vector<bool>&visited, vector<int>&trace, vector<vector<int>>&adj){
    for(auto nxt : adj[now]){
        if(visited[nxt])continue;
        visited[nxt] = true;
        trace.push_back(nxt);
        dfs_adj(nxt, visited, trace, adj);
    }
}


void solution_height_order(){

    vector<vector<int>>adj;
    vector<vector<int>>rev_adj;
    vector<vector<int>>parents;
    vector<vector<int>>children;


    cin>>N>>M;


    adj.resize(N);
    rev_adj.resize(N);

    parents.resize(N);
    children.resize(N);


    while(M--){
        int a, b; cin>>a>>b;
        a--;b--;
        adj[a].push_back(b);
        rev_adj[b].push_back(a);
    }

    for(int i = 0; i<N; i++){
        vector<bool>visited(N, false);
        dfs_adj(i, visited, children[i], adj);
    }

    for(int i =0 ; i<N; i++){
        for(auto ele : children[i]){
            parents[ele].push_back(i);
        }
    }

    int answer = 0;
    for(int i = 0; i<N; i++){
        if(parents[i].size() + children[i].size() == N-1){
            answer++;
        }
    }
    cout<<answer<<endl;

    // //test
    // for(int i = 0; i<N; i++){
    //     cout<<i<<": ";
    //     for(auto ele : children[i]){
    //         cout<<ele <<" ";
    //     }
    //     cout<<endl;
    // }
    // cout<<endl;

    // for(int i = 0; i<N; i++){
    //     cout<<i<<": ";
    //     for(auto ele : parents[i]){
    //         cout<<ele <<" ";
    //     }
    //     cout<<endl;
    // }
    // cout<<endl;
    // //test
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    solution_height_order();

    // int T; cin>>T;
    // while(T--){
    //     solution_height_order();
    // }


    return 0;
}


/*
3
6 6
1 5
3 4
5 4
4 2
4 6
5 2

6 7
1 3
1 5
3 4
5 4
4 2
4 6
5 2

6 3
1 2
2 3
4 5
*/
/*
1
2
0
*/