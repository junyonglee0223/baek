//g1939 중량제한
#include<iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <queue>
using namespace std;


#define endl '\n'

int find_parent(int now, vector<int>& parent){
    return now == parent[now] ? now : find_parent(parent[now], parent);
}

void solution_weight_limits_v2(){
    int N, M;
    cin>>N>>M;

    vector<int>parent(N+1);
    for(int i = 0; i<=N; i++){
        parent[i] = i;
    }

    priority_queue<pair<int,pair<int,int>>> pq;

    for(int i = 0; i<M; i++){
        int a, b, c;
        cin>>a>>b>>c;
        pq.push({c, {a, b}});
    }
    int src, dst;
    cin>>src>>dst;
    bool flag = false;

    int answer = 1000000001;

    while(!pq.empty() && !flag){
        auto cur_node = pq.top();
        pq.pop();
        int cost = cur_node.first;
        int x = cur_node.second.first;
        int y = cur_node.second.second;

        int p_x = find_parent(x, parent);
        int p_y = find_parent(y, parent);
        if(p_x == p_y)continue;

        answer = min(answer, cost);
        parent[p_x] = p_y;
        if(find_parent(src, parent) == find_parent(dst, parent)) flag = true;
    }
    cout<<answer<<endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solution_weight_limits_v2();

    return 0;
}



/*
3 3
1 2 2
3 1 3
2 3 2
1 3
*/
/*
3
*/