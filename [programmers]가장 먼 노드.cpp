#include <string>
#include <vector>

#include <queue>
#include <map>
#include <iostream>
using namespace std;

vector<vector<int>>graph;


int findMaxDistNodeBFS(vector<int>&dist){
    map<int,int>maxDist;
    queue<int>q;
    q.push(1);
    dist[1] = 0;
    maxDist[0] = 1;

    while(!q.empty()){
        int now = q.front();
        q.pop();
        for(auto nxt : graph[now]){
            if(dist[nxt]==-1){
                dist[nxt] = dist[now] + 1;
                if(maxDist.find(dist[nxt]) != maxDist.end()){
                    maxDist[dist[nxt]] = maxDist[dist[nxt]]+1;
                }
                else{
                    maxDist[dist[nxt]] = 1;
                }
                q.push(nxt);
            }
        }
    }
    return maxDist[maxDist.size()-1];
}


int solution(int n, vector<vector<int>> edge) {
    int answer = 0;
    graph.resize(n+1);
    for(auto edg : edge){
        graph[edg[0]].push_back(edg[1]);
        graph[edg[1]].push_back(edg[0]);
    }
    vector<int>dist(n+1, -1);

    answer = findMaxDistNodeBFS(dist);
    return answer;
}