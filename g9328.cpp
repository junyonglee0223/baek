//g9328 열쇠
#include <iostream>
#include <vector>
#include <queue>
#include <string>
using namespace std;

#define endl '\n'

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

void print_char_board(vector<vector<char>>&board){
    int n = board.size();
    int m = board[0].size();
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            cout<<board[i][j]<<" ";
        }
        cout<<endl;
    }
}


int find_max_documents(vector<vector<char>>&board, vector<bool>&is_key){
    int answer = 0;
    int n = board.size();
    int m = board[0].size();

    queue<pair<int,int>>q;
    vector<queue<pair<int,int>>>door_q(26);

    vector<vector<bool>>visited(n, vector<bool>(m, false));

    q.push({0, 0});
    visited[0][0] = true;

    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for(int d = 0; d<4; d++){
            int nx = x + dx[d];
            int ny = y + dy[d];
            if(nx < 0 || nx >= n || ny < 0 || ny >= m)continue;
            if(visited[nx][ny])continue;
            visited[nx][ny] = true;

            if(board[nx][ny] == '$'){
                answer++;
            }
            else if(board[nx][ny] >= 'a' && board[nx][ny] <= 'z'){
                is_key[board[nx][ny] - 'a'] = true;
                while(!door_q[board[nx][ny] - 'a'].empty()){
                    q.push({door_q[board[nx][ny]-'a'].front()});
                    door_q[board[nx][ny] - 'a'].pop();
                }
            }
            else if(board[nx][ny] >= 'A' && board[nx][ny] <= 'Z'){
                if(!is_key[board[nx][ny] - 'A']){
                    door_q[board[nx][ny] - 'A'].push({nx, ny});
                    continue;
                }
            }
            else if(board[nx][ny] == '*'){
                continue;
            }
            q.push({nx, ny});
        }
    }
    return answer;
}

void solution_get_maximum_docu(){
    int n, m;
    cin>>n>>m;

    //set 1 - 27
    vector<bool>is_key(26, false);

    vector<vector<char>>board(n+2, vector<char>(m+2, '.'));
    vector<pair<int,int>>start_pnts;

    for(int i = 1; i<=n; i++){
        string str; cin>>str;
        for(int j = 1; j<=m; j++){
            board[i][j] = str[j-1];
        }
    }
    string have_key;
    cin>>have_key;

    if(have_key != "0"){
        for(int i = 0; i<have_key.size(); i++){
            is_key[have_key[i] - 'a'] = true;
        }
    }
    cout<<find_max_documents(board, is_key)<<endl;
    // print_char_board(board);//test
    // cout<<endl;//test
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int T; cin>>T;
    while(T--){
        solution_get_maximum_docu();
    }
    return 0;
}

/*
3
5 17
*****************
.............**$*
*B*A*P*C**X*Y*.X.
*y*x*a*p**$*$**$*
*****************
cz
5 11
*.*********
*...*...*x*
*X*.*.*.*.*
*$*...*...*
***********
0
7 7
*ABCDE*
X.....F
W.$$$.G
V.$$$.H
U.$$$.J
T.....K
*SQPML*
irony


3
1
0
*/