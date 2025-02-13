//g17144번 미세먼지 안녕!
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

typedef pair<int,int> p;

int N, M, T;
vector<vector<int>>room;
p a, b;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

bool is_range(int x, int y){
    return x >= 0 && x < N && y >= 0 && y < M;
}

vector<p> find_dust(vector<vector<int>>cur_room){
    vector<p>ret;
    for(int i = 0; i<N; i++){
        for(int j = 0; j<M; j++){
            if(cur_room[i][j] != 0 && cur_room[i][j] != -1){
                ret.push_back({i, j});
            }
        }
    }
    return ret; 
}

void copy_vector(vector<vector<int>>&pre, vector<vector<int>>&nxt){
    for(int i = 0; i<N; i++){
        for(int j = 0; j<M; j++){
            nxt[i][j] = pre[i][j];
        }
    }
}
void print_vec(vector<vector<int>>board){
    int N = board.size();
    int M = board[0].size();
    for(int i = 0; i<N; i++){
        for(int j = 0; j<M; j++){
            cout<<board[i][j]<<" ";
        }
        cout<<endl;
    }
}

void spread_dust(vector<p>dust_set){
    vector<vector<int>>new_room(N, vector<int>(M, 0));
    new_room[a.first][a.second] = -1;
    new_room[b.first][b.second] = -1;

    for(auto cur_dust : dust_set){
        int x = cur_dust.first;
        int y = cur_dust.second;
        int cur_dust_capa = room[x][y];

        int send_dust = 0;

        for(int d = 0; d<4; d++){
            int nx = x + dx[d];
            int ny = y + dy[d];
            if(!is_range(nx, ny))continue;
            if(room[nx][ny] == -1)continue;
            
            new_room[nx][ny] += (cur_dust_capa/5);
            send_dust += cur_dust_capa/5;
        }
        new_room[x][y] += (room[x][y] - send_dust);
    }
    copy_vector(new_room, room);
}

void clean_dust_anticlock(){
    //a.first, 0, 0, M-1
    //b.first, N-1, 0, M-1

    //upper side
    int cur_x = a.first-1;
    int cur_y = 0;
    while(cur_x){
        int nxt_x = cur_x - 1;
        int nxt_y = 0;
        room[cur_x][cur_y] = room[nxt_x][nxt_y];
        cur_x = nxt_x;
        cur_y = nxt_y;
    }
    //{0, 0}
    while(cur_y < M-1){
        int nxt_x = 0;
        int nxt_y = cur_y + 1;
        room[cur_x][cur_y] = room[nxt_x][nxt_y];
        cur_x = nxt_x;
        cur_y = nxt_y;
    }
    //{0, M-1}
    while(cur_x < a.first){
        int nxt_x = cur_x + 1;
        int nxt_y = M-1;
        room[cur_x][cur_y] = room[nxt_x][nxt_y];
        cur_x = nxt_x;
        cur_y = nxt_y;
    }
    //{a.first, M-1}
    while(cur_y > 1){
        int nxt_x = a.first;
        int nxt_y = cur_y - 1;
        room[cur_x][cur_y] = room[nxt_x][nxt_y];
        cur_x = nxt_x;
        cur_y = nxt_y;
    }
    room[a.first][1] = 0;
}

void clean_dust_clock(){
        //a.first, 0, 0, M-1
    //b.first, N-1, 0, M-1

    //upper side
    int cur_x = b.first+1;
    int cur_y = 0;
    while(cur_x < N-1){
        int nxt_x = cur_x + 1;
        int nxt_y = 0;
        room[cur_x][cur_y] = room[nxt_x][nxt_y];
        cur_x = nxt_x;
        cur_y = nxt_y;
    }
    //{N-1, 0}
    while(cur_y < M-1){
        int nxt_x = N-1;
        int nxt_y = cur_y + 1;
        room[cur_x][cur_y] = room[nxt_x][nxt_y];
        cur_x = nxt_x;
        cur_y = nxt_y;
    }
    //{0, M-1}
    while(cur_x > b.first){
        int nxt_x = cur_x - 1;
        int nxt_y = M-1;
        room[cur_x][cur_y] = room[nxt_x][nxt_y];
        cur_x = nxt_x;
        cur_y = nxt_y;
    }
    //{a.first, M-1}
    while(cur_y > 1){
        int nxt_x = b.first;
        int nxt_y = cur_y - 1;
        room[cur_x][cur_y] = room[nxt_x][nxt_y];
        cur_x = nxt_x;
        cur_y = nxt_y;
    }
    room[b.first][1] = 0;
}

int dust_sum(){
    int ret = 0;
    for(int i = 0; i<N; i++){
        for(int j = 0; j<M; j++){
            if(room[i][j] != -1)
                ret += room[i][j];
        }
    }
    return ret;
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin>>N>>M>>T;

    room.resize(N, vector<int>(M));
    vector<p>dust_set;

    for(int i = 0; i<N; i++){
        for(int j = 0; j<M; j++){
            cin>>room[i][j];
            if(room[i][j] == -1){
                b.first = i;
                b.second = 0;
            }
            else if(room[i][j] != 0){
                dust_set.push_back({i, j});
            }
        }
    }
    a.first = b.first - 1;
    a.second = 0;

    while(T--){
        //print_vec(room);//test
        spread_dust(find_dust(room));
        clean_dust_anticlock();
        clean_dust_clock();
        //cout<<endl;//test
    }
    //print_vec(room);
    cout<<dust_sum()<<endl;
}
