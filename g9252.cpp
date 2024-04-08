#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string str1, str2;
vector<vector<int>> dp;

void calcLCS() {
    int len1 = str1.size(), len2 = str2.size();
    dp.resize(len1 + 1, vector<int>(len2 + 1, 0));

    for (int i = 1; i <= len1; i++) {
        for (int j = 1; j <= len2; j++) {
            if (str1[i - 1] == str2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
}

string reconstructLCS() {
    string ret;
    int i = str1.size(), j = str2.size();

    while (i > 0 && j > 0) {
        if (str1[i - 1] == str2[j - 1]) {
            ret.push_back(str1[i - 1]);
            i--;
            j--;
        } else if (dp[i - 1][j] > dp[i][j - 1]) {
            i--;
        } else {
            j--;
        }
    }

    reverse(ret.begin(), ret.end());
    return ret;
}

int main() {
    cin >> str1 >> str2;
    calcLCS();
    cout << dp[str1.size()][str2.size()] << endl; 
    cout << reconstructLCS() << endl;  
    return 0;
}
