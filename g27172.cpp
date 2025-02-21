//g27172 수 나누기 게임
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

#define endl '\n'

int N;
vector<int>nums;
vector<int>score;
vector<int>exist_num;



int is_divided(int a, int b){
    if(a > b)return 0;
    return (b%a == 0) ? 1 : 0;
}

void solution_divide_game(){
    nums.clear();
    score.clear();
    
    cin>>N;
    nums.resize(N);
    score.resize(N, 0);



    for(int i = 0; i<N; i++){
        cin>>nums[i];
    }
    
    for(int i = 0; i<N; i++){
        for(int j = 0; j<N; j++){
            if(i == j)continue;
            score[i] += is_divided(nums[i], nums[j]);
            score[j] -= is_divided(nums[i], nums[j]);
        }
    }

    for(int i = 0; i<score.size(); i++){
        cout<<score[i]<<" ";
    }
}



void is_divided_v2(int a){
    vector<int>divided_num_vec;
    for(int i = 1; i<=sqrt(a); i++){
        if(a % i == 0){
            if(i*i == a){
                divided_num_vec.push_back(i);
            }
            else{
                divided_num_vec.push_back(i);
                divided_num_vec.push_back(a / i);
            }
        }
    }
    int tot_get_score = 0;
    for(int i = 0; i < divided_num_vec.size(); i++){
        int divided_idx = exist_num[divided_num_vec[i]];
        if(divided_idx != -1){
            tot_get_score++;
            score[divided_idx] += 1;
        }
    }
    score[exist_num[a]] -= tot_get_score;
}

void solution_divide_game_v2(){
    nums.clear();
    score.clear();
    exist_num.clear();
    
    cin>>N;
    nums.resize(N);
    score.resize(N, 0);
    exist_num.resize(1000001, -1);


    for(int i = 0; i<N; i++){
        cin>>nums[i];
        exist_num[nums[i]] = i;
    }
    sort(nums.begin(), nums.end());

    for(int i = 0; i<N; i++){
        //cin>>nums[i];
        is_divided_v2(nums[i]);
    }


    for(int i = 0; i<score.size(); i++){
        cout<<score[i]<<" ";
    }

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    // int T; cin>>T;
    // while(T--){
    //     solution_divide_game_v2();
    //     cout<<endl;
    // }
    
    
    solution_divide_game_v2();
    return 0;
}


/*
3
3 4 12

-> 1 1 -2

4
7 23 8 6

-> 0 0 0 0


*/