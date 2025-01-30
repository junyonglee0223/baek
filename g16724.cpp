//g16724 피리 부는 사나이
#include <iostream>
#include <vector>
#include <map>
using namespace std;

#define endl '\n'
#define MAXELE 1000001

int N, M;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
//D, R, U, L
map<char, int>charIdx;

vector<vector<int>>board;

int loopCnt = 0;
vector<vector<int>>cntVisited;
void setBoard(int x, int y, int cnt){
    cntVisited[x][y] = cnt;
    
    int nx = x + dx[board[x][y]];
    int ny = y + dy[board[x][y]];

    if(cntVisited[nx][ny] == cntVisited[x][y]){
        loopCnt++;
        return;
    }
    if(cntVisited[nx][ny] != 0){
        return;
    }
    setBoard(nx, ny, cnt);
    return;
}


int main(){

    cin>>N>>M;
    board.resize(N, vector<int>(M));
    charIdx['D'] = 0;
    charIdx['R'] = 1;
    charIdx['U'] = 2;
    charIdx['L'] = 3;

    for(int i = 0; i<N; i++){
        string tmp; cin>>tmp;
        for(int j = 0; j<M; j++){
            board[i][j] = charIdx[tmp[j]];
        }
    }
    cntVisited.resize(N, vector<int>(M, 0));
    int cntIdx = 1;
    for(int i = 0; i<N; i++){
        for(int j = 0; j<M; j++){
            if(cntVisited[i][j] == 0){
                setBoard(i, j, cntIdx);
                cntIdx++;
            }
        }
    }
    cout<<loopCnt<<endl;

}