//g15486 퇴사 2
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define MAX_N 1500001

void solution_resign_two(){
    int n; cin>>n;

    vector<int>days(n+1, 0);
    vector<int>benefits(n+1, 0);
    vector<vector<int>>rev_days(n+2);

    for(int i = 1; i<=n; i++){
        int a, b; cin>>a>>b;
        days[i] = a;
        benefits[i] = b; 

        if(i + a <= n+1)
            rev_days[i + a].push_back(i);
    }

    vector<int>dp(n+2, 0);

    for(int i = 1; i<=n+1; i++){
        int tmp = 0;
        for(auto ele : rev_days[i]){
            if(i < ele) continue;
            tmp = max(tmp, dp[ele] + benefits[ele]);
        }
        dp[i] = max(dp[i-1], tmp);
    }
    cout<<dp[n+1]<<endl;
}

void solution_resign_two_v1(){
    int n; cin>>n;

    vector<int>days(n+1, 0);
    vector<int>benefits(n+1, 0);

    for(int i = 1; i<=n; i++){
        int a, b; cin>>a>>b;
        days[i] = a;
        benefits[i] = b; 
    }

    vector<long long> dp(n+2, 0);

    for(int i = 1; i<=n+1; i++){
        dp[i] = max(dp[i], dp[i-1]);
        if(i<=n && i + days[i] <= n+1){
            dp[i+days[i]] = max(dp[i+days[i]], dp[i] + benefits[i]);
        }
    }
    cout<<dp[n+1]<<endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

//    solution_resign_two();
    solution_resign_two_v1();

    // int T; cin>>T;
    // while(T--){
    //     //solution_resign_two();
    //     solution_resign_two_v1();
    // }

    return 0;
}


/*
4
7
3 10
5 20
1 10
1 20
2 15
4 40
2 200
10
1 1
1 2
1 3
1 4
1 5
1 6
1 7
1 8
1 9
1 10
10
5 10
5 9
5 8
5 7
5 6
5 10
5 9
5 8
5 7
5 6
10
5 50
4 40
3 30
2 20
1 10
1 10
2 20
3 30
4 40
5 50
*/
/*
45
55
20
90
*/