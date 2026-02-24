#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;

typedef long long ll;

ll solution_maximum_uprise(int n, vector<ll>arr){
    ll ret = 0;
    stack<ll>st;
    st.push(arr[0]);

    for(int i = 1; i<n; i++){
        int pre = st.top();
        if(arr[i] < pre){
            st.pop();
            st.push(arr[i]);
        }else{
            ret = max(ret, arr[i] - pre);
        }
    }
    return ret;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin>>n;

    vector<ll>arr(n);
    for(int i = 0; i<n; i++){
        cin>>arr[i];
    }

    cout << solution_maximum_uprise(n, arr) << "\n";

    return 0;
}