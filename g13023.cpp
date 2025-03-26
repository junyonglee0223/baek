//g13023 ABCDE
#include <iostream>
#include <vector>
using namespace std;

#define endl '\n'
vector<vector<int>>adj;

bool dfs_abcd(int now, int depth, vector<bool>&visited){
    if(depth >= 4)return true;
    bool ret = false;

    for(auto nxt : adj[now]){
        if(visited[nxt])continue;
        visited[nxt] = true;
        bool tmp = dfs_abcd(nxt, depth + 1, visited);
        if(tmp)return true;
        visited[nxt] = false;
    }
    return ret;
}

void solution_ABCD_v1(){
    int N, M;
    cin>>N>>M;

    adj.clear();

    adj.resize(N);

    for(int i = 0; i<M; i++){
        int a, b; cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    bool answer = false;
    for(int i = 0; i<N; i++){
        //if(visited[i])continue;
        vector<bool>visited(N, false);
        visited[i] = true;
        bool tmp = dfs_abcd(i, 0, visited);
        if(tmp){
            answer = true;
            break;
        }
    }
    cout<<answer<<endl;
}



int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    solution_ABCD_v1();

    // int T; cin>>T;
    // while(T--){
    //     solution_ABCD_v1();
    // }

    return 0;
}

/*
4
5 4
0 1
1 2
2 3
3 4


5 5
0 1
1 2
2 3
3 0
1 4

6 5
0 1
0 2
0 3
0 4
0 5

8 8
1 7
3 7
4 7
3 4
4 6
3 5
0 4
2 7
*/

/*
1
1
0
1
*/

