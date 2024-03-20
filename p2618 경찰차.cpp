#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

int row, col;
int nums;
vector<pair<int, int>>pathA;
vector<pair<int, int>>pathB;

int cache[1009][1009];
vector<int>v;

int getMaxDistance(int A, int B) {
	if (A == nums || B == nums)return 0;

	int& ret = cache[A][B];
	if (ret != -1)return ret;

	ret = 987654321;
	int maxIdx = max(A, B) + 1;
	int distA = abs(pathA[maxIdx].first - pathA[A].first)
		+ abs(pathA[maxIdx].second - pathA[A].second);
	int distB = abs(pathB[maxIdx].first - pathB[B].first)
		+ abs(pathB[maxIdx].second - pathB[B].second);
	int retA = getMaxDistance(maxIdx, B) + distA;
	int retB = getMaxDistance(A, maxIdx) + distB;

	return ret = min(retA, retB);
}

void reconstruct(int A, int B) {
	if (A == nums || B == nums)return;
	int maxIdx = max(A, B) + 1;
	int distA = abs(pathA[maxIdx].first - pathA[A].first)
		+ abs(pathA[maxIdx].second - pathA[A].second);
	int distB = abs(pathB[maxIdx].first - pathB[B].first)
		+ abs(pathB[maxIdx].second - pathB[B].second);
	int retA = getMaxDistance(maxIdx, B) + distA;
	int retB = getMaxDistance(A, maxIdx) + distB;

	if (retA > retB) {
		cout << 2 << endl;
		reconstruct(A, maxIdx);
	}
	else {
		cout << 1 << endl;
		reconstruct(maxIdx, B);
	}

}

void solve() {
	cout << getMaxDistance(0, 0) << endl;
	
	reconstruct(0, 0);
}


int main() {
	cin >> row; col = row;
	cin >> nums;
	
	memset(cache, -1, sizeof(cache));
	
	pathA.push_back({ 1, 1 });
	pathB.push_back({ row,row });


	int numsCnt = nums;
	while (numsCnt--) {
		int a, b;
		cin >> a >> b;
		pathA.push_back({ a,b });
		pathB.push_back({ a,b });
	}
	solve();
}

