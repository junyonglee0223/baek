#include <string>
#include <vector>
#include <iostream>

using namespace std;
#define endl '\n'

int solution(vector<vector<int>> triangle) {
    int answer = 0;
    int n = triangle[triangle.size() - 1].size();
    vector<int>ret(n, 0);
    ret[0] = triangle[0][0];
    for(int i = 1; i<triangle.size(); i++){
        vector<int>tmp(n, 0);
        tmp[0] = ret[0]+triangle[i][0];
        for(int j = 0; j<triangle[i].size(); j++){
            tmp[j] = max(ret[j], ret[j-1])+triangle[i][j];
        }    
        for(int j = 0; j<n; j++){
            ret[j] = tmp[j];
            answer = max(answer, ret[j]);
        }
    }
    return answer;
}