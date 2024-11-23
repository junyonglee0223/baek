#include <iostream>
#include <vector>
using namespace std;

typedef pair<int,int> p;
int N, M;
vector<vector<int>>board;


int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

bool isRange(int x, int y){
    return (x>=0 && x<N)&&(y>=0&&y<M);
}

int fallenStatus(bool s1, bool s2){
    if(s1==0&&s2==0)
        return 2;
    if(s1 * s2 == 0)
        return 1;
    return 0;
}

int findMaxCnt(p b1, p b2, int cnt){
    if(cnt > 10)return 11;
    int ret = 11;
    
    for(int d = 0; d<4; d++){
        int nx1 = b1.first + dx[d];
        int ny1 = b1.second + dy[d];
        int nx2 = b2.first + dx[d];
        int ny2 = b2.second + dy[d];
        if(isRange(nx1, ny1)&&board[nx1][ny1]==1){
            nx1 = b1.first;
            ny1 = b1.second;
        }
        if(isRange(nx2, ny2)&&board[nx2][ny2]==1){
            nx2 = b2.first;
            ny2 = b2.second;
        }
        
        int result = fallenStatus(isRange(nx1, ny1), isRange(nx2, ny2));
        if(result == 2)ret = min(ret, 11);
        else if(result == 1) ret = min(ret, cnt+1);
        else if(result == 0){
            ret = min(ret, findMaxCnt({nx1, ny1}, {nx2, ny2}, cnt+1));
        }
    }
    return ret;
}

int main(){
    cin>>N>>M;
    board.resize(N, vector<int>(M));
    vector<p>bsave;
    p b1, b2;
    for(int i = 0; i<N; i++){
        for(int j = 0; j<M; j++){
            char c; cin>>c;
            if(c=='o'){
                bsave.push_back({i, j});
            }
            else if(c=='.'){
                board[i][j] = 0;
            }
            else if(c=='#'){
                board[i][j] = 1;
            }
        }
    }
    b1.first = bsave[0].first;
    b1.second = bsave[0].second;
    b2.first = bsave[1].first;
    b2.second = bsave[1].second;

    int answer = findMaxCnt(b1, b2, 0);
    if(answer == 11)answer = -1;
    cout<<answer<<endl;
}

