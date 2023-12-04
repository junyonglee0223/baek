#include <bits/stdc++.h>
using namespace std;

int count_stone(vector<int> stones, int mid) {
    int ret = 0;
    int cnt_stone = 0;
    for (int i = 0; i < stones.size(); i++) {
        if (stones[i] - mid <= 0)
            cnt_stone++;
        else
            cnt_stone = 0;
        ret = max(ret, cnt_stone);
    }
    return ret;
}

int solution(vector<int> stones, int k) {
    int left = 0;
    int right = *max_element(stones.begin(), stones.end());

    while (left < right) {
        int mid = left + (right - left) / 2;
        if (count_stone(stones, mid) < k)
            left = mid + 1;
        else
            right = mid;
    }
    return left;
}
