#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

vector<vector<string>> changeExpressions(vector<string> expressions) {
    vector<vector<string>> ret;
    for (auto str : expressions) {
        vector<string> tmp;

        size_t first_space = str.find(' ');
        size_t second_space = str.find(' ', first_space + 3); // space after second operand
        size_t equal_sign = str.find('=');

        string fstr = str.substr(0, first_space);
        string opstr = str.substr(first_space + 1, 1);
        string sstr = str.substr(first_space + 3, second_space - (first_space + 3));
        string retstr = str.substr(equal_sign + 2);

        tmp.push_back(fstr);
        tmp.push_back(sstr);
        tmp.push_back(opstr);
        tmp.push_back(retstr);
        ret.push_back(tmp);
    }
    return ret;
}

int char2int(char c) {
    int tmp = int(c) - 48;
    if (tmp >= 0 && tmp <= 9) return tmp;
    return -1;
}

string operStr(string s1, string s2, string op, int num) {
    vector<int> fnum(3, 0);
    vector<int> snum(3, 0);
    vector<int> ret(3, 0);
    for (int i = 0; i < s1.size(); i++) {
        fnum[i] = (char2int(s1[s1.size() - i - 1]));
    }
    for (int i = 0; i < s2.size(); i++) {
        snum[i] = (char2int(s2[s2.size() - i - 1]));
    }
    if (op == "+") {
        for (int i = 0; i < 3; i++) {
            ret[i] = fnum[i] + snum[i];
        }
        int up = 0;
        for (int i = 0; i < 3; i++) {
            ret[i] += up;
            if (ret[i] >= num) {
                up = 1;
                ret[i] -= num;
            }
            else
                up = 0;
        }
    }
    else {
        for (int i = 0; i < 3; i++)
            ret[i] = fnum[i] - snum[i];
        int down = 0;
        for (int i = 0; i < 3; i++) {
            ret[i] -= down;
            if (ret[i] < 0) {
                ret[i] += num;
                down++;
            }
            else {
                down = 0;
            }
        }
    }
    int retNum = 0;
    for (int i = 0; i < 3; i++) {
        retNum += ret[i] * pow(10, i);
    }
    return to_string(retNum);
}

bool isFitNum(const vector<vector<string>>& samples, int num) {
    for (auto& ele : samples) {
        string tmp = operStr(ele[0], ele[1], ele[2], num);
        if (ele[3] != tmp) return false;
    }
    return true;
}

vector<string> solution(vector<string> expressions) {
    vector<string> answer;
    vector<vector<string>> pack = changeExpressions(expressions);
    int maxNum = 0;
    for (auto tmp : pack) {
        for (int i = 0; i < tmp[0].size(); i++)
            if (char2int(tmp[0][i]) > maxNum)
                maxNum = char2int(tmp[0][i]);
        for (int i = 0; i < tmp[1].size(); i++)
            if (char2int(tmp[1][i]) > maxNum)
                maxNum = char2int(tmp[1][i]);
        for (int i = 0; i < tmp[3].size(); i++)
            if (char2int(tmp[3][i]) > maxNum)
                maxNum = char2int(tmp[3][i]);
    }

    vector<vector<string>> samples;
    vector<vector<string>> quize;
    int packN = pack.size();
    for (int i = 0; i < packN; i++) {
        if (char2int(pack[i][3][0]) == -1) {
            quize.push_back(pack[i]);
        }
        else {
            samples.push_back(pack[i]);
        }
    }

    vector<int> posOper;
    for (int i = maxNum + 1; i <= 9; i++)
        posOper.push_back(i);
    int n = posOper.size();

    // vector<string> ret(quize.size(), "");  // Initialize to empty strings
    vector<string> ret(quize.size());  // Initialize to empty strings
    bool initialized = false;
    for (int i = 0; i < n; i++) {
        if (!isFitNum(samples, posOper[i])) continue;
        
        for (int j = 0; j < quize.size(); j++) {
            string tmp = operStr(quize[j][0], quize[j][1], quize[j][2], posOper[i]);
            if (!initialized) {
                ret[j] = tmp;  // First valid result
            } else {
                if (ret[j] != tmp) ret[j] = "?";  // Different result
            }
        }
        initialized = true;
    }
    
    for (int i = 0; i < quize.size(); i++) {
        string retStr = "";
        retStr += quize[i][0];
        retStr += " " + quize[i][2] + " ";
        retStr += quize[i][1];
        retStr += " = ";

        retStr += ret[i];
        answer.push_back(retStr);
    }

    return answer;
}

int main() {
    vector<vector<string>> expressions = {
        {"14 + 3 = 17", "13 - 6 = X", "51 - 5 = 44"},
        {"1 + 1 = 2", "1 + 3 = 4", "1 + 5 = X", "1 + 2 = X"},
        {"10 - 2 = X", "30 + 31 = 101", "3 + 3 = X", "33 + 33 = X"}
    };
    for (auto ele : expressions) {
        vector<string> ret = solution(ele);
        for (auto retStr : ret) {
            cout << retStr << endl;
        }
    }
}
