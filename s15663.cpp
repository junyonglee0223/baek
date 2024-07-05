//N과 M (9)
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

#define endl '\n'
int N, M;
vector<int> arr;
vector<vector<int>>ret;
set<vector<int>>setRet;

void arrayBackTracking(set<int>&s, vector<int>&prev){
    if(prev.size() == M && (setRet.find(prev) == setRet.end())){
        ret.push_back(prev);
        setRet.insert(prev);
        return;
    }
    for(int i = 0; i<N; i++){
        if(s.find(i) == s.end()){
            s.insert(i);
            prev.push_back(arr[i]);
            arrayBackTracking(s, prev);
            prev.pop_back();
            s.erase(i);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;
    arr.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    set<int>s;
    vector<int> prev;
    arrayBackTracking(s, prev);
    sort(ret.begin(), ret.end());

    for(int i = 0; i<ret.size(); i++){
        for(int j = 0; j<ret[i].size(); j++){
            cout<<ret[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
