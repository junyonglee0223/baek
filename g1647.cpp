//도시 분할 계획


#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef pair<int, int> p;

int N, M;
vector<pair<int,p>>road;
vector<int>parent;

int find_parent(int x){
    while(parent[x] != x){
        x = parent[x];
    }
    return x;
}

int main(){
    cin>>N>>M;
    parent.resize(N+1);
    for(int i = 1; i<=N; i++){
        parent[i] = i;
    }
    for(int i = 0; i<M; i++){
        int a, b, c; cin>>a>>b>>c;
        road.push_back({c, {a, b}});
    }
    
    sort(road.begin(), road.end());

    vector<int>selected_road;
    for(int i = 0; i<road.size(); i++){
        int a = road[i].second.first;
        int b = road[i].second.second;
        int c = road[i].first;
        int p_a = find_parent(a);
        int p_b = find_parent(b);
        if(p_a != p_b){
            if(p_a < p_b)
                parent[p_b] = p_a;
            else
                parent[p_a] = p_b;
            selected_road.push_back(c);
        }
    }
    int ans = 0;
    for(int i = 0; i<selected_road.size() - 1; i++){
        ans += selected_road[i];
    }
    cout<<ans<<endl;
}

