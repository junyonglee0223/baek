//g1135 뉴스 전하기
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

void min_spread_time(int now, vector<int>&dp, vector<vector<int>>&adj){

    dp[now] = 0;
    
    for(auto nxt : adj[now]){
        min_spread_time(nxt, dp, adj);
    }

    sort(adj[now].begin(), adj[now].end(), [dp](int a, int b){
        return dp[a] > dp[b];
    });


    int ret = 0;
    int tmp = 0;
    for(auto nxt : adj[now]){
        if(ret == 0) ret = dp[nxt] + 1;
        else{
            ret = max(ret, tmp + dp[nxt] + 1);
        }
        tmp++;
    }
    dp[now] = ret;
}


void solution_spread_the_news(){
    int n; cin>>n;

    vector<int>parents(n, -1);
    vector<vector<int>>adj(n);
    vector<int>child_cnt(n, -1);
    vector<int>depth_node(n, 0);

    vector<int>dp(n, -1);

    for(int i = 0; i<n; i++){
        cin>>parents[i];
        if(parents[i] == -1)continue;
        adj[parents[i]].push_back(i);
    }


    min_spread_time(0, dp, adj);
    cout<<dp[0]<<endl;
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solution_spread_the_news();

    // int T; cin>>T;
    // while(T--){
    //     solution_spread_the_news();
    // }

    return 0;
}


/*
4
3
-1 0 0
5
-1 0 0 2 2
5
-1 0 1 2 3
24
-1 0 0 1 1 1 2 2 3 3 4 4 5 5 6 7 7 8 12 13 14 16 16 16
*/
/*
2
3
4
7
*/