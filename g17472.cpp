//g17472 다리 만들기 2
#include <iostream>
#include <vector>
using namespace std;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

struct ISLAND_DOT{
    int x, y;
};

void print_board(vector<vector<int>>&board){
    int N = board.size();
    int M = board[0].size();
    for(int i = 0; i<N; i++){
        for(int j = 0; j<M; j++){
            cout<<board[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}

bool is_range(int x, int y, int N, int M){
    return x >= 0 && x < N && y >= 0 && y < M;
}

void set_idx_island(int idx, int x, int y, vector<vector<int>>&board){
    int N = board.size();
    int M = board[0].size();

    for(int d = 0; d<4; d++){
        int nx = x + dx[d];
        int ny = y + dy[d];
        if(!is_range(nx, ny, N, M)) continue;
        if(board[nx][ny] != -1)continue;
        board[nx][ny] = idx;
        set_idx_island(idx, nx, ny, board);
    }
}

pair<int,int> find_min_dist_and_idx(vector<vector<int>>&board, 
                        vector<bool>&visited_island, vector<vector<ISLAND_DOT>>&island){
    pair<int,int>ret;
    int N = board.size(); int M = board[0].size();
    int get_idx = -1;
    int get_dist = -1;

    vector<ISLAND_DOT>candidates;
    for(int i = 1; i<island.size(); i++){
        if(!visited_island[i])continue;
        for(auto ele : island[i]){
            candidates.push_back(ele);
        }
    }

    for(ISLAND_DOT dot : candidates){
        int x = dot.x;
        int y = dot.y;

        for(int d = 0; d<4; d++){
            int nx = x + dx[d];
            int ny = y + dy[d];
            while(is_range(nx, ny, N, M)){
                if(board[nx][ny] != 0){
                    if(visited_island[board[nx][ny]] == false){
                        int cur_dist = abs(nx - x) + abs(ny - y) - 1;
                        if(cur_dist < 2)break;
                        if(get_dist == -1 || get_dist > cur_dist){
                            get_dist = cur_dist;
                            get_idx = board[nx][ny];
                        }
                    }
                    break;
                }
                nx += dx[d];
                ny += dy[d];
            }
        }
    }
    return {get_idx, get_dist};
}

void solution_building_bridge(){
    int N, M; cin>>N>>M;
    vector<vector<int>>board(N, vector<int>(M, 0));

    for(int i = 0; i<N; i++){
        for(int j = 0; j<M; j++){
            cin>>board[i][j];
            if(board[i][j] == 1)board[i][j] = -1;
        }
    }

    int cnt_idx = 1;
    
    for(int i = 0; i<N; i++){
        for(int j = 0; j<M; j++){
            if(board[i][j] == -1){
                board[i][j] = cnt_idx;
                set_idx_island(cnt_idx, i, j, board);
                cnt_idx++;
            }
        }
    }
    int island_cnt = cnt_idx - 1;
    
    vector<vector<ISLAND_DOT>> islands(island_cnt + 1);
    for(int i = 0; i<N; i++){
        for(int j = 0; j<M; j++){
            if(board[i][j] > 0){
                ISLAND_DOT dot;
                dot.x = i;
                dot.y = j;
                islands[board[i][j]].push_back(dot);
            }
        }
    }

    vector<bool>visited_island(island_cnt + 1, false);
    visited_island[0] = true;
    visited_island[1] = true;

    int tmp_cnt_down = visited_island.size() - 2;
    bool wrong_board = false;
    bool end_flag = false;
    int tot_bridge_dist = 0;

    while(tmp_cnt_down-- 
        // && !end_flag
    ){
        pair<int,int>tmp_ret = find_min_dist_and_idx(board, visited_island, islands);
        if(tmp_ret.first != -1){
            tot_bridge_dist += tmp_ret.second;
            visited_island[tmp_ret.first] = true;
        }else{
            wrong_board = true;
            break;
        }
    }
    if(wrong_board)tot_bridge_dist = -1;
    cout<<tot_bridge_dist<<endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solution_building_bridge();

    // int T; cin>>T;
    // while(T--){
    //     solution_building_bridge();
    // }

    return 0;
}

/*
4
7 8
0 0 0 0 0 0 1 1
1 1 0 0 0 0 1 1
1 1 0 0 0 0 0 0
1 1 0 0 0 1 1 0
0 0 0 0 0 1 1 0
0 0 0 0 0 0 0 0
1 1 1 1 1 1 1 1
7 8
0 0 0 1 1 0 0 0
0 0 0 1 1 0 0 0
1 1 0 0 0 0 1 1
1 1 0 0 0 0 1 1
1 1 0 0 0 0 0 0
0 0 0 0 0 0 0 0
1 1 1 1 1 1 1 1
7 8
1 0 0 1 1 1 0 0
0 0 1 0 0 0 1 1
0 0 1 0 0 0 1 1
0 0 1 1 1 0 0 0
0 0 0 0 0 0 0 0
0 1 1 1 0 0 0 0
1 1 1 1 1 1 0 0
7 7
1 1 1 0 1 1 1
1 1 1 0 1 1 1
1 1 1 0 1 1 1
0 0 0 0 0 0 0
1 1 1 0 1 1 1
1 1 1 0 1 1 1
1 1 1 0 1 1 1
*/

/*
9
10
9
-1
*/