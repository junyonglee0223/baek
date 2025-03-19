//g1922 네트워크 연결
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define endl '\n'

vector<int>find_parent;

int find_parent_root(int now){
    return (now == find_parent[now]) ? now : find_parent_root(find_parent[now]);
}


void solution_network_connecting(){
    find_parent.clear();

    int N, M;
    cin>>N>>M;
    find_parent.resize(N + 1);
    for(int i = 0; i<=N; i++){
        find_parent[i] = i;
    }

    vector<pair<int, pair<int,int>>>connections;
    for(int i = 0; i<M; i++){
        int a, b, c;
        cin>>a>>b>>c;
        connections.push_back({c, {a, b}});
    }

    sort(connections.begin(), connections.end());

    int answer = 0;

    for(auto ele : connections){
        int cost = ele.first;
        int a = ele.second.first;
        int b = ele.second.second;

        int pa = find_parent_root(a);
        int pb = find_parent_root(b);
        if(pa != pb){
            find_parent[pb] = pa;
            answer += cost;
        }
    }
    cout<<answer<<endl;
}



int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solution_network_connecting();
    return 0;
}



/*
6
9
1 2 5
1 3 4
2 3 2
2 4 7
3 4 6
3 5 11
4 5 3
4 6 8
5 6 8
*/