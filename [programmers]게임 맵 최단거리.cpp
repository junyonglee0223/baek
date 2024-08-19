#include<vector>

#include <queue>
using namespace std;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

bool isRange(int x, int y, int n, int m){
    return x>=0 && x<n && y>=0 && y<m;
}

int solution(vector<vector<int> > maps)
{
    int answer = 0;
    
    int n = maps.size();
    int m = maps[0].size();
    vector<vector<int>>dist(n, vector<int>(m, -1));
    queue<pair<int,int>>q;

    dist[0][0] = 1;
    q.push({0, 0});

    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for(int d = 0; d<4; d++){
            int nx = x + dx[d];
            int ny = y + dy[d];
            if(isRange(nx, ny, n, m) && dist[nx][ny]==-1
            && maps[nx][ny]==1){
                q.push({nx, ny});
                dist[nx][ny] = dist[x][y] + 1;
            }
        }
    }
    answer = dist[n-1][m-1];
    return answer;
}