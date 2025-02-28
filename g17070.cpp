//g17070 파이프 옮기기 1
#include <iostream>
#include <vector>
using namespace std;

#define endl '\n'

#define MAX_N 17
int N;
vector<vector<int>>board;
int dp[17][17][3];

void solution_move_pipe1(){
    cin>>N;
    board.resize(N, vector<int>(N, 0));

    for(int i = 0; i<MAX_N; i++){
        for(int j = 0; j<MAX_N; j++){
            for(int k = 0; k<3; k++){
                dp[i][j][k] = 0;
            }
        }
    }


    for(int i = 0; i<N; i++){
        for(int j = 0; j<N; j++){
            cin>>board[i][j];
        }
    }
    dp[0][0][0] = 1;
    dp[0][1][0] = 1;


    for(int i = 0; i<N; i++){
        for(int j = 1; j<N; j++){
            if(i == 0 && j == 1)continue;
            if(board[i][j] == 1)continue;


            bool dia_flag = false;
            if(i >= 1 && j > 1 && board[i][j-1] == 0 && board[i-1][j] == 0){
                dia_flag = true;
            }

            dp[i][j][0] += (dp[i][j-1][0] + dp[i][j-1][1]);
            if(dia_flag)
                dp[i][j][1] += (dp[i-1][j-1][1] + dp[i-1][j-1][0] + dp[i-1][j-1][2]);
            

            if(i > 0)
                dp[i][j][2] += (dp[i-1][j][2] + dp[i-1][j][1]);

        }
    }
    cout<<dp[N-1][N-1][0] + dp[N-1][N-1][1] + dp[N-1][N-1][2] << endl;

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    solution_move_pipe1();

    // int T; cin>>T;
    // while(T--){
    //     solution_move_pipe1();
    // }
    return 0;
}

/*

4
3
0 0 0
0 0 0
0 0 0
4
0 0 0 0
0 0 0 0
0 0 0 0
0 0 0 0
5
0 0 1 0 0
0 0 0 0 0
0 0 0 0 0
0 0 0 0 0
0 0 0 0 0

6
0 0 0 0 0 0
0 1 0 0 0 0
0 0 0 0 0 0
0 0 0 0 0 0
0 0 0 0 0 0
0 0 0 0 0 0


*/