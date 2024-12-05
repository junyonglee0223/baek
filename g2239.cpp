//스도쿠
#include <iostream>
#include <vector>
using namespace std;


vector<vector<int>>sudoku;
vector<pair<int,int>>empties;

void sudokuPrint(){
    for(int i = 1; i<=9; i++){
        for(int j = 1; j<=9; j++){
            cout<<sudoku[i][j];
        }
        cout<<'\n';
    }
}

bool isPossible(int x, int y, int k){
    for(int i = 1; i<=9; i++){
        if(sudoku[x][i] == k || sudoku[i][y] == k)return false;

        int nx = (x-1)/3 * 3 + (i-1)/3 + 1;
        int ny = (y-1)/3 * 3 + (i-1)%3 + 1;
        if(sudoku[nx][ny] == k)return false;
    }
    return true;
}

void sudokuDfs(int idx){
    if(idx == empties.size()){
        sudokuPrint();
        exit(0);
    }

    int x = empties[idx].first;
    int y = empties[idx].second;
    for(int k = 1; k<=9; k++){
        if(isPossible(x, y, k)){
            sudoku[x][y] = k;
            sudokuDfs(idx+1);
            sudoku[x][y] = 0;
        }
    }
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    sudoku.resize(10, vector<int>(10));

    for(int i = 1; i<=9; i++){
        string str; cin>>str;
        for(int j = 1; j<=9; j++){
            sudoku[i][j] = str[j-1] - '0';
            if(sudoku[i][j] == 0){
                empties.push_back({i, j});
            }
        }
    }
    sudokuDfs(0);
    return 0;
}