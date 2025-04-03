//g5430 AC
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

#define endl '\n'


vector<int>parse_arr(string arr){
    vector<int>ret;
    int idx = 0;
    
    int idx_cnt = 0;
    while(idx <= arr.size() - 1){
        if(arr[idx] >= '0' && arr[idx] <='9'){
            idx_cnt++;
        }
        else{
            if(idx_cnt > 0){
                int tmp_ele = stoi(arr.substr(idx - idx_cnt, idx_cnt));
                ret.push_back(tmp_ele);
            }
            idx_cnt = 0;
        }
        idx++;
    }
    return ret;
}

string print_vec(vector<int>&vec){
    string ret;
    ret += "[";
    for(int i = 0; i<vec.size(); i++){
        ret += to_string(vec[i]);

        if(i == vec.size() - 1)continue;
        ret += ",";
    }
    ret += "]";
    return ret;
}


void solution_AC(){
    int T; cin>>T;
    while(T--){
        string cmd, arr;
        int N;

        cin>>cmd;
        cin>>N;
        cin>>arr;

        vector<int>nums = parse_arr(arr);
        // //test
        // for(int i =0 ; i<nums.size(); i++){
        //     cout<<nums[i]<<" ";
        // }
        // cout<<endl;


        // //test


        //cmd start
        bool flag = true;
        for(int i = 0; i<cmd.size(); i++){
            if(cmd[i] == 'R'){
                reverse(nums.begin(), nums.end());
                //cout<< print_vec(nums) << endl;
            }
            else if(cmd[i] == 'D'){
                if(nums.empty()){
                    flag = false;
                    break;
                }
                else{
                    nums.erase(nums.begin());
                    //cout<< print_vec(nums) << endl;
                }
            }
            else{
                
            }
        }
        if(!flag){
            cout<<"error"<<endl;
        }
        else{
            cout<< print_vec(nums) << endl;
        }
        //cmd end
    }
}
//위 코드 시간초과 발생

void solution_AC_v1(){
    int T; cin>>T;
    while(T--){
        string cmd, arr;
        int N;

        cin>>cmd;
        cin>>N;
        cin>>arr;

        vector<int>nums = parse_arr(arr);

        //cmd start
        bool flag = true;
        bool rev_flag = false;
        for(int i = 0; i<cmd.size(); i++){
            if(cmd[i] == 'R'){
                rev_flag = !rev_flag;
            }
            else if(cmd[i] == 'D'){
                if(nums.empty()){
                    flag = false;
                    break;
                }
                if(rev_flag){
                    nums.erase(nums.begin() + nums.size() - 1);
                }
                else{
                    nums.erase(nums.begin());
                }
            }
            else{
                
            }
        }
        if(!flag){
            cout<<"error"<<endl;
        }
        else{
            if(rev_flag){
                reverse(nums.begin(), nums.end());
            }
            cout<< print_vec(nums) << endl;
        }
        //cmd end
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solution_AC_v1();
    
    return 0;
}

/*
4
RDD
4
[1,2,3,4]
DD
1
[42]
RRD
6
[1,1,2,3,5,8]
D
0
[]
*/

/*
[2,1]
error
[1,2,3,5,8]
error
*/
