//g15685 드래곤 커브
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define MAX_D 101

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, -1, 0, 1};

struct DOT {
    int x, y;
    DOT(){
        x = y = 0;
    }
    DOT(int _x, int _y){
        x = _x;
        y = _y;
    }
};

//clockwise rotate
DOT update_clockwise_dot(int x, int y, int gx, int gy){
    int new_x = x - gx;
    int new_y = y - gy;
    swap(new_x, new_y);
    new_x *= -1;

    new_x += gx;
    new_y += gy;
    return DOT(new_x, new_y);
}

vector<DOT> set_dragon_curve(int g, int x, int y, int d){
    vector<DOT>ret;
    ret.push_back(DOT(x, y));
    int nx = x + dx[d];
    int ny = y + dy[d];
    ret.push_back(DOT(nx, ny));

    while(g--){
        int cur_size = ret.size();
        int gx = ret[cur_size - 1].x;
        int gy = ret[cur_size - 1].y;

        for(int i = cur_size-2; i>=0; i--){
            ret.push_back(update_clockwise_dot(ret[i].x, ret[i].y, gx, gy));
        }
    }
    return ret;
}

void solution_dragon_curve(){
    int N; cin>>N;

    //cout<<N<<endl;//test
    vector<vector<int>>board(MAX_D, vector<int>(MAX_D, 0));

    for(int i = 0; i<N; i++){
        int g, x, y, d;
        cin>>x>>y>>d>>g;
        //cout<<x<<y<<d<<g<<endl;//test
        vector<DOT>cur_curve = set_dragon_curve(g, x, y, d);
        for(DOT cd : cur_curve){
            board[cd.x][cd.y] = 1;
            //cout<<cd.x<<" "<<cd.y<<"\t";//test
        }
        //cout<<endl;//test

    }

    int answer = 0;
    for(int i = 0; i<MAX_D-1; i++){
        for(int j = 0; j<MAX_D-1; j++){
            if(board[i][j] == 1 && board[i+1][j] == 1
                    && board[i][j+1] == 1 && board[i+1][j+1] == 1){
                answer++;
                //cout<<i<<" "<<j<<endl;//test
            }
        }
    }
    cout<<answer<<endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solution_dragon_curve();
    // int T; cin>>T;
    // while(T--){
    //     //cout<<"-------------------------------"<<endl;//tst
    //     solution_dragon_curve();
    // }

    return 0;
}
/*
4
3
3 3 0 1
4 2 1 3
4 2 2 1
4
3 3 0 1
4 2 1 3
4 2 2 1
2 7 3 4
10
5 5 0 0
5 6 0 0
5 7 0 0
5 8 0 0
5 9 0 0
6 5 0 0
6 6 0 0
6 7 0 0
6 8 0 0
6 9 0 0
4
50 50 0 10
50 50 1 10
50 50 2 10
50 50 3 10
*/
/*
4
11
8
1992
*/