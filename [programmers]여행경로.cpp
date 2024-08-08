#include <string>
#include <vector>

#include <map>
#include <algorithm>
using namespace std;

map<string, vector<string>>graph;
map<string, vector<bool>>visited;
vector<string>path;
bool flag = false;

void dfs(string now, int n){
    if(path.size() == n+1){
        flag = true;
        return;
    }

    for(int i = 0; i<visited[now].size(); i++){
        if(visited[now][i] == false){
            visited[now][i] = true;
            path.push_back(graph[now][i]);
            dfs(graph[now][i], n);
            if(flag == true)return;
            path.pop_back();
            visited[now][i] = false;
        }
    }
}

vector<string> solution(vector<vector<string>> tickets) {
    vector<string> answer;
    for(auto& ticket : tickets){
        graph[ticket[0]].push_back(ticket[1]);
    }
    for(auto& ele : graph){
        sort(ele.second.begin(), ele.second.end());
    }
    for(auto ele : graph){
        visited[ele.first] = vector<bool>(ele.second.size(), false);
    }
    path.push_back("ICN");
    dfs("ICN", tickets.size());
    answer = path;

    return answer;
}


