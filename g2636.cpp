//g2636 치즈
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

bool is_range(int x, int y, int N, int M){
    return x >= 0 && x < N && y >= 0 && y < M;
}

int is_melting(vector<vector<int>>&board){
    int ret = 0;
    for(int i = 0; i<board.size(); i++){
        for(int j = 0; j<board[0].size(); j++){
            if(board[i][j] == 1)ret++;
        }
    }
    return ret;
}

void set_air(vector<vector<int>>&board){
    int N = board.size();
    int M = board[0].size();

    vector<vector<bool>>visited(N, vector<bool>(M, false));
    queue<pair<int,int>>q;

    board[0][0] = 2;
    visited[0][0] = true;
    q.push({0, 0});
    while(!q.empty()){
        int cx = q.front().first;
        int cy = q.front().second;
        q.pop();
        for(int d = 0; d<4; d++){
            int nx = cx + dx[d];
            int ny = cy + dy[d];
            if(!is_range(nx, ny, N, M))continue;
            if(visited[nx][ny])continue;
            if(board[nx][ny] != 1){
                visited[nx][ny] = true;
                board[nx][ny] = 2;
                q.push({nx, ny});
            }
        }
    }
}

vector<pair<int,int>> melt_candidates (vector<vector<int>>&board){
    int N = board.size();
    int M = board[0].size();

    vector<pair<int,int>>ret;
    vector<vector<bool>>visited(N, vector<bool>(M, false));

    for(int i = 0; i<N; i++){
        for(int j = 0; j<M; j++){
            if(board[i][j] == 1){
                for(int d = 0; d<4; d++){
                    int nx = i + dx[d];
                    int ny = j + dy[d];
                    if(!is_range(nx, ny, N, M))continue;
                    if(board[nx][ny] == 2){
                        ret.push_back({i, j});
                        break;
                    }
                }
            }
        }
    }
    return ret;
}

pair<int,int> how_much_time_melted(vector<vector<int>>&board){
    int T = 0;

    int cnt = is_melting(board);
    int last_cnt = cnt;
    while(cnt > 0){
        //set air
        set_air(board);

        //melt candidate
        vector<pair<int,int>>nxt_melt = melt_candidates(board);
        int melt_cnt = nxt_melt.size();

        //melt
        for(auto ele : nxt_melt){
            int x = ele.first;
            int y = ele.second;
            board[x][y] = 2;
        }

        //check count
        //update count, time
        if(cnt - melt_cnt == 0){
            last_cnt = cnt;
        }
        cnt -= melt_cnt;
        T++;
    }

    return {T, last_cnt};
}

void solution_cheese(){
    int N, M; cin>>N>>M;
    vector<vector<int>>board(N, vector<int>(M, 0));
    for(int i = 0; i<N; i++){
        for(int j = 0; j<M; j++){
            cin>>board[i][j];
        }
    }

    pair<int,int>ret = how_much_time_melted(board);
    cout<<ret.first<<endl;
    cout<<ret.second<<endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solution_cheese();

    return 0;
}


/*
13 12
0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 1 1 0 0 0
0 1 1 1 0 0 0 1 1 0 0 0
0 1 1 1 1 1 1 0 0 0 0 0
0 1 1 1 1 1 0 1 1 0 0 0
0 1 1 1 1 0 0 1 1 0 0 0
0 0 1 1 0 0 0 1 1 0 0 0
0 0 1 1 1 1 1 1 1 0 0 0
0 0 1 1 1 1 1 1 1 0 0 0
0 0 1 1 1 1 1 1 1 0 0 0
0 0 1 1 1 1 1 1 1 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0
*/
/*
3
5
*/