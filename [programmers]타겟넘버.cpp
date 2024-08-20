#include <string>
#include <vector>

#include <iostream>
using namespace std;

int dfs_number(int idx, int sum, vector<int>&nums, int target){
    if(idx == nums.size()){
        return sum == target ? 1 : -1;
    }
    int ret = 0;
    int tmp1 = dfs_number(idx+1, sum + nums[idx], nums, target);
    int tmp2 = dfs_number(idx+1, sum - nums[idx], nums, target);
    if(tmp1 != -1) 
        ret += tmp1;
    if(tmp2 != -1)
        ret += tmp2;
    return ret;
}

int solution(vector<int> numbers, int target) {
    int answer = 0;
    vector<int>test;
    test.push_back(numbers[0]);
    answer = dfs_number(0, 0, numbers, target);
    return answer;
}