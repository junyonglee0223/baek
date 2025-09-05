//sw1280 나무심기
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

typedef long long ll;
const ll MOD = 1000000007;
#define MAX_N 200001

struct SEGTREE {
	vector<ll>segtree;
	vector<ll>segtree_cnt;
	SEGTREE() {
		segtree.resize(4 * MAX_N, 0);
		segtree_cnt.resize(4 * MAX_N, 0);
	}

	void update(int node, int src, int dst, int idx) {
		if (idx < src || dst < idx)return;
		if (src == dst) {
			segtree[node] += idx;
			segtree_cnt[node] += 1;
			return;
		}
		int mid = (src + dst) >> 1;
		update(node << 1, src, mid, idx);
		update((node << 1) | 1, mid + 1, dst, idx);
		segtree[node] = segtree[node << 1] + segtree[(node << 1) | 1];
		segtree_cnt[node] = segtree_cnt[node << 1] + segtree_cnt[(node << 1) | 1];
	}
	void update(int p) {
		update(1, 0, MAX_N - 1, p);
	}

	ll query(int node, int src, int dst, int p, int q) {
		if (q < src || dst < p)return 0;
		if (p <= src && dst <= q)return segtree[node];
		int mid = (src + dst) >> 1;
		return query(node << 1, src, mid, p, q)
			+ query((node << 1) | 1, mid + 1, dst, p, q);
	}
	ll query(int p, int q) {
		return query(1, 0, MAX_N - 1, p, q);
	}
	ll query_cnt(int node, int src, int dst, int p, int q) {
		if (q < src || dst < p)return 0;
		if (p <= src && dst <= q)return segtree_cnt[node];
		int mid = (src + dst) >> 1;
		return query_cnt(node << 1, src, mid, p, q)
			+ query_cnt((node << 1) | 1, mid + 1, dst, p, q);
	}
	ll query_cnt(int p, int q) {
		if (p > q)return 0;
		return query_cnt(1, 0, MAX_N - 1, p, q);
	}
};

ll solution_planting_tree() {
	int N;
	cin >> N;
	SEGTREE sgt;

	ll ret = 1;
	int ele; cin >> ele;
	sgt.update(ele);

	for (int i = 1; i < N; i++) {
		cin >> ele;

		ll less_cnt = sgt.query_cnt(0, ele - 1);
		ll less_sum = sgt.query(0, ele - 1);

		ll more_cnt = sgt.query_cnt(ele + 1, MAX_N - 1);
		ll more_sum = sgt.query(ele + 1, MAX_N - 1);

		ll cur_cost = (ele * less_cnt) - less_sum + more_sum - (ele * more_cnt);
		cur_cost %= MOD;

		ret = (ret * cur_cost) % MOD;
		//cout <<"ele : "<<ele <<" cur_cost : " <<cur_cost << endl;//test/////////////////////////////
		//cout << "\t\t" << less_cnt << " " << less_sum << " " << more_cnt << " " << more_sum << endl;

		sgt.update(ele);
	}
	return ret;
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout<<	solution_planting_tree() << "\n";
	/*
		int T; cin >> T;
		while (T--) {
			cout << solution_planting_tree() << "\n";
			cout << "---------------------------" << "\n";
		}
	*/
	return 0;
}

/*
5

5
3
4
5
6
7

3
5
13
9

4
1
8
15
1

10
4
59
94
89
4
59
94
89
4
59

5
199999
197532
99069
83762
14539
*/
/*
180
64
3087
591860767
499739175
*/