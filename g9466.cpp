//텀 프로젝트
#include <iostream>
#include <vector>
#include <set>
using namespace std;

int N;
vector<int>candidate;
vector<bool>matching;
vector<bool>visited;

//visited_set_set, matching
int cnt;
void IsPointingMe(int now){
    visited[now] = true;
    int nxt = candidate[now];

    if(!visited[nxt]){
        IsPointingMe(nxt);
    }
    else if(!matching[nxt]){
        int tmp = nxt;
        while(now != tmp){
            matching[tmp] = true;
            tmp = candidate[tmp];
            cnt++;
            //visited[tmp] = true;
        }
        cnt++;
    }
    matching[now] = true;
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int T; cin>>T;
    while(T--){
        cin>>N;
        candidate.clear();
        candidate.resize(N+1);
        cnt = 0;
        for(int i = 1; i<=N; i++){
            cin>>candidate[i];
        }

        matching.clear();
        matching.resize(N+1, false);
        visited.clear();
        visited.resize(N+1, false);
        int anwser = 0;
        for(int i = 1; i<=N; i++){
            if(!visited[i])
                IsPointingMe(i);
            // if(!matching[i])
            //     anwser++;
        }
        anwser = N - cnt;
        cout<<anwser<<'\n';
    }

}
