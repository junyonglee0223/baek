//g15573 채굴
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

bool canMine(int D, int N, int M, int K, const vector<vector<int>>& board) {
    vector<char> visited(N * M, 0);
    queue<pair<int,int>> q;
    int cnt = 0;

    auto push_if_ok = [&](int x, int y){
        if (x < 0 || x >= N || y < 0 || y >= M) return;
        if (board[x][y] > D) return;
        int idx = x * M + y;
        if (visited[idx]) return;
        visited[idx] = 1;
        q.push({x,y});
        ++cnt;
    };

    for (int j = 0; j < M; ++j) push_if_ok(0, j);
    for (int i = 0; i < N; ++i) {
        push_if_ok(i, 0);
        push_if_ok(i, M - 1);
    }
    if (cnt >= K) return true;

    while (!q.empty()) {
        auto [x,y] = q.front(); q.pop();
        for (int d = 0; d < 4; ++d) {
            int nx = x + dx[d], ny = y + dy[d];
            if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
            if (board[nx][ny] > D) continue;
            int idx = nx * M + ny;
            if (visited[idx]) continue;
            visited[idx] = 1;
            q.push({nx,ny});
            if (++cnt >= K) return true;
        }
    }
    return false;
}

int solution_mining(){
    int N, M, K; cin>>N>>M>>K;
    vector<vector<int>>board(N, vector<int>(M));

    for(int i = 0; i<N; i++){
        for(int j = 0; j<M; j++){
            cin>>board[i][j];
        }
    }

    int left = 0, right = 1000000;
    while(left < right){
        int mid = (left + right) >> 1;


        //결과가 K개 이상이면 right = mid 등호 주의
        if(canMine(mid, N, M, K, board)){
            right = mid;
        }else{
            left = mid + 1;
        }
    }
    return left;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cout<<solution_mining()<<"\n";

    return 0;
}

/*
5 5 10
3 3 3 3 3
3 2 2 2 3
3 2 2 2 3
3 2 2 2 3
3 2 2 2 3
*/
/*
3
*/

/*
N, M은 1000 이하이다. 
K는 N * M 즉 10^6 이하이다.
광물 강도 S는 10^6 이하이다.

K개 이상 선택할 수 있는 D를 구하면 됨

시작은 아래에서부터 올라가면서 D 이상인 수를 체크함
전체 K개 이상이기만 하면 됨

적절한 강도를 이진탐색으로 선택한다고 해도 전체 보드에서 카운팅하는 방식은
O(N^2)으로 탐색하게 되면 10^12이기 때문에 완전탐색은 안됨


세그먼트 트리를 활용해서 해결할 수도 있다.
4 * 10^6이어도 메모리는 충분하다
O(NlogN)이기 때문에 6 * 10^6 * log10
합 구할때 10^9까지 들어가므로 안전하게 long long 사용하자


다른 방법은 없을까?
격자 또는 배열에서 특정 값 이상인 항목의 개수를 카운트 하는 방법


문제를 잘못 이해했다.
아래 행부터 모든 열보다 이상이어야 다음 이전행으로 넘어갈 수 있다.
각각의 행에 대해 최댓값을 저장하고 선택한 D가 해당 값보다 크다면 M 만큼을 카운트 한다.
즉 D만 정하고 O(N)으로 해결 가능

더 오해했다.
광석의 네개의 테두리 어디서든 시작해도 된다.





*/