
//카카오 2021 1
#include <bits/stdc++.h>
#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    int answer = 0;
   
    int i = 0;
    while(i < s.size()) {
        //cout<<i<<"\t";              //test
        int num = 0;
        if (s[i] >= '0' && s[i] <= '9'){
            num = (s[i] - '0');
            i += 1;
        }
        else{
              
        if (s[i] == 'o') {
            i += 3;
            num = 1;
        }
        else if (s[i] == 't') {
            if (s[i + 1] == 'w') {
                i += 3;
                num = 2;
            }
            else {
                i += 5;
                num = 3;
            }
        }
        else if (s[i] == 'f') {
            if (s[i + 1] == 'o') {
                i += 4;
                num = 4;
            }
            else {
                i += 4;
                num = 5;
            }
        }
        else if (s[i] == 's') {
            if (s[i + 1] == 'i') {
                i += 3;
                num = 6;
            }
            else {
                i += 5;
                num = 7;
            }
        }
        else if (s[i] == 'e') {
            i += 5;
            num = 8;
        }
        else if (s[i] == 'n') {
            i += 4;
            num = 9;
        }
        else if (s[i] == 'z') {
            i += 4;
            num = 0;
        }
            
        }
         
        answer = answer * 10 + num;
        //cout<<i<<"\t" << num <<"\t";
        //cout<<answer<<endl;             //test
    }
    return answer;
}
