//g14890 경사로
#include <iostream>
#include <vector>
using namespace std;
#define endl '\n'

bool is_same_height(vector<int>&board, int start, int end){
    int value = board[start];
    for(int i = start+1; i<=end; i++){
        if(board[i] != value)return false;
    }
    return true;
}

bool check_ramp_cnt(vector<int>board, int L){
    int N = board.size();
    int start = 0, end = N-1;
    //down 1, up -1
    vector<int>set_ramp(N, 0);

    int idx = start;

    while(idx < end){
        //up ramp
        if(idx+1 <= end && board[idx]+1 == board[idx+1]){
            if(idx - L + 1 < 0)return false;
            if(set_ramp[idx - L + 1] == 1)return false;
            if(!is_same_height(board, idx - L + 1, idx))return false;
            for(int i = idx - L + 1; i<=idx; i++){
                set_ramp[i] = -1;
            }
            idx++;
        }
        //down ramp
        else if(idx+1 <= end && board[idx] == board[idx+1]+1){
            //if(set_ramp[idx] != 0)return false;
            if(!is_same_height(board, idx+1, idx+L))return false;
            for(int i = idx+1; i<=idx+L; i++){
                set_ramp[i] = 1;
            }
            idx = idx + L;
        }
        else if(idx+1 <= end && board[idx] == board[idx+1]){
            idx++;
        }
        else{
            return false;
        }
    }
    return true;
}

void solution_ramp(){
    int N, L; cin>>N>>L;
    vector<vector<int>>board(N, vector<int>(N, 0));

    for(int i = 0; i<N; i++){
        for(int j = 0; j<N; j++){
            cin>>board[i][j];
        }
    }

    int answer = 0;
    for(int i = 0; i<N; i++){
        if(check_ramp_cnt(board[i], L)){
            answer++;
        }
    }
    for(int i = 0; i<N; i++){
        vector<int>tmp_board(N, 0);
        for(int j = 0; j<N; j++){
            tmp_board[j] = board[j][i];
        }
        if(check_ramp_cnt(tmp_board, L)){
            answer++;
        }
    }
    cout<<answer<<endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solution_ramp();

    // int T; cin>>T;
    // while(T--){
    //     solution_ramp();
    // }

    return 0;
}

/*
4
6 2
3 3 3 3 3 3
2 3 3 3 3 3
2 2 2 3 2 3
1 1 1 2 2 2
1 1 1 3 3 1
1 1 2 3 3 2
6 2
3 2 1 1 2 3
3 2 2 1 2 3
3 2 2 2 3 3
3 3 3 3 3 3
3 3 3 3 2 2
3 3 3 3 2 2
6 3
3 2 1 1 2 3
3 2 2 1 2 3
3 2 2 2 3 3
3 3 3 3 3 3
3 3 3 3 2 2
3 3 3 3 2 2
6 1
3 2 1 1 2 3
3 2 2 1 2 3
3 2 2 2 3 3
3 3 3 3 3 3
3 3 3 3 2 2
3 3 3 3 2 2
*/
/*
3
7
3
11
*/