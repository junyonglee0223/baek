#include <string>
#include <vector>

#include <iostream>
#include <algorithm>
using namespace std;

vector<vector<int>>dp;

int calc_matrix(int src, int dst, vector<vector<int>>&m){
    int& ret = dp[src][dst];
    if(ret != -1)return ret;
    if(dst <= src)return 0;
    if(dst == src + 1){
        ret = m[src][0]*m[src][1]*m[dst][1];
        return ret;
    }
    /*1.6*10^9*/
    ret = 2147483647;
    for(int i = src; i<dst; i++){
        ret = min(ret, 
        calc_matrix(src, i, m) + calc_matrix(i+1, dst, m)
            + m[src][0]*m[dst][1]*m[i][1]);
    }
    return ret;
}

int solution(vector<vector<int>> matrix_sizes) {
    int answer = 0;
    int n = matrix_sizes.size();
    dp.resize(n, vector<int>(n, -1));
    answer = calc_matrix(0, n-1, matrix_sizes);
    return answer;
}

int main(){
    vector<vector<int>>matrix_sizes = {{5, 3}, {3, 10}, {10, 6}};
    cout<<solution(matrix_sizes)<<endl;
}