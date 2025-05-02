//g1937 욕심쟁이 판다
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define endl '\n'
#define MAX_VAL 1000001

int n;
vector<vector<int>> board;
vector<vector<int>> dp;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

bool is_range(int x, int y){
    return x >= 0 && x < n && y >= 0 && y < n;
}

int max_dfs_pnt(int x, int y){
    int& ret = dp[x][y];
    if(ret != -1)return ret;

    ret = 1;

    for(int d = 0; d < 4; d++){
        int nx = x + dx[d];
        int ny = y + dy[d];
        if(!is_range(nx, ny))continue;
        if(board[nx][ny] <= board[x][y])continue;
        ret = max(ret, max_dfs_pnt(nx, ny) + 1);
    }
    return ret;
}

void solution_greedy_panda(){
    board.clear();
    dp.clear();

    cin >> n;
    board.resize(n, vector<int>(n));
    dp.resize(n, vector<int>(n, -1));

    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            cin>>board[i][j];
        }
    }

    int answer = 0;
    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            answer = max(answer, max_dfs_pnt(i, j));
        }
    }
    cout<<answer<<endl;
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solution_greedy_panda();

    return 0;
}


/*
4
14 9 12 10
1 11 5 4
7 15 2 13
6 3 16 8
*/
/*
4
*/