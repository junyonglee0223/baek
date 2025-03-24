//g2146 다리 만들기
#include <iostream>
#include <vector>
#include <queue>
using namespace std;


vector<vector<pair<int,int>>>island_group;
vector<vector<int>>board;
int N;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1}; 

bool is_range(int x, int y){
    return x >= 0 && x < N && y >= 0 && y < N;
}
// bool is_edge(int x, int y){
//     for(int d = 0; d<4; d++){
//         int nx = x + dx[d];
//         int ny = y + dy[d];
//         if(is_range(nx, ny) == false)continue;
//         if(board[nx][ny] == 0)return true;
//     }
//     return false;
// }

vector<pair<int,int>> set_island(int x, int y, vector<vector<bool>>& visited){
    vector<pair<int,int>>ret;
    queue<pair<int,int>>q;

    visited[x][y] = true;
    ret.push_back({x, y});
    q.push({x, y});

    while(!q.empty()){
        pair<int,int> c_p = q.front();
        int cx = c_p.first;
        int cy = c_p.second;
        q.pop();

        for(int d = 0; d<4; d++){
            int nx = cx + dx[d];
            int ny = cy + dy[d];

            if(!is_range(nx, ny))continue;
            if(board[nx][ny] == 0)continue;
            if(visited[nx][ny] == true)continue;

            visited[nx][ny] = true;
            q.push({nx, ny});
            ret.push_back({nx, ny});
        }
    }
    return ret;
}

int menhatan_dist(vector<pair<int,int>>& a, vector<pair<int,int>>& b){
    int sa = a.size();
    int sb = b.size();

    int ret = 2 * N + 1;
    for(int i = 0; i<sa; i++){
        for(int j = 0; j<sb; j++){
            int tmp = abs(a[i].first - b[j].first) + abs(a[i].second - b[j].second);
            ret = min(ret, tmp);
        }
    }
    return ret;
}


void solution_constructure_bridge(){
    island_group.clear();
    board.clear();

    cin>>N;
    board.resize(N, vector<int>(N));

    for(int i = 0; i<N; i++){
        for(int j = 0; j<N; j++){
            cin>>board[i][j];
        }
    }
    
    vector<vector<bool>>visited(N, vector<bool>(N, false));
    for(int i = 0; i<N; i++){
        for(int j = 0; j<N; j++){
            if(board[i][j] == 0)continue;
            if(visited[i][j] == true)continue;

            vector<pair<int,int>>tmp = set_island(i, j, visited);
            island_group.push_back(tmp);
        }
    } 
    int g_n = island_group.size();


    int answer = 2 * N + 1;

    for(int i = 0; i<g_n; i++){
        for(int j = i+1; j<g_n; j++){
            answer = min(answer, menhatan_dist(island_group[i], island_group[j]));
        }
    }
    cout<<answer - 1<<endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solution_constructure_bridge();

    return 0;
}

/*

10
1 1 1 0 0 0 0 1 1 1
1 1 1 1 0 0 0 0 1 1
1 0 1 1 0 0 0 0 1 1
0 0 1 1 1 0 0 0 0 1
0 0 0 1 0 0 0 0 0 1
0 0 0 0 0 0 0 0 0 1
0 0 0 0 0 0 0 0 0 0
0 0 0 0 1 1 0 0 0 0
0 0 0 0 1 1 1 0 0 0
0 0 0 0 0 0 0 0 0 0
*/