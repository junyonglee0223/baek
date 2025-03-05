//p2162 선분 그룹
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define endl '\n'
typedef pair<int,int> p;
typedef pair<p, p> pp;

int N;
vector<pp>lines;
vector<vector<int>>adj;
vector<int>line_groups;

int dfs_line(int now, vector<bool>&visited){
    visited[now] = true;
    int ret = 1;
    for(auto nxt : adj[now]){
        if(visited[nxt])continue;
        ret += (dfs_line(nxt, visited));
    }
    return ret;
}

int ccw(p a, p b, p c){
    p v1 = {b.first - a.first, b.second - a.second};
    p v2 = {c.first - a.first, c.second - a.second};

    int ccw_result = v1.first * v2.second - v2.first * v1.second;
    if(ccw_result > 0)return 1;
    else if(ccw_result < 0)return -1;
    return 0;
}

bool check_lines(pp l1, pp l2){
    p a = l1.first; p b = l1.second;
    p c = l2.first; p d = l2.second;

    int ccw_ab_c = ccw(a, b, c);
    int ccw_ab_d = ccw(a, b, d);

    int ccw_cd_a = ccw(c, d, a);
    int ccw_cd_b = ccw(c, d, b);

    int ccw_m1 = ccw_ab_c * ccw_ab_d;
    int ccw_m2 = ccw_cd_a * ccw_cd_b;

    if(ccw_m1 == 0 && ccw_m2 == 0){
        if(b < a)swap(a, b);
        if(d < c)swap(c, d);
        return (c <= b) && (a <= d);
    }
    return ccw_m1 <= 0 && ccw_m2 <= 0;
}

void solution_line_group(){
    adj.clear();
    line_groups.clear();
    lines.clear();

    cin>>N;
    adj.resize(N);
    for(int i = 0; i<N; i++){
        int x1, y1, x2, y2;
        cin>>x1>>y1>>x2>>y2;

        p dot1 = {x1, y1};
        p dot2 = {x2, y2};
        if(x1 > x2 || (x1 == x2 && y1 > y2)){
            swap(dot1, dot2);
        }

        lines.push_back({dot1, dot2});
    }

    for(int i = 0; i<N; i++){
        for(int j = i+1; j<N; j++){
            if(check_lines(lines[i], lines[j])){
                adj[i].push_back(j);
                adj[j].push_back(i);
            }
        }
    }

    int group_cnt = 0;
    vector<bool>visited(N, false);
    for(int i = 0; i<N; i++){
        if(!visited[i]){

            int tmp_group_cnt = dfs_line(i, visited);
            line_groups.push_back(tmp_group_cnt);
            group_cnt++;
        }
    }
    //answer output
    int max_size = 0;
    for(int i = 0; i<line_groups.size(); i++){
        max_size = max(max_size, line_groups[i]);
    }
    cout<<line_groups.size()<<endl;
    cout<<max_size<<endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    solution_line_group();


    // int T; cin>>T;
    // while(T--){
    //     solution_line_group();
    // }

}


/*
1
3

2
2
*/

/*
2
3
1 1 2 3
2 1 0 0
1 0 1 1
3
-1 -1 1 1
-2 -2 2 2
0 1 -1 0
*/