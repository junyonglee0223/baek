//g7662 이중 우선순위 큐
#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <set>
using namespace std;

#define endl '\n'

// -1 -> 232 ... -231 -> 462


void solution_double_priority_queue_v2(){
    int N; cin>>N;
    map<int,int>mp;

    priority_queue<int, vector<int>, greater<int>>min_pq;
    priority_queue<int>max_pq;

    for(int i = 0; i<N; i++){
        string cmd; cin>>cmd;
        if(cmd == "I"){
            int x; cin>>x;
            max_pq.push(x);
            min_pq.push(x);
            mp[x]++;
        }
        else if(cmd == "D"){
            int x; cin>>x;
            if(x == 1 && !max_pq.empty()){
                int a = max_pq.top();
                max_pq.pop();
                mp[a]--;
            }else if(x == -1 && !min_pq.empty()){
                int a = min_pq.top();
                min_pq.pop();
                mp[a]--;
            }else{
                //??
            }
        }
        else{
            //??

        }
        while(!max_pq.empty()){
            int t = max_pq.top();
            if(mp[t] > 0)break;
            max_pq.pop();
        }
        while(!min_pq.empty()){
            int t = min_pq.top();
            if(mp[t] > 0)break;
            min_pq.pop();
        }
    }

    if(max_pq.empty() && min_pq.empty()){
        cout<<"EMPTY"<<endl;
    }
    else if(max_pq.empty() || min_pq.empty()){
        int a = max_pq.empty() ? min_pq.top() : max_pq.top();
        cout<<a<<" "<<a<<endl;
    }
    else{
        int a = max_pq.top();
        int b = min_pq.top();
        cout<<a<<" "<<b<<endl;
    }
}

void solution_double_priority_queue(){
    int N; cin>>N;
    multiset<long long>ms;

    while(N--){
        char cmd;
        long long x;
        cin>>cmd>>x;
        if(cmd == 'I'){
            ms.insert(x);
        }
        else{
            if(ms.empty()){
                continue;
            }
            else if(x == 1){
                auto it = ms.end();
                it--;
                ms.erase(it);
            }
            else{
                ms.erase(ms.begin());
            }
        }
    }
    if(ms.empty())cout<<"EMPTY"<<endl;
    else{
        auto max_it = ms.end();
        max_it--;
        auto min_it = ms.begin();
        long long mx = *max_it;
        long long mn = *min_it;
        cout<<mx<<" "<<mn<<endl;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; cin>>T;
    while(T--){
        solution_double_priority_queue();
        //solution_double_priority_queue_v2();
    }
    return 0;
}


/*
EMPTY
333 -45

*/


/*
2
7
I 16
I -5643
D -1
D 1
D 1
I 123
D -1
9
I -45
I 653
D 1
I -642
I 45
I 97
D 1
D -1
I 333

*/