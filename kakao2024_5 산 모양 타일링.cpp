#include <bits/stdc++.h>
#include <string>
#include <vector>

using namespace std;

const int MOD = 10007;

int a[100001];
int b[100001];


int solution(int n, vector<int> tops) {
    int answer = 0;
    a[0] = b[0] = 1;

    for(int i = 0; i<tops.size(); i++){
        if(tops[i] == 1){
            //i+1로
            a[i+1] = (a[i] + b[i])%MOD;
            b[i+1] = (a[i] * 2 + b[i] * 3)%MOD;
        }
        else{
            a[i+1] = (a[i] + b[i])%MOD;
            b[i+1] = (a[i] + b[i] * 2)%MOD;
        }
    }

    answer = (a[n] + b[n])%MOD;

    return answer;
}
