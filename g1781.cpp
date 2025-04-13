//g1781 컵라면
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

#define endl '\n'

typedef pair<int,int> p;

bool compare(const p &a, const p &b){
    if(a.first == b.first)
        return a.second > b.second;  
    return a.first < b.first;        
}


void solution_cup_noodle(){
    int N; cin>>N;
    vector<p>nds;
    for(int i = 0; i<N; i++){
        int a, b; cin>>a>>b;
        nds.push_back({a, b});
    }
    sort(nds.begin(), nds.end(), compare);

    priority_queue<int, vector<int>, greater<int>>pq;
    for(auto ele : nds){
        int d = ele.first;
        int v = ele.second;
        if(pq.size() > d){
            continue;
        }
        else if(pq.size() == d){
            int c_v = pq.top();
            if(v > c_v){
                pq.pop();
                pq.push(v);
            }
        }
        else {
            pq.push(v);
        }
    }

    int answer = 0;
    while(!pq.empty()){
        answer += pq.top();
        pq.pop();
    }

    cout<<answer<<endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solution_cup_noodle();

    return 0;
}


/*
7
1 6
1 7
3 2
3 1
2 4
2 5
6 1
*/
/*
15
*/