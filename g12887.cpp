//g12887 경로게임
#include <iostream>
#include <vector>
#include <string>
#include <climits>
#include <algorithm>
#include <queue>
using namespace std;

typedef long long ll;
typedef pair<int, int>p;
string g_str1, g_str2;
vector<string>g_str;
int N;

ll solution_path_game() {
	g_str.clear();
	cin >> N;
	cin >> g_str1 >> g_str2;
	g_str.push_back(g_str1);
	g_str.push_back(g_str2);

	int dis_cnt = 0;
	vector<vector<int>>dist(2, vector<int>(N, 0));
	for (int i = 0; i < N; i++) {
		if (g_str[0][i] == '#') { dis_cnt++; dist[0][i] = INT_MAX; }
		if (g_str[1][i] == '#') { dis_cnt++; dist[1][i] = INT_MAX; }
	}

	queue<p>que;
	if (g_str[0][0] != '#') { que.push({ 0, 0 }); dist[0][0] = 1; }
	if (g_str[1][0] != '#') { que.push({ 1, 0 }); dist[1][0] = 1; }

	while (!que.empty()) {
		p cur_node = que.front(); que.pop();
		int cur = cur_node.second;
		int idx = cur_node.first;

		//idx, cur + 1
		if (cur < N-1 && dist[idx][cur+1] == 0) {
			dist[idx][cur + 1] = dist[idx][cur] + 1;
			que.push({ idx, cur + 1 });
		}

		//(idx + 1)%2, cur
		int n_idx = (idx + 1) % 2;
		if (dist[n_idx][cur] == 0) {
			dist[n_idx][cur] = dist[idx][cur] + 1;
			que.push({ n_idx, cur });
		}
	}

	int select_path_cnt = min(dist[0][N - 1], dist[1][N - 1]);



	return 2 * N - dis_cnt - select_path_cnt;
}

/*
n이 50 이하 인 점을 생각하면 dfs 탐색으로 상태변화 시키면서 계속 돌리면 가능할 듯
2^100 -> long long 스택 쌓이면 터질 수도 있나
응 안됨
. -> #
단방향 변경 dfs 상태 그대로 유지

문제에 대한 이해를 잘못함
이미 존재하는 상태에서 최대한 바꾸고자함
bfs로 전체 탐색 진행하고 총 거리 제외, 장애물 제외하고 전체 삭제하면 됨

*/

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);


	cout << solution_path_game() << "\n";

	//int T; cin >> T;
	//while (T--) {
	//	cout << solution_path_game() << "\n";
	//}

	return 0;
}



/*
2
5
#....
...#.
1
#
.
*/

/*
2
0
*/