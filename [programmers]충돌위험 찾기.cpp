#include <iostream>
#include <vector>

#include <algorithm>
#include <set>
using namespace std;

vector<pair<int,int>>createRoute(pair<int,int>src, pair<int,int>dst){
    vector<pair<int,int>>ret;
    int x = src.first;
    int y = src.second;
    int dx = (dst.first - x < 0) ? -1: 1;
    int dy = (dst.second - y < 0) ? -1 : 1;
    while(1){
        if(x == dst.first)break;
        ret.push_back({x, y});
        x = x + dx;
    }
    //ret.push_back({x, y});
    while(1){
        if(y == dst.second)break;
        ret.push_back({x, y});
        y = y + dy;
    }
    //ret.push_back({x, y});
    return ret;
}

vector<pair<int,int>>createRouteGroup(vector<vector<int>>points, vector<int>rbPnt){
    vector<pair<int,int>>ret;
    int m = rbPnt.size();
    for(int i = 0; i<m - 1; i++){
        vector<pair<int,int>>tmp;
        int sIdx = rbPnt[i]-1;
        int eIdx = rbPnt[i+1]-1;
        pair<int,int>src = {points[sIdx][0], points[sIdx][1]};
        pair<int,int>dst = {points[eIdx][0], points[eIdx][1]};
        tmp = (createRoute(src, dst));
        for(auto ele : tmp)
            ret.push_back(ele);
    }
    int lastIdx = rbPnt[m-1] - 1;
    pair<int,int>lastPnt = {points[lastIdx][0], points[lastIdx][1]};
    ret.push_back(lastPnt);
    return ret;
}

int solution(vector<vector<int>> points, vector<vector<int>> routes) {
    int answer = 0;

    int n = routes.size();
    vector<vector<pair<int,int>>>robotRoutes;
    int t = 0;
    for(int i = 0; i<n; i++){
        vector<pair<int,int>>tmp = createRouteGroup(points, routes[i]);
        t = max(t, static_cast<int>(tmp.size()));
        robotRoutes.push_back(tmp);
    }
    for(int ct = 0; ct<t; ct++){
        set<pair<int,int>>s, dup_s;
        for(int i = 0; i<n; i++){
            if(robotRoutes[i].size() <= ct)continue;
            pair<int,int>tmp = robotRoutes[i][ct];
            if(s.find(tmp) != s.end()){
                dup_s.insert(tmp);
            }
            else{
                s.insert(tmp);
            }
        }
        answer += dup_s.size();
    }
    // /******************test****************** */
    // for(auto ele : robotRoutes){
    //     cout<<"-----test---"<<endl;
    //     for(auto p : ele){
    //         cout<<p.first<<" "<<p.second<<endl;
    //     }
    // }
   
    return answer;
}

int main() {
    vector<vector<vector<int>>> Points = {
        {{3, 2}, {6, 4}, {4, 7}, {1, 4}},
        {{3, 2}, {6, 4}, {4, 7}, {1, 4}},
        {{2, 2}, {2, 3}, {2, 7}, {6, 6}, {5, 2}}
    };

    vector<vector<vector<int>>> Routes = {
        {{4, 2}, {1, 3}, {2, 4}},
        {{4, 2}, {1, 3}, {4, 2}, {4, 3}},
        {{2, 3, 4, 5}, {1, 3, 4, 5}}
    };

    vector<int> expectedResults = {1, 9, 0};  

    for (int i = 0; i < Points.size(); ++i) {
        cout<<"-----------------------------------------"<<endl;
        int result = solution(Points[i], Routes[i]);
        cout << "Test Case " << i + 1 << ": Expected = " << expectedResults[i] << ", Result = " << result << endl;
    }

    return 0;
}


/*
충돌 포인트와 중복 포인트 두개의 set을 만들어서 
포인트에 중복 되면 중복 set에 등록하고 최종적으로
중복 set의 size를 return 하면 될 듯 하다. 

물론 시간(횟수)마다 두 set을 reset 해야 한다. 

*/