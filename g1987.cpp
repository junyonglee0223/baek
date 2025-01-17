//g1987 알파벳
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int R, C;
vector<vector<char>>board;
int maxCnt = 0;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

bool isRange(int x, int y){
    return x>=0 && x<R && y>=0 && y<C;
}

void travelBoard(int x, int y, int cnt, int alphaBit){
    alphaBit |= (1 << (board[x][y] - 'A'));
    cnt++;
    maxCnt = max(maxCnt, cnt);
    
    for(int d = 0; d<4; d++){
        int nx = x + dx[d];
        int ny = y + dy[d];
        if(!isRange(nx, ny))continue;

        if((alphaBit & (1 << (board[nx][ny] - 'A'))) == 0){
            travelBoard(nx, ny, cnt, alphaBit);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>R>>C;
    board.resize(R, vector<char>(C));


    for(int i = 0; i<R; i++){
        string str; cin>>str;
        for(int j = 0; j<C; j++){
            board[i][j] = str[j];
        }
    }

    vector<bool>alphaVec(26, false);
    vector<vector<bool>>visited(R, vector<bool>(C, false));
    int alphaBit = 0;

    travelBoard(0, 0, 0, alphaBit);

    cout<<maxCnt<<'\n';
    
}

