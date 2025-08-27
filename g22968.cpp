//g22968 AVL Tree Height
#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;

#define MAX_V 1000000001
const int MAX_H = 8 * log2(MAX_V);


vector<long long>heights;

void solution_init() {
	heights.resize(MAX_H + 1);
	heights[1] = 1;
	heights[2] = 2;
	for (int h = 3; h <= MAX_H; h++) {
		long long ele = heights[h - 1] + heights[h - 2] + 1;
		//if (ele > MAX_V)break;
		heights[h] = ele;
	}
}

int solution_avl_height() {
	long long V; cin >> V;
	auto it = upper_bound(heights.begin(), heights.end(), V);

	return it - heights.begin() - 1;
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	/////////////////////////////////
	//cout << MAX_H << endl;
	////////////////////////////////
	
	solution_init();
	int T; cin >> T;
	while (T--) {
		cout << solution_avl_height() << "\n";
	}

	return 0;
}

/*
5
1
2
5
10
1000000000
*/

/*
1
2
3
4
42
*/
/*
노드 개수 주어졌을 때 avl 트리로 가능한 높이의 최댓값 구하는 문제임
이진 -> 노드 위치가 어느정도 정해짐

1	(2, 3)	(4, 5), (6, 7)		8, 9, 10, 11, 12, 13, 14, 15

그냥 힙 과정에 따라 삽입하는 방식 외에 가능한가?
높이가 하나 늘어날때마다 최소 필요한 개수가 정해져 있음




*/