//s2777 숫자 놀이
#include <string>
#include <vector>
#include <iostream>
using namespace std;


int solution_number_playing() {
	int n; cin >> n;
	if (n == 1)return 1;
	int div[8] = { 9, 8, 7, 6, 5, 4, 3, 2 };
	int left = n;
	int ret = 0;
	for (int i = 0; i < 8; i++) {
		while (left % div[i] == 0) {
			left /= div[i];
			ret++;
		}
	}
	if (left > 1)return -1;
	return ret;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int T; cin >> T;
	while (T--) {
		cout << solution_number_playing() << "\n";
	}

	return 0;
}