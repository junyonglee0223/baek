//g28099 이상한 배열
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<unordered_map>
using namespace std;

#define MAX_N 200001
int N;
vector<int>arr;
vector<vector<int>>adj;
unordered_map<int, vector<int>>mp;
unordered_map<int, int>first;
unordered_map<int, int>last;


struct SEGTREE {
	vector<int>segtree;
	SEGTREE() {
		segtree.clear();

		segtree.resize(4 * N);
		init(1, 0, N - 1);
	}

	void init(int node, int src, int dst) {
		if (src == dst) {
			segtree[node] = arr[src];
			return;
		}
		int mid = (src + dst) >> 1;
		init(node << 1, src, mid);
		init((node << 1) | 1, mid + 1, dst);
		segtree[node] = max(segtree[node << 1], segtree[(node << 1) | 1]);
	}

	int query(int node, int src, int dst, int p, int q) {
		if (dst < p || q < src)return 0;
		if (p <= src && dst <= q)return segtree[node];
		int mid = (src + dst) >> 1;
		return max(query(node << 1, src, mid, p, q), query((node << 1) | 1, mid + 1, dst, p, q));
	}

	int query(int p, int q) {
		return query(1, 0, N - 1, p, q);
	}
};



bool solution_strange_array() {
	cin >> N;
	adj.clear();
	arr.clear();
	arr.assign(N, 0);
	first.clear();
	last.clear();
	mp.clear();


	int max_v = 0;
	vector<int>v_idx; v_idx.reserve(N);
	for (int i = 0; i < N; i++) {
		int ele; cin >> ele;
		arr[i] = ele;

		if (first.find(ele) == first.end()) {
			first[ele] = i;
			v_idx.push_back(ele);
		}
		last[ele] = i;

		max_v = max(max_v, ele);
	}

	SEGTREE sgt;

	for (int i = v_idx.size() - 1; i >= 0; i--) {
		int val = v_idx[i];
		int f_i = first[val];
		int l_i = last[val];

		int cur_val = sgt.query(f_i + 1, l_i - 1);
		if (cur_val > val)return false;
	}

	return true;
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int T; cin >> T;
	while (T--) {
		string ret = solution_strange_array() ? "Yes" : "No";
		cout << ret << "\n";
	}

	return 0;
}

/*
p1 - p2

p2 - p3

만족 -> p1 - p3 만족
이런 논리로 가면 되나?
투포인터 느낌이긴 하다

이전 상태가 이후 상태와 독립적이지 않다.


조건 같은 친구가 있어야 함
투포인터로 그 사이 비교함

두 지점 확인해서 나보다 큰게 몇개 나 있는지 확인



*/
/*
6
3
1 2 3
5
1 1 2 2 3
6
1 2 3 1 2 3
9
6 3 2 3 6 4 1 4 6
7
4 3 2 3 1 3 4
9
6 3 1 3 6 4 1 4 6
*/
/*
Yes
Yes
No
Yes
Yes
No
*/