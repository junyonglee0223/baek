//s2559 수열
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int N, K;
vector<int>arr;

int solution_array() {
    cin >> N >> K;
    arr.reserve(N);
    for (int i = 0; i < N; i++) {
        int ele; cin >> ele;
        arr.push_back(ele);
    }
    int left = 0, right = K - 1;
    int sum = 0;
    int ret = 0;
    for (int i = left; i <= right; i++) {
        sum += arr[i];
    }
    ret = sum;
    for (int i = K; i < N; i++) {
        sum += arr[i];
        sum -= arr[i - K];
        ret = max(ret, sum);
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << solution_array() << "\n";
    return 0;
}