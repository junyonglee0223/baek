//용액
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define endl '\n'
#define INF 1000000001
typedef long long ll;
int N;
vector<ll>arr;


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>N;
    arr.resize(N);
    for(int i = 0; i<N; i++){
        cin>>arr[i];
    }

    ll zeroValue = 2 * INF;
    ll first = 0;
    ll second = 0;

    int left = 0;
    int right = N-1;
    while(left < right){
        int sum = arr[left] + arr[right];
        if(abs(sum) < abs(zeroValue)){
            zeroValue = sum;
            first = arr[left];
            second = arr[right];
        }
        if(sum > 0)
            right--;
        else
            left++;
    }
    cout<<first<<" "<<second<<endl;
}


