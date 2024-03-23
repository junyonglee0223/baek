// #include <bits/stdc++.h>
// using namespace std;

// int n;
// int board[10][10];
// bool isused1[20], isused2[20];
// int ans = 0;

// void bishop(int th, int size) {
//     if (th >= 2 * n - 1) {
//         ans = max(ans, size);
//         return;
//     }

//     int i_start = (th < n) ? 0 : th - n + 1;
//     int i_end = min(th, n - 1);

//     bool flag = false;
//     for (int i = i_start; i <= i_end; i++) {
//         int x = i;
//         int y = th - i;
//         if (board[x][y] == 1 && !isused1[x + y] && !isused2[n - 1 + x - y]) {
//             flag = true;
//             isused1[x + y] = true;
//             isused2[n - 1 + x - y] = true;
//             bishop(th + 1, size + 1);
//             isused1[x + y] = false;
//             isused2[n - 1 + x - y] = false;
//         }
//     }
//     if (!flag) bishop(th + 1, size); // 이부분을 밖으로 빼내면 코드가 더 효율적이고 명확해집니다.
// }

// int main() {
//     ios::sync_with_stdio(0);
//     cin.tie(0);
//     cin >> n;

//     for (int i = 0; i < n; i++) // 체스판 입력 받음
//         for (int j = 0; j < n; j++)
//             cin >> board[i][j];

//     bishop(0, 0); // 우상향 대각선의 시작
//     cout << ans;
// }


#include <bits/stdc++.h>
using namespace std;

int N;
int ans = 0;


int leftDiag[20];
int rightDiag[20];
int board[10][10];

void bishop2(int t, int cnt){
    if(t >= 2*N-1){
        ans = max(ans, cnt);
        return;
    }
    int start_i = (t<N) ? 0 : t - N + 1;
    int end_i = min(t, N-1);

    bool flag = false;
    for(int i = start_i; i<=end_i; i++){
        int x = i;
        int y = t - i;
        if(board[x][y] == 1 && leftDiag[x+y]==0 
        && rightDiag[x-y+N-1] == 0){
            flag = true;
            leftDiag[x+y] = 1;
            rightDiag[x-y+N-1] = 1;
            bishop2(x+1, cnt+1);
            leftDiag[x+y] = 0;
            rightDiag[x-y+N-1] = 0;
        }
    }
    if(!flag)bishop2(t+1, cnt);
}

int main(){
    cin>>N;
    memset(leftDiag, 0, sizeof(leftDiag));
    memset(rightDiag, 0, sizeof(rightDiag));

    for(int i = 0; i<N; i++){
        for(int j = 0; j<N; j++){
            cin>>board[i][j];
        }
    }
    //bishop(0, 0, 0);
    bishop2(0, 0);
    cout<<ans<<endl;

}