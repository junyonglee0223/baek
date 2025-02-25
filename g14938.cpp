//g14938번 서강그라운드
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define endl '\n'
#define INF 1001

void solution_sogangground(){
    int n, m, r;
    cin>>n>>m>>r;

    vector<int>items;
    vector<vector<int>>adj;
    vector<int>tot_score;
    
    items.resize(n, 0);
    adj.resize(n, vector<int>(n, INF));
    tot_score.resize(n, 0);

    for(int i = 0; i<n; i++){
        cin>>items[i];
        adj[i][i] = 0;
    }

    for(int i = 0; i<r; i++){
        int a, b, c;
        cin>>a>>b>>c;
        a--; b--;
        adj[a][b] = c;
        adj[b][a] = c;
    }

   for(int k = 0; k<n; k++){
       for(int i = 0; i<n; i++){
           for(int j = 0; j<n; j++){
                adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);
                adj[j][i] = adj[i][j];
           }
       }
   }

   for(int i = 0; i < n; i++){
        for(int j = 0; j<n; j++){
            if(adj[i][j] <=m){
                tot_score[i] += items[j];
            }
        }
   }

   int max_item = 0;

   for(int i = 0; i<n; i++){
    max_item = max(max_item, tot_score[i]);
   }
   cout<<max_item<<endl;
}



int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solution_sogangground();

}

/*
5 5 4
5 7 8 2 3
1 4 5
5 2 4
3 2 3
1 2 3

    -> 23

*/