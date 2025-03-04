//g2533 사회망 서비스(SNS)
#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

#define endl '\n'

int N;
vector<vector<int>>adj;

int dp[1000001][2];


int set_node_flag(int now, bool flag, vector<bool>& visited){

    //visited[now] = true;
    int& ret = dp[now][flag];
    if(ret != -1)return ret;

    ret = 0;
    if(flag == true){
        ret = 1;
        for(auto nxt : adj[now]){
            if(visited[nxt] == true)continue;
            visited[nxt] = true;

            int tmp = min(set_node_flag(nxt, true, visited),
                 set_node_flag(nxt, false, visited));

            visited[nxt] = false;
            ret += tmp;

        }

    }
    else{
        for(auto nxt : adj[now]){
            if(visited[nxt] == true)continue;
            visited[nxt] = true;
            int tmp = set_node_flag(nxt, true, visited);
            visited[nxt] = false;
            ret += tmp;
        }
    }
   // visited[now] = false;
    return ret;
}

void solution_sns(){
    adj.clear();

    cin>>N;
    adj.resize(N);

    for(int i = 0 ;i<N; i++){
        for(int j = 0; j<2; j++){
            dp[i][j] = -1;
        }
    }

    for(int i = 0; i<N-1; i++){
        int a, b; cin>>a>>b;
        a--, b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    vector<bool>visited(N, false);
    visited[0] = true;
    int root_1 = set_node_flag(0, true, visited);
    visited[0] = false;

    visited[0] = true;
    int root_2 = set_node_flag(0, false, visited);
    visited[0] = false;

    int answer = min(root_1, root_2);
    cout<<answer<<endl; 
}


vector<bool>visited;
void set_node_dfs(int now){
    visited[now] = true;

    dp[now][0] = 0;
    dp[now][1] = 1;

    for(auto nxt : adj[now]){
        if(visited[nxt])continue;
        set_node_dfs(nxt);
        dp[now][0] += dp[nxt][1]; 
        dp[now][1] += min(dp[nxt][0], dp[nxt][1]);
    }
}

void solution_sns_v1(){
    adj.clear();
    visited.clear();

    cin>>N;
    adj.resize(N);
    visited.resize(N, false);

    for(int i = 0 ;i<N; i++){
        for(int j = 0; j<2; j++){
            dp[i][j] = -1;
        }
    }

    for(int i = 0; i<N-1; i++){
        int a, b; cin>>a>>b;
        a--, b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    set_node_dfs(0);
    cout<<min(dp[0][0], dp[0][1])<<endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    //solution_sns();
    solution_sns_v1();

    // int T; cin>>T;
    // while(T--){
    //     solution_sns_v1();
    // }
}




/*
3
3
*/

/*
2
8
1 2
1 3
1 4
2 5
2 6
4 7
4 8
9
1 2
1 3
2 4
3 5
3 6
4 7
4 8
4 9


*/