//선분 교차2
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define x first
#define y second
typedef long long ll;
typedef pair<ll,ll> p;

int ccw(p a, p b, p c) {
    long long result = (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
    if (result > 0) return 1;  
    if (result < 0) return -1; 
    return 0;                  
}

bool isBetween(p a, p b, p c) {
    return min(a.x, c.x) <= b.x && b.x <= max(a.x, c.x) &&
           min(a.y, c.y) <= b.y && b.y <= max(a.y, c.y);
}

bool isIntersect(p a1, p a2, p b1, p b2) {
    int ccw1 = ccw(a1, a2, b1);
    int ccw2 = ccw(a1, a2, b2);
    int ccw3 = ccw(b1, b2, a1);
    int ccw4 = ccw(b1, b2, a2);


    if (ccw1 * ccw2 < 0 && ccw3 * ccw4 < 0) {
        return true;
    }

    if (ccw1 == 0 && isBetween(a1, b1, a2)) return true;
    if (ccw2 == 0 && isBetween(a1, b2, a2)) return true;
    if (ccw3 == 0 && isBetween(b1, a1, b2)) return true;
    if (ccw4 == 0 && isBetween(b1, a2, b2)) return true;

    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    ll x1, y1, x2, y2, x3, y3, x4, y4;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;

    p a1 = {x1, y1}, a2 = {x2, y2}, b1 = {x3, y3}, b2 = {x4, y4};

    if(x1 > x2 || (x1 <= x2 && y1 > y2)){
        swap(a1, a2);
    }
    if(x3 > x4 || (x3 <= x4 && y3 > y4)){
        swap(b1, b2);
    }


    if (isIntersect(a1, a2, b1, b2)) {
        cout << "1" << endl;
    } else {
        cout << "0" << endl;
    }

    return 0;
}

