//g11066 파일 합치기
#include <iostream>
#include <vector>
using namespace std;


void solution_combine_file(){
    int n; cin>>n;
    vector<int>arr(n);
    vector<int>sum_arr(n);
    vector<vector<int>>dp(n, vector<int>(n, -1));

    for(int i = 0; i<n; i++){
        cin>>arr[i];
        sum_arr[i] = (i == 0) ? arr[i] : sum_arr[i-1] + arr[i];
        dp[i][i] = 0;
    }

    for(int len = 2; len <= n; len++){
        for(int i = 0; i<n - len + 1; i++){
            int idx = i + len - 1;

            int tmp = -1;

            int cur_num = sum_arr[idx] - (i>0 ? sum_arr[i-1] : 0);
            for(int k = i; k < idx; k++){
                int k_tmp = dp[i][k] + dp[k+1][idx] + cur_num;
                if(tmp == -1 || tmp > k_tmp){
                    tmp = k_tmp;
                }
            }
            dp[i][idx] = tmp;
        }
    }

    cout<<dp[0][n-1]<<endl;
}

void solution_combine_file_v1(){
    int n; cin>>n;
    vector<int>arr(n);
    vector<int>sum_arr(n);
    vector<vector<int>>dp(n, vector<int>(n, -1));
    vector<vector<int>>dp_idx(n, vector<int>(n, -1));

    for(int i = 0; i<n; i++){
        cin>>arr[i];
        sum_arr[i] = (i == 0) ? arr[i] : sum_arr[i-1] + arr[i];
        dp[i][i] = 0;
        dp_idx[i][i] = i;
    }

    for(int len = 2; len <= n; len++){
        for(int i = 0; i<n - len + 1; i++){
            int idx = i + len - 1;

            int tmp = -1;
            int tmp_idx = -1;

            int cur_num = sum_arr[idx] - (i>0 ? sum_arr[i-1] : 0);
            int start = max(i, dp_idx[i][idx-1]);
            int end = min(idx-1, dp_idx[i+1][idx]);

            for(int k = start; k <= end; k++){
                int k_tmp = dp[i][k] + dp[k+1][idx] + cur_num;
                if(tmp == -1 || tmp > k_tmp){
                    tmp = k_tmp;
                    tmp_idx = k;
                }
            }
            dp[i][idx] = tmp;
            dp_idx[i][idx] = tmp_idx;
        }
    }

    cout<<dp[0][n-1]<<endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; cin>>T;
    while(T--){
//        solution_combine_file();
        solution_combine_file_v1();
    }

    return 0;
}

/*
2
4
40 30 30 50
15
1 21 3 4 5 35 5 4 3 5 98 21 14 17 32
*/
/*
300
864
*/