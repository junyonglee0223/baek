//g1043 거짓말
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;


vector<int>parents;
int findParents(int now){
    while(now != parents[now]){
        now = parents[now];
    }
    return now;
}

void unionFind(int a, int b){
    int pa = findParents(a);
    int pb = findParents(b);
    if(pa < pb){
        parents[pb] = pa;
    }
    else{
        parents[pa] = pb;
    }
}

int main(){
    int N, M;
    cin>>N>>M;

    parents.resize(N+1);
    for(int i = 0; i<=N; i++){
        parents[i] = i;
    }

    int truthCnt; cin>>truthCnt;
    for(int i = 0; i<truthCnt; i++){
        int ele; cin>>ele;
        parents[ele] = 0;
    }

    vector<vector<int>>groups(M);

    for(int i = 0; i<M; i++){
        int groupN; cin>>groupN;
        for(int j = 0; j<groupN; j++){
            int ele; cin>>ele;
            groups[i].push_back(ele);
            if(j > 0){
                unionFind(groups[i][j-1], groups[i][j]);
            }
        }
    }

    set<int>NotLieGroup;
    int answer = 0;
    for(int i = 0; i<M; i++){
   
        int idx = findParents(groups[i][0]);
        if(idx == 0){
            answer++;
        }
        
    }
    cout<<M - answer<<endl;


}