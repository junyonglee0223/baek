//sw1231 중위순회
#include<iostream>
#include<vector>
#include<unordered_map>
#include<string>
#include<sstream>
using namespace std;

vector<vector<int>> adj;

void inorder_str(int cur, vector<int>& ret) {
    if (cur == -1) return;
    inorder_str(adj[cur][0], ret);
    ret.push_back(cur);
    inorder_str(adj[cur][1], ret);
}

string solution_inorder_word() {
    int N; 
    cin >> N;
    cin.ignore(); 
    
    unordered_map<int, string> mp;
    adj.clear();
    adj.resize(N + 1, vector<int>(2, -1));
    
    for (int i = 0; i < N; i++) {
        string line;
        getline(cin, line);
        
        istringstream iss(line);
        vector<string> tokens;
        string token;
        
        while (iss >> token) {
            tokens.push_back(token);
        }
        
        if (tokens.size() >= 2) {
            int cur = stoi(tokens[0]);
            string str = tokens[1];
            mp[cur] = str;
            
            // 왼쪽 자식이 있다면
            if (tokens.size() >= 3) {
                adj[cur][0] = stoi(tokens[2]);
            }
            
            // 오른쪽 자식이 있다면
            if (tokens.size() >= 4) {
                adj[cur][1] = stoi(tokens[3]);
            }
        }
    }
    
    vector<int> trav;
    inorder_str(1, trav);
    
    string ret = "";
    for (auto ele : trav) {
        ret += mp[ele];
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int T = 10;
    for (int tc = 1; tc <= T; tc++) {
        cout << "#" << tc << " " << solution_inorder_word() << "\n";
    }
    return 0;
}