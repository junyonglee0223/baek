//N과 M (2)
#include <iostream>
#include <vector>
using namespace std;

#define endl '\n'
int N, M;

void arrayBackTracking(vector<int>& prev, int start) {
    if (prev.size() == M) {
        for (int i = 0; i < M; i++) {
            cout << prev[i] << " ";
        }
        cout << endl;
        return;
    }

    for (int i = start; i <= N; i++) {
        prev.push_back(i);
        arrayBackTracking(prev, i + 1);
        prev.pop_back();
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    cin >> N >> M;
   
    vector<int> save;
    arrayBackTracking(save, 1);

    return 0;
}
