//g17135 캐슬 디펜스
#include <iostream>
#include <vector>
#include <queue>
#include <set>
using namespace std;


int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, -1, 0, 1};

bool is_range(int x, int y, int N, int M){
    return x >= 0 && x < N && y >= 0 && y < M;
}

pair<int,int> find_min_dist(int x, vector<vector<int>>&board, int D){
    int n = board.size();
    int m = board[0].size();
    if(board[n-1][x] == 1){
        return {n-1, x};
    }

    vector<vector<int>>dist_board(n, vector<int>(m, -1));
    queue<pair<int,int>>q;
    
    dist_board[n-1][x] = 1;
    q.push({n-1, x});

    while(!q.empty()){
        int cx = q.front().first;
        int cy = q.front().second;
        q.pop();
        
        for(int d = 1; d<4; d++){
            int nx = cx + dx[d];
            int ny = cy + dy[d];
            if(!is_range(nx, ny, n, m))continue;
            if(dist_board[nx][ny] >= 0)continue;
            
            dist_board[nx][ny] = dist_board[cx][cy] + 1;
            if(dist_board[nx][ny] > D)continue;

            if(board[nx][ny] == 1){
                return {nx, ny};
            }
            q.push({nx, ny});
        }
    }
    return {-1, -1};
}


int find_max_count(int x, int y, int z, vector<vector<int>>&board, int D){
    int n = board.size();
    int m = board[0].size();

    int ret = 0;

    for(int i = n-1; i >= 0; i--){
        pair<int,int> px = find_min_dist(x, board, D);
        pair<int,int> py = find_min_dist(y, board, D);
        pair<int,int> pz = find_min_dist(z, board, D);
        
        if(px.first != -1 && board[px.first][px.second] == 1){
            board[px.first][px.second] = 0;
            ret++;
        }
        if(py.first != -1 && board[py.first][py.second] == 1){
            board[py.first][py.second] = 0;
            ret++;
        }
        if(pz.first != -1 && board[pz.first][pz.second] == 1){
            board[pz.first][pz.second] = 0;
            ret++;
        }
        
        
        for(int r = n-1; r > 0; r--){
            for(int c = 0; c<m; c++){
                board[r][c] = board[r-1][c];
            }
        }
        for(int j = 0; j<m; j++){
            board[0][j] = 0;
        }
    }
    return ret;
}




void solution_castle_depence(){
    int N, M, D;
    cin>>N>>M>>D;
    
    vector<vector<int>>board(N, vector<int>(M));

    for(int i = 0; i<N; i++){
        for(int j = 0; j<M; j++){
            cin>>board[i][j];
        }
    }

    int answer = 0;

    for(int i = 0; i<M; i++){
        for(int j = i+1; j<M; j++){
            for(int k = j+1; k<M; k++){
                vector<vector<int>>tmp_board = board;
                answer = max(answer, find_max_count(i, j, k, tmp_board, D));
            }
        }
    }

    cout<<answer<<endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solution_castle_depence();
    // int T; cin>>T;
    // while(T--){
    //     solution_castle_depence();
    // }

    return 0;
}
/*
6
5 5 1
0 0 0 0 0
0 0 0 0 0
0 0 0 0 0
0 0 0 0 0
1 1 1 1 1
5 5 1
0 0 0 0 0
0 0 0 0 0
0 0 0 0 0
1 1 1 1 1
0 0 0 0 0
5 5 2
0 0 0 0 0
0 0 0 0 0
0 0 0 0 0
1 1 1 1 1
0 0 0 0 0
5 5 5
1 1 1 1 1
1 1 1 1 1
1 1 1 1 1
1 1 1 1 1
1 1 1 1 1
6 5 1
1 0 1 0 1
0 1 0 1 0
1 1 0 0 0
0 0 0 1 1
1 1 0 1 1
0 0 1 0 0
6 5 2
1 0 1 0 1
0 1 0 1 0
1 1 0 0 0
0 0 0 1 1
1 1 0 1 1
0 0 1 0 0
*/
/*
3
3
5
15
9
14
*/