//g12100 2048 (Easy)
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define endl '\n'

int N;
//vector<vector<int>>board;
int max_block;

vector<vector<int>> rotate_board(vector<vector<int>>&board){
    vector<vector<int>>rotated_board(N, vector<int>(N, 0));
    for(int i = 0; i<N; i++){
        for(int j = 0; j<N; j++){
            rotated_board[j][N-1-i] = board[i][j];
        }
    }
    return rotated_board;
}

void merge_compress(vector<vector<int>>&board){
    for(int i = 0; i<N; i++){
        vector<int>line;
        for(int j = 0; j<N; j++){
            if(board[i][j] != 0){
                line.push_back(board[i][j]);
            }
        }
        for(int j = 1; j<line.size(); j++){
            if(line[j] == line[j-1]){
                line[j-1] = 2 * line[j];
                line[j] = 0;
                max_block = max(max_block, line[j-1]);
            }
        }
        line.erase(remove(line.begin(), line.end(), 0), line.end());
        line.resize(N, 0);

        for(int j = 0; j<N; j++){
            board[i][j] = line[j];
        }
    }
}


void game_process(vector<vector<int>>&board, int game_count){
    if(game_count == 5){
        for(int i = 0; i<N; i++){
            for(int j = 0; j<N; j++){
                max_block = max(max_block, board[i][j]);
            }
        }
        return;
    }

    for(int dir = 0; dir < 4; dir++){
        vector<vector<int>>tmp_board = board;
        for(int d = 0; d < dir; d++){
            tmp_board = rotate_board(tmp_board);
        }
        merge_compress(tmp_board);
        for(int d = 0; d < (4 - dir)%4; d++){
            tmp_board = rotate_board(tmp_board);
        }
        game_process(tmp_board, game_count + 1);
    }
}

void solution_2048_easy(){
    cin>>N;

    vector<vector<int>>board;
    board.clear();
    max_block = 0;
    
    board.resize(N, vector<int>(N));

    for(int i = 0; i<N; i++){
        for(int j = 0; j<N; j++){
            cin>>board[i][j];
        }
    }

    game_process(board, 0);

    cout<<max_block<<endl;
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    solution_2048_easy();
    return 0;
}


/*
3
2 2 2
4 4 4
8 8 8


-> 16

*/