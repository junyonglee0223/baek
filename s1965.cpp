//s1965 상자넣기
#include <iostream>
#include <vector>
using namespace std;

#define endl '\n'


int get_max_input_count(vector<int>& arr){
    vector<int>ret;

    for(int i = 0; i<arr.size(); i++){
        int r_idx = ret.empty() ? 0 : ret.size() - 1;
        if(ret.empty() || ret[r_idx] < arr[i]){
            ret.push_back(arr[i]);
        }else{
            int start = 0;
            int end = r_idx;
            while(start <= end){
                int mid = (start + end) / 2;
                if(ret[mid] >= arr[i]){
                    end = mid - 1;
                }else if(ret[mid] < arr[i]){
                    start = mid + 1;
                }
            }
            ret[start] = arr[i];
        }
    }
    return ret.size();
}

void solution_input_box(){
    int n; cin>>n;
    vector<int>arr(n);
    
    for(int i = 0; i<n; i++){
        cin>>arr[i];
    }

    int answer = get_max_input_count(arr);
    cout<<answer<<endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solution_input_box();

    // int T; cin>>T;
    // while(T--){
    //     solution_input_box();
    // }

    return 0;
}

/*
2
8
1 6 2 5 7 3 5 6
10
1 2 3 4 5 6 7 8 9 10
*/
/*
5
10
*/