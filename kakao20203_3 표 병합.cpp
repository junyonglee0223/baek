/*
#include <string>
#include <vector>
#include <sstream>

using namespace std;

int link[2501];
string value[2501];

int flatPos(int r, int c) {
    return (r - 1) * 50 + c;
}

vector<string> solution(vector<string> commands) {
    vector<string> answer;

    //초기화
    for (int i = 1; i <= 2500; i++) {
        link[i] = i;
        value[i] = "EMPTY";
    }

    //해법
    for (string &command : commands) {
        vector<string> v;
        stringstream ss(command);
        string token;
        while (ss >> token) v.push_back(token);

        if (v[0] == "UPDATE") {
            if (v.size() == 4) { //1. UPDATE r c value
                int pos = flatPos(stoi(v[1]), stoi(v[2]));
                string val = v[3];
                int parent = link[pos];
                value[parent] = val;
            }
            else { //2. UPDATE value1 value2
                string val1 = v[1], val2 = v[2];
                for (int i = 1; i <= 2500; i++) {
                    if (value[i] == val1) value[i] = val2;
                }
            }
        }
        else if (v[0] == "MERGE") { //3. MERGE r1 c1 r2 c2
            int pos1 = flatPos(stoi(v[1]), stoi(v[2])), pos2 = flatPos(stoi(v[3]), stoi(v[4]));
            int parent1 = link[pos1], parent2 = link[pos2];
            if (parent1 != parent2) {
                for (int i = 1; i <= 2500; i++) {
                    if (link[i] == parent2) link[i] = parent1;
                }
                string val1 = value[parent1], val2 = value[parent2];
                if (val1 == "EMPTY" && val2 != "EMPTY") {
                    value[parent1] = value[parent2];
                }
                else {
                    value[parent2] = value[parent1];
                }
            }
        }
        else if (v[0] == "UNMERGE") { //4. UNMERGE r c
            int pos = flatPos(stoi(v[1]), stoi(v[2]));
            int parent = link[pos];
            string val = value[parent];
            for (int i = 1; i <= 2500; i++) {
                if (link[i] == parent) {
                    link[i] = i;
                    value[i] = "EMPTY";
                }
            }
            value[pos] = val;
        }
        else { //5. PRINT r c
            int pos = flatPos(stoi(v[1]), stoi(v[2]));
            int parent = link[pos];
            answer.push_back(value[parent]);
        }
    }

    return answer;
}
*/

/*
제한사항
1 ≤ commands의 길이 ≤ 1,000
commands의 각 원소는 아래 5가지 형태 중 하나입니다.
"UPDATE r c value"
r, c는 선택할 셀의 위치를 나타내며, 1~50 사이의 정수입니다.
value는 셀에 입력할 내용을 나타내며, 알파벳 소문자와 숫자로 구성된 길이 1~10 사이인 문자열입니다.
"UPDATE value1 value2"
value1은 선택할 셀의 값, value2는 셀에 입력할 내용을 나타내며, 알파벳 소문자와 숫자로 구성된 길이 1~10 사이인 문자열입니다.
"MERGE r1 c1 r2 c2"
r1, c1, r2, c2는 선택할 셀의 위치를 나타내며, 1~50 사이의 정수입니다.
"UNMERGE r c"
r, c는 선택할 셀의 위치를 나타내며, 1~50 사이의 정수입니다.
"PRINT r c"
r, c는 선택할 셀의 위치를 나타내며, 1~50 사이의 정수입니다.
commands는 1개 이상의 "PRINT r c" 명령어를 포함하고 있습니다.
*/

#include <string>
#include <vector>

using namespace std;

vector<string> solution(vector<string> commands)
{
    vector<string> answer;

    return answer;
}