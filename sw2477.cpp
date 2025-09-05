//sw2477 차량 정비소
#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<climits>
using namespace std;


#define MAX_N 10

int N, M, K;
vector<int>R1;
vector<int>R2;
struct NODE {
	int t, id;
	NODE(int _t, int _id) {
		t = _t; id = _id;
	}
	NODE() {}
};
struct NODE_CMP {
	bool operator()(NODE a, NODE b) {
		if (a.t == b.t)return a.id > b.id;
		return a.t > b.t;
	}
};
struct CUSTOMER {
	int t, id, r1, r2;
	CUSTOMER(int _t, int _id) {
		t = _t, id = _id, r1 = -1, r2 = -1;
	}
	CUSTOMER() {}
};
struct CUSTOMER_CMP {
	bool operator()(CUSTOMER a, CUSTOMER b) {
		if (a.t == b.t) {
			if (a.r1 == b.r1) {
				return a.id > b.id;
			}
			return a.r1 > b.r1;
		}
		return a.t > b.t;
	}
};


int solution_autorepairshop() {
	R1.clear(); R2.clear();
	int A, B;
	cin >> N >> M >> K >> A >> B;
	R1.reserve(N); R2.reserve(M);
	R1.push_back(0);
	R2.push_back(0);

	priority_queue<NODE, vector<NODE>, NODE_CMP> P1;
	priority_queue<NODE, vector<NODE>, NODE_CMP> P2;
	for (int i = 0; i < N; i++) {
		int ele; cin >> ele;
		R1.push_back(ele);
		P1.push(NODE(0, (i + 1)));
	}	
	for (int i = 0; i < M; i++) {
		int ele; cin >> ele;
		R2.push_back(ele);
		P2.push(NODE(0, (i + 1)));
	}

	vector<int>w1(N + 1, 0);
	vector<int>w2(M + 1, 0);

	int ret = -1;
	vector<CUSTOMER>customers(K+1);
	priority_queue<CUSTOMER, vector<CUSTOMER>, CUSTOMER_CMP>P_CUS;
	//pq에 종료 시간 저장
	for (int tk = 0; tk < K; tk++) {
		int tcus; cin >> tcus;

		int idx = -1;
		int min_v = INT_MAX;
		int min_idx = -1;
		for (int j = 1; j <= N; j++) {
			if (w1[j] <= tcus) {
				idx = j;
				break;
			}
			if (min_v > w1[j]) {
				min_v = w1[j];
				min_idx = j;
			}
		}
		int end_time = 0;
		if (idx == -1) {
			idx = min_idx;
		}
		end_time = w1[idx] < tcus ? tcus : w1[idx];
		end_time += R1[idx];
		w1[idx] = end_time;
		CUSTOMER c(end_time, tk + 1);
		c.r1 = idx;

		customers[tk + 1] = c;
		P_CUS.push(c);
	}

	while (!P_CUS.empty()) {
		int c_idx = P_CUS.top().id; P_CUS.pop();
		CUSTOMER& c = customers[c_idx];

		int tcus = c.t;


		int idx = -1;
		int min_v = INT_MAX;
		int min_idx = -1;
		for (int j = 1; j <= M; j++) {
			if (w2[j] <= tcus) {
				idx = j;
				break;
			}
			if (min_v > w2[j]) {
				min_v = w2[j];
				min_idx = j;
			}
		}
		int end_time = 0;
		if (idx == -1) {
			idx = min_idx;
		}
		end_time = w2[idx] < tcus ? tcus : w2[idx];
		end_time += R2[idx];
		w2[idx] = end_time;
		c.t = end_time;
		c.r2 = idx;

		if (c.r1 == A && c.r2 == B) {
			if (ret == -1)ret = 0;
			ret += c.id;
		}
	}


	return ret;
}



int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int T; cin >> T;
	for (int test_case = 1; test_case <= T; test_case++) {
		cout <<"#"<<test_case<<" " << solution_autorepairshop() << "\n";
	}
	return 0;
}

/*
N, M -> 1 - 9
ai -> 1 - 20



*/

/*
10
1 1 2 1 1
5
7
7 10
2 2 6 1 2
3 2
4 2
0 0 1 2 3 4
*/