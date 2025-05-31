//g15683 감시
#include <iostream>
#include <vector>
using namespace std;

struct CCTV_ELE{
    int x, y, type;
};

void print_board(vector<vector<int>>& board){
    int n = board.size();
    int m = board[0].size();
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            cout<<board[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}
bool set_type_flag(int dir, int x, int y, int n, int m){
    if(dir == 0){
        return x >= 0;
    }else if(dir == 1){
        return y < m;
    }else if(dir == 2){
        return x < n;
    }else if(dir == 3){
        return y >= 0;
    }
    return false;
}

int set_type(int x, int y, int type, int dir, vector<vector<int>>& board){
    int n = board.size();
    int m = board[0].size();
    int ret = 0;

    if(dir == 0){
        x--;
    }else if(dir == 1){
        y++;
    }else if(dir == 2){
        x++;
    }else if(dir == 3){
        y--;
    }
    while(set_type_flag(dir, x, y, n, m) && board[x][y] != 6){
        if(board[x][y] == 0){
            board[x][y] = type;
            ret++;
        }
        if(dir == 0){
            x--;
        }else if(dir == 1){
            y++;
        }else if(dir == 2){
            x++;
        }else if(dir == 3){
            y--;
        }
    }
    return ret;
}

int set_watching_spot_1(int x, int y, int dir, vector<vector<int>>&board){
    //one way watching
    return set_type(x, y, 1, dir, board);
}

int set_watching_spot_2(int x, int y, int dir, vector<vector<int>>&board){
    //tri watching
    return set_type(x, y, 2, dir, board) + set_type(x, y, 2, (dir + 1)%4, board)
    + set_type(x, y, 2, (dir + 3)%4, board);
}

int set_watching_spot_3(int x, int y, int dir, vector<vector<int>>&board){
    //90 degree watching
    return set_type(x, y, 3, dir, board) + set_type(x, y, 3, (dir + 1)%4, board);
}

int set_watching_spot_4(int x, int y, int dir, vector<vector<int>>&board){
    //dir == 0 || dir == 1
    //up down watching
    if(dir == 0){
        return set_type(x, y, 4, 0, board) + set_type(x, y, 4, 2, board);
    }
    //left right watching
    else{
        return set_type(x, y, 4, 1, board) + set_type(x, y, 4, 3, board);
    }
}

int set_watching_spot_5(int x, int y, vector<vector<int>>&board){
    //all round watching
    return set_type(x, y, 5, 0, board) + set_type(x, y, 5, 1, board)
        + set_type(x, y, 5, 2, board) + set_type(x, y, 5, 3, board);
}

int max_watching_area(int idx, vector<CCTV_ELE>&cctvs, vector<vector<int>>tmp_board){
    if(idx == cctvs.size()){
        return 0;
    }
    CCTV_ELE cur_cctv = cctvs[idx];
    int x = cur_cctv.x;
    int y = cur_cctv.y;
    int type = cur_cctv.type;
    vector<vector<int>>nxt_tmp_board;
    int ret = 0;
    if(cur_cctv.type == 5){
        nxt_tmp_board = tmp_board;
        int make_watch = set_watching_spot_5(x, y, nxt_tmp_board);
        ret = max(ret, make_watch + max_watching_area(idx+1, cctvs, nxt_tmp_board));
    }else if(cur_cctv.type == 4){
        for(int d = 0; d<2; d++){
            nxt_tmp_board = tmp_board;
            int make_watch = set_watching_spot_4(x, y, d, nxt_tmp_board);
            ret = max(ret, make_watch + max_watching_area(idx+1, cctvs, nxt_tmp_board));
        }
    }else if(cur_cctv.type == 3){
        for(int d = 0; d<4; d++){
            nxt_tmp_board = tmp_board;
            int make_watch = set_watching_spot_3(x, y, d, nxt_tmp_board);
            ret = max(ret, make_watch + max_watching_area(idx+1, cctvs, nxt_tmp_board));
        }
    }else if(cur_cctv.type == 2){
        for(int d = 0; d<4; d++){
            nxt_tmp_board = tmp_board;
            int make_watch = set_watching_spot_2(x, y, d, nxt_tmp_board);
            ret = max(ret, make_watch + max_watching_area(idx+1, cctvs, nxt_tmp_board));
        }
    }else if(cur_cctv.type == 1){
        for(int d = 0; d<4; d++){
            nxt_tmp_board = tmp_board;
            int make_watch = set_watching_spot_1(x, y, d, nxt_tmp_board);
            ret = max(ret, make_watch + max_watching_area(idx+1, cctvs, nxt_tmp_board));
        }
    }
    //cout<<idx<<" "<<ret<<endl;//test
    return ret;
}

void solution_watching(){
    int n, m; cin>>n>>m;
    vector<vector<int>>board(n, vector<int>(m));

    vector<CCTV_ELE>cctvs;

    int tot_margin = 0;

    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            int ele; cin>>ele;

            //2, 4 방향 교체
            if(ele == 2){
                board[i][j] = 4;
            }else if(ele == 4){
                board[i][j] = 2;
            }else{
                board[i][j] = ele;
            }

            if(board[i][j] == 0){
                tot_margin++;
            }
            
            if(board[i][j] != 0 && board[i][j] != 6){
                CCTV_ELE tmp;
                tmp.type = board[i][j];
                tmp.x = i;
                tmp.y = j;
                cctvs.push_back(tmp);
            }
        }
    }


    int answer = max_watching_area(0, cctvs, board);


    //cout<<tot_margin<<endl;//test
    cout<< tot_margin - answer <<endl;


}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solution_watching();

    // int T; cin>>T;
    // while(T--){
    //     solution_watching();
    // }

    return 0;
}

/*
6
4 6
0 0 0 0 0 0
0 0 0 0 0 0
0 0 1 0 6 0
0 0 0 0 0 0
6 6
0 0 0 0 0 0
0 2 0 0 0 0
0 0 0 0 6 0
0 6 0 0 2 0
0 0 0 0 0 0
0 0 0 0 0 5
6 6
1 0 0 0 0 0
0 1 0 0 0 0
0 0 1 0 0 0
0 0 0 1 0 0
0 0 0 0 1 0
0 0 0 0 0 1
6 6
1 0 0 0 0 0
0 1 0 0 0 0
0 0 1 5 0 0
0 0 5 1 0 0
0 0 0 0 1 0
0 0 0 0 0 1
1 7
0 1 2 3 4 5 6
3 7
4 0 0 0 0 0 0
0 0 0 2 0 0 0
0 0 0 0 0 0 4
*/
/*
20
15
6
2
0
0
*/