//g2423 전구를 켜라
#include<iostream>
#include<vector>
#include<queue>
#include<climits>
#include<algorithm>
#include<set>
using namespace std;

#define endl '\n'

//create dot state 
struct DOT_STAT{
    int t, x, y;
    DOT_STAT(int _t, int _x, int _y){
        t = _t;
        x = _x;
        y = _y;
    }
    // bool operator()(DOT_STAT a, DOT_STAT b){
    //     return a.t < b.t;
    // }
    bool operator<(const DOT_STAT& o) const {
        return t > o.t; 
    }
};

int dx[4] = {+1, -1, +1, -1};
int dy[4] = {+1, -1, -1, +1};

bool is_range(int x, int y, int n, int m){
    return x >= 0 && x < n && y >= 0 && y < m;
}


//solution function
int solution_switch_bulb(){
    int n, m; cin>>n>>m;
    vector<vector<int>>adj(n, vector<int>(m, 0));

    for(int i = 0; i<n; i++){
        string str; cin>>str;
        for(int j = 0; j<m; j++){
            //reverse slash should manipulate others
            if(str[j] == '/'){
                adj[i][j] = 1;
            }
        }
    }

    priority_queue<DOT_STAT>pq;
    vector<vector<int>>dist(n+1, vector<int>(m+1, INT_MAX));

    pq.push(DOT_STAT(0, 0, 0));
    dist[0][0] = 0;

    while(!pq.empty()){
        DOT_STAT cur = pq.top();
        pq.pop();
        int cur_x = cur.x;
        int cur_y = cur.y;
        int cur_d = cur.t;

        //x, y possible case
        //x, y = (0) -> x+1, y+1
        //x-1, y-1 = (0) -> x-1, y-1
        //x, y-1 = (1) -> x+1, y-1
        //x-1, y = (1) -> x-1, y+1
        if(cur_x == n && cur_y == m){
            return cur_d;
        }

        if(dist[cur_x][cur_y] < cur_d)continue;
        for(int dir=0; dir<4; dir++){
        int nx = cur_x + dx[dir], ny = cur_y + dy[dir];
        if(!is_range(nx, ny, n+1, m+1)) continue;
        
        int tx = (dir==0? cur_x : (dir==1? cur_x-1 : (dir==2? cur_x : cur_x-1)));
        int ty = (dir==0? cur_y : (dir==1? cur_y-1 : (dir==2? cur_y-1 : cur_y)));
        
        bool slash = adj[tx][ty];  
        bool freeMove = (dir<2 ? (slash==0) : (slash==1));
        int cost = freeMove ? 0 : 1;

            if(dist[nx][ny] > cur_d + cost){
                dist[nx][ny] = cur_d + cost;
                pq.push(DOT_STAT(cur_d+cost, nx, ny));
            }
        }
    }

    return dist[n][m];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int ret = solution_switch_bulb();
    if(ret == INT_MAX){
        cout<<"NO SOLUTION"<<endl;
    }else{
        cout<<ret<<endl;
    }

    return 0;
}

/*
3 5
\\/\\
\\///
/\\\\
*/
/*
1
*/
