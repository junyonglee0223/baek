#include <string>
#include <vector>

#include <iostream>
#include <map>
#include <queue>
using namespace std;

/*
bottom up 방식과 topdown 방식 두가지 있는데 
n이 과도하게 크다면 topdown으로 하는게 좋을텐데
14개니까 그렇게 까지 고려하진 않아도 될 듯


비트마스킹으로 유도하려고 적게준건가???

중복 제거가 중요할 듯 - 과연?

*/

/*problem of below code
stack memory overflow!!!

if you want to code like this then 
bottom could solve problem*/
int cnt_parenthesis_test(int n, int zero, int one, int size){
    if(zero > size)return 0;
    if(one > size) return 0;
    if(zero > one)return 0;

    if(n == 0){
        if(zero == size && one == size)return 1;
        return 0;
    }

    int ret = 0;
    int tmp2 = cnt_parenthesis_test(n-1, zero, one+1, size);
    int tmp1 = cnt_parenthesis_test(n-1, zero+1, one, size);


    ret = tmp1+tmp2;

    return ret;
}

map<pair<int,int>, int>mp;
/*change point this function activate focus on add elements*/
int calc_parenthesis_bfs(int n){
    queue<pair<int, int>>q;
    q.push({1, 0});
    mp[{1, 0}] = 1;

    while(!q.empty()){
        int z = q.front().first;
        int o = q.front().second;
        q.pop();

        if(z+1 <= n){
            q.push({z+1, o});
            mp[{z+1, o}]+=1;
        }
        if(z >= o+1 && o+1<=n){
            q.push({z, o+1});
            mp[{z, o+1}]+=1;
        }


    }
    return mp[{n, n}];
}

int solution(int n) {
    int answer = 0;
    //answer = cnt_parenthesis_test(n*2, 0, 0, n);
    answer = calc_parenthesis_bfs(n);
    return answer;
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int tests[2] = {2, 3};
    for(auto test : tests){
        cout<<solution(test)<<endl; 
    }
}

/*

n	result
2	2
3	5
*/