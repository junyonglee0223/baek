//g14712 넴모넴모(Easy)
#include<iostream>
#include<unordered_set>
#include<string>
#include<vector>
using namespace std;


typedef long long ll;
int N, M;
int ans;

bool is_pos(ll mask, int r, int c) {
	if (c == 0 || r == 0)return true;
	int m1 = (r - 1) * M + (c - 1);
	int m2 = (r - 1) * M + c;
	int m3 = r * M + (c - 1);
	if ((mask & (1 << m1)) && (mask & (1 << m2)) && (mask & (1 << m3)))return false;
	return true;
}

void dfs(ll mask, int k) {
	if(k == N * M) {
		ans++;
		return;
	}
	dfs(mask, k + 1);

	int r = k / M;
	int c = k % M;
	if (is_pos(mask, r, c)) {
		dfs((mask | (1 << k)), k + 1);
	}
	return;
}



int solution_rect_rect() {
	cin >> N >> M;
	dfs(0, 0);
	return ans;
}


int main(int argc, char** argv)
{
		cout << solution_rect_rect() << "\n";

	//
	//int T;
	//cin >> T;
	//while (T--) {
	//	ans = 0;
	//	cout << solution_rect_rect() << "\n";
	//}
	return 0;
}

/*
3
2 2
2 3
3 5
*/
/*
15
57
22077
*/