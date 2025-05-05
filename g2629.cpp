//g2629 양팔저울
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

#define MAX_n 40001
vector<int>dp;

void set_pos_weight_v1(vector<int>& scales){
    vector<int>saved;

    saved.push_back(scales[0]);
    dp[scales[0]] = 1;

    for(int i = 1; i<scales.size(); i++){
        
        vector<int>tmp;
        for(int j = 0; j<saved.size(); j++){
            int m_w = abs(saved[j] - scales[i]);
            int p_w = min(MAX_n - 1, saved[j] + scales[i]);
            
            if(dp[m_w] != 1) tmp.push_back(m_w);
            dp[m_w] = 1;

            if(dp[p_w] != 1) tmp.push_back(p_w);
            dp[p_w] = 1;
        }
        for(auto ele : tmp){
            saved.push_back(ele);
        }
        if(dp[scales[i]] != 1) saved.push_back(scales[i]);
        dp[scales[i]] = 1;
        //sort(saved.begin(), saved.end());
    }
}

void solution_two_arms_scale(){
    dp.clear();

    dp.resize(MAX_n, 0);


    int n; cin>>n;
    vector<int>scales(n);
    for(int i = 0; i<n; i++){
        cin>>scales[i];
    }

    set_pos_weight_v1(scales);



    int m; cin>>m;
    vector<char>ret;
    for(int i = 0; i<m; i++){
        int ele ; cin>>ele;
        if(dp[ele] == 1) ret.push_back('Y');
        else ret.push_back('N');
    }

    for(int i = 0; i<m; i++){
        cout<<ret[i]<<" ";
    }
    cout<<endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solution_two_arms_scale();
    // int T; cin>>T;
    // while(T--){
    //     solution_two_arms_scale();
    // }

    return 0;
}

/*
2
2
1 4
2
3 2
4
2 3 3 3
3
1 4 10
*/
/*
Y N
Y Y N
*/