//g3109 빵집
#include <iostream>
#include <vector>
using namespace std;

#define endl '\n'

int dx[3] = {-1, 0, 1};
int dy[3] = {1, 1, 1};

bool is_range(int x, int y, int n, int m){
    return x >= 0 && x < n && y >= 0 && y < m;
}

bool is_pos_route(int x, int y, vector<vector<char>>& board, vector<vector<bool>>&visited){
    int n = board.size();
    int m = board[0].size();
    if(y == m-1){
        return true;
    }
    for(int d = 0; d<3; d++){
        int nx = x + dx[d];
        int ny = y + dy[d];
        if(!is_range(nx, ny, n, m))continue;
        if(visited[nx][ny])continue;
        if(board[nx][ny] == 'x')continue;
        
        visited[nx][ny] = true;
        bool next_ret = is_pos_route(nx, ny, board, visited);
        if(next_ret)return true;
    }
    return false;
}

void print_visited(vector<vector<bool>>&visited){
    int n = visited.size();
    int m = visited[0].size();
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            cout<<visited[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}

void solution_bread_house(){
    int r, c; cin>>r>>c;

    vector<vector<char>>board(r, vector<char>(c, '.'));
    for(int i = 0; i<r; i++){
        string str; cin>>str;
        for(int j = 0; j<c; j++){
            board[i][j] = str[j];
        }
    }

    
    vector<vector<bool>>visited(r, vector<bool>(c, false));

    int answer = 0;
    for(int i = 0; i<r; i++){
        
        if(is_pos_route(i, 0, board, visited)){
            answer++;
        }
        //print_visited(visited);//test
    }
    cout<<answer<<endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solution_bread_house();

    // int T; cin>>T;
    // while(T--){
    //     solution_bread_house();
    // }
    return 0;
}

/*
2
5 5
.xx..
..x..
.....
...x.
...x.
6 10
..x.......
.....x....
.x....x...
...x...xx.
..........
....x.....
*/
/*
2
5
*/