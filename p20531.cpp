#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;
const ll MOD = 1000000007;

int N, M;

vector<vector<ll>>GCACHE;
vector<ll>GCACHESUM;
vector<int>PARENTS;
//vector<int>NODECNTS;

int findParents(int cur){
    if(PARENTS[cur] == cur)return cur;
    return PARENTS[cur] = findParents(PARENTS[cur]);
}

bool unionNode(int a, int b){
    int pa = findParents(a);
    int pb = findParents(b);

    if(pa == pb)return false;
    // if(NODECNTS[pa] > NODECNTS[pb]){
    //     int tmp = pa;
    //     pa = pb;
    //     pb = tmp;
    // }

    PARENTS[pa] = pb;
    //NODECNTS[pb] += NODECNTS[pa];
    return true;
}

void initGroup(){
    GCACHE.clear();
    GCACHESUM.clear();
    
    GCACHE.resize(N+1, vector<ll>(N+1, 0));
    GCACHESUM.resize(N+1, 0);
    GCACHE[0][0] = 1;


    for(int i = 1; i<=N; i++){
        for(int k = 1; k<=i; k++){
            ll val = GCACHE[i-1][k-1];
            GCACHE[i][k] = (val + GCACHE[i-1][k] * k) % MOD;
        }
    }



    for(int i = 1; i<=N; i++){
        ll tmpSum = 0;
        for(int k = 0; k<=i; k++){
            tmpSum += GCACHE[i][k];
            tmpSum %= MOD;
        }
        GCACHESUM[i] = tmpSum;
    }

}

void solutionPersonalRelationship(){
        PARENTS.clear();
    PARENTS.resize(N, 0);

    for(int i = 0; i<N; i++){
        PARENTS[i] = i;
        //NODECNTS[i] = 1;
    }

    int totalN = N;

    for(int i = 0; i<M; i++){
        int a, b; cin>>a>>b;
        a--; b--;

        if(unionNode(a, b)){
            totalN--;
        }
        cout<< GCACHESUM[totalN] <<"\n";
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);


    cin>>N>>M;

    initGroup();

    solutionPersonalRelationship();

    return 0;
}
/*
3 4
1 1
1 1
1 2
2 3
*/
/*
5
5
2
1
*/