//g14503 로봇 청소기
#include <iostream>
#include <vector>
using namespace std;


int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

bool is_range(int x, int y, int n, int m){
    return x >= 0 && x < n && y >= 0 && y < m;
}

void solution_robot_cleaner(){
    int n, m; cin>>n>>m;
    vector<vector<int>>board(n, vector<int>(m, 0));
    int r, c, d; cin>>r>>c>>d;

    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            cin>>board[i][j];
            if(board[i][j] == 0)
                board[i][j] = 2;
        }
    }

    int x = r;
    int y = c;
    int cur_d = d;

    int answer = 0;
    
    bool process_flag = true;

    while(process_flag){
        if(board[x][y] == 2){
            answer++;
            board[x][y] = 0;
        }

        bool check_around = false;
        for(int d = 0; d<4; d++){
            int nx = x + dx[d];
            int ny = y + dy[d];
            if(!is_range(nx, ny, n, m))continue;
            if(board[nx][ny] == 0 || board[nx][ny] == 1)continue;
            check_around = true;
        }

        if(check_around){
            for(int d = 0; d<4; d++){
                int nxt_d = (cur_d + 3 - d) % 4;
                int nx = x + dx[nxt_d];
                int ny = y + dy[nxt_d];
                if(!is_range(nx, ny, n, m))continue;
                if(board[nx][ny] == 2){
                    x = nx;
                    y = ny;
                    cur_d = nxt_d;
                    break;
                }
            }
        }else{
            int nx = x + dx[(cur_d + 2)%4];
            int ny = y + dy[(cur_d + 2)%4];
            if(!is_range(nx, ny, n, m) || board[nx][ny] == 1){
                process_flag = false;
            }else{
                x = nx;
                y = ny;
            }
        }
    }
    cout<<answer<<endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solution_robot_cleaner();
    // int T; cin>>T;
    // while(T--){
    //     solution_robot_cleaner();
    // }
    return 0;
}



/*
2
3 3
1 1 0
1 1 1
1 0 1
1 1 1
11 10
7 4 0
1 1 1 1 1 1 1 1 1 1
1 0 0 0 0 0 0 0 0 1
1 0 0 0 1 1 1 1 0 1
1 0 0 1 1 0 0 0 0 1
1 0 1 1 0 0 0 0 0 1
1 0 0 0 0 0 0 0 0 1
1 0 0 0 0 0 0 1 0 1
1 0 0 0 0 0 1 1 0 1
1 0 0 0 0 0 1 1 0 1
1 0 0 0 0 0 0 0 0 1
1 1 1 1 1 1 1 1 1 1
*/
/*
1
57
*/