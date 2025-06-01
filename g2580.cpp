//g2580 스도쿠
#include <iostream>
#include <vector>
using namespace std;

#define endl '\n'
const int SIZE = 9;

vector<vector<int>>answer_board;

bool make_sudoku(vector<vector<int>>&board, int idx, vector<pair<int,int>>&empty_spot, 
    vector<int>&weight, vector<int>&height, vector<int>&rect, vector<vector<int>>&rect_idx){
    if(empty_spot.size() == idx){
        answer_board = board;
        
        return true;
    }

    int x = empty_spot[idx].first;
    int y = empty_spot[idx].second;
    int r_idx = rect_idx[x][y];

    vector<vector<int>>new_board;

    for(int i = 0; i<SIZE; i++){
        if((weight[x] & (1 << i)) == 0 
                && (height[y] & (1 << i)) == 0 
                    && (rect[r_idx] & (1 << i)) == 0){
            board[x][y] = i;
            weight[x] = (weight[x] | (1<<i));
            height[y] = (height[y] | (1<<i)); 
            rect[r_idx] = (rect[r_idx] | (1<<i)); 

            bool end_flag = make_sudoku(board, idx+1, empty_spot, weight, height, rect, rect_idx);
            if(end_flag)return true;

            weight[x] = (weight[x] ^ (1<<i));
            height[y] = (height[y] ^ (1<<i)); 
            rect[r_idx] = (rect[r_idx] ^ (1<<i));     
            board[x][y] = -1;        
            
        }
    }
    return false;
}

void solution_sudoku(){
    vector<vector<int>>board(SIZE, vector<int>(SIZE));

    vector<pair<int,int>>empty_spot;

    for(int i = 0; i<SIZE; i++){
        for(int j = 0; j<SIZE; j++){
            cin>>board[i][j];
            board[i][j]--;
            if(board[i][j] == -1){
                empty_spot.push_back({i, j});
            }
        }
    }

    vector<int>weight(SIZE, 0);
    vector<int>height(SIZE, 0);
    vector<int>rect(SIZE, 0);

    vector<vector<int>> rect_idx(SIZE, vector<int>(SIZE, 0));
    for(int i = 0; i<SIZE; i++){
        for(int j = 0; j<SIZE; j++){
            if(i/3 == 0 && j/3 == 0){
                rect_idx[i][j] = 0;
            }else if(i/3==0 && j/3==1){
                rect_idx[i][j] = 1;
            }else if(i/3==0 && j/3==2){
                rect_idx[i][j] = 2;                
            }else if(i/3==1 && j/3==0){
                rect_idx[i][j] = 3;
            }else if(i/3==1 && j/3==1){
                rect_idx[i][j] = 4;
            }else if(i/3==1 && j/3==2){
                rect_idx[i][j] = 5;                
            }else if(i/3==2 && j/3==0){
                rect_idx[i][j] = 6;
            }else if(i/3==2 && j/3==1){
                rect_idx[i][j] = 7;
            }else if(i/3==2 && j/3==2){
                rect_idx[i][j] = 8;                
            }
        }
    }

    for(int i = 0; i<SIZE; i++){
        int tmp = 0;
        for(int j = 0; j<SIZE; j++){
            if(board[i][j] != -1){
                tmp = (tmp | (1 << board[i][j]));
            }
        }
        weight[i] = tmp;
    }

    for(int i = 0; i<SIZE; i++){
        int tmp = 0;
        for(int j = 0; j<SIZE; j++){
            if(board[j][i] != -1){
                tmp = (tmp | (1 << board[j][i]));
            }
        }
        height[i] = tmp;
    }

    for(int i = 0; i<SIZE; i++){
        for(int j = 0; j<SIZE; j++){
            if(board[i][j] == -1)continue;
            int tmp = rect[rect_idx[i][j]];
            tmp = (tmp | (1 << board[i][j]));
            rect[rect_idx[i][j]] = tmp;
        }
    }


    make_sudoku(board, 0, empty_spot, weight, height, rect, rect_idx);
    
    for(int i = 0; i<SIZE; i++){
        for(int j = 0; j<SIZE; j++){
            answer_board[i][j]++;
            cout<<answer_board[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solution_sudoku();

    return 0;
}

/*
0 3 5 4 6 9 2 7 8
7 8 2 1 0 5 6 0 9
0 6 0 2 7 8 1 3 5
3 2 1 0 4 6 8 9 7
8 0 4 9 1 3 5 0 6
5 9 6 8 2 0 4 1 3
9 1 7 6 5 2 0 8 0
6 0 3 7 0 1 9 5 2
2 5 8 3 9 4 7 6 0
*/
/*
1 3 5 4 6 9 2 7 8
7 8 2 1 3 5 6 4 9
4 6 9 2 7 8 1 3 5
3 2 1 5 4 6 8 9 7
8 7 4 9 1 3 5 2 6
5 9 6 8 2 7 4 1 3
9 1 7 6 5 2 3 8 4
6 4 3 7 8 1 9 5 2
2 5 8 3 9 4 7 6 1

*/