#include <bits/stdc++.h>
#include <string>
#include <vector>

using namespace std;

int K, R, C;
int dx[4] = {1, 0, 0, -1};
int dy[4] = {0, -1, 1, 0};
// 1, 0    0, -1  0, 1   -1, 0
char c[4] = {'d', 'l', 'r', 'u'};

// string bfs(int sx, int sy, int gx, int gy){
//     queue<pair<string, pair<int,int>>>q;
//     q.push({"", {sx, sy}});

//     while(!q.empty()){
//         auto now = q.front(); q.pop();
//         string now_str = now.first;
//         int hx = now.second.first;
//         int hy = now.second.second;
//         cout<<hx<<" "<<hy<<" "<<now_str<<endl;                  //test
//         if(now_str.size() == K && hx == gx && hy == gy)
//             return now_str;
//         if(now_str.size() == K)
//             return "impossible";
//         for(int i = 0; i<4; i++){
//             int nx = hx + dx[i];
//             int ny = hy + dy[i];
//             if(0<=nx && nx<R && 0<=ny && ny < C){
//                 q.push({now_str + c[i], {nx, ny}});
//             }
//         }
//     }
// }
string answer;

void dfs(int x, int y, int gx, int gy, string str)
{
    if (answer != "")
        return;
    if (str.size() == K && x == gx && y == gy)
        answer = str;
    if (str.size() == K)
        return;

    for (int i = 0; i < 4; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (0 <= nx && nx < R && 0 <= ny && ny < C)
        {
            dfs(nx, ny, gx, gy, str + c[i]);
        }
    }
}

string solution(int n, int m, int x, int y, int r, int c, int k)
{
    answer = "";
    K = k;
    R = n;
    C = m;
    // answer = bfs(x-1, y-1, r-1, c-1);
    dfs(x - 1, y - 1, r - 1, c - 1, "");

    if (answer == "")
        answer = "impossible";
    return answer;
}

char dir_char[4] = {'d', 'l', 'r', 'u'};
int dx[4] = {1, 0, 0, -1};
int dy[4] = {0, -1, 1, 0};
int k;


int dfs1(int x, int y, int gx, int gy, string str){
    



}


string solution(int n, int m, int x, int y, int r, int c, int k)
{
    answer = "";
    K = k;
    R = n;
    C = m;
    // answer = bfs(x-1, y-1, r-1, c-1);
    dfs(x - 1, y - 1, r - 1, c - 1, "");

    if (answer == "")
        answer = "impossible";
    return answer;
}

/*

def solution(n, m, x, y, r, c, k):
    answer = ''
    dist = abs(x-r)+abs(y-c)
    k -= dist
    if k < 0 or k%2 != 0:
        return "impossible"

    direction = {'d':0, 'l':0, 'r':0, 'u':0}
    if x > r:
        direction['u'] += x-r
    else:
        direction['d'] += r-x
    if y > c:
        direction['l'] += y-c
    else:
        direction['r'] += c-y

    answer += 'd'*direction['d']
    d = min(int(k/2), n-(x+direction['d']))
    answer += 'd'*d
    direction['u'] += d
    k -= 2*d

    answer += 'l'*direction['l']
    l = min(int(k/2), y-direction['l']-1)
    answer += 'l'*l
    direction['r'] += l
    k -= 2*l

    answer += 'rl'*int(k/2)
    answer += 'r'*direction['r']
    answer += 'u'*direction['u']
    return answer
*/

/*
#include <bits/stdc++.h>
using namespace std;

string solution(int n, int m, int x, int y, int r, int c, int k) {
    string answer = "";
    int dist = abs(x - r) + abs(y - c);
    k -= dist;

    if (k < 0 || k % 2 != 0) {
        return "impossible";
    }

    map<char, int> direction = {{'d', 0}, {'l', 0}, {'r', 0}, {'u', 0}};
    direction[x > r ? 'u' : 'd'] += abs(x - r);
    direction[y > c ? 'l' : 'r'] += abs(y - c);

    answer += string(direction['d'], 'd');
    int d = min(k / 2, n - (x + direction['d']));
    answer += string(d, 'd');
    direction['u'] += d;
    k -= 2 * d;

    answer += string(direction['l'], 'l');
    int l = min(k / 2, y - 1 - direction['l']);
    answer += string(l, 'l');
    direction['r'] += l;
    k -= 2 * l;

    answer += string(k / 2, 'r');
    answer += string(k / 2, 'l');
    answer += string(direction['r'], 'r');
    answer += string(direction['u'], 'u');

    return answer;
}


*/
