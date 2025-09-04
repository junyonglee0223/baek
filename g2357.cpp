//g2357 최솟값과 최댓값
#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;

typedef long long ll;
int N, M;
vector<int>arr;

struct SEGMAX {
	int segsize;
	vector<int>segtree;
	SEGMAX() {
		set_segsize();
		segtree.resize(segsize * 2);
		init();
	}
	void set_segsize() {
		int ret = 1;
		while (ret < N)ret <<= 1;
		segsize = ret;
	}

	void init() {
		for (int i = 0; i < N; i++) {
			segtree[i + segsize] = arr[i];
		}

		for (int i = segsize - 1; i >= 1; i--) {
			segtree[i] = max(segtree[i << 1], segtree[(i << 1) | 1]);
		}
	}
	int query(int p, int q) {
		if (q < p)swap(p, q);
		int ret = 0;
		int a = segsize + p;
		int b = segsize + q;
		while (a <= b) {
			if ((a & 1) == 1) {
				ret = max(ret, segtree[a]);
				a++;
			}
			if ((b & 1) == 0) {
				ret = max(ret, segtree[b]);
				b--;
			}
			a >>= 1;
			b >>= 1;
		}
		return ret;
	}	
	void print_seg() {
		for (int i = 1; i < segsize; i++) {
			cout << segtree[i] << " ";
		}
		cout << endl;
	}

};

struct SEGMIN {
	int segsize;
	vector<int>segtree;
	SEGMIN() {
		set_segsize();
		segtree.resize(segsize * 2, INT_MAX);
		init();
	}
	void set_segsize() {
		int ret = 1;
		while (ret < N)ret <<= 1;
		segsize = ret;
	}

	void init() {
		for (int i = 0; i < N; i++) {
			segtree[i + segsize] = arr[i];
		}

		for (int i = segsize - 1; i >= 1; i--) {
			segtree[i] = min(segtree[i << 1], segtree[(i << 1) | 1]);
		}
	}
	int query(int p, int q) {
		if (q < p)swap(p, q);
		int ret = INT_MAX;
		int a = segsize + p;
		int b = segsize + q;
		while (a <= b) {
			if ((a & 1) == 1) {
				ret = min(ret, segtree[a]);
				a++;
			}
			if ((b & 1) == 0) {
				ret = min(ret, segtree[b]);
				b--;
			}
			a >>= 1;
			b >>= 1;
		}
		return ret;
	}
	void print_seg() {
		for (int i = 1; i < segsize; i++) {
			cout << segtree[i] << " ";
		}
		cout << endl;
		for (int i = segsize; i < segsize + N; i++) {
			cout << segtree[i] << " ";
		}
		cout << endl;
	}
};

void solution_minnum_maxnum() {
	arr.clear();
	cin >> N >> M;
	arr.reserve(N);

	for (int i = 0; i < N; i++) {
		int ele; cin >> ele;
		arr.push_back(ele);
	}
	SEGMAX sgtmax;
	SEGMIN sgtmin;

	//sgtmax.print_seg();//test
	sgtmin.print_seg();//test

	for (int i = 0; i < M; i++) {
		int a, b; cin >> a >> b;
		a--; b--;
		cout << sgtmin.query(a, b) << " " << sgtmax.query(a, b) << "\n";
	}
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	solution_minnum_maxnum();

	return 0;
}
/*
N, M <-100,000
value <= 1,000,000,000
합산하는게 아닌 최대 최소기 때문에 long 필요 없다.


*/




/*
10 4
75
30
100
38
50
51
52
20
81
5
1 10
3 5
6 9
8 10
*/
/*
5 100
38 100
20 81
5 81
*/