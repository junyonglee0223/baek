#include <string>
#include <vector>

#include <queue>
using namespace std;
vector<vector<int>>graph;

bool isChangeAble(int a, int b, vector<string>words){
    int wsize = words[0].size();
    int cnt = 0;
    for(int i = 0; i<wsize; i++){
        if(words[a][i] != words[b][i]){
            cnt++;
        }
        if(cnt > 1)return false;
    }
    return cnt == 0 ? false : true;
}

int bfs_words(vector<string>words, int target){
    int n = words.size();
    vector<int>num_val(n, -1);
    queue<int>q;
    
    int ret = 51;           //set maximum num of words
    q.push(0);
    num_val[0] = 0;

    while(!q.empty()){
        int now = q.front();
        q.pop();

        for(auto nxt : graph[now]){
            if(num_val[nxt] == -1){
                num_val[nxt] = num_val[now] + 1;
                q.push(nxt);
                if(nxt == target){
                    return num_val[nxt];
                }
            }
        }
    }
    return num_val[target];    //in this case search impos return -1
}


int solution(string begin, string target, vector<string> words) {
    int answer = 0;

    vector<string>tot_words;
    tot_words.push_back(begin);
    int goal = -1;
    int idx = 1;
    for(auto word : words){
        if(word == target)
            goal = idx;
        tot_words.push_back(word);
        idx++;      //이 부분 refactoring 필요
    }
    if(goal == -1)
        return 0;
    

    int n = tot_words.size();
    
    graph.resize(n);

    for(int i = 0; i<tot_words.size(); i++){
        for(int j = 0; j<tot_words.size(); j++){
            if(i == j)continue;
            if(isChangeAble(i, j, tot_words)){
                graph[i].push_back(j);
                graph[j].push_back(i);
            }
        }
    }
    int tmp_ret = bfs_words(tot_words, goal);
    answer = (tmp_ret == -1) ? 0 : tmp_ret;
    return answer;
}