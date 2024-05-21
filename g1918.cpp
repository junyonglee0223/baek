//후위 표기식
#include <iostream>
#include <stack>
#include <string>
using namespace std;

int prior_oper(char op) {
    if (op == '*' || op == '/') return 2;
    if (op == '+' || op == '-') return 1;
    return 0;
}

bool check_oper(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '(' || c == ')';
}

string makePostfix(string s) {
    string ret = "";
    stack<char> st;
    for (int i = 0; i < s.size(); i++) {
        if (check_oper(s[i])) {
            if (s[i] == '(') {
                st.push(s[i]);
            } else if (s[i] == ')') {
                while (!st.empty() && st.top() != '(') {
                    ret += st.top();
                    st.pop();
                }
                st.pop(); 
            } else {
                while (!st.empty() && prior_oper(st.top()) >= prior_oper(s[i])) {
                    ret += st.top();
                    st.pop();
                }
                st.push(s[i]);
            }
        } else {
            ret += s[i];
        }
    }

    while (!st.empty()) {
        ret += st.top();
        st.pop();
    }

    return ret;
}

int main() {
    string infix;
    cin >> infix;

    string postfix = makePostfix(infix);
    cout << postfix << endl;

    return 0;
}
