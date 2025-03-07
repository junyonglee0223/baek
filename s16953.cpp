//s16953번 A → B
#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <algorithm>
#include <map>
using namespace std;

#define endl '\n'

void solution_A_2_B(){
    int A, B; cin>>A>>B;

    vector<int>num_cnt(B+1, -1);
    queue<int>q;

    q.push(A);
    num_cnt[A] = 0;

    while(!q.empty()){
        int cur_num = q.front();
        q.pop();

        vector<int>nxt_nums;
        nxt_nums.push_back(2 * cur_num);
        nxt_nums.push_back(10 * cur_num + 1);

        for(auto nxt_num : nxt_nums){
            if(nxt_num <= B && num_cnt[nxt_num] == -1){
                q.push(nxt_num);
                num_cnt[nxt_num] = num_cnt[cur_num] + 1;
                //cout<<nxt_num<<" "<<num_cnt[nxt_num]<<endl;//test
            }
        }
    }
    cout<<(num_cnt[B] == -1 ? -1 : num_cnt[B] + 1)<<endl;
}

typedef long long ll;
void solution_A_2_B_V1(){
    ll A, B; cin>>A>>B;
    
    map<ll, ll> mp_num;
    queue<ll>q;

    mp_num[A] = 0;
    q.push(A);

    while(!q.empty()){
        ll cur_num = q.front();
        q.pop();

        vector<ll>nxt_nums;
        nxt_nums.push_back(cur_num * 2);
        nxt_nums.push_back(cur_num * 10 + 1);

        for(auto nxt_num : nxt_nums){
            if(nxt_num <= B && mp_num.find(nxt_num) == mp_num.end()){
                mp_num[nxt_num] = mp_num[cur_num] + 1;
                q.push(nxt_num);
            }
        }
    }

    cout<<(mp_num.find(B) == mp_num.end() ? -1 : mp_num[B] + 1)<<endl;
}
int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(0);
    solution_A_2_B_V1();

    // int T; cin>>T;
    // while(T--){
    //     solution_A_2_B_V1();
    // }

    return 0;
}


/*
5
-1
5
*/

/*
3
2 162
4 42
100 40021
*/