

#include <bits/stdc++.h>
#include <string>
#include <vector>

using namespace std;

#define MAXN 200001

bool solution(int n, vector<vector<int>> path, vector<vector<int>> order) {
    bool answer = true;

    vector<int>big_graph[MAXN];
    int indegree[MAXN] = { 0 };
    for (auto ele : path) {
        int x = ele[0];
        int y = ele[1];
        big_graph[x].push_back(y);
        big_graph[y].push_back(x);
    }

    vector<int>graph[MAXN];
    queue<int>q;
    vector<int>visited(n, 0);

    q.push(0);
    visited[0] = 1;
    while (!q.empty()) {
        int now = q.front();
        q.pop();
        for (auto nxt : big_graph[now]) {
            if (visited[nxt] == 0) {
                graph[now].push_back(nxt);
                visited[nxt] = 1;
                indegree[nxt] += 1;
                q.push(nxt);
            }
        }
    }

    //for (int i = 0; i < n; i++) {
    //    for (auto nxt : graph[i])
    //        cout << nxt << "\t";
    //    cout << endl;
    //}
    ////test



    for (auto ele : order) {
        int x = ele[0];
        int y = ele[1];
        graph[x].push_back(y);
        indegree[y] += 1;
    }


    for (int i = 0; i < n; i++) {
        if (indegree[i] == 0) {
            q.push(i);
        }
    }
    
    while (!q.empty()){
        int now = q.front();
        q.pop();
        //cout << now << endl;                    //test

        for (auto nxt : graph[now]) {
            indegree[nxt]--;
            if (indegree[nxt] == 0) {
                q.push(nxt);
            }
        }
    }

    for (int i = 0; i < n; i++) {
        //cout << indegree[i] << "\t";                //test
        if (indegree[i] > 0) {
            return answer = false;
        }
    }

    return answer = true;
}
