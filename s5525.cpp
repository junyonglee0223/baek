//s5525 IOIOI
#include <iostream>
#include <vector>
#include <string>
using namespace std;

#define endl '\n'

string make_pattern(int n){
    if(n <= 0)return "";

    string ret = "I";
    for(int i = 0; i<n; i++){
        ret += "OI";
    }
    return ret;
}



int is_match_cnt(string str, string pattern){
    int n = str.size();
    int m = pattern.size();
    int ret = 0;

    for(int i = 0; i<= n - m; i++){
        bool tmp_flag = true;
        for(int j = 0; j<m; j++){
            if(str[i+j] != pattern[j]){
                tmp_flag = false;
                break;
            }
        }
        if(tmp_flag){
            ret++;
        }
    }
    return ret;
}


void soulution_IOIOI(){
    int N, M;
    cin>>N>>M;

    string str;
    cin>>str;

    string pattern = make_pattern(N);

    int answer = is_match_cnt(str, pattern);
    cout<<answer<<endl;
}


void solution_IOIOI_v3(){
    int N, M;
    cin >> N >> M;        
    string str;
    cin >> str;

    int answer = 0;
    
    int idx = 0;
    int len = 0;
    while(idx < M){
        if(str[idx] == 'O'){
            idx++;
        }
        if(str[idx] == 'I'){
            while(idx+2 < M){
                if(str[idx+1] == 'O' && str[idx+2] == 'I'){
                    idx += 2;
                    len += 1;
                }
                else{
                    break;
                }
            }
            if(len >= N){
                answer += (len - N + 1);
            }

            idx++;
            len = 0;
        }
    }
    cout<<answer<<endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

//    soulution_IOIOI();
    solution_IOIOI_v3();



    // int T; cin>>T;
    // while(T--){
    //     //soulution_IOIOI();
    //     solution_IOIOI_v3();

    // }

    return 0;
}


/*
2
1
13
OOIOIOIOIIOII
2
13
OOIOIOIOIIOII
*/
/*
4
2
*/