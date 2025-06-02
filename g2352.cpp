//g2352 반도체 설계
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void solution_semiconductor_design(){
    int n; cin>>n;
    vector<int>arr(n);
    for(int i = 0; i<n; i++){
        cin>>arr[i];
    }

    vector<int>sorted_arr;
    vector<int>sorted_arr_rev;
    for(int i = 0; i<n; i++){
        if(sorted_arr.size() == 0 
                || sorted_arr[sorted_arr.size() - 1] < arr[i]){
            sorted_arr.push_back(arr[i]);
        }else{
            int start = 0;
            int end = sorted_arr.size() - 1;
            int mid;

            while(start < end){
                int mid = (start + end)/2;
                if(sorted_arr[mid] < arr[i]){
                    start = mid + 1;
                }else{
                    end = mid;
                }
            }
            sorted_arr[start] = arr[i];
        }
    }

    cout<<sorted_arr.size()<<endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solution_semiconductor_design();

    return 0;
}

/*
6
4 2 6 3 1 5
*/
/*
3
*/