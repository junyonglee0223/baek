//벽부수고 이동하기4
#include <iostream>
#include <queue>
#include <string>
#include <cstring>
#include <vector>
#include <set>
#define endl "\n"
#define MAX 1000
using namespace std;

int N, M;
int MAP[MAX][MAX];
int Area_Num[MAX][MAX];
int Zero_Area_Num;
int Answer[MAX][MAX];
bool Visit[MAX][MAX];
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
vector<int> Zero_Area_Size;

// 입력 받는 함수
void Input() {
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        string Inp;
        cin >> Inp;
        for (int j = 0; j < Inp.length(); j++) {
            MAP[i][j] = Inp[j] - '0';
        }
    }
    memset(Area_Num, -1, sizeof(Area_Num));
}

// 0이 있는 영역의 크기를 구하는 BFS 함수
void BFS(int a, int b) {
    queue<pair<int, int>> Q;
    Q.push(make_pair(a, b));
    int Cnt = 1;
    Area_Num[a][b] = Zero_Area_Num;
    Visit[a][b] = true;

    while (!Q.empty()) {
        int x = Q.front().first;
        int y = Q.front().second;
        Q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx >= 0 && ny >= 0 && nx < N && ny < M && MAP[nx][ny] == 0 && !Visit[nx][ny]) {
                Visit[nx][ny] = true;
                Area_Num[nx][ny] = Zero_Area_Num;
                Q.push(make_pair(nx, ny));
                Cnt++;
            }
        }
    }
    Zero_Area_Size.push_back(Cnt);
}

// 전체 솔루션을 실행하는 함수
void Solution() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (MAP[i][j] == 0 && !Visit[i][j]) {
                BFS(i, j);
                Zero_Area_Num++;
            }
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (MAP[i][j] == 1) {
                set<int> Search;
                for (int k = 0; k < 4; k++) {
                    int nx = i + dx[k];
                    int ny = j + dy[k];

                    if (nx >= 0 && ny >= 0 && nx < N && ny < M && MAP[nx][ny] == 0) {
                        if (Search.find(Area_Num[nx][ny]) == Search.end()) {
                            Search.insert(Area_Num[nx][ny]);
                            Answer[i][j] += Zero_Area_Size[Area_Num[nx][ny]];
                        }
                    }
                }
                Answer[i][j] = (Answer[i][j] + 1) % 10; // 벽을 둘러싸고 있는 영역의 크기 합산
            }
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cout << Answer[i][j];
        }
        cout << endl;
    }
}

// 메인 함수
void Solve() {
    Input();
    Solution();
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // freopen("Input.txt", "r", stdin);
    Solve();

    return 0;
}
