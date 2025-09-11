//p1786 찾기
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;



void print_vec(vector<int>arr) {
	int n = arr.size();
	for (int i = 0; i < n; i++)
		cout << arr[i] << " ";
	cout << endl;
}

vector<int>failure_func(string str) {
	int n = str.size();
	vector<int>ret(n, 0);
	int match = 0;

	for (int i = 1; i < n; i++) {
		while (match > 0 && str[match] != str[i])match = ret[match - 1];
		if (str[i] == str[match]) { match++; ret[i] = match; }
	}
	return ret;
}

void solution_searching() {
	string T;
	getline(cin, T);
	cin.clear();
	string P;
	getline(cin, P);

	vector<int>pfunc = failure_func(P);

	int TSize = T.size();
	int PSize = P.size();

	int begin = 0;
	int len = 0;

	int ret_cnt = 0;
	vector<int>ret;

	for (int tidx = 0; tidx < TSize; tidx++) {
		while (len > 0 && T[tidx] != P[len])len = pfunc[len - 1];
		if (T[tidx] == P[len]) {
			len++;
			if (len == PSize) {
				ret_cnt++;
				//문자열이 [1, Tsize] 형태라고 했기 때문에 마지막에 1 더해줌
				ret.push_back(tidx - len + 1 + 1);
				len = pfunc[len - 1];
			}
		}
	}

	cout << ret_cnt << "\n";
	for (auto ele : ret) {
		cout << ele << " ";
	}
	cout << "\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	solution_searching();

	return 0;
}

/*
ABC ABCDAB ABCDABCDABDE
ABCDABD

*/
/*
1
16
*/