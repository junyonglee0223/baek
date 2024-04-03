//플로이드
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define MAX_COST 99999999
int N, M;
vector<vector<int>>bus_road;


int main(){
    cin>>N>>M;
    bus_road.resize(N+1, vector<int>(N+1, MAX_COST));
    for(int i = 0; i<M; i++){
        int a, b, c;
        cin>>a>>b>>c;
        if(bus_road[a][b] > c)
            bus_road[a][b] = c;
        //bus_road[b][a] = c;
    }

    for(int i = 1; i<=N; i++)
        bus_road[i][i] = 0;

    for(int k = 1; k<=N; k++){
        for(int j = 1; j<=N; j++){
            for(int i = 1; i<=N; i++){
                bus_road[i][j] = min({bus_road[i][j], 
                bus_road[i][k] + bus_road[k][j], MAX_COST});
            }
        }
    }
    for(int i = 1; i<=N; i++){
        for(int j = 1; j<=N; j++){
            if(bus_road[i][j] != MAX_COST)
                cout<<bus_road[i][j]<<" ";
            else
                cout<<0<<" ";
        }
        cout<<endl;
    }

}


