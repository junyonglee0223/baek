#include <iostream>

#include <vector>

#include <algorithm>

using namespace std;

vector<int> temp;

long long countInversions(int left, int right, vector<int>& positions) {

    if (left >= right) return 0;

    int mid = (left + right) / 2;

    long long inversions = countInversions(left, mid, positions) + countInversions(mid + 1, right, positions);

    int i = left, j = mid + 1, k = left;

    while (i <= mid && j <= right) {

        if (positions[i] <= positions[j]) {

            temp[k++] = positions[i++];

        } else {

            temp[k++] = positions[j++];

            inversions += mid - i + 1;

        }

    }

    while (i <= mid) temp[k++] = positions[i++];

    while (j <= right) temp[k++] = positions[j++];

    for (int i = left; i <= right; ++i) positions[i] = temp[i];

    return inversions;

}

int main() {

    ios_base::sync_with_stdio(false);

    cin.tie(nullptr);

    int N;

    cin >> N;

    vector<int> A(N), B(N), positions(N);

    for (int i = 0; i < N; ++i) {

        cin >> A[i];

    }

    for (int i = 0; i < N; ++i) {

        cin >> B[i];

    }

    // Create a map to find positions quickly

    vector<int> positionMap(1000001);

    for (int i = 0; i < N; ++i) {

        positionMap[B[i]] = i;

    }

    // Translate A array to relative positions

    for (int i = 0; i < N; ++i) {

        positions[i] = positionMap[A[i]];

    }

    temp.resize(N);

    cout << countInversions(0, N - 1, positions) << '\n';

    return 0;

}