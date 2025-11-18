#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int N, W;
const int H = 7;

struct NODE {
	int len, f_cnt, start;
	NODE(int _len, int _f_cnt, int _start)
		: len(_len), f_cnt(_f_cnt), start(_start) {}
	bool operator<(const NODE& other) const {
		if (len != other.len)
			return len > other.len;
		if (f_cnt != other.f_cnt)
			return f_cnt < other.f_cnt;
		//if (start != other.start)
			return start < other.start;
	}

	bool operator==(const NODE& other) const {
		return len == other.len &&
			f_cnt == other.f_cnt &&
			start == other.start;
	}
};

struct PNODE {
	string name;
	int len, f_cnt, start, fail;

	PNODE(string _name, int _len, int _f_cnt, int _start, int _fail)
		: name(_name), len(_len), f_cnt(_f_cnt), start(_start), fail(_fail) {}

	bool operator<(const PNODE& other) const {
		if (len != other.len)
			return len > other.len;
		if (f_cnt != other.f_cnt)
			return f_cnt < other.f_cnt; 
		if (start != other.start)
			return start < other.start; 
		if (fail != other.fail)
			return fail < other.fail; 
		return name < other.name;
	}

	bool operator==(const PNODE& other) const {
		return len == other.len &&
			f_cnt == other.f_cnt &&
			start == other.start &&
			fail == other.fail;
	}
};

PNODE calcPerson(string name) {
	vector<vector<char>>c_mp(H, vector<char>(W));
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			cin >> c_mp[i][j];
		}
	}
	string status_str = "";
	for (int i = 0; i < W; i++) {
		for (int j = 0; j < H; j++) {
			status_str += c_mp[j][i];
		}
	}
	int start = 0;
	int fcnt = 0;
	int fail_cnt = 0;
	vector<NODE>node_list;

	for (int i = 0; i < status_str.size(); i++) {
		if (status_str[i] == 'O') {
			node_list.push_back(NODE(i - start + 1 - fcnt, fcnt, start));
		}
		else if (status_str[i] == 'X') {
			start = i + 1;
			fcnt = 0;
			fail_cnt++;
		}
		else if (status_str[i] == 'F') {
			if (start == i) {
				start++;
			}
			else {
				fcnt++;
			}
		}
	}

	sort(node_list.begin(), node_list.end());
	////////////////////////////////////////////////////////////
	//for (int i = 0; i < node_list.size(); i++) {
	//	NODE tmp = node_list[i];
	//	cout << tmp.len << " " << tmp.f_cnt <<" "<< tmp.start << "\n";
	//}

	//cout << status_str << "\n";

	if (node_list.empty()) {
		return PNODE(name, 0, 0, H*W, fail_cnt);
	}

	NODE ret = node_list[0];
	return PNODE(name, ret.len, ret.f_cnt, ret.start, fail_cnt);
}

void solution_bsil_loves_grass() {
	cin >> N >> W;

	vector<PNODE>p_list;

	for (int i = 0; i < N; i++) {
		string name; cin >> name;
		PNODE tmp = calcPerson(name);
		p_list.push_back(tmp);
	}
	sort(p_list.begin(), p_list.end());
	vector<int>tier(N, 0);
	tier[0] = 1;
	for (int i = 1; i < N; i++) {
		if (p_list[i-1] == p_list[i]) {
			tier[i] = tier[i - 1];
			continue;
		}
		tier[i] = tier[i-1] + 1;
	}

	for (int i = 0; i < N; i++) {
		cout << tier[i] << ". " << p_list[i].name << "\n";
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	solution_bsil_loves_grass();

	return 0;
}

/*
2
2 4
baekjoon
OOOF
XOOO
OOFO
OOOO
OOOF
OFOO
XOOO
shiftpsh
XOOO
OOOO
OOFO
OOOO
OOOO
OOOO
XOOO

3 9
nonickname
OOOOOFOOO
XOOFOOFOO
OOOFOOXOO
OOFOOOOOO
OOOOOOOOO
OOOOOOOOO
OOOOOOOOO
baekjoon
OOOOOOOOO
OOOOFOOOO
OXOOOOOXO
OOOOOFOOO
OOFOOFOOO
OOFOOOOOO
OOOOOOOOO
shiftpsh
OOOOOOOOO
OOOOFOOOO
OOFOOOOOO
OOOOFOOOO
OFOOOOOOO
XOOOFOXOO
OOOOOOOOO
 */
 /*
 1. shiftpsh
 2. baekjoon
  */
  /*
  1. nonickname
  2. shiftpsh
  3. baekjoon
   */