//g2263 트리의 순회
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define endl '\n'

vector<int>left_node;
vector<int>right_node;

vector<int>inorder;
vector<int>postorder;

vector<int>inorder_idx;
vector<int>post_arr;

int pos_idx;
void divide_set(int start, int end, int pre, int dir){
    if(start > end)return;
    
    int mid = post_arr[pos_idx];
    pos_idx--;
    
    divide_set(mid+1, end, mid, 1);
    divide_set(start, mid - 1, mid, 0);

    if(pre != -1){
        if(dir == 1){
            right_node[pre] = mid;
        }
        else {
            left_node[pre] = mid;
        }
    }

    return;

}


void dfs_pre(int now, vector<int>&group){
    group.push_back(now);
    if(left_node[now] != -1)
        dfs_pre(left_node[now], group);
    if(right_node[now] != -1)
        dfs_pre(right_node[now], group);
}

void solution_find_preorder(){
    int n;
    cin>>n;

    inorder.clear();
    postorder.clear();
    inorder_idx.clear();
    post_arr.clear();
    left_node.clear();
    right_node.clear();


    inorder.resize(n);
    postorder.resize(n);

    inorder_idx.resize(n+1, -1);
    post_arr.resize(n);

    left_node.resize(n, -1);
    right_node.resize(n, -1);

    for(int i = 0; i<n; i++){
        cin>>inorder[i];
        inorder_idx[inorder[i]] = i;
    }

    for(int i = 0; i<n; i++){
        cin>>postorder[i];
        post_arr[i] = inorder_idx[postorder[i]];
    }


    pos_idx = n-1;
    divide_set(0, n-1, -1, 1);

    int root = post_arr[n-1];
    vector<int>ans_idx;
    dfs_pre(root, ans_idx);

    for(int i = 0; i<ans_idx.size(); i++){
        cout<<inorder[ans_idx[i]]<<" ";
    }
    cout<<endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    solution_find_preorder();

}

/*

3
1 2 3
1 3 2

    ->1 2 3 
*/
