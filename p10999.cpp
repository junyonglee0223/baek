//p10999 구간 합 구하기2
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;

typedef long long ll;

int N;
vector<ll>arr;
struct SEGTREE{
	vector<ll>segtree;
	vector<ll>lazy;
	SEGTREE() {
		segtree.resize(4 * N);
		lazy.resize(4 * N);
		init(1, 0, N-1);
	}
	void init(int node, int src, int dst) {
		if (src == dst) {
			segtree[node] = arr[src];
			////////////////////////////////////////////////////
			//cout << "node: " << node << " value : " << arr[src] << endl;
			////////////////////////////////////////////////////
			return;
		}

		int mid = (src + dst) >> 1;
		init(node << 1, src, mid);
		init((node << 1) | 1, mid + 1, dst);
		segtree[node] = segtree[node << 1] + segtree[(node << 1) | 1];
	}

	void push(int node, int src, int dst) {
		if (lazy[node] == 0)return;
		segtree[node] += lazy[node] * (dst - src + 1);
		if (src != dst) {
			lazy[node << 1] += lazy[node];
			lazy[(node << 1) | 1] += lazy[node];
		}
		lazy[node] = 0;
		return;
	}

	void update(int node, int src, int dst, int p, int q, ll v) {
		push(node, src, dst);
		if (q < src || dst < p)return;
		if (p <= src && dst <= q) {
			lazy[node] += v;
			push(node, src, dst);
			return;
		}
		int mid = (src + dst) >> 1;
		update(node << 1, src, mid, p, q, v);
		update((node << 1) | 1, mid + 1, dst, p, q, v);
		segtree[node] = segtree[node << 1] + segtree[(node << 1) | 1];
	}
	void update(int p, int q, ll v) {
		update(1, 0, N - 1, p, q, v);
	}
	ll query(int node, int src, int dst, int p, int q) {
		push(node, src, dst);
		if (q < src || dst < p)return 0;
		if (p <= src && dst <= q) {
			return segtree[node];
		}
		int mid = (src + dst) >> 1;
		return query(node << 1, src, mid, p, q)+ query((node << 1) | 1, mid + 1, dst, p, q);
	}

	ll query(int p, int q) {
		if (p > q)return query(q, p);
		return query(1, 0, N - 1, p, q);
	}

	void print_arr_area() {
		int s = 1;
		while (s < N)s <<= 1;
		for (int i = 0; i < N; i++) {
			cout << segtree[s + i] << " ";
		}
		cout << endl;
	}
	void print_seg_tree() {
		int s = 1;
		while (s < N)s <<= 1;
		for (int i = 1; i < 2 * s; i++) {
			cout << "node: " << i << " = " << segtree[i] << endl;
		}
	}
};

string solution_sum_of_intervals_2() {
	int M, K; cin >> N >> M >> K;
	arr.reserve(N);
	string ret;
	for (int i = 0; i < N; i++) {
		ll ele; cin >> ele;
		arr.push_back(ele);
	}

	SEGTREE sgt;
	////////////////////////////////
	//cout << "//////////////////////////////////////" << endl;
	//	//sgt.print_arr_area();
	//	sgt.print_seg_tree();
	//cout << "//////////////////////////////////////" << endl;

	for (int i = 0; i < M + K; i++) {
		int a, b, c; cin >> a >> b >> c;
		b--; c--;
		if (a == 1) {
			ll d;	cin >> d;
			sgt.update(b, c, d);
		}
		else if (a == 2) {
			ll cur_ret = sgt.query(b, c);
			ret.append(to_string(cur_ret)).append("\n");
		}
		
		/////////////////////////////////////////////
		//sgt.print_arr_area();
	}
	return ret;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cout << solution_sum_of_intervals_2() << "\n";

	return 0;
}
/*
5 2 2
1
2
3
4
5
1 3 4 6
2 2 5
1 1 3 -2
2 2 5
*/
/*
26
22
*/