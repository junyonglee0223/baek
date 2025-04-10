//s21736 헌내기는 친구가 필요해
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define endl '\n'

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

bool is_range(int x, int y, int n, int m){
    return x >= 0 && x<n && y >= 0 && y < m;
}

void solution_need_friends(){
    int n, m;
    cin>>n>>m;

    int start_x = -1;
    int start_y = -1;
    vector<vector<int>>board(n, vector<int>(m));


    for(int i = 0; i<n; i++){
        string str; cin>>str;
        for(int j = 0; j<m; j++){
            if(str[j] == 'O'){
                board[i][j] = 0;
            }    
            else if(str[j] == 'P'){
                board[i][j] = 1;
            }    
            else if(str[j] == 'X'){
                board[i][j] = -1;
            }
            else if(str[j] == 'I'){
                start_x = i;
                start_y = j;
            }
        }    
    }    

    
    int answer = 0;
    
    vector<vector<int>>p_board = board;
    queue<pair<int,int>>q;
    q.push({start_x, start_y});
    p_board[start_x][start_y] = -1;

    while(!q.empty()){
        int cx = q.front().first;
        int cy = q.front().second;
        q.pop();

        for(int d = 0; d<4; d++){
            int nx = cx + dx[d];
            int ny = cy + dy[d];
            if(!is_range(nx, ny, n, m))continue;
            if(p_board[nx][ny] < 0)continue;

            if(p_board[nx][ny] == 1){
                answer++;
            }
            q.push({nx, ny});
            p_board[nx][ny] = -1;
        }
    }
    if(answer == 0){
        cout<<"TT"<<endl;
    }
    else{
        cout<<answer<<endl;
    }
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solution_need_friends();

    // int T; cin>>T;
    // while(T--){
    //     solution_need_friends();
    // }

    return 0;
}

/*
2
3 5
OOOPO
OIOOX
OOOXP
3 3
IOX
OXP
XPP
*/

/*
1
TT
*/