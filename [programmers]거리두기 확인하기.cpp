#include <string>
#include <vector>
#include <iostream>

using namespace std;

bool check_boundary(int x, int y) {
    return x >= 0 && x < 5 && y >= 0 && y < 5;
}

bool check(vector<string>now, int x, int y) {
    //bool flag = false;
    if (check_boundary(x + 1, y) && now[x + 1][y] == 'P') {
        return false;
    }

    if (check_boundary(x + 2, y) && now[x + 2][y] == 'P') {
        if (now[x + 1][y] != 'X')
            return false;
    }

    if (check_boundary(x, y + 2) && now[x][y + 2] == 'P') {
        if (now[x][y + 1] != 'X')
            return false;
    }
    if (check_boundary(x, y + 1) && now[x][y + 1] == 'P') {
        return false;
    }


        if (check_boundary(x - 1, y + 1) && now[x - 1][y + 1] == 'P') {
            if (now[x - 1][y] != 'X' || now[x][y + 1] != 'X')
                return false;
        }
        if (check_boundary(x + 1, y + 1) && now[x + 1][y + 1] == 'P') {
            if (now[x + 1][y] != 'X' || now[x][y + 1] != 'X')
                return false;
        }

    
    return true;
}


vector<int> solution(vector<vector<string>> places) {
    vector<int> answer;
    int test_case = 0;
    int test_case_max = places.size();
    while (test_case < test_case_max) {
        vector<string> now = places[test_case];
        bool flag = true;
        for (int i = 0; i < 5; i++) {
            if (!flag) break;
            for (int j = 0; j < 5; j++) {
                if (now[i][j] == 'P') {
                    flag = check(now, i, j);
                    //cout<<i<<"\t"<<j<<"\t"<<flag<<endl; //test

                    if (flag == false) {
                        break;

                    }
                }
            }
        }
        answer.push_back(flag ? 1 : 0);
        //cout<<endl<<endl;       //test
        test_case++;
    }


    return answer;
}