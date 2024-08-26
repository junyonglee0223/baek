#include <vector>
#include <unordered_map>
#include <iostream>
using namespace std;


int answer;
void rev_higher(int high, int cur, int m, int p){
    
    if(cur<3)return;
    if(m < (p<<1))return;
    if(p > high)return;
    if(m > (high << 1))return;

    if(cur == 3 && ((p+1)<<1) == m){
        answer+=1;
        return;
    }

    if(cur%3==0){
        rev_higher(high, cur/3, m, p+1);
    }
    rev_higher(high, cur-1, m+1, p);
}

int solution(int n) {
    answer = 0;
    int high_idx[19] = {1};
    int tmp = -2;
    for(int i = 1; i<20; i++){
        high_idx[i] = high_idx[i-1]*3 - tmp;
        tmp+=4;
    }
    int high = 0;
    for(; high<20; high++){
        if(high_idx[high] > n){
            high -= 1;
            break;
        }
    }
    rev_higher(high, n-2, 2, 0);
    return answer;
}

int main(){
    vector<int> test_cases = {15, 24, 41};
    for(int n : test_cases) {
        cout << "Result for " << n << ": " << solution(n) << endl;
    }
    cout << "Result for " << 2147483647 << ": " << solution(2147483647) << endl;
    return 0;
}

