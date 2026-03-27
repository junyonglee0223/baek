#define MAX_M 4
#define MAX_N 100

#include <string>
#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;

static int N_, M_;
static int board[MAX_N][MAX_N];

static vector<string>grades;
static unordered_map<string, int>gradeToIdx;


static void buildGradesDfs(string& cur, int depth){     
    if(depth == M_)return;

    for(char ch = 'A'; ch <= 'Z'; ch++){
        cur.push_back(ch);

        gradeToIdx[cur] = grades.size();
        grades.push_back(cur);

        buildGradesDfs(cur, depth + 1);

        cur.pop_back();
    }
}

struct QELE{
    int x, y;
};

static bool canReach(int limitIdx, int L, int sRow, int sCol, int eRow, int eCol){
    int dist[MAX_N][MAX_N];

    for(int i = 0; i<N_; i++){
        for(int j = 0; j<N_; j++){
            dist[i][j] = -1;
        }
    }

    queue<QELE>que;
    que.push({sRow, sCol});
    dist[sRow][sCol] = 0;

    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, 1, 0, -1};

    auto isRange = [&](int a, int b){
        return 0 <= a && a < N_ && 0 <= b && b < N_;
    };


    while(!que.empty()){
        QELE cur = que.front();
        que.pop();

        int x = cur.x;
        int y = cur.y;

        if(x == eRow && y == eCol){
            return dist[x][y] <= L;
        }

        for(int d = 0; d < 4; d++){
            int nx = x + dx[d];
            int ny = y + dy[d];

            if(!isRange(nx, ny))continue;
            if(dist[nx][ny] != -1)continue;

            if(!(nx == sRow && ny == sCol) && (board[nx][ny] < limitIdx))continue;
            dist[nx][ny] = dist[x][y] + 1;
            que.push({nx, ny});
        }
    }

    return false;
}


/*
각 테스트 케이스의 처음에 호출된다.
도시의 크기 N과, 보안등급의 최대 길이 M이 주어진다.
(r, c) 위치에 해당하는 구역의 보안등급이 mGrade[r][c] 문자열로 주어진다.
보안등급 mGrade[r][c] 길이는 최대가 M이며 최대 길이보다 작은 보안등급도 존재한다.

__Parameters
_____N : 도시 한 변의 길이 (5 ≤ N ≤ 100)
_____M : 보안등급의 최대 길이 (1 ≤ M ≤ 3)
_____mGrade[i][j] : (i, j) 구역의 보안등급 (0 ≤ i, j＜ N, 1 ≤ 각 보안등급의 길이 ≤ M)
1번 호출
*/
void init(int N, int M, char mGrade[][MAX_N][MAX_M]) {
    N_ = N; M_ = M;

    grades.clear();
    gradeToIdx.clear();

    string cur;
    buildGradesDfs(cur, 0);

    for(int i = 0; i<N_; i++){
        for(int j = 0; j<N_; j++){
            board[i][j] = gradeToIdx[string(mGrade[i][j])];
        }
    }
}



/*
(mRow, mCol) 구역부터 mDir 방향으로 mLength개의 구역의 보안등급을 mGrade로 변경한다.
mDir 값이 0인 경우, 행(row)이 증가하는 방향을 의미한다.
mDir 값이 1인 경우, 열(col)이 증가하는 방향을 의미한다.
대상 범위가 되는 구역은 도시 밖을 벗어나지 않음을 보장한다.

__Parameters
_____mRow : 대상 범위의 시작 구역의 행 (0 ≤ mRow < N)
_____mCol : 대상 범위의 시작 구역의 열 (0 ≤ mCol < N)
_____mDir : 대상 범위의 방향 (0 ≤ mDir ≤ 1)
_____mLength : 대상 범위의 길이 (1 ≤ mLength ≤ N)
_____mGrade : 변경할 보안등급 (1 ≤ 보안등급의 길이 ≤ M)
10,000
*/
    void change(int mRow, int mCol, int mDir, int mLength, char mGrade[MAX_M]) {
    int idx = gradeToIdx[string(mGrade)];

        // 세로 방향 갱신
    if (mDir == 0) {
        for (int k = 0; k < mLength; k++) {
            board[mRow + k][mCol] = idx;
        }
        return;
    }

    // 가로 방향 갱신
    for (int k = 0; k < mLength; k++) {
        board[mRow][mCol + k] = idx;
    }
}

char ret[MAX_M];

/*
출발 구역(sRow, sCol)에서 도착 구역(eRow, eCol)까지 
L회의 사용 횟수를 가진 통행증으로 이동 가능한 경로들을 탐색하고, 
이동에 필요한 가장 낮은 보안등급을 반환하라.
단, 통행증은 다른 구역으로 이동할 때 사용되므로, 
출발 구역(sRow, sCol)은 사용 횟수 및 최소 보안등급 계산에 포함되지 않는다.
출발 구역과 도착 구역은 서로 다른 위치의 구역으로 주어진다.
통행증의 사용 횟수는 출발 구역에서 도착 구역으로 
도착하기 위한 최소 사용 횟수 이상으로 주어짐을 보장한다.
C++인 경우 문자열 끝에 ‘\0’를 넣어야 한다.

__Parameters
_____L : 통행증의 사용 횟수 (1 ≤ L ≤ N * N)
_____sRow : 출발 구역의 행 (0 ≤ sRow < N)
_____sCol : 출발 구역의 열 (0 ≤ sCol < N)
_____eRow : 도착 구역의 행 (0 ≤ eRow < N)
_____eCol : 도착 구역의 열 (0 ≤ eCol < N)
__Returns
_____이동에 필요한 최소 보안등급
200
*/
char* calculate(int L, int sRow, int sCol, int eRow, int eCol) {
    int lo = 0;
    int hi = (int)grades.size() - 1;

    int ans = 0;

    while (lo <= hi) {
        int mid = (lo + hi) >> 1;

        if (canReach(mid, L, sRow, sCol, eRow, eCol)) {
            ans = mid;
            lo = mid + 1;
        }
        else {
            hi = mid - 1;
        }
    }

    const string& s = grades[ans];
    int len = (int)s.size();

    for (int i = 0; i < len; i++) {
        ret[i] = s[i];
    }
    ret[len] = '\0';

    return ret;
}


