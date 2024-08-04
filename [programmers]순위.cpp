#include <string>
#include <vector>

using namespace std;

// vector<int>child_dfs;

int dfs_graph(int now, vector<bool>&visited, vector<vector<int>>graph){
    int ret = 0;
    for(auto ele : graph[now]){
        if(!visited[ele]){
            visited[ele] = true;
            ret += (1 + dfs_graph(ele, visited, graph));
        }
    }
    return ret;
}


int solution(int n, vector<vector<int>> results) {
    int answer = 0;
    vector<vector<int>>graph(n+1);
    vector<vector<int>>rev_graph(n+1);

    for(auto ele : results){
        graph[ele[0]].push_back(ele[1]);
        rev_graph[ele[1]].push_back(ele[0]);
    }

    for(int i = 1; i<=n; i++){
        vector<bool>visited(n+1, false);
        int straight = dfs_graph(i, visited, graph);
        visited.resize(n+1, false);
        visited.clear();
        int reverse = dfs_graph(i, visited, rev_graph);
        if(straight + reverse == n-1){
            answer++;
        }
    }

    return answer;
}

