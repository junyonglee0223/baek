//s1325 효율적인 해킹
#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;


void solution_complete_hacking(){
    int n, m; cin>>n>>m;
    vector<vector<int>>adj(n+1);
    //a b -> a가 b에게 종속되어있다.
    //adj[a] -> b

    for(int i = 0; i<m; i++){
        int a, b; cin>>a>>b;
        adj[b].push_back(a);
    }

    
    vector<int>child_cnt(n+1, 0);
    int max_val = 0;
    for(int i = 1; i<=n; i++){
        vector<bool>visited(n+1, false);
        visited[i] = true;
        queue<int>que;
        que.push(i);
        while(!que.empty()){
            int cur = que.front();
            child_cnt[i]++;
            que.pop();
            for(auto nxt : adj[cur]){
                if(visited[nxt] == true)continue;
                visited[nxt] = true;
                que.push(nxt);
            }
        }
        max_val = max(max_val, child_cnt[i]);
    }
    vector<int>ret;
    for(int i= 1; i<=n; i++){
        if(child_cnt[i] == max_val){
            ret.push_back(i);
        }
    }
    for(auto ele : ret){
        cout<<ele<<" ";
    }
    cout<<endl;
}

void solution(){}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    solution_complete_hacking();
    return 0;
}

/*
5 4
3 1
3 2
4 3
5 3
예제 출력 1 
1 2
*/