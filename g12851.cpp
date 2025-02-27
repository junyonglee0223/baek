//g12851 숨바꼭질 2
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define endl '\n'
#define MAX_N 100001
typedef pair<int, int> p;


vector<int>pos_time;
vector<int>min_way;     

void solution_hideandseek(){
    int src, dst;
    cin>>src>>dst;

    pos_time.clear();
    min_way.clear();
    pos_time.resize(MAX_N, MAX_N);
    min_way.resize(MAX_N, 0);

    priority_queue<p, vector<p>, greater<p>>pq;
    pq.push({0, src});
    pos_time[src] = 0;
    min_way[src] = 1;

    int answer = 0;

    while(!pq.empty()){
        int cur_time = pq.top().first;
        int cur_pos = pq.top().second;
        pq.pop();

        if(cur_time > pos_time[cur_pos])continue;
        if(cur_pos == dst){
            continue;
        }

        vector<int>nxt_pos_group;
        nxt_pos_group.push_back(2* cur_pos);
        nxt_pos_group.push_back(cur_pos + 1);
        nxt_pos_group.push_back(cur_pos - 1);
        int nxt_time = cur_time + 1;

        for(auto nxt_pos : nxt_pos_group){
            if(nxt_pos >= 0 && nxt_pos < MAX_N){
                if(pos_time[nxt_pos] == MAX_N){
                    pos_time[nxt_pos] = nxt_time;
                    min_way[nxt_pos] = 1;
                    pq.push({nxt_time, nxt_pos});
                }
                else if(pos_time[nxt_pos] == nxt_time){
                    min_way[nxt_pos]++;
                    pq.push({nxt_time, nxt_pos});
                }
                else{

                }
            }

        }
    }

    cout<<pos_time[dst]<<endl;
    cout<<min_way[dst]<<endl;
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solution_hideandseek();

    return 0;
}
/*
5 17

->
4
2

*/