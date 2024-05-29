//최소 힙
#include <iostream>
#include <queue>
using namespace std;

#define endl '\n'

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    priority_queue<int, vector<int>, greater<int>>pq;
    int N; cin>>N;
    while(N--){
        int ele; cin>>ele;
        if(ele == 0){
            if(pq.empty())
                cout<<0<<endl;
            else{
                cout<<pq.top()<<endl;
                pq.pop();
            }
        }
        else{
            pq.push(ele);
        }
    }
}

