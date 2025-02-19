//g20040 사이클 게임
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define endl '\n'

int N, M;
vector<int>parents;
vector<int>ranks;

int find_parents(int now){
    if(now != parents[now]){
        parents[now] = find_parents(parents[now]);
    }
    return parents[now];
}

bool union_node(int a, int b){
    int parent_a = find_parents(a);
    int parent_b = find_parents(b);

    if(parent_a == parent_b)return false;

    if(ranks[parent_a] < ranks[parent_b]){
        parents[parent_a] = parent_b;
    }
    else if(ranks[parent_a] > ranks[parent_b]){
        parents[parent_b] = parent_a;
    }
    else{
        parents[parent_b] = parent_a;
        ranks[parent_a]++;
    }
    return true;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin>>N>>M;

    parents.resize(N, -1);
    ranks.resize(N, 0);

    for(int i = 0; i<N; i++)
        parents[i] = i;

    int cycle_occur = 0;

    for(int i = 0; i<M; i++){
        int a, b; cin>>a>>b;
        if(!union_node(a, b)){
            cycle_occur = i+1;
            break;
        }
    }
    cout<<cycle_occur<<endl;


}

/*

6 5
0 1
1 2
2 3
5 4
0 4

0


6 5
0 1
1 2
1 3
0 3
4 5

4

*/