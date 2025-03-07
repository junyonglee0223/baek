//g15686 치킨 배달
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <climits>
using namespace std;

int N, M;
int h_size;
int c_size;
vector<vector<int>>maps;
vector<vector<int>>map_dist;
int answer = INT_MAX;


void set_dist_init(vector<pair<int,int>>&houses, vector<pair<int,int>>&chickens){
    int h_size = houses.size();
    int c_size = chickens.size();

    for(int i = 0; i<h_size; i++){
        for(int j = 0; j<c_size; j++){
            map_dist[i][j] = (abs(houses[i].first - chickens[j].first)
                                + abs(houses[i].second - chickens[j].second));
        }
    }
}

void select_chickens(int idx, vector<int>&selected){
    if(idx == c_size){
        if(selected.size() == M){
            int ret = 0;
            for(int i = 0; i<h_size; i++){
                int tmp = INT_MAX;
                for(auto ele : selected){
                    tmp = min(tmp, map_dist[i][ele]);
                }
                ret += tmp;
            }
            answer = min(answer, ret);
        }
        return;
    }
    else if(selected.size() > M)return;

    selected.push_back(idx);
    select_chickens(idx + 1, selected);
    selected.pop_back();

    select_chickens(idx + 1, selected);
}


void solution_delivery_chicken(){
    maps.clear();
    map_dist.clear();
    answer = INT_MAX;

    cin>>N>>M;
    maps.resize(N, vector<int>(N, 0));

    vector<pair<int,int>>chickens;
    vector<pair<int,int>>houses;


    for(int i = 0; i<N; i++){
        for(int j = 0; j<N; j++){
            cin>>maps[i][j];
            if(maps[i][j] == 1){
                houses.push_back({i, j});
            }
            else if(maps[i][j] == 2){
                chickens.push_back({i, j});
            }
        }
    }

    sort(houses.begin(), houses.end());
    sort(chickens.begin(), chickens.end());

    h_size = houses.size();
    c_size = chickens.size();
    map_dist.resize(h_size, vector<int>(c_size, -1));

    set_dist_init(houses, chickens);

    vector<int>selected;
    select_chickens(0, selected);

    cout<<answer<<endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    solution_delivery_chicken();

    // int T; cin>>T;
    // while(T--){
    //     solution_delivery_chicken();
    // }

    return 0;
}



/*
N은 50 이하 2 이상
M은 1 이상 13 이하


*/

/*
5
10
11
32

*/

/*
4
5 3
0 0 1 0 0
0 0 2 0 1
0 1 2 0 0
0 0 1 0 0
0 0 0 0 2
5 2
0 2 0 1 0
1 0 1 0 0
0 0 0 0 0
2 0 0 1 1
2 2 0 1 2
5 1
1 2 0 0 0
1 2 0 0 0
1 2 0 0 0
1 2 0 0 0
1 2 0 0 0
5 1
1 2 0 2 1
1 2 0 2 1
1 2 0 2 1
1 2 0 2 1
1 2 0 2 1



*/