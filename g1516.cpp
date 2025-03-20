//g1516 게임 개발
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define endl '\n'


void solution_game_constructor_v1(){
    int N; cin>>N;

    vector<vector<int>> adj(N+1);
    vector<int>inorder(N+1, 0);
    vector<int>make_time(N+1, 0);

    for(int i = 1; i<=N; i++){
        cin>>make_time[i];

        int ele; cin>>ele;
        while(ele != -1){
            adj[ele].push_back(i);
            inorder[i]++;
            cin>>ele;
        }
    }

    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>pq;
    //queue<pair<int,int>>q;
    for(int i = 1; i<=N; i++){
        if(inorder[i] == 0){
            pq.push({make_time[i], i});
        }
    }

    vector<int>ret(N+1, 0);

    while(!pq.empty()){
        auto now_n = pq.top();
        pq.pop();

        int now = now_n.second;
        int now_cost = now_n.first;
        ret[now] = now_cost;

        for(auto nxt : adj[now]){
            inorder[nxt]--;
            if(inorder[nxt] == 0){
                pq.push({now_cost + make_time[nxt], nxt});
            }
        }
    }

    for(int i = 1; i<=N; i++){
        cout<<ret[i]<<endl;
    }

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solution_game_constructor_v1();

    return 0;
}


/*
5
10 -1
10 1 -1
4 1 -1
4 3 1 -1
3 3 -1

*/

/*
5
10 -1
20 1 -1
30 2 -1
40 3 5 -1
100 -1
*/