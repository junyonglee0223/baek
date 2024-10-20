#include <string>
#include <vector>

#include <iostream>
#include <set>
using namespace std;

vector<vector<int>>candidates;

bool isBanned(string id, string banned_id){
    int idsize = id.size();
    int bsize = banned_id.size();
    /*use two pointer*/
    int idx = 0;
    int bidx = 0;
    while(idx<idsize && bidx<bsize){
        if(id[idx] == banned_id[bidx]){
            idx++;bidx++;
        }
        else{
            if(banned_id[bidx]=='*'){
                idx++;bidx++;
            }
            else{
                // if(bidx>=1&&banned_id[bidx-1]=='*'){
                //     while(idx<idsize && id[idx] != banned_id[bidx]){
                //         idx+=1;
                //     }
                // }
                // else{
                //     return false;
                // }
                return false;
            }
        }
    }
    /*two case 
    1. left bidx -> must return false
    2. left idx -> 
    */
    if(bidx != bsize)
        return false;
    if(idx != idsize){
        // if(banned_id[bsize-1]=='*')
        //     return true;
        // else
        //     return false;
        return false;
    }
    return true;

}

set<set<int>>banned_set;

void dfs(int idx, set<int>&visited){
    int n = candidates.size();
    if(idx == n){
        if(banned_set.find(visited)==banned_set.end()){
            banned_set.insert(visited);
        }
        return;
    }
    for(auto candidate : candidates[idx]){
        if(visited.find(candidate)==visited.end()){
            visited.insert(candidate);
            dfs(idx+1, visited);
            visited.erase(candidate);
        }
    }
    return;
}

int solution(vector<string> user_id, vector<string> banned_id) {
    int answer = 0;
    candidates.resize(banned_id.size());

    for(int i = 0; i<banned_id.size(); i++){
        for(int j = 0; j<user_id.size(); j++){
            if(isBanned(user_id[j], banned_id[i])){
                candidates[i].push_back(j);
            }
        }
    }

    set<int>visited;
    dfs(0, visited);
    answer = banned_set.size();
    return answer;
}

// int main(){
//     vector<string>user_id;
//     vector<string>banned_id;
//     int select_test; cin>>select_test;
//     int N, M;
//     switch (select_test)
//     {
//     case 1:
//         N=5; M=2;
//         break;
//     case 2:
//         N=5; M=3;        /* code */
//         break;
//     case 3:
//         N=5; M=4;        /* code */
//         break;
        
//     default:
//         break;
//     }

//     for(int i = 0; i<N; i++){
//         string str; cin>>str;
//         user_id.push_back(str);
//     }
//     for(int i = 0; i<M; i++){
//         string str; cin>>str;
//         banned_id.push_back(str);
//     }
//     cout<<solution(user_id, banned_id)<<endl;
    
//     for(int i = 0; i<candidates.size(); i++){
//         cout<<i<<"=\t";
//         for(auto ele : candidates[i]){
//             cout<<user_id[ele]<<" ";
//         }
//         cout<<endl;
//     }
// }


/*

### **[제한사항]**

- user_id 배열의 크기는 1 이상 8 이하입니다.
- user_id 배열 각 원소들의 값은 길이가 1 이상 8 이하인 문자열입니다.
    - 응모한 사용자 아이디들은 서로 중복되지 않습니다.
    - 응모한 사용자 아이디는 알파벳 소문자와 숫자로만으로 구성되어 있습니다.
- banned_id 배열의 크기는 1 이상 user_id 배열의 크기 이하입니다.
- banned_id 배열 각 원소들의 값은 길이가 1 이상 8 이하인 문자열입니다.
    - 불량 사용자 아이디는 알파벳 소문자와 숫자, 가리기 위한 문자 '*' 로만 이루어져 있습니다.
    - 불량 사용자 아이디는 '*' 문자를 하나 이상 포함하고 있습니다.
    - 불량 사용자 아이디 하나는 응모자 아이디 중 하나에 해당하고 같은 응모자 아이디가 중복해서 제재 아이디 목록에 들어가는 경우는 없습니다.
- 제재 아이디 목록들을 구했을 때 아이디들이 나열된 순서와 관계없이 아이디 목록의 내용이 동일하다면 같은 것으로 처리하여 하나로 세면 됩니다.
user_id	banned_id	result
["frodo", "fradi", "crodo", "abc123", "frodoc"]	["fr*d*", "abc1**"]	2
["frodo", "fradi", "crodo", "abc123", "frodoc"]	["*rodo", "*rodo", "******"]	2
["frodo", "fradi", "crodo", "abc123", "frodoc"]	["fr*d*", "*rodo", "******", "******"]	3
*/

/*
1
frodo
fradi
crodo
abc123
frodoc
fr*d*
abc1**




2
frodo
fradi
crodo
abc123
frodoc
*rodo
*rodo
******


3
frodo
fradi
crodo
abc123
frodoc
fr*d*
*rodo
******
******
*/