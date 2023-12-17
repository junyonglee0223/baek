
// 제한 조건 가로 세로가 4이하이다.
// 0	빈칸
// 1	빨간 수레의 시작 칸
// 2	파란 수레의 시작 칸
// 3	빨간 수레의 도착 칸
// 4	파란 수레의 도착 칸
// 5	벽

#include <bits/stdc++.h>
using namespace std;

#define INF 987654321
int answer;
int r, c;
int RX, RY, BX, BY;

int dx[5] = {0, 1, 0, -1, 0};
int dy[5] = {0, 0, 1, 0, -1};
bool visited[4][4][2] = {0};

bool is_in_bound(int x, int y)
{
    return 0 <= x && x < r && 0 <= y && y < c;
}
bool is_overlap(int rx, int ry, int bx, int by)
{
    return (rx == bx) && (ry == by);
}
bool is_cross(int rx, int ry, int nrx, int nry, int bx, int by, int nbx, int nby)
{
    return (nrx == bx && nry == by) && (nbx == rx && nby == ry);
}

void move_dfs(vector<vector<int>> maze, int rx, int ry, int bx, int by, int cnt)
{
    if (rx == RX && ry == RY && bx == BX && by == BY)
    {
        answer = min(answer, cnt);
        return;
    }
    int nrx, nry, nbx, nby;

    for (int i = 0; i < 5; i++)
    {
        nrx = rx + dx[i];
        nry = ry + dy[i];
        if (!is_in_bound(nrx, nry) || (maze[nrx][nry] != 3 && visited[nrx][nry][0]) || maze[nrx][nry] == 5)
            continue;

        visited[nrx][nry][0] = true;
        for (int j = 0; j < 5; j++)
        {
            nbx = bx + dx[j];
            nby = by + dy[j];
            if (i == 0 && j == 0)
                continue;
            if (!is_in_bound(nbx, nby) || (maze[nbx][nby] != 4 && visited[nbx][nby][1]) || maze[nbx][nby] == 5)
                continue;
            if (is_overlap(nrx, nry, nbx, nby) || is_cross(rx, ry, nrx, nry, bx, by, nbx, nby))
                continue;
            visited[nbx][nby][1] = true;
            move_dfs(maze, nrx, nry, nbx, nby, cnt + 1);
            visited[nbx][nby][1] = false;
        }
        visited[nrx][nry][0] = false;
    }
}

int solution(vector<vector<int>> maze)
{

    answer = INF;
    r = maze.size();
    c = maze[0].size();
    int rx, ry, bx, by;
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if (maze[i][j] == 1)
            {
                rx = i;
                ry = j;
            }
            else if (maze[i][j] == 2)
            {
                bx = i;
                by = j;
            }
            else if (maze[i][j] == 3)
            {
                RX = i;
                RY = j;
            }
            else if (maze[i][j] == 4)
            {
                BX = i;
                BY = j;
            }
        }
    }
    visited[rx][ry][0] = 1;
    visited[bx][by][1] = 1;
    move_dfs(maze, rx, ry, bx, by, 0);
    return answer == INF ? 0 : answer;
}
