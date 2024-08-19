#include <string>
#include <vector>

#include <map>
using namespace std;

int solution(string word) {
    int answer = 0;
    string urb = "AEIOU";
    map<char, int>mp;
    mp['A'] = 0;
    mp['E'] = 1;
    mp['I'] = 2;
    mp['O'] = 3;
    mp['U'] = 4;
    /*A E I O U
    word 1 - 5*/
    int index[5] = {781, 156, 31, 6, 1};
    for(int i = 0; i<word.size(); i++){
        answer += (mp[word[i]]) * index[i];
        answer += 1;
    }

    return answer;
}