// //g30805 사전 순 최대 공통 부분 수열
// #include <iostream>
// #include <vector>
// #include <algorithm>
// using namespace std;

// int NA, NB;
// vector<int>A, B;
// typedef pair<int,int> p;

// int main(){

//     cin>>NA;
//     A.resize(NA);
//     vector<p> tmpA;
//     for(int i =0 ; i<NA; i++){
//         cin>>A[i];
//         tmpA.push_back({A[i], i});
//     }
//     sort(tmpA.begin(), tmpA.end(), [](p &a, p &b) {
//         if (a.first == b.first) {
//             return a.second < b.second; 
//         }
//         return a.first > b.first; 
//     });



//     cin>>NB;
//     B.resize(NB);
//     for(int i =0 ; i<NB; i++){
//         cin>>B[i];
//     }

//     vector<int>ret;
//     int idx = 0;
//     int Aidx = -1;

//     for(int i = 0; i<NA; i++){
//         if(tmpA[i].second <= Aidx)continue;
//         for(int j = idx; j<NB; j++){
//             if(tmpA[i].first == B[j]){
//                 ret.push_back(tmpA[i].first);
//                 Aidx = tmpA[i].second;
//                 idx = j + 1;
//                 break;
//             }
//         }
//     }

//     cout<<ret.size()<<'\n';
//     for(auto ele : ret){
//         cout<<ele<<" ";
//     }
// }

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool isLexGreater(const vector<int>& a, const vector<int>& b){
    int n = a.size();
    int m = b.size();
    int len = min(n, m);
    for(int i = 0; i < len; i++){
        if(a[i] > b[i]) return true;
        if(a[i] < b[i]) return false;
    }
    return n > m;
}

vector<int> maxLex3(const vector<int>& a, const vector<int>& b, const vector<int>& c){
    vector<int> res = a;
    if(isLexGreater(b, res)) res = b;
    if(isLexGreater(c, res)) res = c;
    return res;
}

int main(){
    int NA, NB;
    cin >> NA;
    vector<int> A(NA);
    for(int i =0 ; i<NA; i++) cin >> A[i];
    
    cin >> NB;
    vector<int> B(NB);
    for(int i =0 ; i<NB; i++) cin >> B[i];
    
    vector<vector<vector<int>>> dp(NA + 1, vector<vector<int>>(NB + 1, vector<int>()));
    
    for(int i = NA - 1; i >= 0; i--){
        for(int j = NB -1; j >=0; j--){
            if(A[i] == B[j]){
                vector<int> temp = dp[i+1][j+1];
                temp.insert(temp.begin(), A[i]);
                dp[i][j] = maxLex3(temp, dp[i+1][j], dp[i][j+1]);
            }
            else{
                if(isLexGreater(dp[i+1][j], dp[i][j+1])){
                    dp[i][j] = dp[i+1][j];
                }
                else{
                    dp[i][j] = dp[i][j+1];
                }
            }
        }
    }
    
    vector<int> ret = dp[0][0];
    cout << ret.size() << '\n';
    if(ret.size() > 0){
        for(auto ele : ret){
            cout << ele << " ";
        }
    }
    cout << '\n';
    return 0;
}
