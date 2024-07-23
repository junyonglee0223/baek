// //KAKAO 2021
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> graph;
vector<vector<int>> dp;


void dfs(int now, const vector<int>& sales){
    dp[now][0] = 0;
    dp[now][1] = sales[now];

    bool isInclude = false;
    int extra_val = 1e9;
    for(auto nxt : graph[now]){
            dfs(nxt, sales);
            dp[now][0] += min(dp[nxt][0], dp[nxt][1]);
            dp[now][1] += min(dp[nxt][0], dp[nxt][1]);
            if(dp[nxt][0] >= dp[nxt][1]){
                isInclude = true;
            }
            else{
                extra_val = min(extra_val, dp[nxt][1] - dp[nxt][0]);
            }
    }
    if(!isInclude && extra_val != 1e9){
        dp[now][0] += extra_val;
    }
}

int solution(vector<int> sales, vector<vector<int>> links) {
    int n = sales.size();
    graph.resize(n);
    dp.resize(n, vector<int>(2, 0));

    for (auto& link : links) {
        link[0]--; link[1]--;
        graph[link[0]].push_back(link[1]);
    }

    dfs(0, sales);

    return min(dp[0][0], dp[0][1]);
}