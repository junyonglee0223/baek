#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<unordered_set>
#include<set>
#include<climits>
using namespace std;

int A, B, C;
bool visited[201][201];
bool possibleC[201];

void dfs(int a, int b) {
	if (visited[a][b]) return;
	visited[a][b] = true;
	int c = C - a - b;
	if (a == 0) possibleC[c] = true;

	int move;
	move = min(a, B - b);            dfs(a - move, b + move); // a->b
	move = min(a, C - c);            dfs(a - move, b);        // a->c
	move = min(b, A - a);            dfs(a + move, b - move); // b->a
	move = min(b, C - c);            dfs(a, b - move);        // b->c
	move = min(c, A - a);            dfs(a + move, b);        // c->a
	move = min(c, B - b);            dfs(a, b + move);        // c->b
}

void solution_bottles() {
	cin >> A >> B >> C;
	dfs(0, 0);


	for (int i = 0; i <= 200; i++) {
		if(possibleC[i])
			cout << i << " ";
	}
	cout << "\n";

}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	solution_bottles();
	return 0;
}

/*
1 - 5 - 4 - 2
3 - 4 - 2
4 - 6
5 - 2

N이 500까지고 M은 N^2까지기 때문에
시간 초과 발생하고 있음

*/

/*

8 9 10
*/

/*
1 2 8 9 10
*/
