//g1311 할 일 정하기1
#include <iostream>
#include <vector>
#include <climits>
using namespace std;


int bit_count(int mask){
    int ret = 0;
    while(mask){
        if(mask & 1){
            ret++;
        }
        mask = (mask >> 1);
    }
    return ret;
}

void solution_schedule_do_work(){
    int n; cin>>n;
    vector<vector<int>>board(n, vector<int>(n, 0));

    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            cin>>board[i][j];
        }
    }

    int FULL = 1<<n;
    const int INF = INT_MAX/2;
    vector<int> dp(FULL, INF);
    dp[0] = 0;
    for (int mask = 0; mask < FULL; ++mask) {
        int i = bit_count(mask); 
        if (i >= n) continue;
        for (int j = 0; j < n; ++j) {
            if (!(mask & (1<<j))) {
                int nxt = mask | (1<<j);
                dp[nxt] = min(dp[nxt], dp[mask] + board[i][j]);
            }
        }
    }
    cout << dp[FULL-1];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solution_schedule_do_work();

    return 0;
}


/*
3
2 3 3
3 2 3
3 3 2
*/
/*
6
*/