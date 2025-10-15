//g2109	순회공연
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;

struct NODE {
	int s, t;
	NODE() {}
	NODE(int _s, int _t) {
		s = _s; t = _t;
	}
};

struct NODE_CMP {
	bool operator()(NODE a, NODE b) {
		return a.s < b.s;
	}
};
		
int solution_touring_performance() {
	int n; cin >> n;
	if (n == 0)return 0;

	vector<NODE> arr(n);
	for (int i = 0; i < n; i++) {
		int a, b; cin >> a >> b;
		arr[i] = NODE(a, b);
	}

	sort(arr.begin(), arr.end(), [](const NODE a, const NODE b) {
		return a.t > b.t;
	});


	int max_d = arr[0].t;
	int cur_d = 0;

	priority_queue<NODE, vector<NODE>, NODE_CMP>pq;

	int ret = 0;

	while (max_d) {
		while (cur_d < n) {
			if (arr[cur_d].t >= max_d) {
				pq.push(arr[cur_d]);
				cur_d++;
			}
			else break;
		}
		if (!pq.empty()) {
				//cout << pq.top().s << pq.top().t << endl;//////////////////////////////test
			ret += pq.top().s;
			pq.pop();
		
		}
		max_d--;
	}
	return ret;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cout << solution_touring_performance() << "\n";

	return 0;
}

/*

7
20 1
2 1
10 3
100 2
8 2
5 20
50 10
*/