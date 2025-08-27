//g4373 수집합
#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
using namespace std;

typedef long long ll;

int solution_abcd_v1(int n) {
	int ret = -1;
	if (n < 4)return ret;

	vector<ll>arr(n);
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	sort(arr.begin(), arr.end());
	for (int last_idx = n - 1; last_idx >= 3; last_idx--) {
		for (int first_idx = 0; first_idx < last_idx-2; first_idx++) {
			ll target = arr[last_idx] - arr[first_idx];
			int left = first_idx + 1, right = last_idx - 1;
			while (left < right) {
				ll tmp_sum = arr[left] + arr[right];
				if (tmp_sum < target)left++;
				else if (tmp_sum > target)right--;
				else {
					return arr[last_idx];
				}
			}
		}
	}
	return -1;
}

typedef pair<int, int> p;

struct PSUM {
	int i, j;
	ll ele;
	PSUM(int _i, int _j, ll _ele) {
		i = _i, j = _j, ele = _ele;
	}
	bool operator<(const PSUM& other) const {
		if (ele != other.ele) return ele < other.ele;
		if (i != other.i) return i < other.i;
		return j < other.j;
	}
};
int solution_abcd(int n) {
	int ret = -1;
	if (n < 4)return ret;

	vector<ll>arr(n);
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	sort(arr.begin(), arr.end());

	vector<PSUM>two_rets;

	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			ll ele = arr[i] + arr[j];
			two_rets.push_back(PSUM(i, j, ele));
		}
	}
	sort(two_rets.begin(), two_rets.end());


	for (int last_idx = n - 1; last_idx >= 0; last_idx--) {
		for (int first_idx = 0; first_idx < n; first_idx++) {
            if(first_idx == last_idx)continue;
			ll ele = arr[last_idx] - arr[first_idx];
			PSUM left = PSUM(-1, -1, ele);
			PSUM right = PSUM(n, n, ele);

			auto left_it = lower_bound(two_rets.begin(), two_rets.end(), left);
			auto right_it = upper_bound(two_rets.begin(), two_rets.end(), right);
			if (left_it == right_it)continue;
			for (auto it = left_it; it != right_it; it++) {
				int c = it->i;
				int d = it->j;
				if (first_idx == c || first_idx == d || last_idx == c || last_idx == d)continue;
				return arr[last_idx];
			}
		}
	}
	return -1;
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n; cin >> n;
	while (n != 0) {
		int ret = solution_abcd(n);
		if (ret == -1) {
			cout << "no solution" << "\n";
		}
		else {
			cout << ret << "\n";
		}
		cin >> n;
	}

	return 0;
}


/*
5
2
3
5
7
12
5
2
16
64
256
1024
0
*/

/*
12
no solution
*/
