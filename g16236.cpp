//g16236 아기 상어
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <climits>
using namespace std;

#define endl '\n'

int N;
vector<vector<int>>board;

bool is_range(int x, int y){
    return x >= 0 && x < N && y >= 0 && y < N;
}

bool is_pos(int size){
    for(int i = 0; i<N; i++){
        for(int j = 0; j<N; j++){
            if(board[i][j] != 0 && board[i][j] < size){
                return true;
            }
        }
    }
    return false;
}



int dx[4] = {-1, 0, 0, 1};
int dy[4] = {0, -1, 1, 0};

pair<int,int>find_pos_v1(int x, int y, int size, int &dist){
    vector<vector<int>>dist_board(N, vector<int>(N, 0));
    queue<pair<int,int>>q;
    q.push({x, y});
    vector<pair<int,int>>candidates;

    int tmp_dist = INT_MAX;

    while(!q.empty()){
        int c_x = q.front().first;
        int c_y = q.front().second;
        q.pop();
        for(int d = 0; d<4; d++){
            int n_x = c_x + dx[d];
            int n_y = c_y + dy[d];
            if(!is_range(n_x, n_y))continue;
            if(dist_board[n_x][n_y] != 0 || (n_x == x && n_y == y))continue;
            if(board[n_x][n_y] > size)continue;
            
            dist_board[n_x][n_y] = dist_board[c_x][c_y] + 1;

            if(dist_board[n_x][n_y] > tmp_dist)continue;
            if(board[n_x][n_y] != 0 && board[n_x][n_y] < size){
                //dist = dist_board[n_x][n_y];
                tmp_dist = min(tmp_dist, dist_board[n_x][n_y]);
                candidates.push_back({n_x, n_y});
                continue;
            }
            q.push({n_x, n_y});
        }
    }
    if(!candidates.empty()){
        sort(candidates.begin(), candidates.end());
        dist = tmp_dist;
        return {candidates[0].first, candidates[0].second};
    }
    dist = -1;
    return {-1, -1};
}

void print_board(){
    for(int i = 0; i<N; i++){
        for(int j = 0; j<N; j++){
            cout<<board[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}

void solution_baby_shark(){
    board.clear();

    cin>>N;
    board.resize(N, vector<int>(N, 0));

    int s_x, s_y;
    for(int i =0 ; i<N; i++){
        for(int j = 0; j<N; j++){
            cin>>board[i][j];
            if(board[i][j] == 9){
                board[i][j] = 0;
                s_x = i;
                s_y = j;
            }
        }
    }

    int size = 2;
    int eat_cnt = 0;
    int answer = 0;
    while(true){
        int dist = 0;
        pair<int,int> n_p = find_pos_v1(s_x, s_y, size, dist);
        if(dist == -1)break;//test
        if(dist != -1){
            board[n_p.first][n_p.second] = 0;
            s_x = n_p.first;
            s_y = n_p.second;
            eat_cnt++;
            if(eat_cnt == size){
                size++;
                eat_cnt = 0;
            }
            answer += dist;
        }

    }

    cout<<answer<<endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    solution_baby_shark();

    // int T; cin>>T;
    // while(T--){
    //     solution_baby_shark();
    // }

}

/*
0
3
14
60
48
39
*/

/*
6
3
0 0 0
0 0 0
0 9 0
3
0 0 1
0 0 0
0 9 0
4
4 3 2 1
0 0 0 0
0 0 9 0
1 2 3 4
6
5 4 3 2 3 4
4 3 2 3 4 5
3 2 9 5 6 6
2 1 2 3 4 5
3 2 1 6 5 4
6 6 6 6 6 6
6
6 0 6 0 6 1
0 0 0 0 0 2
2 3 4 5 6 6
0 0 0 0 0 2
0 2 0 0 0 0
3 9 3 0 0 1
6
1 1 1 1 1 1
2 2 6 2 2 3
2 2 5 2 2 3
2 2 2 4 6 3
0 0 0 0 0 6
0 0 0 0 0 9



*/
