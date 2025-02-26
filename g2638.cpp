//g2638 치즈
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define endl '\n'
typedef pair<int,int> p;

int N, M;
vector<vector<int>>init_board;
vector<vector<int>>board;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

bool is_range(int x, int y){
    return x >= 0 && x < N && y >= 0 && y < M;
}


/*
한번 외곽 상태는 변하지 않는데 굳이 매번 탐색하는 로직을 거쳐야 하는지 의문!!!
*/
void check_out_space(){
    queue<p> q;
    vector<vector<bool>>visited(N, vector<bool>(M, false));
    visited[0][0] = false;
    q.push({0, 0});
    board[0][0] = 2;

    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for(int d = 0; d<4; d++){
            int nx = x + dx[d];
            int ny = y + dy[d];
            if(!is_range(nx, ny) || visited[nx][ny])continue;
            if(board[nx][ny] == 2 || board[nx][ny] == 1)continue;
            board[nx][ny] = 2;
            visited[nx][ny] = true;
            q.push({nx, ny});
        }
    }
}

void update_space(int sx, int sy){
    queue<p> q;
    vector<vector<bool>>visited(N, vector<bool>(M, false));

    visited[sx][sy] = true;
    q.push({sx, sy});
    board[sx][sy] = 2;
    

    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for(int d = 0; d<4; d++){
            int nx = x + dx[d];
            int ny = y + dy[d];
            if(!is_range(nx, ny) || visited[nx][ny] 
                        || board[nx][ny] != 0)continue;
            visited[nx][ny] = true;
            board[nx][ny] = 2;
            q.push({nx, ny});
        }
    }
}

void one_day_melt_cheese(){

    vector<p>update_pos;

    for(int i = 0; i<N; i++){
        for(int j = 0; j<M; j++){
            if(board[i][j] != 1)continue;
            int out_cnt = 0;;
            for(int d = 0; d<4; d++){
                int nx = i + dx[d];
                int ny = j + dy[d];
                if(!is_range(nx, ny) || board[nx][ny] != 2)continue;
                out_cnt++;
            }
            if(out_cnt >= 2){
                update_pos.push_back({i, j});
            }
        }
    }

    for(auto ele_node : update_pos){
        update_space(ele_node.first, ele_node.second);
    }
}

bool is_finish_board(){
    for(int i = 0; i<N; i++){
        for(int j = 0; j<M; j++){
            if(board[i][j] != 2)return false;
        }
    }
    return true;    
}

void print_board(){
    for(int i = 0; i<N; i++){
        for(int j = 0; j<M; j++){
            cout<<board[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}
void solution_cheese(){
    cin>>N>>M;
    init_board.resize(N, vector<int>(M, 0));
    board.resize(N, vector<int>(M, 0));

    for(int i = 0; i<N; i++){
        for(int j = 0; j<M; j++){
            cin>>init_board[i][j];
        }
    }
    board = init_board;
    check_out_space();

    //print_board();//test



    int T = 0;
    while(!is_finish_board()){
        one_day_melt_cheese();
        T++;

        //print_board();//test
    }
    cout<<T<<endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    solution_cheese();
    return 0;
}

/*
8 9
0 0 0 0 0 0 0 0 0
0 0 0 1 1 0 0 0 0
0 0 0 1 1 0 1 1 0
0 0 1 1 1 1 1 1 0
0 0 1 1 1 1 1 0 0
0 0 1 1 0 1 1 0 0
0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0

    -> 4
*/