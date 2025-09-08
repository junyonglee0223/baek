//p16496 큰 수 만들기
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<queue>
using namespace std;

struct STR_CMP {
	bool operator()(const string a, const string b) {
		string c_a = a + b;
		string c_b = b + a;
		for (int i = 0; i < c_a.size(); i++) {
			if (c_a[i] == c_b[i])continue;
			return c_a[i] < c_b[i];
		}
		return false;
	}
};

string solution_make_big_num() {
	int n; cin >> n;
	priority_queue<string, vector<string>, STR_CMP>pq;
	bool is_all_zero = true;
	for (int i = 0; i < n; i++) {
		int ele; cin >> ele;
		pq.push(to_string(ele));
		if (ele != 0)is_all_zero = false;
	}
	if (is_all_zero)return "0";

	string ret;
	while (!pq.empty()) {
		ret.append(pq.top());
		pq.pop();
	}
	return ret;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cout << solution_make_big_num() << "\n";
	
		//int T; cin >> T;
		//while (T--) {
		//	cout << solution_make_big_num() << "\n";
		//}
	
	return 0;
}

/*
2
5
3 30 34 5 9
5
0 0 0 0 1
*/

/*
9534330
10000
*/
