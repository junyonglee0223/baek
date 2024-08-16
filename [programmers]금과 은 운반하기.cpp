#include <string>
#include <vector>
#include <climits>
using namespace std;

bool isPosTime(int a, int b, vector<int>g, vector<int>s, vector<int>w, vector<int>t, long long time){
    long long total_gold = 0;
    long long total_silver = 0;
    long long total_weight = 0;

    int n = g.size();
    for(int i = 0; i<n; i++){
        long long maxTrips = time / (2LL * t[i]);
        long long remainingTime = time % (2LL * t[i]);

        long long maxCarry = maxTrips * (long long)w[i];
        if(remainingTime >= (long long)t[i])
            maxCarry += (long long)w[i];
        total_gold += min(static_cast<long long>(g[i]), maxCarry);
        total_silver += min(static_cast<long long>(s[i]), maxCarry);
        total_weight += min(static_cast<long long>(g[i]+s[i]), maxCarry);
    }
    return total_gold>=(long long)a && total_silver>=(long long)b && total_weight>=(long long)(a+b);
}



long long solution(int a, int b, vector<int> g, vector<int> s, vector<int> w, vector<int> t) {
    long long answer = -1;
    long long left = 0;
    long long right = 4e14;
    while(left <= right){
        long long mid = (left + right)/2;
        if(isPosTime(a, b, g, s, w, t, mid)){
            answer = mid;
            right = mid - 1;
        }
        else{
            left = mid + 1;
        }
    }
    return answer;
}