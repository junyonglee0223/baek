//음악프로그램

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N, M;
vector<vector<int>> order_graph;
vector<vector<int>> order;
vector<int>inorder;
queue<int>q;

int main(){
    cin>>N>>M;
    order_graph.resize(N+1);
    order.resize(M);
    inorder.resize(N+1, 0);
    for(int i = 0; i<M; i++){
        int tmpSize; cin>>tmpSize;
        for(int j = 0; j<tmpSize; j++){
            int ele; cin>>ele;
            order[i].push_back(ele); 
            if(j == 0)continue;
            order_graph[order[i][j-1]].push_back(order[i][j]);
            inorder[ele]++;
        }
    }

    for(int i = 1; i<=N; i++){
        if(inorder[i] == 0){
            q.push(i);
        }
    }

    vector<int>ret;
    while(!q.empty()){
        int now = q.front();
        q.pop();
        ret.push_back(now);
        for(auto nxt : order_graph[now]){
            inorder[nxt]--;
            if(inorder[nxt] == 0)
                q.push(nxt);
        }
    }
    
    if (ret.size() != N) {
        cout << 0 << '\n';  
        return 0;
    }


    for (int i = 0; i < ret.size(); i++) {
        cout << ret[i] << '\n';
    }

}

