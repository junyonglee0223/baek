#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<unordered_set>
#include<set>
using namespace std;

struct EDGE {
	int d, s, e;
	EDGE(int _d, int _s, int _e) {
		d = _d; s = _s; e = _e;
	}
	EDGE() {}
};
struct EDGE_CMP {
	bool operator()(const EDGE&a, const EDGE &b) {
		return a.d < b.d;
	}
}edge_cmp;

#define MAX_D 1001
int N, M;

vector<int>parents;

int find(int cur) {
	if (parents[cur] == cur)return cur;
	return parents[cur] = find(parents[cur]);
}
bool union_find(int a, int b) {
	int pa = find(a);
	int pb = find(b);

	if (pa == pb)return false;
	parents[pa] = pb;
	return true;
}
int solution_eternally_single() {
	cin >> N >> M;
	vector<int>vtx(N);
	parents.resize(N);
	for (int i = 0; i < N; i++) {
		char c; cin >> c;
		if (c == 'M')vtx[i] = 0;
		else vtx[i] = 1;
		parents[i] = i;
	}
	vector<EDGE>edges;

	for (int i = 0; i < M; i++) {
		int u, v, d; cin >> u >> v >> d;
		u--; v--;
		if (vtx[u] == vtx[v])continue;
		if (u > v)swap(u, v);

		edges.push_back(EDGE(d, u, v));
	}
	sort(edges.begin(), edges.end(), edge_cmp);
	int ret = 0;
	int r_cnt = 0;
	for (int i = 0; i < edges.size() && r_cnt < N-1; i++) {
		EDGE e = edges[i];
		if (union_find(e.s, e.e)) {
			ret += e.d;
			r_cnt++;
		}
	}
	int target = find(0);
	for (int i = 1; i < N; i++) {
		if (find(i) != target)return -1;
	}


	return ret;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cout << solution_eternally_single() << "\n";

	//int T; cin >> T;
	//for (int tc = 1; tc <= T; tc++) {
	//	cout << "#" << tc << " " << solve() << "\n";
	//}
	return 0;
}

/*
M, W 간의 간선만 의미가 있다.
경로의 길이가 최소가 되어야 함

최소 스패닝 트리가 아닌가?
맞긴 한데 로직이 잘못됨
유니온 파인드로 하던가 아니면 프림 알고리즘으로 해야 함

유니온 파인드로 하는데 오류 발생 중 


*/


/*
5 7
M W W W M
1 2 12
1 3 10
4 2 5
5 2 5
2 5 10
3 4 3
5 4 7
*/

/*
34
*/
