//s4963 섬의 개수
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define endl '\n'

typedef pair<int,int> p;

int dx[8] = {1, 1, 0, -1, -1, -1, 0, 1};
int dy[8] = {0, 1, 1, 1, 0, -1, -1, -1};


bool is_range(int x, int y, int n, int m){
    return x >= 0 && x < n && y >= 0 && y < m;
}

void set_island_visited(int x, int y, 
    vector<vector<bool>>&visited, vector<vector<int>>&board){
    int n = board.size();
    int m = board[0].size();
    queue<p>q;

    q.push({x, y});
    visited[x][y] = true;

    while(!q.empty()){
        int cx = q.front().first;
        int cy = q.front().second;
        q.pop();

        for(int d = 0; d<8; d++){
            int nx = cx + dx[d];
            int ny = cy + dy[d];

            if(!is_range(nx, ny, n, m))continue;
            if(visited[nx][ny])continue;
            if(board[nx][ny] == 0)continue;

            visited[nx][ny] = true;
            q.push({nx, ny});
        }
    }
}

int get_islands_count(vector<vector<int>>&board){
    int n = board.size();
    int m = board[0].size();

    vector<vector<bool>>visited(n, vector<bool>(m, false));

    int ret = 0;
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            if(board[i][j] == 1 && visited[i][j] == false){
                ret++;
                set_island_visited(i, j, visited, board);
            }
        }
    }

    return ret;
}

void solution_island_count(){

    int N, M;
    cin>>M>>N;
    while(N != 0 && M != 0){
        vector<vector<int>>board(N, vector<int>(M, 0));

        for(int i = 0; i<N; i++){
            for(int j = 0; j<M; j++){
                cin>>board[i][j];
            }
        }

        int answer = get_islands_count(board);
        cout<<answer<<endl;

        cin>>M>>N;
    }

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solution_island_count();

    return 0;
}


/*
1 1
0
2 2
0 1
1 0
3 2
1 1 1
1 1 1
5 4
1 0 1 0 0
1 0 0 0 0
1 0 1 0 1
1 0 0 1 0
5 4
1 1 1 0 1
1 0 1 0 1
1 0 1 0 1
1 0 1 1 1
5 5
1 0 1 0 1
0 0 0 0 0
1 0 1 0 1
0 0 0 0 0
1 0 1 0 1
0 0
*/

/*
0
1
1
3
1
9
*/