//구간 합 구하기 5
#include <iostream>
using namespace std;

int N, M;
int board[1025][1025];
int sum_board[1025][1025];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> board[i][j];
            sum_board[i][j] = board[i][j];
            if (i > 0) sum_board[i][j] += sum_board[i-1][j];
            if (j > 0) sum_board[i][j] += sum_board[i][j-1];
            if (i > 0 && j > 0) sum_board[i][j] -= sum_board[i-1][j-1];
        }
    }
    
    for (int i = 0; i < M; i++) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        x1--; y1--; x2--; y2--;

        int ans = sum_board[x2][y2];
        if (x1 > 0) ans -= sum_board[x1-1][y2];
        if (y1 > 0) ans -= sum_board[x2][y1-1];
        if (x1 > 0 && y1 > 0) ans += sum_board[x1-1][y1-1];

        cout << ans << '\n';
    }
}
