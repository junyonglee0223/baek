#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

class Node {
public:
    int x, y, num;
    Node* left;
    Node* right;
    Node(int x, int y, int n) : x(x), y(y), num(n), left(nullptr), right(nullptr) {}
};

bool compare_vec(const vector<int>& a, const vector<int>& b) {
    return (a[1] == b[1]) ? a[0] < b[0] : a[1] > b[1];
}

Node* set_node(vector<Node*>& nodeinfo) {
    if (nodeinfo.empty()) return nullptr;

    vector<Node*> tmpnodeinfo = nodeinfo;
    sort(tmpnodeinfo.begin(), tmpnodeinfo.end(), [](Node* a, Node* b) {
        return (a->y == b->y) ? a->x < b->x : a->y > b->y;
    });
    Node* top = tmpnodeinfo[0];

    vector<Node*> node_left;
    vector<Node*> node_right;
    for (int i = 0; i < nodeinfo.size(); ++i) {
        if (nodeinfo[i]->x < top->x) {
            node_left.push_back(nodeinfo[i]);
        } else if(nodeinfo[i]->x > top->x){
            node_right.push_back(nodeinfo[i]);
        }
        else{
            continue;
        }
    }
    top->left = set_node(node_left);
    top->right = set_node(node_right);
    return top;
}

void travel(Node* now, vector<int>& pre, vector<int>& post) {
    if (now == nullptr) return;
    pre.push_back(now->num);
    travel(now->left, pre, post);
    travel(now->right, pre, post);
    post.push_back(now->num);
}

vector<vector<int>> solution(vector<vector<int>> nodeinfo) {
    vector<vector<int>> answer;
    vector<Node*> node_set;

    for (int i = 0; i < nodeinfo.size(); ++i) {
        int x = nodeinfo[i][0];
        int y = nodeinfo[i][1];
        node_set.push_back(new Node(x, y, i + 1));
    }

    Node* root = set_node(node_set);
    vector<int> pre_travel;
    vector<int> post_travel;
    travel(root, pre_travel, post_travel);
    answer.push_back(pre_travel);
    answer.push_back(post_travel);

    // 메모리 해제
    for (Node* n : node_set) {
        delete n;
    }

    return answer;
}



/*
5 3
11 5
13 3
3 5
6 1
1 3
8 6
7 2
2 2
[[5,3],[11,5],[13,3],[3,5],[6,1],[1,3],[8,6],[7,2],[2,2]]
*/
