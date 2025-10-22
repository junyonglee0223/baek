//g1588-1
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<vector<int>> trans = {
    {},          
    {1, 3, 2},   
    {2, 1, 1},   
    {2, 3, 2}  
};

ll lenArr[21];

array<ll, 3> fullCount[4][21];
bool filled[4][21];

array<ll, 3> getFull(int num, int n) {
    if (filled[num][n]) return fullCount[num][n];
    if (n == 0) {
        fullCount[num][n] = {0, 0, 0};
        fullCount[num][n][num - 1] = 1;
        filled[num][n] = true;
        return fullCount[num][n];
    }

    array<ll, 3> res = {0, 0, 0};
    for (int i = 0; i < 3; i++) {
        auto sub = getFull(trans[num][i], n - 1);
        for (int j = 0; j < 3; j++) res[j] += sub[j];
    }
    fullCount[num][n] = res;
    filled[num][n] = true;
    return res;
}

array<ll, 3> countRange(int num, int n, ll l, ll r) {
    if (l > r) return {0, 0, 0};
    if (n == 0) {
        array<ll, 3> res = {0, 0, 0};
        if (l <= 0 && r >= 0) res[num - 1] = 1;
        return res;
    }

    ll segLen = lenArr[n - 1];
    ll totalLen = segLen * 3;

    if (l == 0 && r == totalLen - 1)
        return getFull(num, n);

    array<ll, 3> res = {0, 0, 0};
    for (int i = 0; i < 3; i++) {
        ll s = i * segLen;
        ll e = (i + 1) * segLen - 1;
        if (r < s || l > e) continue;
        ll nl = max(0LL, l - s);
        ll nr = min(segLen - 1, r - s);
        auto sub = countRange(trans[num][i], n - 1, nl, nr);
        for (int j = 0; j < 3; j++) res[j] += sub[j];
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int startNum;
    ll L, R;
    int N;
    cin >> startNum >> L >> R >> N;

    lenArr[0] = 1;
    for (int i = 1; i <= N; i++) lenArr[i] = lenArr[i - 1] * 3;

    auto ans = countRange(startNum, N, L, R);
    cout << ans[0] << " " << ans[1] << " " << ans[2] << "\n";
}
