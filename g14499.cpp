//g14499 주사위 굴리기
#include <iostream>
#include <vector>
using namespace std;


struct DICE{
    int bottom, top;

    vector<int>side;
    DICE(){
        side.resize(4);
        this->bottom = 0;
        this->top = 0;

        side[0] = 0;
        side[1] = 0;
        side[2] = 0;
        side[3] = 0;
    }

    void roll_front(){
        int nxt_bottom, nxt_top, nxt_front;
        vector<int>nxt_side(4);

        nxt_bottom = this->side[0];
        nxt_top = this->side[2];

        nxt_side[0] = this->top;
        nxt_side[1] = this->side[1];
        nxt_side[2] = this->bottom;
        nxt_side[3] = this->side[3];

        this->bottom = nxt_bottom;
        this->top = nxt_top;
        for(int i = 0; i<4; i++)
            side[i] = nxt_side[i];
    }

    void roll_back(){
        int nxt_bottom, nxt_top, nxt_front;
        vector<int>nxt_side(4);

        nxt_bottom = this->side[2];
        nxt_top = this->side[0];

        nxt_side[0] = this->bottom;
        nxt_side[1] = this->side[1];
        nxt_side[2] = this->top;
        nxt_side[3] = this->side[3];

        this->bottom = nxt_bottom;
        this->top = nxt_top;
        for(int i = 0; i<4; i++)
            side[i] = nxt_side[i];
    }

    void roll_left(){
        int nxt_bottom, nxt_top, nxt_front;
        vector<int>nxt_side(4);

        nxt_bottom = this->side[3];
        nxt_top = this->side[1];

        nxt_side[0] = this->side[0];
        nxt_side[1] = this->bottom;
        nxt_side[2] = this->side[2];
        nxt_side[3] = this->top;

        this->bottom = nxt_bottom;
        this->top = nxt_top;
        for(int i = 0; i<4; i++)
            side[i] = nxt_side[i];
    }

    void roll_right(){
        int nxt_bottom, nxt_top, nxt_front;
        vector<int>nxt_side(4);

        nxt_bottom = this->side[1];
        nxt_top = this->side[3];

        nxt_side[0] = this->side[0];
        nxt_side[1] = this->top;
        nxt_side[2] = this->side[2];
        nxt_side[3] = this->bottom;

        this->bottom = nxt_bottom;
        this->top = nxt_top;
        for(int i = 0; i<4; i++)
            side[i] = nxt_side[i];
    }
};

bool is_range(int x, int y, int n, int m){
    return x >= 0 && x < n && y >= 0 && y < m;
}
void solution_rolling_dice(){
    int n, m, x, y, k;
    cin>>n>>m>>x>>y>>k;

    vector<vector<int>>board(n, vector<int>(m));

    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            cin>>board[i][j];
        }
    }

    DICE dice;

    if(board[x][y] == 0){
        board[x][y] = dice.bottom;
    }else{
        dice.bottom = board[x][y];
        board[x][y] = 0;
    }

    int cur_x = x;
    int cur_y = y;

    for(int i = 0; i<k; i++){
        int dir; cin>>dir;
        int nx, ny;
        if(dir == 1){
            nx = cur_x;
            ny = cur_y + 1;
            if(!is_range(nx, ny, n, m))continue;
           
            dice.roll_right();
            cur_x = nx;
            cur_y = ny;
        }else if(dir == 2){
            nx = cur_x;
            ny = cur_y - 1;
            if(!is_range(nx, ny, n, m))continue;
            
            dice.roll_left();
            cur_x = nx;
            cur_y = ny;
        }else if(dir == 3){
            nx = cur_x - 1;
            ny = cur_y;
            if(!is_range(nx, ny, n, m))continue;

            dice.roll_front();
            cur_x = nx;
            cur_y = ny;
        }else if(dir == 4){
            nx = cur_x + 1;
            ny = cur_y;
            if(!is_range(nx, ny, n, m))continue;

            dice.roll_back();
            cur_x = nx;
            cur_y = ny;
        }

        if(board[cur_x][cur_y] == 0){
            board[cur_x][cur_y] = dice.bottom;
        }else{
            dice.bottom = board[cur_x][cur_y];
            board[cur_x][cur_y] = 0;
        }
        cout<<dice.top<<endl;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solution_rolling_dice();

    // int T; cin>>T;
    // while(T--){
    //     solution_rolling_dice();
    //     cout<<"-------------------"<<endl;
    // }


    return 0;
}

/*
4

4 2 0 0 8
0 2
3 4
5 6
7 8
4 4 4 1 3 3 3 2

3 3 1 1 9
1 2 3
4 0 5
6 7 8
1 3 2 2 4 4 1 1 3

2 2 0 0 16
0 2
3 4
4 4 4 4 1 1 1 1 3 3 3 3 2 2 2 2

3 3 0 0 16
0 1 2
3 4 5
6 7 8
4 4 1 1 3 3 2 2 4 4 1 1 3 3 2 2
*/
/*
0
0
3
0
0
8
6
3


0
0
0
3
0
1
0
6
0

0
0
0
0


0
0
0
6
0
8
0
2
0
8
0
2
0
8
0
2

*/