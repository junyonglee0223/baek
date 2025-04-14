//g1715 카드 정렬하기
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;


void solution_sort_card_v1(){
    int N; cin>>N;
    vector<int>arr(N);
    priority_queue<int, vector<int>, greater<int>>pq;

    for(int i = 0; i<N; i++){
        cin >> arr[i];
        pq.push(arr[i]);
    }

    int answer = 0;

    while(pq.size() > 1){
        int v1 = pq.top();
        pq.pop();
        int v2 = pq.top();
        pq.pop();
        int tmp_sum = v1 + v2;

        answer += tmp_sum;
        pq.push(tmp_sum);
    }

    cout<<answer<<endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solution_sort_card_v1();


    return 0;
}


/*
3
10
20
40
*/
/*
100
*/