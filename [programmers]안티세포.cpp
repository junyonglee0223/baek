
// #include <bits/stdc++.h>
// using namespace std;

// const int MOD = 1e9 + 7;

// int binary_search(const vector<long long>& ps, long long target) {
//     int idx = lower_bound(ps.begin(), ps.end(), target) - ps.begin();
//     if (idx < ps.size() && ps[idx] == target) {
//         return idx;
//     } else {
//         return -1;
//     }
// }

// int solve(const vector<int>& b) {
//     int n = b.size();
//     vector<long long> ps(n + 1, 0);
//     for (int i = 1; i <= n; ++i) {
//         ps[i] = ps[i - 1] + b[i - 1];
//     }

//     int maxe = ceil(log2(ps[n]));
//     vector<vector<int>> dp(n, vector<int>(maxe + 1, 0));
//     dp[0][0] = 1;

//     for (int i = 1; i < n; ++i) {
//         dp[i][0] = accumulate(dp[i - 1].begin(), dp[i - 1].end(), 0LL) % MOD;

//         for (int e = 1; e <= maxe; ++e) {
//             if (dp[i][e - 1] == 0) continue;

//             long long target = ps[i + 1] - b[i] * (1LL << (e - 1));
//             int jhalf = binary_search(ps, target);
//             if (jhalf == -1) continue;

//             double eprime = log2(b[i] / (double)b[jhalf - 1]) + e - 1;
//             if (eprime < 0 || eprime > maxe || floor(eprime) != eprime) continue;

//             target = ps[i + 1] - b[i] * (1LL << e);
//             int jfull = binary_search(ps, target);
//             if (jfull == -1) continue;

//             dp[i][e] = jfull == 0 ? 1 : accumulate(dp[jfull - 1].begin(), dp[jfull - 1].end(), 0LL) % MOD;
//         }
//     }

//     return accumulate(dp[n - 1].begin(), dp[n - 1].end(), 0LL) % MOD;
// }

// vector<int> solution(const vector<int>& a, const vector<int>& s) {
//     vector<int> answer;
//     int start = 0;
//     for (int l : s) {
//         vector<int> b(a.begin() + start, a.begin() + start + l);
//         start += l;
//         answer.push_back(solve(b));
//     }
//     return answer;
// }





// #include <bits/stdc++.h>
// using namespace std;

// const int MOD = 1e9 + 7;

// int binary_search(const vector<long long>& ps, long long target) {
//     int idx = lower_bound(ps.begin(), ps.end(), target) - ps.begin();
//     if (idx < ps.size() && ps[idx] == target) {
//         return idx;
//     } else {
//         return -1;
//     }
// }

// int solve(const vector<int>& b) {
//     int n = b.size();
//     vector<long long> ps(n + 1, 0);
//     for (int i = 1; i <= n; ++i) {
//         ps[i] = ps[i - 1] + b[i - 1];
//     }

//     int maxe = ceil(log2(ps[n]));
//     vector<vector<int>> dp(n, vector<int>(maxe + 1, 0));
//     dp[0][0] = 1;

//     for (int i = 1; i < n; ++i) {
//         dp[i][0] = accumulate(dp[i - 1].begin(), dp[i - 1].end(), 0LL) % MOD;

//         for (int e = 1; e <= maxe; ++e) {
//             if (dp[i][e - 1] == 0) continue;

//             long long target = ps[i + 1] - b[i] * (1LL << (e - 1));
//             int jhalf = binary_search(ps, target);
//             if (jhalf == -1) continue;

//             double eprime = log2(b[i] / (double)b[jhalf - 1]) + e - 1;
//             if (eprime < 0 || eprime > maxe || floor(eprime) != eprime) continue;

//             target = ps[i + 1] - b[i] * (1LL << e);
//             int jfull = binary_search(ps, target);
//             if (jfull == -1) continue;

//             dp[i][e] = jfull == 0 ? 1 : accumulate(dp[jfull - 1].begin(), dp[jfull - 1].end(), 0LL) % MOD;
//         }
//     }

//     return accumulate(dp[n - 1].begin(), dp[n - 1].end(), 0LL) % MOD;
// }

// vector<int> solution(const vector<int>& a, const vector<int>& s) {
//     vector<int> answer;
//     int start = 0;
//     for (int l : s) {
//         vector<int> b(a.begin() + start, a.begin() + start + l);
//         start += l;
//         answer.push_back(solve(b));
//     }
//     return answer;
// }




// import math
// import bisect
// MOD = int(1e9 + 7)

// def binary_search(arr, x):
//     idx = bisect.bisect_left(arr, x)
    
//     if idx == 0 and arr[idx] != x:
//         return -1
//     elif idx == len(arr):
//         return -1
//     else:
//         return idx

// def solve(b):
//     maxb, n = max(b), len(b)
    
//     ps = [0, b[0]]
//     for i in range(1, n):
//         ps.append(ps[-1] + b[i])
    
//     maxe = math.ceil(math.log2(ps[-1]))
    
//     dp = [[0] * (maxe + 1) for _ in range(n)]
//     dp[0][0] = 1
    
//     for i in range(1, n):
//         # e = 0인 기저 케이스들을 채웁니다.
//         dp[i][0] = sum(dp[i-1])
        
//         # 나머지 케이스들을 채웁니다.
//         for e in range(1, maxe + 1):
//             if dp[i][e-1] == 0:
//                 continue
            
//             # jhalf를 찾습니다.
//             target = ps[i + 1] - b[i] * 2**(e-1)
//             jhalf = binary_search(ps, target)
//             if jhalf == -1:
//                 continue
                
//             eprime = math.log2(b[i] / b[jhalf - 1]) + (e - 1)
//             if not eprime.is_integer() or eprime < 0:
//                 continue
            
//             if not dp[jhalf - 1][int(eprime)] > 0:
//                 continue
            
//             # jfull을 찾습니다.
//             target = ps[i + 1] - b[i] * 2**e
            
//             jfull = binary_search(ps, target)
//             if jfull == -1:
//                 continue
            
//             if jfull == 0:
//                 dp[i][e] = 1
//             else:
//             	dp[i][e] = sum(dp[jfull - 1]) % MOD
            
//     return sum(dp[-1]) % MOD
    
// def solution(a, s):
//     answer = []
    
//     start = 0
//     for l in s:
//         b = a[start:start+l]
        
//         answer.append( solve(b) )
        
//         start += l
        
//     return answer
