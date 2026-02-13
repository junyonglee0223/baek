#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

#define MAX_N 301

int calc_psum(int psum[10][MAX_N][MAX_N], int d, int x1, int y1, int x2, int y2){

    int val = 0;

    if(x1 == 0 && y1 == 0){
        val = psum[d][x2][y2];
    }else if(x1 == 0){
        val = psum[d][x2][y2] - psum[d][x2][y1-1];
    }else if(y1 == 0){
        val = psum[d][x2][y2] - psum[d][x1-1][y2];

    }else{
        val = psum[d][x2][y2] 
            - psum[d][x1-1][y2] - psum[d][x2][y1-1]
            + psum[d][x1-1][y1-1];
    }

    return val;
}

void solution_rectangle_and_query_v2(int n, vector<vector<int>>&board, vector<vector<int>>&querys){
    //psum[d][x][y] <- 
    /*
    psum[d][x][y] 
        = psum[d][x-1][y] + psum[x][y-1] 
            - psum[x-1][y-1] + arr[x][y](val)
    */

    int psum[10][MAX_N][MAX_N];

    psum[board[0][0]][0][0] = 1;
    
    for(int i = 1; i<n; i++){
        for(int d = 0; d<10; d++){
            if(board[0][i] == d)psum[d][0][i] = 1;
            psum[d][0][i] += psum[d][0][i-1];
        }
    }

    for(int i = 1; i<n; i++){
        for(int d = 0; d<10; d++){
            if(board[i][0] == d)psum[d][i][0] = 1;
            psum[d][i][0] += psum[d][i-1][0];
        }
    }

    for(int d = 0; d<10; d++){
        for(int i = 1; i<n; i++){
            for(int j = 1; j<n; j++){
                int add_val = (d == board[i][j] ? 1 : 0);
                psum[d][i][j] = (
                    psum[d][i-1][j] + psum[d][i][j-1]
                    - psum[d][i-1][j-1] + add_val
                );
            }
        }
    }

    for(auto query : querys){
        int x1 = query[0];
        int y1 = query[1];
        int x2 = query[2];
        int y2 = query[3];
        
        vector<int>visited(10, 0);
        int num_counts = 0;
        for(int d = 0; d<10; d++){
            int calc_val = calc_psum(psum, d, x1, y1, x2, y2);
            
            if(calc_val > 0)
                num_counts++;
        }
        cout<<num_counts<<"\n";
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin>>n;
    vector<vector<int>>board(n, vector<int>(n));

    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            cin>>board[i][j];
            board[i][j]--;
        }
    }

    
    int q; cin>>q;
    vector<vector<int>>querys;

    for(int i = 0; i<q; i++){
        vector<int>cur_query(4);
        for(int j = 0; j<4; j++){
            cin>>cur_query[j];
            cur_query[j]--;
        }

        querys.push_back(cur_query);
    }


    solution_rectangle_and_query_v2(n, board, querys);

    return 0;
}