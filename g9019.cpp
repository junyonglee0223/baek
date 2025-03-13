//g9019 DSLR
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

#define endl '\n'

const int MOD = 10000;

vector<char>calc_idx;
vector<int>parent_num;

string do_calc_v3(int A, int B){
    char char_idx[4] = {'D', 'S', 'L', 'R'};

    vector<bool>visited(10000, false);
    queue<int>q;

    visited[A] = true;
    q.push(A);

    while(!q.empty()){
        int cur = q.front();
        q.pop();

        int nxt = (cur * 2) % MOD;
        if(visited[nxt] == false){
            visited[nxt] = true;
            calc_idx[nxt] = 'D';
            parent_num[nxt] = cur;
            q.push(nxt);
        }
        
        nxt = (cur - 1 + MOD) % MOD;
        if(visited[nxt] == false){
            visited[nxt] = true;
            calc_idx[nxt] = 'S';
            parent_num[nxt] = cur;
            q.push(nxt);
        }
        nxt = (cur * 10) % MOD + (cur / 1000);
        if(visited[nxt] == false){
            visited[nxt] = true;
            calc_idx[nxt] = 'L';
            parent_num[nxt] = cur;
            q.push(nxt);
        }
        nxt = (cur % 10) * 1000 + (cur / 10);
        if(visited[nxt] == false){
            visited[nxt] = true;
            calc_idx[nxt] = 'R';
            parent_num[nxt] = cur;
            q.push(nxt);
        }
    }

    int now = B;
    string ret;
    while(now != A){
        ret += calc_idx[now];
        now = parent_num[now];
    }
    reverse(ret.begin(), ret.end());
    return ret;
}




void solution_DSLR(){
    int T; cin>>T;
    while(T--){
        int A, B; cin>>A>>B;

        calc_idx.clear();
        parent_num.clear();

        calc_idx.resize(10000);
        parent_num.resize(10000, -1);

        //cout<<do_calc(A, B)<<endl;
        //cout<<do_calc_v2(A, B)<<endl;
        cout<<do_calc_v3(A, B)<<endl;

        // //test
        // string t = int_2_string(A);
        // cout<<calc_D(t)<<endl;
        // cout<<calc_S(t)<<endl;
        // cout<<calc_R(t)<<endl;
        // cout<<calc_L(t)<<endl;
        // //test
    }

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    solution_DSLR();

}

/*
LL
L
DDDD

*/

/*

3
1234 3412
1000 1
1 16

*/