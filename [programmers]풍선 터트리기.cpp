#include <string>
#include <vector>
#include <iostream>
#include <set>
#include <algorithm>
using namespace std;

int solution(vector<int> a) {
    int n = a.size();
    if (n <= 2) return n; 

    vector<int> leftMin(n), rightMin(n);

    leftMin[0] = a[0];
    for (int i = 1; i < n; i++) {
        leftMin[i] = min(leftMin[i - 1], a[i]);
    }

    rightMin[n - 1] = a[n - 1];
    for (int i = n - 2; i >= 0; i--) {
        rightMin[i] = min(rightMin[i + 1], a[i]);
    }

    int answer = 2; 

    for (int i = 1; i < n - 1; i++) {
        if (a[i] <= leftMin[i - 1] || a[i] <= rightMin[i + 1]) {
            answer++;
        }
    }

    return answer;
}

int main() {
    vector<vector<int>> testCases = {
        {9, -1, -5},
        {-16, 27, 65, -2, 58, -92, -71, -68, -61, -33}
    };
    for (int i = 0; i < testCases.size(); i++) {
        cout << "Test Case " << i + 1 << ": " << solution(testCases[i]) << endl;
    }
}

/*
-16, -92, -71, -68, -61, -33
    2번 예제 가능한 원소
작은거 삭제는 최대 한번만 가능하다.
generally 하게 큰 게 삭제된다. 인접한 풍선은 임의 선택 가능하다.
    = 가장 최소 풍선이 남는다. 

left, mid, right
mid가 살아남기 위해서는 left, right가 둘 다 작아서는 안 됨.

구체적으로 
chance 사용하지 않았을 경우 left, right 중 하나만 크거나 둘 다 커야 가능.
chance 사용했다면 둘 다 커야 가능

0. 
    segment tree 만들어서 좌우 배열 최소와 2번째 최소 저장하고 싶은데
    비용이 클 거 같아서 불가능 하다고 판단. 

1.
    세번 돌아서 해결 가능할 듯 하다. 배열에 왼쪽 부분만 판단해서
    min, second_min, 저장해 가면서, 0, 1, 2 상태로 불가 , 조건 가능, 가능
    상태로 저장한다.
    우측도 마찬가지로 저장한다.
    마지막 판단은 모두 2거나 하나만 

2.
    양끝의 원소는 무조건 생존 가능하다.

*/

