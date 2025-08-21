//g2672 여러 직사각형의 전체 면적 구하기
#include<iostream>
#include<vector>
#include<algorithm>
#include<iomanip>
using namespace std;

int N;

struct ELE {
	int x, y1, y2, type;
};

int cur_cnt(vector<int>&states) {
	int ret = 0;
	for (int i = 0; i <= 20000; i++) {
		if (states[i] > 0)ret++;
	}
	return ret;
}

int solution_get_area_of_all_rectangles() {
	cin >> N;

	vector<ELE>elements;
	vector<int>states(20001, 0);

	for (int i = 0; i < N; i++) {
		double x, y, w, h;
		cin >> x >> y >> w >> h;
		int x1 = (int)(x * 10);
		int y1 = (int)(y * 10);
		int ww = (int)(w * 10);
		int hh = (int)(h * 10);

		int x2 = x1 + ww;
		int y2 = y1 + hh;
		elements.push_back({ x1, y1, y2, 1 });
		elements.push_back({ x2, y1, y2, -1 });
	}
	sort(elements.begin(), elements.end(), [&](ELE a, ELE b) {return a.x < b.x; });

	//int size 넘지 않음
	int ret = 0;

	int i = 0;
	int cur_x = elements[0].x;
	for (; i < elements.size();) {
		ELE cur = elements[i];
		int cur_state = cur_cnt(states);
		ret += (cur.x - cur_x) * cur_state;

		while ((i < elements.size() && elements[i].x == cur.x)) {
			cur = elements[i++];
			for (int j = cur.y1; j < cur.y2; j++) {
				states[j] += cur.type;
			}
		}
		cur_x = cur.x;
	}


	return ret;
}

void output(int ret) {
	double d_ret = (double)ret / 100;
	if (ret % 100 == 0) {
		cout << ret / 100 << "\n";
	}
	else {
		cout << fixed << setprecision(2) << (ret / 100.0) << "\n";
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int ret = solution_get_area_of_all_rectangles();
	output(ret);

	return 0;
}

/*
N, 1000.0 이하 소수점 한자리 표현
결과물은 소수점 2자리 까지 표현
주어진 사각형의 넒이 산출 겹치는 부분 처리에 대한 고민
x, y, w, h

정수 부분이었으면 처리 방법이 다양함
double 형태이기 때문에 직접 넓이를 구하는 방식

소수점 한자리까지면 정수형으로 변환시켜서 해도 될 듯
-> 10000까지 가능

n 값이 크지 않다는 점 확인

x좌표 기준 정렬
해당 칸에 존재하는 칸 개수 카운팅

세그먼트 활용해도 문제는 없는데 굳이 생각이 든다.
업데이트 한번하고 개수만 세면 2번안에 해결됨

한번 만들어서 계속 활용해도 되겠다.

(x1, y1, y2, 1) -> 생성
(x2, y1, y2, -1) -> x2 이후 삭제 - x2+1로 설정

x는 양의 실수 조건 있음


1
10.0 10.0 10.0 10.0

*/

/*
4
52.7 22.9 27.3 13.3
68.8 57.6 23.2 8.0
20.0 48.0 37.0 23.5
41.5 36.2 27.3 21.4
예제 출력 1
1853.61
*/