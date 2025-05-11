//p2887 행성 터널
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

struct Planet{
    int x, y, z;
    int idx;
    Planet(int _idx, int _x, int _y, int _z){
        idx = _idx;
        x = _x;
        y = _y;
        z = _z;
    }
};


struct planet_edge {
    int cost, u, v;
};

int find(int now, vector<int>&parents){
    if(now == parents[now])return now;
    return parents[now] = find(parents[now], parents);
}


void solution_planet_tunnel_v1(){
    int n; cin>>n;

    vector<Planet>planets;
    for(int i = 0; i<n; i++){
        int x, y, z;
        cin>>x>>y>>z;
        planets.push_back(Planet(i, x, y, z));
    }

    vector<planet_edge>edges;

    for(int d = 0; d<3; d++){
        sort(planets.begin(), planets.end(), [d](Planet a, Planet b){
            if(d == 0)return a.x < b.x;
            else if(d == 1)return a.y < b.y;
            return a.z < b.z;
        });

        for(int i = 1; i<n; i++){
            planet_edge e;
            e.cost = d == 0 ? abs(planets[i].x - planets[i-1].x) :
                     d == 1 ? abs(planets[i].y - planets[i-1].y) :
                              abs(planets[i].z - planets[i-1].z);
            e.u = planets[i].idx;
            e.v = planets[i-1].idx;
            edges.push_back(e);
        }
    }
    sort(edges.begin(), edges.end(), [](planet_edge &a, planet_edge &b){
        return a.cost < b.cost;
    });

    vector<int>parents(n, -1);
    for(int i = 0; i<n; i++)
        parents[i] = i;
    

    int answer = 0;

    for(auto edge : edges){
        int u = edge.u;
        int v = edge.v;
        int pu = find(u, parents);
        int pv = find(v, parents);
        if(pu != pv){
            parents[pu] = pv;
            answer += edge.cost;
        }
        
    }
    cout<<answer<<endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solution_planet_tunnel_v1();

    return 0;
}


/*
1 <= N <= 100,000
-109 ~ 109
*/

/*
5
11 -15 -15
14 -5 -15
-1 -1 -5
10 -4 -1
19 -4 19
*/
/*
4
*/