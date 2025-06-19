//g14719 빗물
#include <iostream>
#include <vector>
using namespace std;


void solution_raindrop_v1(){
    int W, H; cin>>H>>W;
    vector<vector<int>>board(H, vector<int>(W, 0));
    for(int i = 0; i<W; i++){
        int ele; cin>>ele;
        for(int j = 0; j<ele; j++){
            board[j][i] = 1;
        }
    }
    int answer = 0;
    for(int i = 0; i<H; i++){
        bool let_check = false;
        int idx = -1;
        for(int j = 0; j<W; j++){
            if(board[i][j] == 1){
                if(idx != -1)
                    answer += (j - idx - 1);
                idx = j;
            }
        }
    }
    cout<<answer<<endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solution_raindrop_v1();

    // int T; cin>>T;
    // while(T--){
    //     solution_raindrop_v1();
    // }


    return 0;
}

/*
3
4 4
3 0 1 4
4 8
3 1 2 3 4 1 1 2
3 5
0 0 0 2 0
*/
/*
5
5
0
*/