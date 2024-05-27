#include <iostream>
using namespace std;

#define endl '\n'
int N, R, C;

int RectZCnt(int cnt, int x, int y, int size) {
    if (size == 1) {
        if (x == R && y == C) return cnt;
        if (x == R && y + 1 == C) return cnt + 1;
        if (x + 1 == R && y == C) return cnt + 2;
        if (x + 1 == R && y + 1 == C) return cnt + 3;
    }
    
    int dist = (size >> 1);

    if (R < x + dist && C < y + dist) {
        return RectZCnt(cnt, x, y, dist);
    } else if (R < x + dist && C >= y + dist) {
        return RectZCnt(cnt + dist * dist, x, y + dist, dist);
    } else if (R >= x + dist && C < y + dist) {
        return RectZCnt(cnt + dist * dist * 2, x + dist, y, dist);
    } else {
        return RectZCnt(cnt + dist * dist * 3, x + dist, y + dist, dist);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> R >> C;
    cout << RectZCnt(0, 0, 0, (1 << N)) << endl;
}
