//집합 언어 제한
#include <iostream>
using namespace std;
#define endl '\n'

int group;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    group = 0;

    int T; 
    cin >> T;
    while (T--) {
        string cmd; 
        cin >> cmd;
        int x;
        if (cmd == "check") {
            cin >> x;
            cout << ((group & (1 << x)) ? 1 : 0) << endl;
        } 
        else if (cmd == "add") {
            cin >> x;
            group |= (1 << x);
        } 
        else if (cmd == "remove") {
            cin >> x;
            group &= ~(1 << x);
        } 
        else if (cmd == "toggle") {
            cin >> x;
            group ^= (1 << x);
        } 
        else if (cmd == "all") {
            group = (1 << 21) - 1;
        } 
        else if (cmd == "empty") {
            group = 0;
        } 
        else {
            cout << "wrong cmd" << endl;
        }
    }
    return 0;
}
