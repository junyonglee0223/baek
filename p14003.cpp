//p14003 가장 긴 증가하는 부분 수열 5
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int N;
vector<int>arr;

#define endl '\n'

vector<int>dp;

int find_max_length(int idx){
    if(idx == N){
        return 0;
    }
    int & ret = dp[idx];
    if(ret != -1)return ret;

    ret = 1;
    for(int i = idx+1; i<N; i++){
        if(arr[idx] < arr[i]){
            ret = max(ret, 1 + find_max_length(i));
        }
    }
    return ret;
}

void find_max_route(int idx, vector<int>&route){
    if(idx == N){
        return;
    }
    for(int i = idx+1; i<N; i++){
        if(arr[idx] < arr[i] && dp[idx] == dp[i] + 1){
            route.push_back(i);
            find_max_route(i, route);
        }
    }
}

/*
find route 로직에 대한 생각
들어가면서 바로 저장하는 방식 vs 백트래킹으로 역으로 꺼내오는 방식
어느게 로직적으로 더 적절할지에 대한 고민

초기 선택은 들어가면서 저장하는 방식

직접 element를 저장할게 아니라 index를 저장해야 추후 관리에 더 편할 것임

*/

/*

maximum length 생성 로직
    뒤에서부터 백트래킹으로 실행하면 된다. 

주의할 점 증가는 무조건 커야 배열에 삽입한다. 
같은 경우는 패스한다. -> 이후 배열 탐색 과정에서 주의해야 할 점

best route 찾는 과정에서 일차 탐색인데 굳이 재귀를 사용하는게 옳은 것인지???
선형으로 구현해도 작동하는데 문제 없고 메모리 스택을 더 아낄수 있다고 생각
그러나 현재 시간초과 발생이 주원인이기 때문에 해당 부분은 추후 개선하겠음!!!!


코드는 잘 작동하는데 이분탐색으로 시간 더 줄이는 방식으로 개선해야 겠음
*/


/*
이분 탐색으로 설정하는 궁극적인 이유도 있다. 
    애초에 최대 증가 부분 수열이기 때문에 정렬된 수열 상태이므로 이분 탐색이 가능함!

이분 탐색 시 입력과 동시에 save_arr에 입력해도 문제는 없는데 
해당 부분이 큰 영향을 줄 거라고 생각하지 않음

*/
vector<int> save_arr;
vector<int> save_arr_idx;




/************************************************************** */

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin>>N;
    arr.resize(N);
    for(int i = 0; i<N; i++)
        cin>>arr[i];
    

    save_arr_idx.resize(N, -1);
    int max_arr_length = 0;

    for(int i = 0; i<N; i++){
        if(save_arr.empty() ||arr[i] > save_arr[save_arr.size() - 1]){
            save_arr.push_back(arr[i]);
            save_arr_idx[i] = save_arr.size() - 1;
        }
        else{
            int start = 0;
            int end = save_arr.size() - 1;
            while(start < end){
                int mid = (start + end)>>1;
                if(save_arr[mid] >= arr[i]){
                    end = mid;
                }
                else if(save_arr[mid] < arr[i]){
                    start = mid + 1;
                }
                else{
                    /*
                    break 걸어서 빼는거도 좋을 듯
                    */
                    //save_arr_idx[i] = mid;
                }
            }
            save_arr[end] = arr[i];
            save_arr_idx[i] = end; 
        }
        max_arr_length = max(max_arr_length, save_arr_idx[i]);

        // //test
        // for(int i = 0; i<save_arr.size(); i++){
        //     cout<<save_arr[i]<<" ";
        // }
        // cout<<endl;
        // for(int i = 0; i<N; i++){
        //     cout<<save_arr_idx[i]<<" ";
        // }
        // cout<<endl;


        //test

    }

    vector<int>find_route;
    for(int i = N-1; i>=0; i--){
        if(find_route.empty()){
            if(save_arr_idx[i] == max_arr_length)
                find_route.push_back(i);
        }
        else{
            int last_idx = find_route[find_route.size() - 1];
            if(arr[last_idx] > arr[i] && save_arr_idx[last_idx] == save_arr_idx[i] + 1){
                find_route.push_back(i);
            }
        }
    }

    cout<<find_route.size()<<endl;
    reverse(find_route.begin(), find_route.end());
    for(int i = 0; i<find_route.size(); i++){
        cout<<arr[find_route[i]]<<" ";
    }







    // int arr_max_length = 0;
    // for(int i = 0; i<N; i++){
    //     if(dp[i] == -1){
    //         arr_max_length = max(arr_max_length, find_max_length(i));
    //     }
    // }

    // vector<int>find_route;
    // for(int i = 0; i<N; i++){
    //     if(dp[i] == arr_max_length){
    //         find_route.push_back(i);
    //         find_max_route(i, find_route);
    //         break;          //반드시 걸어줘야 재탐색 하지 않는다!!!
    //     }
    // }
    // cout<<find_route.size()<<endl;
    // for(int i = 0; i<find_route.size(); i++){
    //     cout<<arr[find_route[i]]<<" ";
    // }
}

/*

6
10 20 10 30 20 50
*/