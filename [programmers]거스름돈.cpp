#include <string>
#include <vector>

#include <algorithm>
using namespace std;

const int MOD = 1000000007;

int solution(int n, vector<int> money) {
    int answer = 0;
    vector<int>cnt(100001, 0);
    cnt[0] = 1;
    for(int i = 0; i<money.size(); i++){
        for(int j = 0; j<100001; j++){
            if(j - money[i] >= 0){
                cnt[j] += cnt[j - money[i]];
                cnt[j] %= MOD;
            }
        }
    }
    answer = cnt[n];
    return answer;
}