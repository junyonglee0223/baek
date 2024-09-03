#include <string>
#include <vector>

#include <iostream>
using namespace std;

vector<int> solution(int n, int s) {
    vector<int> answer;
    /*직접 나누는 것이 아니라 나누는 것을 최적화 해야 하는게 목표일 수도*/
    int candidate = s/n;
    if(candidate == 0){
        answer.push_back(-1);
        return answer;
    }
    for(int i = 0; i<n; i++){
        answer.push_back(candidate);
    }
    int now = candidate * n;
    int rest = s - now;
    for(int i = rest-1; i>=0; i--){
        answer[n - i - 1]+=1;
    }
    return answer;
}

int main(){
    int n[3] = {2, 2, 2};
    int s[3] = {9, 1, 8};
    for(int i = 0; i<3; i++){
        vector<int>tmp = solution(n[i], s[i]);
        for(int j = 0; j<tmp.size(); j++){
            cout<<tmp[j]<<" ";
        }
        cout<<endl;
    }
}
/*
| n | s | result |
| --- | --- | --- |
| 2 | 9 | [4, 5] |
| 2 | 1 | [-1] |
| 2 | 8 | [4, 4] |
*/