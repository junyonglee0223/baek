//문자열 폭발
#include <iostream>
#include <string>
using namespace std;
#define endl '\n'

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    string text, key;
    cin >> text >> key;
    int ts = text.size();
    int ks = key.size();

    string ans;
    for (int i = 0; i < text.size(); i++) {
        ans += text[i];
        if (text[i] == key[ks - 1] && ans.size() >= ks) {
            bool isMatch = true;
            int as = ans.size();
            for(int j = 0; j<ks; j++){
                if(ans[as-ks+j] != key[j]){
                    isMatch = false;
                    break;
                }
            }
            if(isMatch){
                int tmp = ks;
                while(tmp--)
                    ans.pop_back();
            }
        }
    }
    if (ans.empty()) {
        cout << "FRULA" << endl;
    } else {
        cout << ans << endl;
    }
    return 0;
}

