//g16234 인구 이동
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

#define endl '\n'

typedef pair<int,int> p;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

//test
void print_double_p(vector<vector<p>>&vec){
    for(int i = 0; i<vec.size(); i++){
        for(int j = 0; j<vec[i].size(); j++){
            cout<<"("<<vec[i][j].first<<", "<<vec[i][j].second<<") ";
        }
        cout<<endl;
    }
    cout<<endl;
}

void print_board(vector<vector<int>>&board){
    int n = board.size();
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout<<board[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}

//test



bool is_range(int x, int y, int n){
    return x >= 0 && x < n && y >= 0 && y < n;
}

vector<p> do_set_group(int x, int y, vector<vector<bool>>&visited, 
    vector<vector<int>>&board, int l, int r){
    vector<p>ret;
    int n = board.size();

    queue<p>q;
    visited[x][y] = true;
    ret.push_back({x, y});
    q.push({x, y});

    while(!q.empty()){
        int cx = q.front().first;
        int cy = q.front().second;
        q.pop();

        for(int d = 0; d<4; d++){
            int nx = cx + dx[d];
            int ny = cy + dy[d];

            if(!is_range(nx, ny, n))continue;
            if(visited[nx][ny])continue;

            int dist = abs(board[cx][cy] - board[nx][ny]);
            if(dist >= l && dist <= r){
                visited[nx][ny] = true;
                ret.push_back({nx, ny});
                q.push({nx, ny});
            }
        }
    }

    return ret;
}

vector<vector<p>> set_group(vector<vector<int>>&board, int l, int r){
    int n = board.size();
    vector<vector<bool>>visited(n, vector<bool>(n, false));
    vector<vector<p>>ret;

    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            if(!visited[i][j]){
                vector<p> tmp = do_set_group(i, j, visited, board, l, r);
                ret.push_back(tmp);
            }
        }
    }
    return ret;
}

bool move_people(vector<vector<p>>&group, vector<vector<int>>&board){
    int n = board.size();
    bool ret = false;

    int g_size = group.size();
    for(int i = 0; i<g_size; i++){
        vector<p> e_group = group[i];
        if(e_group.size() > 1){
            ret = true;
        }
        int e_group_people = 0;
        for(int j = 0; j<e_group.size(); j++){
            int e_g_x = e_group[j].first;
            int e_g_y = e_group[j].second;
            e_group_people += board[e_g_x][e_g_y];
        }
        int re_group_people = e_group_people / e_group.size();
        for(int j = 0; j<e_group.size(); j++){
            int e_g_x = e_group[j].first;
            int e_g_y = e_group[j].second;
            board[e_g_x][e_g_y] = re_group_people;
        }
    }
    return ret;
}

void solution_people_moving(){
    int n; cin>>n;
    int l, r; cin>>l>>r;
    vector<vector<int>>board(n, vector<int>(n));

    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            cin >> board[i][j];
        }
    }

    vector<vector<p>> set_tmp = set_group(board, l, r);
    //print_double_p(set_tmp);//test

    int day = 0;
    while(move_people(set_tmp, board) == true){
        day++;
        set_tmp = set_group(board, l, r);
        //print_board(board);//test
    }
    cout<<day<<endl;
    //cout<<"_________________________________________________"<<endl;//test
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solution_people_moving();

    // int T; cin>>T;
    // while(T--){
    //     solution_people_moving();
    // }

    return 0;
}


/*
5
2 20 50
50 30
20 40
2 40 50
50 30
20 40
2 20 50
50 30
30 40
3 5 10
10 15 20
20 30 25
40 22 10
4 10 50
10 100 20 90
80 100 60 70
70 20 30 40
50 20 100 10
*/
/*
1
0
1
2
3
*/