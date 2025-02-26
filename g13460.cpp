//g13460 구슬 탈출 2
#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <set>
using namespace std;

typedef pair<int,int> p;

#define endl '\n'


int N, M;
p r, b;
vector<vector<int>>board;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
bool is_range(int x, int y){
    return x >= 0 && x < N && y >= 0 && y < M;
}

p move_dir(p cur, int dir){
    int x = cur.first;
    int y = cur.second;

    int nx = cur.first + dx[dir];
    int ny = cur.second + dy[dir];
    while(is_range(nx, ny) && board[nx][ny] == 0){
        x = nx; y = ny;
        nx = nx + dx[dir];
        ny = ny + dy[dir];
    }
    return {x, y};
}


void solution_escape_ball2_V1(){
    cin>>N>>M;
    board.clear();

    board.resize(N, vector<int>(M, -1));
    for(int i = 0; i<N; i++){
        string str; cin>>str;
        for(int j = 0; j<M; j++){
            if(str[j] == '.'){
                board[i][j] = 0;
            }
            else if(str[j] == 'O'){
                board[i][j] = 1;
            }
            else if(str[j] == 'R'){
                board[i][j] = 0;
                r.first = i;
                r.second = j;
            }
            else if(str[j] == 'B'){
                board[i][j] = 0;
                b.first =  i;
                b.second = j;
            }
        }
    }

    int check_count = -1;
    set<pair<p, p>> visited;
    visited.insert({r, b});
    bool is_finish = false;

    priority_queue<pair<int, pair<p, p>>>pq;
    pq.push({0, {r, b}});

    while(!pq.empty() && pq.top().first >= -10 && !is_finish){
        int cnt = pq.top().first;
        p cur_r = pq.top().second.first;
        p cur_b = pq.top().second.second;
        pq.pop();
        if(cnt <= -10)continue;

        for(int d = 0; d<4; d++){

            p nxt_r = move_dir(cur_r, d);
            p nxt_b = move_dir(cur_b, d);

            bool red_first;
            if(d == 0) {
                red_first = (cur_r.first > cur_b.first);
            } else if(d == 1) {
                red_first = (cur_r.second > cur_b.second);
            } else if(d == 2) {
                red_first = (cur_r.first < cur_b.first);
            } else {
                red_first = (cur_r.second < cur_b.second);
            }

            if(nxt_r == nxt_b && !red_first){
                nxt_b = move_dir(cur_b, d);
                nxt_r = {nxt_b.first - dx[d], nxt_b.second - dy[d]};

                p tmp_b = {nxt_b.first + dx[d], nxt_b.second + dy[d]};
                if(board[tmp_b.first][tmp_b.second] == 1)continue;

                if(visited.find({nxt_r, nxt_b}) != visited.end())continue;
                visited.insert({nxt_r, nxt_b});
                pq.push({cnt - 1 ,{nxt_r, nxt_b}});
            }
            else if(nxt_r == nxt_b && red_first){
                nxt_r = move_dir(cur_r, d);
                nxt_b = {nxt_r.first - dx[d], nxt_r.second - dy[d]};

                p tmp_r = {nxt_r.first + dx[d], nxt_r.second + dy[d]};
                
                if(board[tmp_r.first][tmp_r.second] == 1){
                    continue;
                }

                if(visited.find({nxt_r, nxt_b}) != visited.end())continue;
                visited.insert({nxt_r, nxt_b});
                pq.push({cnt -1 ,{nxt_r, nxt_b}});
            }
            else{
                p tmp_r = {nxt_r.first + dx[d], nxt_r.second + dy[d]};
                p tmp_b = {nxt_b.first + dx[d], nxt_b.second + dy[d]};

                if(is_range(tmp_b.first, tmp_b.second) && 
                        board[tmp_b.first][tmp_b.second] == 1){
                    continue;
                }
                else if(is_range(tmp_r.first, tmp_r.second) &&
                        board[tmp_r.first][tmp_r.second] == 1){
                    is_finish = true;
                    check_count = -cnt + 1;
                }
                else{
                    if(visited.find({nxt_r, nxt_b}) != visited.end())continue;
                    visited.insert({nxt_r, nxt_b});
                    pq.push({cnt -1 ,{nxt_r, nxt_b}});
                }
            }
        }
    }

    cout << (check_count > 10 ? -1 : check_count) <<endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    solution_escape_ball2_V1();

    // int T; cin>>T;
    // while(T--){
    //     solution_escape_ball2_V1();
    // }



    return 0;
}
/*
1
5
5
-1
1
7
-1
*/

/*
7
5 5
#####
#..B#
#.#.#
#RO.#
#####
7 7
#######
#...RB#
#.#####
#.....#
#####.#
#O....#
#######
7 7
#######
#..R#B#
#.#####
#.....#
#####.#
#O....#
#######
10 10
##########
#R#...##B#
#...#.##.#
#####.##.#
#......#.#
#.######.#
#.#....#.#
#.#.#.#..#
#...#.O#.#
##########
3 7
#######
#R.O.B#
#######
10 10
##########
#R#...##B#
#...#.##.#
#####.##.#
#......#.#
#.######.#
#.#....#.#
#.#.##...#
#O..#....#
##########
3 10
##########
#.O....RB#
##########

*/