#include <string>
#include <vector>

#include <algorithm>
using namespace std;

bool isPosHeight(long long h, int n, vector<int>times){
    long long sum = 0;
    for(int i = 0; i<times.size(); i++){
        sum += (h/times[i]);
        if(sum >= n){
            return true;
        }
    }
    return false;
}
long long findMinHeight(int n, vector<int>times){
    long long left = 0;
    long long right = static_cast<long long>(times[times.size()-1]) * n;

    while(left < right){
        long long mid = ((left + right)>>1);
        if(isPosHeight(mid, n, times)){
            right = mid;
        }
        else{
            left = mid+1;
        }
    }
    return right;
}

long long solution(int n, vector<int> times) {
    long long answer = 0;
    sort(times.begin(), times.end());
    answer = findMinHeight(n, times);
    return answer;
}
