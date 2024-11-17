//배열정렬
#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <queue>
using namespace std;

int N, M;
vector<int>A;
vector<tuple<int,int,int>>operations;
unordered_map<long long, long long>dp;
long long targetMask;

long long arrayToMask(const vector<int>& arr){
    long long mask = 0;
    for(int i = 0; i<arr.size(); i++){
        mask |= (static_cast<long long>(arr[i]) << (4 * i));
    }
    return mask;
}

vector<int> maskToArray(long long mask){
    vector<int> arr(N);
    for(int i = 0; i<N; i++){
        arr[i] = (mask >> (4*i)) & 15;
    }
    return arr;
}

long long dijkstra(long long startMask){
    priority_queue<pair<long long, long long>, vector<pair<long long, long long>>
    , greater<pair<long long, long long>>>pq;
    pq.push({0, startMask});
    dp[startMask] = 0;

    while(!pq.empty()){
        auto [cost, mask] = pq.top();
        pq.pop();

        if(mask == targetMask)return cost;

        vector<int> arr = maskToArray(mask);
        for(auto& op : operations){
            int l = get<0>(op) - 1;
            int r = get<1>(op) - 1;
            int c = get<2>(op);

            swap(arr[l], arr[r]);
            long long nxtMask = arrayToMask(arr);
            swap(arr[l], arr[r]);
            if(!dp.count(nxtMask) || dp[nxtMask] > cost + c){
                dp[nxtMask] = cost + c;
                pq.push({dp[nxtMask], nxtMask});
            }
        }
    }
    return -1;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin>>N;
    A.resize(N);
    for(int i = 0; i<N; i++)cin>>A[i];

    cin>>M;
    operations.resize(M);
    for(int i = 0; i<M; i++){
        int l, r, c;
        cin>>l>>r>>c;
        operations[i] = {l, r, c};
    }

    vector<int>target = A;
    sort(target.begin(), target.end());    
    targetMask = arrayToMask(target);

    long long startMask = arrayToMask(A);

    long long result = dijkstra(startMask);
    cout<<result<<endl;
}


