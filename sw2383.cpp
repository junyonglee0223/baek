//SW2383_LunchTime.java
#include<iostream>
#include<vector>
#include<queue>
#include<set>
#include<algorithm>
#include<climits>
using namespace std;

typedef pair<int, int>p;

int get_time(vector<int>list, int time) {
	priority_queue<int, vector<int>, greater<>>pq;
	pq.push(0);
	pq.push(0);
	pq.push(0);

	for (auto arrive : list) {
		int ele = arrive + 1;
		if (pq.top() <= ele) {
			pq.pop();
			pq.push(ele + time);
		}
		else {
			int end_time = pq.top();
			pq.pop();
			pq.push(end_time + time);
		}
	}
	pq.pop();
	pq.pop();
	return pq.top();
}

int min_using_time(int stat, vector<int>stime, vector<vector<int>>dist) {
	int psize = dist.size();
	vector<int>f_list;
	vector<int>s_list;

	for (int i = 0; i < psize; i++) {
		if ((stat & (1 << i)) == 0) {
			f_list.push_back(dist[i][0]);
		}
		else {
			s_list.push_back(dist[i][1]);
		}
	}
	sort(f_list.begin(), f_list.end());
	sort(s_list.begin(), s_list.end());

	int t1 = get_time(f_list, stime[0]);
	int t2 = get_time(s_list, stime[1]);
	///////////////////////////////////////////////
	//cout << "\t" << t1 << " " << t2 << endl;

	return max(t1, t2);
}

int solution_lunch_time() {
	int N; cin >> N;
	vector<vector<int>>board(N, vector<int>(N, 0));
	int stair_cnt = 0;
	vector<p>stairs;
	vector<int>stair_time;
	vector<p>people;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> board[i][j];
			if (board[i][j] > 1) {
				stair_cnt++;
				stairs.push_back({ i, j });
				stair_time.push_back(board[i][j]);
			}
			else if (board[i][j] == 1) {
				people.push_back({ i, j });
			}
		}
	}	
	int psize = people.size();
	int ssize = stairs.size();
	vector<vector<int>>dist(psize, vector<int>(ssize, 0));
	for (int i = 0; i < psize; i++) {
		for (int j = 0; j < ssize; j++) {
			p person = people[i];
			p stair = stairs[j];
			dist[i][j] = abs(person.first - stair.first) + abs(person.second - stair.second);
		}
	}
	int ret = INT_MAX;
	for (int i = 0; i < (1 << psize); i++) {
		//////////////////////////////////////////////
		//cout << min_using_time(i, stair_time, dist) << endl;
		ret = min(ret, min_using_time(i, stair_time, dist));
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
		cout << "#" << test_case << " " << solution_lunch_time() << "\n";
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
/*
거리는 계산하면 된다.
도착했다고 할때 얼마나 딜레이 될지가 중요하다.
그리디한 방식으로 구현하나?
ㄱㄱ

*/

/*

10
5
0 1 1 0 0
0 0 1 0 3
0 1 0 1 0
0 0 0 0 0
1 0 5 0 0
5
0 0 1 1 0
0 0 1 0 2
0 0 0 1 0
0 1 0 0 0
1 0 5 0 0
*/


/*
#1 9
#2 8
#3 9
#4 7
#5 8
#6 8
#7 11
#8 11
#9 18
#10 12
*/
