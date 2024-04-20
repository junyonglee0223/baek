//좌표 압축
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    vector<int> original(N); 
    for(int i = 0; i < N; i++) {
        cin >> original[i];
    }

    vector<int> sorted(original);
    sort(sorted.begin(), sorted.end());
    sorted.erase(unique(sorted.begin(), sorted.end()), sorted.end()); // 중복 제거

    unordered_map<int, int> compressed;
    for(int i = 0; i < sorted.size(); i++) {
        compressed[sorted[i]] = i;
    }

    for(int i = 0; i < N; i++) {
        cout << compressed[original[i]] << ' ';
    }

    return 0;
}
