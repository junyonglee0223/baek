//g1068 트리
#include <iostream>
#include <vector>
using namespace std;

void dfs_set_deleted(int x, vector<bool>&is_deleted, vector<vector<int>>&adj){
    is_deleted[x] = true;
    for(auto nxt : adj[x]){
        dfs_set_deleted(nxt, is_deleted, adj);
    }
}

void solution_tree(){
    int n; cin>>n;

    vector<vector<int>>adj(n);
    vector<int>outdegree(n, 0);
    vector<bool>is_deleted(n, false);

    vector<int>arr(n);
    for(int i = 0; i<n; i++){
        cin>>arr[i];
        if(arr[i] == -1)continue;
        adj[arr[i]].push_back(i);
        outdegree[arr[i]]++;
    }

    int x; cin>>x;
    if(arr[x] != -1)outdegree[arr[x]]--;
    dfs_set_deleted(x, is_deleted, adj);

    int answer = 0;
    for(int i = 0; i<n; i++){
        if(is_deleted[i] == false && outdegree[i] == 0){
            answer++;
        }
    }
    cout<<answer<<endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solution_tree();
    // int T; cin>>T;
    // while(T--){
    //     solution_tree();
    // }

    return 0;
}
/*
4
5
-1 0 0 1 1
2
5
-1 0 0 1 1
1
5
-1 0 0 1 1
0
9
-1 0 0 2 2 4 4 6 6
4
*/
/*
2
1
0
2
*/