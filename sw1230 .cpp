//sw1230 암호문3
#include<iostream>
#include<vector>
using namespace std;


/*

1. I(삽입) x, y, s : 앞에서부터 
x번째 암호문 바로 다음에 y개의 암호문을 삽입한다. 
s는 덧붙일 암호문들이다.[ ex) I 3 2 123152 487651 ]

2. D(삭제) x, y : 앞에서부터 
x번째 암호문 바로 다음부터 y개의 암호문을 삭제한다.[ ex) D 4 4 ]

3. A(추가) y, s : 암호문 뭉치 맨 뒤에 y개의 암호문을 덧붙인다. 
s는 덧붙일 암호문들이다. [ ex) A 2 421257 796813 ]
*/
string solution_password(){
    int N; cin>>N;
    vector<string>words;
    for(int i = 0; i<N; i++){
        string str_ele; cin>>str_ele;
        words.push_back(str_ele);
    }

    int Q; cin>>Q;
    for(int q = 0; q<Q; q++){
        char cmd; cin>>cmd;
                if (cmd == 'I') {
            int x, y; 
            cin >> x >> y;
            int pos = x;
            if (pos < 0) pos = 0;
            if (pos > (int)words.size()) pos = (int)words.size();
            for (int j = 0; j < y; j++) {
                string s; 
                cin >> s;
                words.insert(words.begin() + pos + j, s);
            }
        }

        if (cmd == 'D') {
            int x, y; 
            cin >> x >> y;
            int start = x;
            if (start < 0) start = 0;
            if (start > (int)words.size()) start = (int)words.size();
            int end = start + y;
            if (end > (int)words.size()) end = (int)words.size();
            if (start < end) {
                words.erase(words.begin() + start, words.begin() + end);
            }
        }

        if (cmd == 'A') {
            int y; 
            cin >> y;
            for (int j = 0; j < y; j++) {
                string s; 
                cin >> s;
                words.push_back(s);
            }
        }
    }
    
    string ret;
    for(int i = 0; i<10; i++){
        ret += words[i];
        ret += " ";
    }
    ret += '\n';
    return ret;
}

int main(int argc, char** argv)
{
	int test_case;
	int T = 10;

	for(test_case = 1; test_case <= T; ++test_case)
	{
        string ret = solution_password();
        cout<<"#"<<test_case<<" "<<ret;
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}