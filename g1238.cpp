#include <iostream>
#include <vector>
using namespace std;

#define MAX_N 1001
#define INF 1e9     //max time 수정해야 할 수 도 있음
int N, D, P;    
vector<vector<int>>graph;
vector<vector<int>>dp;


int main(){
    cin>>N>>D>>P;
    P--;
    graph.resize(N+1, vector<int>(N+1, INF));
    dp.resize(N+1, vector<int>(N+1, INF));

    for(int i = 0; i<N; i++){
        graph[i][i] = 0;
        dp[i][i] = 0;
    }
    
    for(int i = 0; i<D; i++){
        int a, b, c;
        cin>>a>>b>>c;
        a--; b--;
        graph[a][b] = c;
        dp[a][b] = c;
    }

    //모든 노드 최단거리를 설정한다.
    //더 최적이 있나??

    for(int k = 0; k<N; k++){
        for(int i = 0; i<N; i++){
            for(int j = 0; j<N; j++){
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
            }    
        }
    }

    // //test
    // for(int i = 0; i<N; i++){
    //     for(int j = 0; j<N; j++){
    //         cout<<dp[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }

    int ans = 0;
    for(int i = 0; i<N; i++){
        ans = max(ans, dp[i][P] + dp[P][i]);
    }
    cout<<ans<<'\n';

}

