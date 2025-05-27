//g2515 전시장
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define endl '\n'


void solution_exhibition_hall(){
    int n, s; cin>>n>>s;

    vector<pair<int, int>>arr(n);
    vector<int>height(n, 0);
    vector<int>cost(n);
    vector<int>arr_idx(n, -1);


    for(int i = 0; i<n; i++){
        cin>>arr[i].first>>arr[i].second;
    }
    
    sort(arr.begin(), arr.end());

    for(int i = 0; i<n; i++){
        height[i] = arr[i].first;
        cost[i] = arr[i].second;
    }

    int idx = 0;
    for(int i = 0; i<n; i++){

        while(height[idx] + s <= height[i]){
            idx++;
        }

        idx--;
        arr_idx[i] = idx;
    }


    vector<int>dp(n, 0);
    dp[0] = cost[0];

    for(int i = 1; i<n; i++){
        dp[i] = max(cost[i], dp[i-1]);

        if(arr_idx[i] != -1){
            dp[i] = max(dp[i-1], dp[arr_idx[i]] + cost[i]);
        }
    }

    cout<<dp[n-1]<<endl;
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solution_exhibition_hall();

    // int T; cin>>T;
    // while(T--){
    //     solution_exhibition_hall();
    // }


    return 0;
}


/*
2
6 4
15 80
8 230
10 100
17 200
20 75
26 80
9 3
8 30
5 10
14 50
12 80
8 20
16 50
11 60
15 40
10 50
*/
/*
510
170
*/