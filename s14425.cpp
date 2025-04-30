//s14425 문자열 집합
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

#define endl '\n'

void solution_string_set_v2(){
    int n, m; cin>>n>>m;

    set<string>texts;
    vector<string>patterns;

    for(int i = 0; i<n; i++){
        string tmp_str; cin>>tmp_str;
        texts.insert(tmp_str);
    }
    int answer = 0;
    for(int i = 0; i<m; i++){
        string tmp_str; cin>>tmp_str;
        if(texts.find(tmp_str) != texts.end()){
            answer++;
        }
    }

    cout<<answer<<endl;
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solution_string_set_v2();

    return 0;
}


/*
5 11
baekjoononlinejudge
startlink
codeplus
sundaycoding
codingsh
baekjoon
codeplus
codeminus
startlink
starlink
sundaycoding
codingsh
codinghs
sondaycoding
startrink
icerink
*/
/*
4
*/