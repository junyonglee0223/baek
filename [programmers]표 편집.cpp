#include <bits/stdc++.h>
using namespace std;

class node {
public:
    node(int _val) : val(_val), pre(nullptr), nxt(nullptr) {}
    node* pre;
    node* nxt;
    int val;
};

node* move(node* ptr, int x) {
    if (x > 0) {
        while (x--)
            ptr = ptr->nxt;
    }
    else {
        x = -x;
        while (x--)
            ptr = ptr->pre;
    }
    return ptr;
}

string solution(int n, int k, vector<string> cmd) {
    vector<node*> node_list(n);
    node header(-1), footer(-1);
    header.nxt = &footer;
    footer.pre = &header;

    for (int i = 0; i < n; i++) {
        node_list[i] = new node(i);
        if (i > 0) {
            node_list[i]->pre = node_list[i - 1];
            node_list[i - 1]->nxt = node_list[i];
        }
    }

    node_list.front()->pre = &header;
    node_list.back()->nxt = &footer;
    header.nxt = node_list.front();
    footer.pre = node_list.back();

    node* ptr = node_list[k];
    stack<node*> deleted_node;

    for (string c : cmd) {
        char command = c[0];

        if (command == 'U' || command == 'D') {
            int x = stoi(c.substr(2));
            ptr = move(ptr, command == 'U' ? -x : x);
        }
        else if (command == 'C') {
            deleted_node.push(ptr);
            ptr->pre->nxt = ptr->nxt;
            ptr->nxt->pre = ptr->pre;
            ptr = (ptr->nxt == &footer) ? ptr->pre : ptr->nxt;
        }
        else if (command == 'Z') {
            node* recovered = deleted_node.top();
            deleted_node.pop();
            recovered->pre->nxt = recovered;
            recovered->nxt->pre = recovered;
        }
    }

    //cout<<"print result"<<endl;             //test
    string answer(n, 'X');
    for (node* cur = header.nxt; cur != &footer; cur = cur->nxt) {
        //cout<<cur->val<<endl;           //test
        answer[cur->val] = 'O';
    }

    for (node* cur : node_list) {
        delete cur;
    }

    return answer;
}
