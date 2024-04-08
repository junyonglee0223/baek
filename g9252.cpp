//LCS 2


#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

string str1, str2;
vector<vector<int>>dp;


// int compare_str(int idx1, int idx2){
//     if(idx1 == 0 && idx2 == 0){
//         if(str1[idx1] == str2[idx2])return 1;
//         return 0;
//     }
    
//     int& ret = dp[idx1][idx2];
//     if(ret != -1)return ret;
//     ret = 0;

//     for(int i = 0; i<=idx1; i++){
//         for(int j = 0; j<=idx2; j++){
//             if(str1[i] == str2[j]){
//                 ret = max(ret, compare_str(i, j) + 1);
//             }
//         }
//     }
//     return ret;
// }


// void compare_str(){
//     int len1 = str1.size();
//     int len2 = str2.size();
//     for(int i = 0; i<len1; i++){
//         for(int j = 0; j<len2; j++){
//             if(i == 0 && j == 0){
//                 str1[0] == str2[0] ? dp[0][0] = 1: dp[0][0] = 0;
//                 continue;
//             }
//             if(str1[i] == str2[j]){
//                 dp[i][j] = max(dp[i][j], dp[i-1][j-1] + 1);
//             }
//             else{
//                 dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
//             }
//         }
//     }
// }


// string reconstruct_str(int idx1, int idx2, string ret){
//     if(idx1 == 0 && idx2 == 0){
//         if(str1[0] == str2[0])
//             ret += str1[0];
//         return ret;
//     }

//     if(str1[idx1] == str2[idx2] 
//     && dp[idx1][idx2] == dp[idx1-1][idx2-1]){
//         ret += (str1[idx1]);
//         reconstruct_str(idx1-1, idx2-1, ret);
//     }
//     else{
//         if(idx1 == 0){
//             reconstruct_str(idx1, idx2-1, ret);
//         }
//         else if(idx2 == 0){
//             reconstruct_str(idx1-1, idx2, ret);
//         }
//         else{
//             reconstruct_str(idx1-1, idx2, ret);
//             reconstruct_str(idx1, idx2-1, ret);
//         }
//     }
// }

// int compare_str(int idx1, int idx2) {
    
//     int& ret = dp[idx1][idx2];
//     if (ret != -1)return ret;
//     if(idx1 == str1.size() -1 && idx2 == str2.size() - 1){
//         if(str1[idx1] == str2[idx2]){
//             return ret = 1;
//         }
//         else{
//             return ret = 0;
//         }
//     }

//     if (str1[idx1] == str2[idx2]) {
//         ret = max(ret, compare_str(idx1+1, idx2+1) + 1);
//     }
//     else {
//         ret = max(ret, compare_str((idx1 + 1 >= str1.size()) ? str1.size()-1 : idx1+1, idx2));
//         ret = max(ret, compare_str(idx1, (idx2 + 1 >= str2.size()) ? str2.size()-1 : idx2+1));
//     }
//     return ret;
// }

void calcLCS(){
    int len1 = str1.size();
    int len2 = str2.size();
    dp[0][0] = (str1[0] == str2[0]) ? 1 : 0 ;
    dp[0][1] = (str1[0] == str2[1]) ? 1 : 0 ;
    dp[1][0] = (str1[1] == str2[0]) ? 1 : 0 ;
    

    for(int i = 1; i<len1; i++){
        for(int j = 1; j<len2; j++){
            if(str1[i] == str2[j]){
                dp[i][j] = dp[i-1][j-1] + 1;
            }
            else{
                dp[i][j] = max(dp[i][j], dp[i-1][j]);
                dp[i][j] = max(dp[i][j], dp[i][j-1]);
            }
        }
    }
}

string reconstructLCS(){
    string ret = "";
    int i = str1.size() - 1;
    int j = str2.size() - 1;
    while(i >= 1 && j >= 1){
        if(str1[i] == str2[j]){
            ret += str1[i];
            i--; j--;
        }
        else if(dp[i-1][j] > dp[i][j-1]){
            i--;
        }
        else{
            j--;
        }
    }
    reverse(ret.begin(), ret.end());
    return ret;
}

int main(){
    cin>>str1>>str2;
    dp.resize(str1.size(), vector<int>(str2.size(), -1));
    calcLCS();
    string ans = reconstructLCS();
    cout<<ans<<"\n";
}

/*

예제 입력 1 
ACAYKP
CAPCAK
예제 출력 1 
4
ACAK

*/



