#include <bits/stdc++.h>
using namespace std;

vector<vector<pair<int, int>>> graph;
//vector<int> dp[21]; 
vector<vector<vector<int>>> dp;
const int INF = 1e9+7;

int charToIndex(char c) {
    return c - 'a'; 
}

int palenPath(int src, int dst, int pathLen, int parSrc, int parDst) {
    if (src == dst) {
        return pathLen;
    }

    int& ret = dp[src][dst][pathLen];
    if (ret != -1) return ret; 
    ret = INF;

    for (auto &nxts : graph[src]) {
        int nxtSrc = nxts.first, nxtSrcChar = nxts.second;
        for (auto &nxtd : graph[dst]) {
            int nxtDst = nxtd.first, nxtDstChar = nxtd.second;
            if (nxtSrc == parSrc && nxtDst == parDst) continue;
            if (nxtSrc == dst && nxtDst == src) {
                ret = min(ret, pathLen + 1);
            } else if (nxtSrc == nxtDst) {
                if (nxtSrcChar == nxtDstChar) {
                    ret = min(ret, pathLen + 2);
                }
            } else if (nxtSrcChar == nxtDstChar) {
                ret = min(ret, palenPath(nxtSrc, nxtDst, pathLen + 2, src, dst));
            }
        }
    }
    return ret;
}

int main() {
    int N, M;
    cin >> N >> M;

    graph.resize(N);

    dp.assign(N, vector<vector<int>>(N, vector<int>(200 + 1, -1)));



    for (int i = 0; i < M; ++i) {
        int a, b; char c;
        cin >> a >> b >> c;
        int cIdx = charToIndex(c);
        graph[a].push_back({b, cIdx});
        graph[b].push_back({a, cIdx});
    }
    
    int ans = palenPath(0, 1, 0, -1, -1);
    if(ans == INF) ans = -1;
    cout << ans << endl;

}



