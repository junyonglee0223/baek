//g1933 스카이라인
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

int N;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin>>N;
    vector<pll>buildings;

    for(int i = 0; i<N; i++){
        ll l, r, h;
        cin>>l>>h>>r;
        buildings.push_back({l, h});
        buildings.push_back({r, -h});
    }

    sort(buildings.begin(), buildings.end(), [&](const pll &a, const pll &b) -> bool{
        if(a.first != b.first)
            return a.first < b.first;
        if(a.second != b.second)
            return a.second > b.second;
        return false;
    });

    vector<pll>ret;;
    priority_queue<ll> pq;
    map<ll, int>removed;

    ll preMaxHeight = 0;
    for(auto& building : buildings){
        ll x = building.first;
        ll h = building.second;
        
        if(h > 0){
            pq.push(h);
        }
        else{
            removed[-h]++;
        }

        while(!pq.empty()){
            if(removed[pq.top()] > 0){
                removed[pq.top()]--;
                pq.pop();
            }
            else{
                break;
            } 
        }

        ll currentMaxHeight = pq.empty() ? 0 : pq.top();
        if(currentMaxHeight != preMaxHeight){
            ret.push_back({x, currentMaxHeight});
            preMaxHeight = currentMaxHeight;
        }

    }

    for(auto &[x, h] : ret){
        cout<<x<<" "<<h<<" ";
    }
}

/*

height, end point만 저장한다.

삽입하는 경우와 제거하는 경우를 생각해야 함

- top end < input start
    top 제거
    input 삽입

- top end > input start
    - top end < input end
            if top height < input height -> top 제거  
        input 삽입

    - top end > input end
        input pass
        break




input vs top
    - top 높이가 더 높다.
        - top end가 더 빠름: 삽입한다.

        - top end가 더 느림: 삽입하지 않는다.

        - 같다.: 삽입한다.


    - top 높이가 더 낮다.

        - top end가 더 빠름

        - top end가 더 느림

        - 같다.



    - 높이가 같다.





제거하는 경우
    top 높이가 낮다 & top end가 더 빠르다.
    while로 전부 제거하되 처음 제거하는 친구만 저장해야 한다.

삽입하는 경우
    - empty
    - top 높이가 낮다. 

*/