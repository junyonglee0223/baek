#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int MAX_B;

int dx[2] = {1, 0};
int dy[2] = {0, 1};
int N;
vector<vector<int>>BOARD;

bool out_range(int x, int y){
    return !(x >= 0 && x < N && y >= 0 && y < N);
}

vector<vector<int>>CACHE;

int dfs_board_v1(int x, int y){
    if(x == N-1 && y == N-1){
        return (CACHE[x][y] = 0);
    }

    int& ret = CACHE[x][y];
    if(ret != -1)return ret;
    ret = 1e9;

    for(int d = 0; d<2; d++){
        int nx = x + dx[d];
        int ny = y + dy[d];

        if(out_range(nx, ny))continue;

        int tmp_ret = dfs_board_v1(nx, ny);
        if(BOARD[nx][ny] >= BOARD[x][y]){
            tmp_ret += (abs(BOARD[nx][ny] - BOARD[x][y]) + 1);
        }

        ret = min(ret, tmp_ret);
    }
    return ret;
}


int solution_escape_array(int n, vector<vector<int>>&board){

    N = n;
    BOARD = board;
    MAX_B = 1e9;

    CACHE.resize(n, vector<int>(n, -1));

    return dfs_board_v1(0, 0);
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin>>n;
    vector<vector<int>>board(n, vector<int>(n));
    for(int i = 0; i<n ;i++){
        for(int j = 0; j<n; j++){
            cin>>board[i][j];
        }
    }

    cout << solution_escape_array(n, board) << "\n";

    return 0;
}