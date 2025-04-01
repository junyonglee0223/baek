//s11727 2×n 타일링 2
#include <iostream>
#include <vector>
using namespace std;


const int MOD = 10007;

void solution_2_multi_n_tiling(){
    int n; cin>>n;

    vector<int>dp(2002, -1);
    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 3;
    for(int i = 3; i<=n; i++){
        dp[i] = (dp[i-1] + dp[i-2] * 2)%MOD;
    }

    cout<<dp[n]<<endl;
}

vector<vector<int>>multiple_vec(vector<vector<int>>&a, vector<vector<int>>&b){
    vector<vector<int>>ret(2, vector<int>(2, 0));
    for(int i = 0; i<2; i++){
        for(int j = 0; j<2; j++){
            ret[i][j] = 0;
            for(int k = 0; k<2; k++){
                ret[i][j] += (a[i][k] * b[k][j])%MOD; 
                ret[i][j] %= MOD;
            }
        }
    }
    return ret;
}

vector<vector<int>>pow_vec(vector<vector<int>>&x, int n){
    vector<vector<int>>ret = {{1, 0}, {0, 1}};
    vector<vector<int>>tmp = x;
    while(n > 0){
        if(n % 2){
            ret = multiple_vec(ret, tmp);
            n -= 1;
        }
        tmp = multiple_vec(tmp, tmp);
        n = n/2;
    }
    return ret;
}

void solution_2_multi_n_tiling_v1(){
    int n; cin>>n;

    vector<vector<int>>init = {{1, 1}, {1, 0}};
    vector<vector<int>>multi_unit = {{1, 2}, {1, 0}};

    vector<vector<int>> n_pow = pow_vec(multi_unit, n-1);
    vector<vector<int>> ret = multiple_vec(n_pow, init);
    cout<<ret[0][0]<<endl;
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solution_2_multi_n_tiling();

    // int T; cin>>T;
    // while(T--){
    //     solution_2_multi_n_tiling_v1();
    // }

    return 0;
}

/*
3
2
8
12
*/
/*
3
171
2731
*/