//s24542 튜터-튜티 관계의 수
#include<iostream>
#include<vector>
#include<map>
using namespace std;

const int MOD = 1000000007;

int get_parents(int start, vector<int>& parents) {
	if (start == parents[start])return start;
	return parents[start] = get_parents(parents[start], parents);
}

long long solution_tutor_tutie() {
	int N, M; cin >> N >> M;
	vector<int>parents(N+1);
	for (int i = 1; i <= N; i++) {
		parents[i] = i;
	}


	for (int i = 0; i < M; i++) {
		int a, b; cin >> a >> b;
		int pa = get_parents(a, parents);
		int pb = get_parents(b, parents);
		if (pa != pb) {
			//no matter
			parents[pa] = pb;
		}
	}

	map<int, int>mp;
	vector<int>groups;

	for (int i = 1; i <= N; i++) {
		int pi = get_parents(i, parents);
		if (mp.find(pi) == mp.end()) {
			groups.push_back(pi);
		}
		mp[pi]++;
	}
	long long ret = 1;
	for (auto ele : groups) {
		ret = (ret * mp[ele]) % MOD;
		if (ret < 0) ret += MOD;
	}
	return ret;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	long long ret = solution_tutor_tutie();
	cout << ret << endl;
	/*
	int T; cin >> T;
	while (T--) {
		int ret = 	solution_tutor_tutie();
		cout << ret << "\n";
	}
	*/

	return 0;
}



/*
2
3 2
1 2
2 3

6 4
1 2
3 1
4 5
4 6
*/
/*
3
9
*/