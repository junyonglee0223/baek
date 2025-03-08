//g14500 테트로미노
#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

#define MAX_N 501

int N, M;
vector<vector<int>>board;
vector<vector<vector<int>>>tet_group;

void print_tet(vector<vector<int>>&tet){
    int n = tet.size();
    int m = tet[0].size();
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            cout<<tet[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}

vector<int>min_max_x_y(vector<vector<int>>&tet){
    int max_x = - MAX_N;
    int max_y = - MAX_N;
    int min_x = MAX_N;
    int min_y = MAX_N;
    for(int i = 0; i<tet.size(); i++){
        max_x = max(max_x, tet[i][0]);
        min_x = min(min_x, tet[i][0]);
    
        max_y = max(max_y, tet[i][1]);
        min_y = min(min_y, tet[i][1]);
    }
    vector<int>ret;
    ret.push_back(min_x);
    ret.push_back(min_y);
    ret.push_back(max_x);
    ret.push_back(max_y);
    return ret;
}

vector<int>get_size_tet(vector<vector<int>>&tet){
    vector<int> mmtmp =  min_max_x_y(tet);
    int size_x = mmtmp[2] - mmtmp[0];
    int size_y = mmtmp[3] - mmtmp[1];
    vector<int>ret;
    ret.push_back(size_x);
    ret.push_back(size_y);
    return ret;
}

void regularize_tet(vector<vector<int>>&tet){
    sort(tet.begin(), tet.end());
    vector<int>mmtmp = min_max_x_y(tet);
    int min_x = mmtmp[0];
    int min_y = mmtmp[1];

    for(int i = 0; i<tet.size(); i++){
        tet[i][0] -= min_x;
        tet[i][1] -= min_y;
    }
}

vector<vector<int>> rotate_tet(vector<vector<int>> tet){
    vector<vector<int>>rotated_tet;
    //regularize_tet(rotated_tet);

    vector<int>tmp_tet_size = get_size_tet(rotated_tet);
    int size_x = tmp_tet_size[0];
    int size_y = tmp_tet_size[1];


    regularize_tet(tet);
    
    for(int i = 0; i<tet.size(); i++){
        rotated_tet.push_back({tet[i][1], size_x - 1 - tet[i][0]});
    }
    regularize_tet(rotated_tet);
    return rotated_tet;
}

void set_tetromino(){
    vector<vector<int>>tet_0 = {
        {0, 0},
        {0, 1},
        {1, 0},
        {1, 1}
    };
    vector<vector<int>>tet_1 = {
        {0, 0},
        {0, 1},
        {0, 2},
        {0, 3}
    };
    vector<vector<int>>tet_2 = {
        {0, 0},
        {1, 0},
        {2, 0},
        {2, 1}
    };
    vector<vector<int>>tet_3 = {
        {0, 0},
        {1, 0},
        {1, 1},
        {2, 1}
    };
    vector<vector<int>>tet_4 = {
        {0, 0},
        {0, 1},
        {0, 2},
        {1, 1}
    };
    vector<vector<int>>tet_5 = {
        {0, 1},
        {1, 1},
        {2, 0},
        {2, 1}
    };
    vector<vector<int>>tet_6 = {
        {0, 1},
        {1, 0},
        {1, 1},
        {2, 0}
    };



    tet_group.push_back(tet_0);

    vector<vector<int>>tmp_tet_t = tet_1;
    for(int i = 0; i<2; i++){
        tet_group.push_back(tmp_tet_t);
        tmp_tet_t = rotate_tet(tmp_tet_t);
    }

    tmp_tet_t = tet_2;
    for(int i = 0; i<4; i++){
        tet_group.push_back(tmp_tet_t);
        tmp_tet_t = rotate_tet(tmp_tet_t);
    }    
    tmp_tet_t = tet_3;
    for(int i = 0; i<4; i++){
        tet_group.push_back(tmp_tet_t);
        tmp_tet_t = rotate_tet(tmp_tet_t);
    }    
    tmp_tet_t = tet_4;
    for(int i = 0; i<4; i++){
        tet_group.push_back(tmp_tet_t);
        tmp_tet_t = rotate_tet(tmp_tet_t);
    }    
    tmp_tet_t = tet_5;
    for(int i = 0; i<4; i++){
        tet_group.push_back(tmp_tet_t);
        tmp_tet_t = rotate_tet(tmp_tet_t);
    }    
    tmp_tet_t = tet_6;
    for(int i = 0; i<4; i++){
        tet_group.push_back(tmp_tet_t);
        tmp_tet_t = rotate_tet(tmp_tet_t);
    }        
}

bool is_range(int x, int y){
    return x>=0 && x<N && y>=0 && y<M;
}

int calc_tetromino(int x, int y, vector<vector<int>>tet){
    int ret = 0;
    for(auto ele : tet){
        int cx = x + ele[0];
        int cy = y + ele[1];
        if(!is_range(cx, cy))return -1;
        ret += board[cx][cy];
    }
    return ret;
}

void solution_tetromino(){
    tet_group.clear();
    board.clear();

    cin>>N>>M;
    board.resize(N, vector<int>(M, 0));
    for(int i = 0; i<N; i++){
        for(int j = 0; j<M; j++){
            cin>>board[i][j];
        }
    }

    set_tetromino();
    int answer = -1;

    for(int i = 0; i<N; i++){
        for(int j = 0; j<M; j++){
            for(auto ele : tet_group){
                answer = max(answer, calc_tetromino(i, j, ele));
            }
        }
    }
    cout<<answer<<endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    solution_tetromino();

    // int T; cin>>T;
    // while(T--){
    //     solution_tetromino();
    // }


    return 0;
}

/*
19
20
7
*/

/*
3
5 5
1 2 3 4 5
5 4 3 2 1
2 3 4 5 6
6 5 4 3 2
1 2 1 2 1
4 5
1 2 3 4 5
1 2 3 4 5
1 2 3 4 5
1 2 3 4 5
4 10
1 2 1 2 1 2 1 2 1 2
2 1 2 1 2 1 2 1 2 1
1 2 1 2 1 2 1 2 1 2
2 1 2 1 2 1 2 1 2 1

*/