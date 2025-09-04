//p2243 사탕상자
#include <iostream>
#include<string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

#define endl '\n'


const int MAX  = 1000001;
int tree[4 * MAX];
int n;

void update(int node, int target, int diff, int start, int end) {
	if (target<start || target > end)return;
	tree[node] += diff;
	int mid = (start + end) / 2;
	if (start == end)return;
	update(2 * node, target, diff, start, mid);
	update(2 * node + 1, target, diff, mid + 1, end);
}

int query(int node, int target, int start, int end) {

	if (start == end)return start;

	int mid = (start + end) / 2;

	if (target <= tree[node * 2])
		return query(2 * node, target, start, mid);
	else
		return query(2 * node + 1, target - tree[node* 2], mid + 1, end);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;
	while (n--) {
		int a, b, c;
		cin >> a;
		
		if (a == 1) {
			cin >> b;
			int favor = query(1, b, 1, MAX);
			cout << favor << '\n';
			update(1, favor, -1, 1, MAX);
		}
		else {
			cin >> b >> c;
			update(1, b, c, 1, MAX);
		}
	}



}

