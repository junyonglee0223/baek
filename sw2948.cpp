//sw2948 문자열 교집합
#include<iostream>
#include<unordered_set>
#include<string>
#include<vector>
using namespace std;

int solution_string_set() {
	int NA, NB; cin >> NA >> NB;

	unordered_set<string>str_set;

	for (int i = 0; i < NA; i++) {
		string str; cin >> str;
		str_set.insert(str);
	}

	unordered_set<string>B_set;
	vector<string>vb;
	for (int i = 0; i < NB; i++) {
		string str; cin >> str;
		if (B_set.find(str) == B_set.end()) {
			B_set.insert(str);
			vb.push_back(str);
		}
	}

	int ret = 0;
	for (auto ele : vb) {
		if (str_set.find(ele) != str_set.end()) {
			ret++;
		}
	}
	return ret;
}


int main(int argc, char** argv)
{
	int test_case;
	int T;
	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		int ret = solution_string_set();
		cout << "#" << test_case << " " << ret << "\n";
	}
	return 0;
}

/*
2
2 3
ab a
a ac ba
3 3
aa bb cc
dd cc aa
*/
/*
출력
#1 1
#2 2
*/