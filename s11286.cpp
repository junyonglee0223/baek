//s11286 절댓값 힙
#include <iostream>
#include <queue>
using namespace std;

#define endl '\n'

typedef pair<int,int> p;


void solution_absolute_heap(){
    int N; cin>>N;
    priority_queue<p, vector<p>, greater<p>> pq;

    while(N--){
        int ele; cin>>ele;
        if(ele == 0){
            if(pq.empty()){
                cout<<0<<endl;
            }
            else{
                int flag = pq.top().second;
                int ret = pq.top().first * flag;

                cout<<ret<<endl;
                pq.pop();
            }
        }
        else{            
            if(ele > 0){
                pq.push({ele, 1});
            }
            else{
                pq.push({-ele, -1});
            }
        }
    }
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solution_absolute_heap();

    return 0;
}


/*
18
1
-1
0
0
0
1
1
-1
-1
2
-2
0
0
0
0
0
0
0
*/

/*
-1
1
0
-1
-1
1
1
-2
2
0
*/