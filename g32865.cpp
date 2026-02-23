#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define endl '\n'
typedef pair<int,int> pii;

void solution_comsoin_s_christmas(int n, vector<int>fail_cnt){
    queue<int>complete_ele;
    queue<pii> ready_que;

    for(int i = 0; i<fail_cnt.size(); i++){
        if(fail_cnt[i] == 0){
            complete_ele.push(i+1);
        }
        else{
            ready_que.push({fail_cnt[i], i+1});
        }
    }

    if(complete_ele.empty()){
        cout<<-1<<endl;
        return;
    }

    vector<int>ans;

    for(int i = 0; i<(2*n - 1); i++){
        if(i % 2 != 0){
            if(ready_que.empty()){
                cout<<-1<<endl;
                return;
            }
            ready_que.front().first -= 1;
            ans.push_back(ready_que.front().second);
            if(ready_que.front().first == 0){
                complete_ele.push(ready_que.front().second);
                ready_que.pop();
            }            

        }else{
            if(complete_ele.empty()){
                cout<<-1<<endl;
                return;
            }
            ans.push_back(complete_ele.front());
            complete_ele.pop();
        }

    }
    if(!ready_que.empty() || !complete_ele.empty()){
        cout<<-1<<endl;
        return;
    }
    for(auto i : ans){
        cout<<i<<endl;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin>>n;
    vector<int>fail_cnt(n);

    int tot_fail_cnt = 0;
    for(int i = 0; i<n; i++){
        cin>>fail_cnt[i];
        tot_fail_cnt += fail_cnt[i];
    }

    if(tot_fail_cnt >= n){
        cout<<-1<<endl;
        return 0;
    }

    solution_comsoin_s_christmas(n, fail_cnt);
    return 0;
}
