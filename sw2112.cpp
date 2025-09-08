#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<string>
#include<queue>
using namespace std;

int W, D, K;
vector<int> col_bits;
int best_ans;

inline bool pass_col(int num, int D, int K) {
	int last = (num & 1);
	int cnt = 1;
	if (K <= 1) return true;
	for (int i = 1; i < D; i++) {
		int b = (num >> i) & 1;
		if (b == last) cnt++;
		else { last = b; cnt = 1; }
		if (cnt >= K) return true;
	}
	return false;
}

inline bool all_pass(const vector<int>& col_bits, int D, int K) {
	for (int x : col_bits) {
		if (!pass_col(x, D, K)) return false;
	}
	return true;
}

inline void apply_row(int d, int target, vector<int>& changed_idx) {
	changed_idx.clear();
	int mask = 1 << d;
	if (target == 0) {
		for (int i = 0; i < (int)col_bits.size(); i++) {
			if ((col_bits[i] >> d) & 1) {
				col_bits[i] &= ~mask;
				changed_idx.push_back(i);
			}
		}
	}
	else {
		for (int i = 0; i < (int)col_bits.size(); i++) {
			if (((col_bits[i] >> d) & 1) == 0) {
				col_bits[i] |= mask;
				changed_idx.push_back(i);
			}
		}
	}
}

inline void restore_row(int d, int target, const vector<int>& changed_idx) {
	int mask = 1 << d;
	if (target == 0) {
		for (int i : changed_idx) col_bits[i] |= mask;
	}
	else {
		for (int i : changed_idx) col_bits[i] &= ~mask;
	}
}

void dfs(int row, int used) {
	if (used >= best_ans) return;
	if (all_pass(col_bits, D, K)) { best_ans = used; return; }
	if (row == D) return;

	dfs(row + 1, used);

	vector<int> changed;
	apply_row(row, 0, changed);
	dfs(row + 1, used + 1);
	restore_row(row, 0, changed);

	apply_row(row, 1, changed);
	dfs(row + 1, used + 1);
	restore_row(row, 1, changed);
}

int solution_protection_film() {
		cin >> D >> W >> K;
		vector<vector<int>> a(D, vector<int>(W));
		for (int i = 0; i < D; i++) {
			for (int j = 0; j < W; j++) cin >> a[i][j];
		}

		col_bits.assign(W, 0);
		for (int j = 0; j < W; j++) {
			int v = 0;
			for (int i = 0; i < D; i++) {
				if (a[i][j] == 1) v |= (1 << i);
			}
			col_bits[j] = v;
		}

		if (K <= 1) return 0;
		if (all_pass(col_bits, D, K))return 0;

		best_ans = K;
		dfs(0, 0);
		return best_ans;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T; cin >> T;
	for (int tc = 1; tc <= T; ++tc) {
		int ret = solution_protection_film();
		cout << "#" << tc << " " << ret << "\n";
	}
	return 0;
}
