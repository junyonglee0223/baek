//g2342 Dance Dance Revolution
#include <iostream>
#include <vector>
#include <climits>
#include <cstring>
#include <algorithm>
using namespace std;


int dp[5][5][100001];
vector<int>steps;
int N;

/*
    0 1 2 3 4

0   1 2 2 2 2
1   2 1 3 4 3
2   2 3 1 3 4
3   2 4 3 1 3
4   2 3 4 3 1
*/

int getStep(int now, int nxt){
    if(now ==  0)return 2;
    if(now == nxt)return 1;
    if(abs(now - nxt) == 2)return 4;
    return 3;
}

int findMinStep(int idx, int left, int right){
    if(idx == N){
        return 0;
    }
    int& ret = dp[left][right][idx];
    if(ret != -1)return ret;

    int leftValue = getStep(left, steps[idx]);
    int rightValue = getStep(right, steps[idx]);

    ret = min(findMinStep(idx+1, steps[idx], right) + leftValue,
    findMinStep(idx+1, left, steps[idx]) + rightValue);

    return ret;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    memset(dp, -1, sizeof(dp));

    int ele; cin>>ele;
    while(ele != 0){
        steps.push_back(ele);
        cin>>ele;
    }
    N = steps.size();

    int answer = INT_MAX;
    answer = findMinStep(0, 0, 0);
    cout<<answer<<'\n';
}