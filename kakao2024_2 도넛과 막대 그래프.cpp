
#include <bits/stdc++.h>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<vector<int>> edges) {
    int V = 0; 
    for (auto& edge : edges) {
        V = max(V, max(edge[0], edge[1]));
    }
    V++; 
    vector<int> incoming(V, 0), outgoing(V, 0);
    for (auto& edge : edges) {
        incoming[edge[1]]++;
        outgoing[edge[0]]++;
    }

    int createdNode = -1;
    for (int i = 1; i < V; i++) {
        if (incoming[i] == 0 && outgoing[i] >= 2) {
            createdNode = i;
            break;
        }
    }

    int totalGraphs = outgoing[createdNode];
    int stickGraphs = 0, cycleGraphs = 0, eightGraphs = 0;
    
    
    
    incoming.clear();
    outgoing.clear();
    incoming.resize(V, 0), outgoing.resize(V, 0);
     for (auto& edge : edges) {
        if(edge[0] == createdNode || edge[1] == createdNode)continue;
        incoming[edge[1]]++;
        outgoing[edge[0]]++;
    }
   


    for (int i = 1; i < V; i++) {
        if (i == createdNode) continue;
        if (outgoing[i] == 0) stickGraphs++;
        if (incoming[i] == 2 && outgoing[i] == 2) eightGraphs++;
    }

    cycleGraphs = totalGraphs - stickGraphs - eightGraphs;

    vector<int> answer = {createdNode, cycleGraphs, stickGraphs, eightGraphs};
    return answer;
}

