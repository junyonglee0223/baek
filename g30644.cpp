#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

int solution_sorting_sticks(int n, vector<int> &arr){

    vector<int>pre_sort_arr = arr;
    sort(pre_sort_arr.begin(), pre_sort_arr.end());

    map<int, int>keys;

    for(int i = 0; i<n; i++){
        keys[pre_sort_arr[i]] = i;
    }

    vector<int>sorted_arr(n);
    for(int i = 0; i<n; i++){
        sorted_arr[i] = keys[arr[i]];
    }


    int ret = 0;
    for(int i = 0; i<n; i++){
        if(i == 0 
            || (abs(sorted_arr[i] - sorted_arr[i-1]) == 1))continue;

        ret++;
    }

    return ret;
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin>>n;
    vector<int>arr(n);
    for(int i = 0; i<n; i++){
        cin>>arr[i];
    }

    cout << solution_sorting_sticks(n, arr) <<"\n";


    return 0;
}
