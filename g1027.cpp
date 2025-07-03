//g1027 고층 건물
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

typedef long long ll;
#define MAX_N 10000000001

void solution_high_building_v1(){
    int n; cin>>n;
    vector<ll>arr(n);

    for(int i = 0; i<n; i++){
        cin>>arr[i];
    }


    vector<int>can_see(n, 0);

    for(int i = 0; i<n-1; i++){
        double max_dec = -MAX_N;
        for(int j = i+1; j<n; j++){
            double tmp = (double)(arr[j] - arr[i])/(j - i);
            if(tmp > max_dec){
                can_see[i]++;
                can_see[j]++;
                max_dec = tmp;
            }
        }
    }

    int answer = 0;
    for(int i = 0; i<can_see.size(); i++){
        answer = max(answer, can_see[i]);
    }

    cout<<answer<<endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solution_high_building_v1();

    // int T; cin>>T;
    // while(T--){
    //     solution_high_building_v1();
    // }

    return 0;
}



/*
5
15
1 5 3 2 6 3 2 6 4 2 5 7 3 1 5
1
10
4
5 5 5 5
5
1 2 7 3 2
10
1000000000 999999999 999999998 999999997 999999996 1 2 3 4 5
*/

/*
7
0
2
4
6
*/

/*
빌딩 배열이 있고 
구하는 것은 좌우로 마주보는 건물의 개수가 가장 많은 개수를 구하는 것임

N은 50 이하이고
높이가 10 ^ 9 이하이다. 높이가 long 타입으로 설정하고 해야할 것 같다

2 1 3
서로가 다 보이는 예시이다

4 3 2 1
4와 2는 마주보지 못하는 상황이다
50 이하이면 모든 쌍 탐색해도 문제가 없지 않을까?

마주본다는 개념을 다시 정립해야 할 것 같다.
두개의 높이 사이에 모든 높이가 작아야 햔다


두 빌딩을 잇는 선분이 접하거나 만나면 안된다고 함






*/