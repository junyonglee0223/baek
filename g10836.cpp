//g10836 여왕벌
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int N, M;
vector<vector<int>>bugs;

void makeBugsInit(vector<int>&BugGrowth){

    for(int i = 0; i<M-1; i++){
        bugs[M-i-1][0] += BugGrowth[i];
    }
    bugs[0][0] += BugGrowth[M-1];
    for(int i = M; i<2 * M - 1; i++){
        bugs[0][i - M + 1] += BugGrowth[i];
    }
}

void printBug(){
    for(int i = 0; i<M; i++){
        for(int j = 0; j<M; j++){
            cout<<bugs[i][j]<<" ";
        }
        cout<<endl;
    }
}


int main(){

    cin>>M>>N;
    bugs.resize(M, vector<int>(M, 1));

    vector<int>BugGrowth(2 * M - 1, 0);

    for(int i = 0; i<N ;i++){
        int a, b, c; cin>>a>>b>>c;
        int idx = 0;
        for(int j = 0; j < a; j++){
            BugGrowth[j] += 0;
        }
        for(int j = a; j < a + b; j++){
            BugGrowth[j] += 1;
        }
        for(int j = a + b; j < a + b + c; j++){
            BugGrowth[j] += 2;
        }
    }


    makeBugsInit(BugGrowth);

    for(int i = 1; i<M ;i++){
        for(int j = 1; j<M; j++){
            bugs[i][j] = max({bugs[i-1][j-1], bugs[i-1][j], bugs[i][j-1]});
        }
    }
    printBug();
}