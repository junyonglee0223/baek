#include <string>
#include <vector>
#include <iostream>
#include <map>
#include <set>

using namespace std;

int dx[8] = {0, 1, 1, 1, 0, -1, -1, -1};
int dy[8] = {1, 1, 0, -1, -1, -1, 0, 1};

int solution(vector<int> arrows) {
    map<pair<int, int>, bool> visited;
    set<pair<pair<int, int>, pair<int, int>>> visited_edges;
    int x = 0, y = 0;
    int answer = 0;

    visited[{x, y}] = true;

    for (int arrow : arrows) {
        for (int step = 0; step < 2; ++step) {  
            int nx = x + dx[arrow];
            int ny = y + dy[arrow];

            pair<int, int> current = {x, y};
            pair<int, int> next = {nx, ny};

            if (visited[next] && visited_edges.find({current, next}) == visited_edges.end()) {
                answer++;
            }

            visited_edges.insert({current, next});
            visited_edges.insert({next, current});

            visited[next] = true;

            x = nx;
            y = ny;
        }
    }

    return answer;
}
