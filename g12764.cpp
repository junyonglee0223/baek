//g12764 싸지방에 간 준하
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

typedef pair<int,int> p;
vector<int>visited;
vector<int>computer;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    vector<p> people;
    int N; cin>>N;
    for(int i = 0; i<N; i++){
        int s, d; cin>>s>>d;
        people.push_back({s, d});
    }

    visited.resize(N, 0);
    computer.resize(N, 0);

     sort(people.begin(), people.end());

    int maxIdx = -1;
    priority_queue<p, vector<p>, greater<p>> pq;
    priority_queue<int, vector<int>, greater<int>> avail_pq; 

    for(int i = 0; i<N; i++){
        int a = people[i].first;
        int b = people[i].second;
        if(pq.empty()){
            pq.push({b, 0});
            visited[0]++;
            maxIdx++;
            continue;
        }

        while(!pq.empty()){
            if(pq.top().first <= a){
                avail_pq.push(pq.top().second);
                pq.pop();
            }
            else{
                break;
            }
        }

        if(!avail_pq.empty()){
            int nxt = avail_pq.top();
            avail_pq.pop();
            visited[nxt]++;
            pq.push({b, nxt});
        }
        else{
            maxIdx++;
            visited[maxIdx]++;
            pq.push({b, maxIdx});
        }
    }


    cout<<maxIdx+1<<endl;
    for(int i = 0; i<=maxIdx; i++){
        cout<<visited[i]<<" ";
    }
}



