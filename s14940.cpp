//쉬운 최단거리
#include <iostream>
#include <vector> 
#include <queue>
using namespace std;

#define endl '\n'
typedef pair<int, int> p;


int n, m;
bool isRange(int x, int y){
    return 0<=x && x<n && 0<=y && y<m; 
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>m;

    int dx[4] = {0, 1, 0, -1};
    int dy[4] = {1, 0, -1, 0};

    vector<vector<int>>board(n, vector<int>(m));
    vector<vector<int>>dist(n, vector<int>(m, -1));
    int g_x = -1, g_y = -1;


    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            cin>>board[i][j];
            if(board[i][j] == 2){
                g_x = i;
                g_y = j;
            }
            else if(board[i][j] == 0){
                dist[i][j] = 0;
            }
        }
    }


    queue<p>q;
    dist[g_x][g_y] = 0;
    q.push({g_x, g_y});

    while(!q.empty()){
        int nowX = q.front().first;
        int nowY = q.front().second;
        q.pop();

        for(int d = 0; d<4; d++){
            int nxtX = nowX + dx[d];
            int nxtY = nowY + dy[d];
            if(!isRange(nxtX, nxtY))continue;
            if(board[nxtX][nxtY] == 0) continue;
            if(dist[nxtX][nxtY] != -1)continue;
            q.push({nxtX, nxtY});
            dist[nxtX][nxtY] = dist[nowX][nowY] + 1;
        }
    }

    for(int i = 0; i<n; i++){
        for(int j = 0; j<m ;j++){
            cout<<dist[i][j]<<" ";
        }
        cout<<endl;
    }
}



