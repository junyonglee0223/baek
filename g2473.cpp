//세 용액
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define endl '\n'
typedef long long ll;


int N;
vector<ll> arr;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>N;
    arr.resize(N);
    for(int i = 0; i<N; i++){
        cin>>arr[i];
    }
    sort(arr.begin(), arr.end());
    ll zeroClosestValue = 3000000001;
    ll first = 0;
    ll second = 0;
    ll third = 0;

    for(int start = 0; start < N-2; start++){
        int left = start + 1;
        int right = N - 1;
        while(left < right){
            ll sum = (arr[start] + arr[left] + arr[right]);
            
            if(abs(sum) < abs(zeroClosestValue)){
                zeroClosestValue = sum;
                first = arr[start];
                second = arr[left];
                third = arr[right];
            }
            
            if(sum > 0){
                right--;
            }
            else{
                left++;
            }
        }
    }
    cout<<first<<" "<<second<<" "<<third<<endl;
}

