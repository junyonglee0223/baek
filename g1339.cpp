//g1339 단어 수학
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

typedef long long ll;


void init_weight(vector<ll> &my_11_pow){
    ll num = 1;
    my_11_pow.push_back(num);
    for(int i = 1; i<8; i++){
        num *= 10;
        my_11_pow.push_back(num);
    }
}

int word_2_int(string str, vector<int>&ch_weight){
    string tmp;
    for(int i = 0; i<str.size(); i++){
        tmp += to_string(ch_weight[str[i] - 'A']);
    }
    return stoi(tmp);
}

void solution_word_math(){
 
    vector<ll> my_11_pow;
    init_weight(my_11_pow);
    
    vector<string>words;
    vector<vector<int>>ch_board(26, vector<int>(8, 0));
    
    int n; cin>>n;
    for(int i = 0; i<n; i++){
        string str; cin>>str;
        words.push_back(str);
    }
    
    for(int i = 0; i<n; i++){
        int tmp_n = words[i].size();
        for(int j = tmp_n - 1; j >= 0; j--){
            int j_pow = tmp_n - 1 - j;
            int idx = words[i][j] - 'A';
            //ch_weight[idx] += my_11_pow[j_pow];
            ch_board[idx][j_pow]++;
        }
    }
    
    vector<pair<ll, int>>init_sort;
    for(int i = 0; i<26; i++){
        ll tmp = 0;
        for(int j = 7; j>=0; j--){
            tmp += ch_board[i][j] * my_11_pow[j];
        }
        init_sort.push_back({tmp, i});
    }
    
    sort(init_sort.begin(), init_sort.end(), [](pair<ll, int> &a, pair<ll, int> &b){
        return a.first > b.first;
    });
    
    vector<int>ch_weight(26, 0);
    int idx = 0;
    for(int i = 0; i<init_sort.size(); i++){
        int idx = init_sort[i].second;
        ch_weight[idx] = 9 - i;
    }

    int answer = 0;
    for(int i = 0; i<words.size(); i++){
        answer += word_2_int(words[i], ch_weight);
    }
    cout<<answer<<endl;
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solution_word_math();

    // int T; cin>>T;
    // while(T--){
    //     solution_word_math();
    // }


    return 0;
}



/*
4
2
AAA
AAA
2
GCF
ACDEB
10
A
B
C
D
E
F
G
H
I
J
2
AB
BA
*/
/*
1998
99437
45
187
*/