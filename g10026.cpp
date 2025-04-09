//g10026 적록색약
#include <iostream>
#include <vector>
#include <queue>
using namespace std;


#define endl '\n'

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

bool is_range(int x, int y, int N){
    return x >= 0 && x < N && y >= 0 && y < N;
}


void set_bfs_visited(int x, int y, vector<vector<char>>&board, vector<vector<bool>>&visited){
    int n = board.size();
    char c = board[x][y];
    queue<pair<int,int>> q;
    q.push({x, y});
    visited[x][y] = true;

    while(!q.empty()){
        int cx = q.front().first;
        int cy = q.front().second;
        q.pop();

        for(int d = 0; d < 4; d++){
            int nx = cx + dx[d];
            int ny = cy + dy[d];
            if(!is_range(nx, ny, n))continue;
            if(visited[nx][ny])continue;
            if(board[nx][ny] != c)continue;

            visited[nx][ny] = true;
            q.push({nx, ny});
        }
    }
}


int normal_board_count(vector<vector<char>>&board){
    int ret = 0;
    int n = board.size();
    vector<vector<bool>>visited(n, vector<bool>(n, false));

    
    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            if(!visited[i][j]){
                set_bfs_visited(i, j, board, visited);
                ret++;
            }
        }
    }

    return ret;
}

int blindness_board_count(vector<vector<char>>&board){
    int ret = 0;
    int n = board.size();
    vector<vector<char>>new_board = board;

    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            if(board[i][j] == 'G'){
                new_board[i][j] = 'R';
            }
        }
    }
    ret = normal_board_count(new_board);

    return ret;
}


void solution_red_green_color_blindness(){
    int N; cin>>N;
    vector<vector<char>>board(N, vector<char>(N));

    for(int i = 0; i<N; i++){
        string str; cin>>str;
        for(int j = 0; j<N; j++){
            board[i][j] = str[j];
        }
    }

    // set_board_group(board);
    // vector<vector<int>>adj(cnt);

    cout<<normal_board_count(board)<<" ";
    cout<<blindness_board_count(board)<<endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solution_red_green_color_blindness();

    return 0;
}


/*
5
RRRBB
GGBBB
BBBRR
BBRRR
RRRRR
*/
/*
4 3
*/