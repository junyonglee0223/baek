#include <iostream>
#include <vector>
#include <cmath> 
#include <iomanip> 

using namespace std;
#define x first
#define y second

typedef pair<double, double> pnt;

int N;
vector<pnt> polygon;

double areaPolygon(const vector<pnt>& polygon) {
    double area = 0.0;
    int n = polygon.size();

    for(int i = 1; i<n-1; i++){
        int j = i+1;
        area += (polygon[i].x * polygon[j].y - polygon[j].x * polygon[i].y);
    }

    return abs(area) / 2.0;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    double sa, sb;
    cin >> sa >> sb;

    polygon.push_back({0, 0});
    
    for (int i = 1; i < N; i++) {
        double a, b;
        cin >> a >> b;
        a -= sa;
        b -= sb;
        polygon.push_back({a, b});
    }

    double ans = areaPolygon(polygon);

    cout << fixed << setprecision(1) << ans << endl;
    return 0;
}
