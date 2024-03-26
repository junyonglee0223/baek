// //팰린드롬 분할
// #include <iostream>
// #include <string>
// using namespace std;

// string palenString;
// int N;
// //int dp[2501][2501];


// bool checkPalendrom(int src, int dst){
//     bool flag = true;
//     while(src <= dst){
//         if(palenString[src] != palenString[dst])
//             return false;
//         src++;
//         dst--;
//     }
//     return true;
// }

// int cntPalen(int src, int dst){
//     //if(src > dst)return 0;
//     if(src == dst)return 1;
//     for(int i = dst; i>=src; i--){
//         if(checkPalendrom(src, i)){
//             return 1 + cntPalen(i+1, dst);
//         }
//     }
//     return cntPalen(src+1, dst);
// }


// int main(){
//     cin>>palenString;
//     N = palenString.size();
//     // for(int i = 0; i<2501; i++){
//     //     for(int j = 0; j<2501; j++){
//     //         if(i == j)dp[i][j] = 1;
//     //         else dp[i][j] = 2501;
//     //     }
//     // }
//     int ans = cntPalen(0, N-1);
//     cout<<ans<<endl;
// }
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;
ll DP[2525][2525]; // 팰린드롬 여부를 저장할 DP 배열
ll DP2[2525]; // 최소 팰린드롬 분할 수를 저장할 DP 배열
string S;
int N;

// 주어진 부분 문자열이 팰린드롬인지 판별하는 함수
int isPal(int st, int ed) {
    ll& ret = DP[st][ed];
    if (ret != -1) return ret; // 이미 계산된 경우 해당 값 반환
    if (st >= ed) return 1; // 기저 조건: 한 글자이거나 빈 문자열인 경우
    if (S[st] != S[ed]) return 0; // 양 끝 문자가 다른 경우
    return ret = isPal(st + 1, ed - 1); // 양 끝을 제외한 내부 문자열에 대해 팰린드롬 판별
}

int main() {
    cin >> S;
    N = S.size();
    S = '#' + S; // 문자열 앞에 '#' 추가
    memset(DP, -1, sizeof(DP)); // DP 배열 -1로 초기화
    memset(DP2, 0x3f, sizeof(DP2)); // DP2 배열 큰 값으로 초기화
    DP2[0] = 0; // 0번째까지의 최소 팰린드롬 분할 수는 0

    for (int i = 1; i <= N; i++) {
        DP2[i] = DP2[i - 1] + 1; // 초기 상태 설정: i번째 문자 하나만으로 구성된 팰린드롬
        for (int j = 1; j < i; j++) {
            if (!isPal(j, i)) continue; // j부터 i까지가 팰린드롬이 아니면 건너뜀
            DP2[i] = min(DP2[i], DP2[j - 1] + 1); // j-1까지의 최소 분할 수 + j부터 i까지의 팰린드롬
        }
    }

    cout << DP2[N] << '\n'; // 최종 결과 출력
}



