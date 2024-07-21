#include <string>
#include <vector>
#include <iostream>
using namespace std;
#define endl '\n'

void dfs(int now, vector<bool>&visited, vector<vector<int>>&computers){
    int n = visited.size();
    visited[now] = true;
    for(int i = 0; i<n; i++){
        if(computers[now][i]==1 && visited[i]==false){
            visited[i] = true;
            dfs(i, visited, computers);
        }
    }
    return;
}

bool isAllCheck(vector<bool>&visited){
    for(int i = 0; i<visited.size(); i++){
        if(visited[i] == false)
            return false;
    }
    return true;
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    vector<bool>visited(n, false);
    while(!isAllCheck(visited)){
        for(int i = 0; i<n; i++){
            if(visited[i] == false){
                answer++;
                dfs(i, visited, computers);
            }
        }
    }
    
    cout<<answer<<endl;//test
    
    return answer;
}