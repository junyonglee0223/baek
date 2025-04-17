//s2156 포도주 시식
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


void print_dp(vector<vector<int>>&vec){
    int n = vec.size();
    int m = 3;
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            cout<<vec[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}


void solution_wine_tasting(){
    int n; cin>>n;
    vector<vector<int>>dp(n+1, vector<int>(3, 0));
    vector<int>wines(n+1);

    for(int i = 1; i<=n; i++){
        cin>>wines[i];
    }

    for(int i = 1; i<=n; i++){
        dp[i][0] = max({dp[i-1][2], dp[i-1][1], dp[i-1][0]});
        if(i >= 1){
            dp[i][1] = dp[i-1][0] + wines[i];
        }
        if(i >= 2){
            dp[i][2] = dp[i-2][0] + wines[i] + wines[i-1];
        }
    }

    int answer = max({dp[n][0], dp[n][1], dp[n][2]});
    cout<<answer<<endl;

    //print_dp(dp);//test
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solution_wine_tasting();

    return 0;
}

/*
6
6
10
13
9
8
1
*/
/*
33
*/