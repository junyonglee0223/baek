#include <iostream>
#include <vector>
#include <stack>
using namespace std;

struct stackEle{
    long long value;
    int cnt;
};
vector<long long>heights;
stack<long long> stHeights;
stack<stackEle>st;
int N;


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin>>N;
    for(int i = 0; i<N; i++){
        long long ele; cin>>ele;
        heights.push_back(ele);
    }

    long long answer = 0;
    for(int i = 0; i<N; i++){
        stackEle nowEle;
        nowEle.value = heights[i];
        nowEle.cnt = 1;

        while(!st.empty() && st.top().value <= nowEle.value){
            stackEle topEle = st.top();
            if(topEle.value == nowEle.value){
                nowEle.cnt = topEle.cnt + 1;
            }
            answer += (topEle.cnt);
            st.pop();
        }
        if(!st.empty())answer+=1;
        st.push(nowEle);

    }
    cout<<answer<<"\n";
}
