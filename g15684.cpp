//g15684 사다리 조작
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool check(vector<vector<bool>>&ladders){
    int H = ladders.size();
    int N = ladders[0].size();

    for(int i = 0; i<N; i++){
        int pos = i;
        for(int j = 0; j<H; j++){
            if(ladders[j][pos])pos++;
            else if(pos > 0 && ladders[j][pos-1])pos--;
        }
        if(pos != i)return false;
    }
    return true;
}

bool is_pos_ladder(int x, int y, vector<vector<bool>>&ladders){
    int H = ladders.size();
    int N = ladders[0].size();
    if(y >= N-1 || y < 0)return false;
    if(ladders[x][y])return false;
    if(y == 0){
        return ladders[x][y+1] == true ? false : true;
    }
    if((y > 0 && ladders[x][y-1] == false && ladders[x][y+1] == false))return true;
    return false;
}

int answer = 4;
void dfs_v1(int cnt, int h, int n, vector<vector<bool>>&ladders){
    if(cnt >= answer)return;
    if(check(ladders)){
        answer = cnt;
        return;
    }
    if(cnt == 3)return;
    int H = ladders.size();
    int N = ladders[0].size();
    int ret = -1;

    for(int x = h; x<H; x++){
        for(int y = (x == h ? n : 0); y<N-1; y++){
            if(cnt + 1 >= answer)continue;
            if(is_pos_ladder(x, y, ladders)){
                ladders[x][y] = true;
                dfs_v1(cnt+1, x, y, ladders);
                ladders[x][y] = false;
                if(answer == cnt + 1)return;
            }
        }
    }
}

void solution_ladder_operation_v1(){
    int N, M, H;
    //세로가 N, 가로가 H
    cin>>N>>M>>H;

    vector<vector<bool>>ladders(H, vector<bool>(N, false));

    for(int i = 0; i<M; i++){
        int a, b; cin>>a>>b;
        a--; b--;
        ladders[a][b] = true;
    }

    dfs_v1(0, 0, 0, ladders);
    cout<<((answer >= 4) ? -1 : answer) <<endl;

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solution_ladder_operation_v1();

    // int T; cin>>T;
    // while(T--){
    //     answer = 4;
    //     solution_ladder_operation_v1();
    // }

    return 0;
}

/*
7
2 0 3
2 1 3
1 1
5 5 6
1 1
3 2
2 3
5 1
5 4
6 5 6
1 1
3 2
1 3
2 5
5 5
5 8 6
1 1
2 2
3 3
4 4
3 1
4 2
5 3
6 4
5 12 6
1 1
1 3
2 2
2 4
3 1
3 3
4 2
4 4
5 1
5 3
6 2
6 4
5 6 6
1 1
3 1
5 2
4 3
2 3
1 4


*/
/*
0
1
3
3
-1
-1
2
*/