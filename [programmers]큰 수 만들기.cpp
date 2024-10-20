#include <string>
#include <vector>

#include <algorithm>
#include <iostream>

using namespace std;

string solution(string number, int k) {
    string answer = "";
    int n = number.length();

    int cnt = 0;
    int idx = 0;
    while(cnt < k && idx < number.size()){
        if(idx+1 < n && (number[idx]) < (number[idx+1])){
            number.erase(idx, 1);
            idx = idx-1 < 0 ? idx:idx-1; 
            cnt += 1;
        }
        else{
            idx += 1;
        }
    }
    idx -= 1;
    while(cnt < k && idx >= 0){
        number.erase(idx, 1);
        idx -= 1;
        cnt += 1;
    }
    answer = number;    
    return answer;
}