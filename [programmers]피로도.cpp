#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int dfs(int k, vector<bool>visited, vector<vector<int>>&dungeons, int cnt){
    int ret = 0;
    bool flag = false;
    for(int i = 0; i<dungeons.size(); i++){
        if(dungeons[i][0] <= k && !visited[i]){
            visited[i] = true;
            flag = true;
            ret = max(ret, dfs(k - dungeons[i][1], visited, dungeons, cnt+1));
            visited[i] = false;
        }
    }
    if(!flag)return cnt;
    return ret;
}

int solution(int k, vector<vector<int>> dungeons) {
    int answer = -1;
    vector<bool>visited(dungeons.size(), false);
    answer = dfs(k, visited, dungeons, 0);
    return answer;
}