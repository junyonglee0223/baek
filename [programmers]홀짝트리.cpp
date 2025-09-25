//[programmers]홀짝트리
#include <string>
#include <vector>
using namespace std;

#define MAX_V 1000001
int N;
vector<vector<int>> adj;
vector<int> nodes_idx;
vector<int> child_cnt; 
vector<int> match;

typedef pair<int, int> p;
p dfs(int cur, vector<bool>& visited) {
    visited[cur] = true;
    int cnt = 1;
    int match_cnt = match[cur];

    for (auto nxt : adj[cur]) {
        if (visited[nxt]) continue;
        p nxt_ret = dfs(nxt, visited);
        cnt += nxt_ret.first;
        match_cnt += nxt_ret.second;
    }
    return { cnt, match_cnt };
}

vector<int> solution(vector<int> nodes, vector<vector<int>> edges) {
    vector<int> answer;

    N = nodes.size();
    nodes_idx.assign(MAX_V, -1);
    match.assign(N, 0);
    adj.assign(N, {});
    child_cnt.assign(N, 0);

    for (int i = 0; i < N; i++) {
        nodes_idx[nodes[i]] = i;
    }

    for (auto ele : edges) {
        int a = nodes_idx[ele[0]];
        int b = nodes_idx[ele[1]];
        child_cnt[a]++;
        child_cnt[b]++;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }


    for (int i = 0; i < N; i++) {
        if ( ((nodes[i] ^ child_cnt[i]) & 1) == 0 ) {
            match[i] = 1;  
        }
    }

    vector<bool> visited(N, false);
    vector<int> group_cnt;
    vector<int> group_match;

    for (int i = 0; i < N; i++) {
        if (!visited[i]) {
            p tmp_ret = dfs(i, visited);
            group_cnt.push_back(tmp_ret.first);
            group_match.push_back(tmp_ret.second);
        }
    }

    int ret_match = 0;
    int ret_unmatch = 0;

    for (int i = 0; i < (int)group_cnt.size(); i++) {
        
        if (group_match[i] == 1) ret_match++;
        if (group_match[i] == group_cnt[i] - 1) ret_unmatch++;
    }

    answer.push_back(ret_match);
    answer.push_back(ret_unmatch);
    return answer;
}
