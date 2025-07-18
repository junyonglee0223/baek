//g10800 컬러볼
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define endl '\n'

void print_group(vector<vector<int>>&group){
    int w_size = group.size();
    for(int i = 0; i<w_size; i++){
        for(auto ele : group[i]){
            cout<<ele<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}

// int find_idx(vector<int>&arr, int value){
//     int start = -1;
//     int end = arr.size() - 1;
    
//     while(start < end){
//         int mid = (start + end) / 2;
//         if(arr[mid] < value){
//             start = mid;
//         }
//         else{
//             end = mid-1;
//         }
//     }
//     //while로 해야 하나?
//     if(end >= 0 && arr[end]>=value)end--;

//     return end;
// }

int find_idx_v1(vector<int>&arr, int value){
    int start = 0;
    int end = arr.size() - 1;

    while(start <= end){
        int mid = (start + end) / 2;
        if(arr[mid] >= value){
            end = mid - 1;
        }
        else{
            start = mid + 1;
        }
    }
    return end;
}

// void test_find_idx(){
//     vector<int>arr = {3, 3, 4, 5, 8, 10, 15};

//     sort(arr.begin(), arr.end());

//     for(int i = 0; i<10; i++){
//         int tmp_idx = find_idx_v1(arr, i);
//         cout<<tmp_idx <<" "<< (tmp_idx == -1 || tmp_idx == arr.size()) ? -1 : arr[tmp_idx];
//         cout<<endl;
//     }
// }

void solution_color_ball(){
    int n; cin>>n;

    vector<int>init_color;
    vector<int>tot_weights;
    vector<vector<int>>weights_set;
    vector<int>color_idx(200001, -1);
    vector<int>weight_idx(200001, -1);

    int idx = 0;
    for(int i = 0; i<n; i++){
        int c, w; cin>>c>>w;
        tot_weights.push_back(w);
        if(color_idx[c] == -1){
            vector<int>tmp;
            tmp.push_back(w);
            
            color_idx[c] = weights_set.size();
            weights_set.push_back(tmp);
        }
        else{
            weights_set[color_idx[c]].push_back(w);
        }
        init_color.push_back(color_idx[c]);
    }

    vector<int>init_weight = tot_weights;
    sort(tot_weights.begin(), tot_weights.end());
    for(int i = 0; i<weights_set.size(); i++){
        sort(weights_set[i].begin(), weights_set[i].end());
    }


    vector<int>tot_sum_weights(n);
    vector<vector<int>>weights_set_sum(weights_set.size());
    tot_sum_weights[0] = tot_weights[0];
    for(int i = 1; i<n; i++){
        tot_sum_weights[i] = tot_sum_weights[i-1] + tot_weights[i];
    }

    for(int i = 0; i<weights_set.size(); i++){
        weights_set_sum[i].resize(weights_set[i].size());
        weights_set_sum[i][0] = weights_set[i][0];
        for(int j = 1; j<weights_set[i].size(); j++){
            weights_set_sum[i][j] = weights_set_sum[i][j-1] + weights_set[i][j];
        }
    }

    for(int i = 0; i<n; i++){
        int tot_idx = find_idx_v1(tot_weights, init_weight[i]);
        int c_idx = find_idx_v1(weights_set[init_color[i]], init_weight[i]);

        int t_w = tot_idx == -1 ? 0 : tot_sum_weights[tot_idx];
        int c_w = c_idx == -1 ? 0 : weights_set_sum[init_color[i]][c_idx];
        cout<<t_w - c_w<<endl;
    }

   // print_group(weights_set);//test

}

/****************************************** */

struct Ball{
    int idx, color, weight;
    Ball(int idx, int color, int weight){
        this->idx = idx;
        this->color = color;
        this->weight = weight;
    }
};
bool compare_ball(Ball &a, Ball &b){
    return a.weight < b.weight;
}
void solution_color_ball_v1(){
    int n; cin>>n;

    vector<int>color_idx(200001, -1);
    vector<Ball>s_balls;
    vector<pair<int,int>>balls;

    int color_idx_cnt = 0;
    for(int i = 0; i<n; i++){
        int a, b; cin>>a>>b;
        if(color_idx[a] == -1){
            color_idx[a] = color_idx_cnt++;
        }
        balls.push_back({b, color_idx[a]});
        
        s_balls.push_back(Ball(i, color_idx[a], b));
    }

    sort(balls.begin(), balls.end());
    sort(s_balls.begin(), s_balls.end(), compare_ball);


    int tot_sum = 0;
    int tot_sum_dup = 0;
    vector<int>tot_visited;

    vector<int>color_sum(color_idx_cnt, 0);
    vector<int>color_sum_dup(color_idx_cnt, 0);
    vector<vector<int>>color_visited(color_idx_cnt);


    vector<int>ret(n, 0);

    for(int i = 0; i<n; i++){
        int c = s_balls[i].color;
        int w = s_balls[i].weight;
        int idx = s_balls[i].idx;

        if(!tot_visited.empty() && tot_visited[tot_visited.size() - 1] == w){
            tot_sum_dup++;

        }else{
            if(tot_sum_dup > 0){
                tot_sum += tot_sum_dup * tot_visited[tot_visited.size() - 1];
            }
            tot_visited.push_back(w);
            tot_sum_dup = 1;
        }

        int t_w = tot_sum;

        if(!color_visited[c].empty() && color_visited[c][color_visited[c].size() - 1] == w){
            color_sum_dup[c]++;
        }
        else{
            if(color_sum_dup[c] > 0){
                color_sum[c] += color_sum_dup[c] * color_visited[c][color_visited[c].size() - 1];
            }
            color_visited[c].push_back(w);
            color_sum_dup[c] = 1;
        }

        int c_w = color_sum[c];

        ret[idx] = t_w - c_w;
    }

    for(int i = 0; i<n; i++){
        cout<<ret[i]<<endl;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    //test_find_idx();
    
    //solution_color_ball();
    solution_color_ball_v1();
    
    // int T; cin>>T;
    // while(T--){
    //     //solution_color_ball();
    //     solution_color_ball_v1();
    // }

    return 0;
}

/*
2
4
1 10
3 15
1 3
4 8
3
2 3
2 5
2 4
*/
/*
8
21
0
3

0
0
0
*/