//p1028 다이아몬드 게임
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

#define MAX_N 751
char board[MAX_N][MAX_N];
int dp_l[MAX_N][MAX_N];
int dp_r[MAX_N][MAX_N];
int R, C;

bool is_range(int x, int y) {
    return x >= 0 && x < R && y >= 0 && y < C;
}

int solution_diamond_mining() {
    cin >> R >> C;

    //dpl, dpr 초기화
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            dp_l[i][j] = 0;
            dp_r[i][j] = 0;
        }
    }

    bool flag = false;
    for (int i = 0; i < R; i++) {
        string tmp; cin >> tmp;
        for (int j = 0; j < C; j++) {
            board[i][j] = tmp[j];
            if (board[i][j] == '1')flag = true;
        }
    }
    int ret = 0;
    for (int i = 1; i < R; i++) {
        for (int j = 0; j < C; j++) {
            if (board[i][j] == '0')continue;
            if (j > 0 && board[i - 1][j - 1] == '1') {
                dp_l[i][j] = dp_l[i - 1][j - 1] + 1;
            }
            if (j < C - 1 && board[i - 1][j + 1] == '1') {
                dp_r[i][j] = dp_r[i - 1][j + 1] + 1;
            }

            int c_size = min(dp_l[i][j], dp_r[i][j]);
            for (int s = c_size; s > ret; s--) {
                int p_x = i - s;
                int p_y = j - s;
                int n_x = i - s;
                int n_y = j + s;
                if (dp_r[p_x][p_y] >= s && dp_l[n_x][n_y] >= s) {
                    ret = max(ret, s);
                }
            }
        }
    }

    return !flag ? 0 : ret + 1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cout << solution_diamond_mining() << "\n";

    //int T;
    //cin >> T;
    //for (int t = 1; t <= T; t++) {
    //    int ret = solution_diamond_mining();
    //    cout << "#" << t << " " << ret << "\n";
    //}
    return 0;
}
/*
* R, C가 주어지고 750 이하 값이다.
* 가장 길이가 긴 값을 출력하면 된다.
* dp 2개 만들어서 해당 위치에서 아래 좌우로 가능한 최대 길이를 
* 저장한다.
* 
* 우선 생각한 방식
* left, right 배열 설정해서 h 내려가면서
* 최대 길이 설정 -> 대각선 -1, -1 -> left + 1, -1, +1, -> right + 1
* 
* 
* left, right min 값이 현재 포인트에서 위로 가능한 최대 사이즈
* 1 <= x <= min(left, right)
* right[cur - x] >= x, left[cur + x] >= x 이기만 하면 현재 위치에서
* 최대 다이아 생성 가능
* 
* 
* 
* 
* 근데 왜 누적합으로 가능한거지??
* 
* 
*/
/*
* 
4
5 5
01100
01011
11111
01111
11111
5 5
01100
00011
11111
01111
11111
4 4
0000
0000
0000
0000
3 6
111000
101111
111111
*/
/*
* 3
* 2
* 0
* 2
*/