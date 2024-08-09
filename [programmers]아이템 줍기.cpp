#include <string>
#include <vector>

#include <queue>
#include <iostream>
using namespace std;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
bool isRange(int x, int y){
    return x>=0 && x<101 && y>=0 && y<101;
}

int solution(vector<vector<int>> rectangle, int characterX, int characterY, int itemX, int itemY) {
    int answer = 0;
    vector<vector<int>>map(101, vector<int>(101, 0));
    for(auto rec : rectangle){
        int x1 =rec[0]*2;
        int y1 = rec[1]*2;
        int x2 = rec[2]*2;
        int y2 = rec[3]*2;
        for(int i = x1; i<=x2; i++){
            for(int j = y1; j<=y2; j++){
                if(i==x1||i==x2||j==y1||j==y2){
                    if(map[i][j]!=2)map[i][j] = 1;
                }
                else{
                    map[i][j] = 2;
                }
            }
        }
    }

    queue<pair<int,int>>q;
    vector<vector<int>>dist(101, vector<int>(101, -1));

    q.push({characterX*2, characterY*2});
    dist[characterX*2][characterY*2] = 0;

    while(!q.empty()){
        int nowX = q.front().first;
        int nowY = q.front().second;
        q.pop();
        if(nowX == itemX*2 && nowY == itemY*2){
            return answer = (dist[nowX][nowY])/2;
        }
        for(int i = 0; i<4; i++){
            int nxtX = nowX + dx[i];
            int nxtY = nowY + dy[i];
            if(isRange(nxtX, nxtY)&&dist[nxtX][nxtY]==-1&&map[nxtX][nxtY]==1){
                dist[nxtX][nxtY] = dist[nowX][nowY]+1;
                q.push({nxtX, nxtY});
            }
        }
    }

    return answer;
}