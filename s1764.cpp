#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;


int main(){
    ios_base::sync_with_stdio(false);
    int n, m;   cin>>n>>m;
    set<string>st;
    vector<string>ret;
    for(int i = 0; i<n; i++){
        string s; cin>>s;
        st.insert(s);
    }
    for(int i = 0; i<m; i++){
        string s; cin>>s;
        if(st.find(s) != st.end()){
            ret.push_back(s);
        }
    }

    sort(ret.begin(), ret.end());
    cout<<ret.size()<<endl;
    for(auto ele : ret){
        cout<<ele<<endl;
    }
}
