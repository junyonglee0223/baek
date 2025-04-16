//s3273 두 수의 합
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
100,000
2,000,000
*/

void test_lower_upper(vector<int>&arr){
    for(int i = 0; i<arr.size(); i++){
        cout<<i * 2 <<endl;
        auto it_lower = lower_bound(arr.begin(), arr.end(), i*2);
        auto it_upper = upper_bound(arr.begin(), arr.end(), i * 2);

        cout<<arr[it_lower - arr.begin()]<<" "<<*it_lower<<endl;
        cout<<arr[it_upper - arr.begin()]<<" "<<*it_upper<<endl;

        cout<<*(lower_bound(arr.begin(), arr.end(), i * 2))<<endl;
        cout<<*(upper_bound(arr.begin(), arr.end(), i * 2))<<endl;
        cout<<"_______________________________________________________"<<endl;
    }
}

int find_pair(vector<int>&arr, int target){
    int ret = 0;

    for(int i = 0; i<arr.size(); i++){
        int tmp = target - arr[i];
        auto it_lower = lower_bound(arr.begin(), arr.end(), tmp);
        if(arr[i] + *it_lower == target){
            ret++;
        }
    }

    return ret / 2;
}

void solution_two_nums_sum(){

    vector<int>arr;
    int n; cin>>n;
    for(int i = 0; i<n;i++){
        int ele; cin>>ele;
        arr.push_back(ele);
    }
    int target; cin>>target;

    sort(arr.begin(), arr.end());

    //test_lower_upper(arr);

    cout<<find_pair(arr, target)<<endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solution_two_nums_sum();

    return 0;
}


/*
9
5 12 7 10 9 1 2 3 11
13
*/
/*
3
*/