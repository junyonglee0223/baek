//g5052 전화번호 목록
#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <unordered_set>
using namespace std;

#define endl '\n'

bool is_consistency(int n, vector<string> texts){
    unordered_set<string>txt_set;
    for(int i = 0; i<texts.size(); i++){
        for(int len = 1; len < texts[i].size(); len++){
            txt_set.insert(texts[i].substr(0, len));
        }
    }

    bool ret = false;
    for(int i = 0; i<n; i++){
        if(txt_set.find(texts[i]) != txt_set.end()){
            return false;
        }
    }
    return true;
}


void solution_diary_list(){
    int T; cin>>T;
    while(T--){
        int n; cin>>n;
        vector<string>texts;
        for(int i = 0; i<n; i++){
            string str; cin>>str;
            texts.push_back(str);
        }
        if(is_consistency(n, texts)){
            cout<<"YES"<<endl;
        }else{
            cout<<"NO"<<endl;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solution_diary_list();

    return 0;
}

/*
2
3
911
97625999
91125426
5
113
12340
123440
12345
98346
*/
/*
NO
YES
*/