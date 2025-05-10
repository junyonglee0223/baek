//g2011 암호코드
#include <iostream>
#include <vector>
using namespace std;

const int MOD = 1000000;

bool is_alphabet(string str){
    if(str[0] == '0')return false;
    int tmp_num = stoi(str);
    if(tmp_num >= 1 && tmp_num <= 26)return true;
    return false;
}

void solution_secretecode(){
    string num; cin>>num;

    vector<int>dp(num.size()+1, 0);
    dp[0] = is_alphabet(num.substr(0, 1)) ? 1 : 0;
    if(num.size() <= 1){
        cout<<dp[0]<<endl;
        return;
    }

    dp[1] = (is_alphabet(num.substr(1, 1)) ? dp[0] : 0) 
        + (is_alphabet(num.substr(0, 2)) ? 1 : 0);

    for(int i = 2; i<num.size(); i++){


        int tmp = 0;
        if(is_alphabet(num.substr(i, 1))){
            tmp += dp[i-1];
        }
        if(is_alphabet(num.substr(i-1, 2))){
            tmp += dp[i-2];
        }
        dp[i] = tmp % MOD;
    }

    cout<<dp[num.size() - 1]<<endl;
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solution_secretecode();

//     int T; cin>>T;
//     while(T--){
// //        solution_secretecode();
// }

    return 0;
}

/*
2
25114
1111111111
*/
/*
6
89
*/
