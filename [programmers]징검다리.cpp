#include <string>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

bool isPostDist(int d, vector<int> rocks, int n) {
    int removeCount = 0;
    int prev = 0; 

    for (int i = 1; i < rocks.size(); i++) {
        if (rocks[i] - prev < d) {
            removeCount++;
        } else {
            prev = rocks[i];
        }
    }
    return removeCount <= n;
}

ll findMindDist(vector<int> rocks, int distance, int n) {
    ll left = 1;
    ll right = distance; 

    while (left <= right) { 
        ll mid = (left + right) / 2;
        if (isPostDist(mid, rocks, n)) {
            left = mid + 1;
        } else {
            right = mid - 1; 
        }
    }
    return right; 
}

int solution(int distance, vector<int> rocks, int n) {
    rocks.push_back(0);
    rocks.push_back(distance);
    sort(rocks.begin(), rocks.end());

    return static_cast<int>(findMindDist(rocks, distance, n));
}
