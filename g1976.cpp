//g1976 여행 가자
#include <iostream>
#include <vector>
using namespace std;

void solution_lets_go_travel(){

    int N, M; cin>>N>>M;
    vector<vector<int>> board(N, vector<int>(M, 0));
    for(int i = 0; i<N; i++){
        for(int j = 0; j<N; j++){
            cin>>board[i][j];
        }
    }
    for(int i = 0; i<N; i++){
        board[i][i] = 1;
    }

    for(int k = 0; k<N; k++){
        for(int i = 0; i<N; i++){
            for(int j = 0; j<N; j++){
                if(board[i][k] == 1 && board[k][j] == 1){
                    board[i][j] = board[j][i] = 1;
                }
            }
        }
    }

    bool answer = true;
    int prev = -1;
    int cur;
    vector<int>travel_units;
    for(int i = 0; i<M; i++){
        int ele; cin>>ele;
        ele--;
        travel_units.push_back(ele);
    }

    for(int i = 0; i<M; i++){
        cur = travel_units[i];
        if(i != 0 && board[prev][cur] == 0){
            answer = false;
            break;
        }
        prev = cur;
    }
    cout<<(answer == true ? "YES" : "NO")<<endl;

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solution_lets_go_travel();

    return 0;
}


/*
3
3
0 1 0
1 0 1
0 1 0
1 2 3
*/
/*
YES
*/