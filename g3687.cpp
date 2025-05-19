//g3687 성냥개비
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
2 : 1
3 : 7
4 : 4
5 : 2 3 5
6 : 0 6 9
7 : 8
*/


vector<string> max_str;
vector<string> min_str;

void max_match_num(){
    max_str[2] = "1";
    max_str[3] = "7";

    for(int i = 4; i<=100; i++){
        max_str[i] = max_str[i-2] + "1";
    }
}
/*
    2 : 1
    3 : 7
    4 : 4 
    5 : 2 3 5
    6 : 0 6 9
    7 : 8

    n-8 > 1
    rest + 7 조합으로 최솟값 생성
     1, 7 -> 26(10)
     2, 7 -> 27(18)
     3, 7 -> 46(40)
     4, 7 -> 56(20)
     5, 7 -> 57(28)
     6, 7 -> 67(80)
*/

void min_match_num(){
    vector<string> str_units;
    str_units.push_back("");
    str_units.push_back("");
    str_units.push_back("1");
    str_units.push_back("7");
    str_units.push_back("4");
    str_units.push_back("2");
    str_units.push_back("0");
    str_units.push_back("8");

    for(int i = 0; i<=7; i++){
        min_str[i] = str_units[i];
    }
    min_str[6] = "6";


    for(int i = 8; i<=100; i++){
        string cur_str = "";

        for(int j = 2; j<=7; j++){
            if(min_str[i-j].empty())continue;
            string tmp = min_str[i - j] + str_units[j];
            if(cur_str == "" || cur_str.size() > tmp.size()
                             || cur_str.size() == tmp.size() && cur_str > tmp){
                cur_str = tmp;
            }
        }
        min_str[i] = cur_str;
    }
}



void solution_matchstick(){
    max_str.resize(101, "");
    min_str.resize(101, "");
    
    max_match_num();
    min_match_num();
    
    int T; cin>>T;
    while(T--){
        int n; cin>>n;
        cout<<min_str[n]<<" "<<max_str[n]<<endl;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solution_matchstick();

    return 0;
}

/*
4
3
6
7
15
*/
/*
7 7
6 111
8 711
108 7111111
*/
