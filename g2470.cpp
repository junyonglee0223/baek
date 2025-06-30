//g2470 두 용액
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;

#define MAX_VAL 1000000001

int find_upper_idx(vector<ll>& arr, int target, int start_idx){
    int start = start_idx;
    int end = arr.size() - 1;

    while(start < end){
        int mid = (start + end)/2;
        if(arr[mid] < target){
            start = mid + 1;
        }else{
            end = mid;
        }
    }
    return end;
}

void solution_two_liquid(){
    int n; cin>>n;
    vector<ll>arr(n);

    for(int i = 0; i<n; i++){
        cin>>arr[i];
    }

    sort(arr.begin(), arr.end());

    ll min_val = 2 * MAX_VAL;
    ll idx1 = 0;
    ll idx2 = 1;

    int plus_first_idx = -1;
    for(int i = 0; i<arr.size(); i++){
        if(arr[i] > 0){
            plus_first_idx = i;
            break;
        }
        int target_idx = find_upper_idx(arr, -arr[i], i+1);
        int target_num = target_idx < arr.size() ? arr[target_idx] : arr[arr.size() - 1];
        if(target_idx != i && abs(arr[i] + target_num) < min_val){
            min_val = abs(arr[i] + target_num);
            idx1 = i; idx2 = target_idx;
        }

        int nxt_target_idx = target_idx - 1;
        int nxt_target_num = arr[nxt_target_idx];
        if(nxt_target_idx != i && abs(arr[i] + nxt_target_num) < min_val){
            min_val = abs(arr[i] + nxt_target_num);
            idx1 = i; idx2 = nxt_target_idx;
        }
    }

    if(plus_first_idx != -1 && plus_first_idx + 1 < arr.size() && min_val > arr[plus_first_idx] + arr[plus_first_idx + 1]){
        min_val = arr[plus_first_idx] + arr[plus_first_idx+1];
        idx1 = plus_first_idx;
        idx2 = plus_first_idx + 1;
    }
    int last_idx = arr.size() - 1;
    if(arr[last_idx-1] < 0 && arr[last_idx]<0){
        idx1 = last_idx - 1;
        idx2 = last_idx;
    }

    cout<<arr[idx1]<<" "<<arr[idx2]<<endl;
}

void solution_two_liquid_v1(){
    int n; cin>>n;
    vector<ll>arr(n);
    for(int i = 0; i<n; i++){
        cin>>arr[i];
    }
    sort(arr.begin(), arr.end());
    int left = 0;
    int right = arr.size() - 1;

    int idx1 = left;
    int idx2 = right;
    ll min_val = 2 * MAX_VAL;

    while(left < right){
        int tmp = (arr[left] + arr[right]);
        if(tmp > 0){
            if(min_val > abs(tmp)){
                min_val = abs(tmp);
                idx1 = left;
                idx2 = right;
            }
            right--;
        }else if(tmp < 0){
            if(min_val > abs(tmp)){
                min_val = abs(tmp);
                idx1 = left;
                idx2 = right;
            }
            left++;
        }else{
            idx1 = left;
            idx2 = right;
            break;
        }
    }
    cout<<arr[idx1]<<" "<<arr[idx2]<<endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solution_two_liquid_v1();
     
    return 0;
}

/*
5
-2 4 -99 -1 98
*/
/*
-99 98
*/