#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int max_score(vector<vector<int>>& stickers, int N) {
    vector<int> prev(3, 0), curr(3, 0);

    prev[0] = 0;
    prev[1] = stickers[0][0];
    prev[2] = stickers[1][0];

    for (int i = 1; i < N; ++i) {
        curr[0] = max({prev[0], prev[1], prev[2]});
        curr[1] = max(prev[0], prev[2]) + stickers[0][i];
        curr[2] = max(prev[0], prev[1]) + stickers[1][i];
        swap(prev, curr);
    }

    return max({prev[0], prev[1], prev[2]});
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        vector<vector<int>> stickers(2, vector<int>(N));

        for (int i = 0; i < 2; ++i) {
            for (int j = 0; j < N; ++j) {
                cin >> stickers[i][j];
            }
        }

        cout << max_score(stickers, N) << endl;
    }

    return 0;
}
