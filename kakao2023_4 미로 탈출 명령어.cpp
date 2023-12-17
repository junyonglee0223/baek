
#include <bits/stdc++.h>

#include <string>
#include <vector>

using namespace std;

// d, l, r, u
int c_cnt[4] = {0};
int K;

string solution(int n, int m, int x, int y, int r, int c, int k)
{
    string answer = "";
    K = k;
    int dist = abs(r - x) + abs(c - y);
    if (r > x)
        c_cnt[0] += (r - x);
    else if (r < x)
        c_cnt[3] += (x - r);

    if (c > y)
        c_cnt[2] += (c - y);
    else if (c < y)
        c_cnt[1] += (y - c);

    k -= dist;
    if (k < 0 || k % 2 == 1)
    {
        answer = "impossible";
        return answer;
    }

    // 반영하고 answer string에 추가하기
    // k/2
    // d 추가 식은 이게 맞음
    // d 먼저 반영하고 u에도 같은 값으로 저장하기
    // k -= 2 * add_d
    //  d는 먼저 반영하고 l도 먼저 반영하고 시작한다.

    int d = min(k / 2, n - x - c_cnt[0]);
    c_cnt[0] += d;
    c_cnt[3] += d;
    answer.append(c_cnt[0], 'd');
    k -= 2 * d;

    int l = min(k / 2, y - 1 - c_cnt[1]);
    c_cnt[1] += l;
    c_cnt[2] += l;
    answer.append(c_cnt[1], 'l');
    k -= 2 * l;

    for (int i = 0; i < k / 2; ++i)
        answer += "rl";

    answer.append(c_cnt[2], 'r');
    answer.append(c_cnt[3], 'u');

    if (answer.size() != K)
        answer = "impossible";

    return answer;
}