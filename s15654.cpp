//N과 M (5)
#include<iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define endl '\n'
int N, M;
vector<int> arr;

void arrBackTracking(vector<int>& prev, vector<bool>& used) {
    if (prev.size() == M) {
        for (int i = 0; i < prev.size(); i++) {
            cout << prev[i] << " ";
        }
        cout << endl;
        return;
    }

    for (int i = 0; i < N; i++) {
        if (!used[i]) {
            used[i] = true;
            prev.push_back(arr[i]);
            arrBackTracking(prev, used);
            prev.pop_back();
            used[i] = false;
        }
    }
    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> M;

    arr.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    sort(arr.begin(), arr.end()); 
    vector<int> ret;
    vector<bool> used(N, false);
    arrBackTracking(ret, used);

    return 0;
}
