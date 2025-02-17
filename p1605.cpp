//p1605 반복 부분문자열
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

#define endl '\n'

const long long BASE = 256;
const long long MOD = 1000000007;

vector<long long>pow_table;


bool is_pos_length(string &str, int mid){
    int n = str.size();
    if(mid > n || mid == 0)return false;

    unordered_map<long long, vector<int>> hash_map;
    hash_map.reserve(n);
    hash_map.max_load_factor(0.7f);

    long long hash_val = 0;
    for(int i = 0; i<mid; i++){
        hash_val = (hash_val * BASE + str[i])%MOD;
    }
    hash_map[hash_val].push_back(0);

    for(int i = mid; i<n; i++){
        long long left = (pow_table[mid-1] * str[i-mid])%MOD;
        hash_val = (hash_val - left + MOD)%MOD;
        hash_val = (hash_val * BASE + str[i])%MOD;

        int start_idx = i - mid + 1;
        if(hash_map.find(hash_val) != hash_map.end()){
            for(auto ele : hash_map[hash_val]){
                if(str.compare(ele, mid, str, start_idx, mid) == 0){
                    return true;
                }
            }
        }
        hash_map[hash_val].push_back(start_idx);
    }
    return false;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int N;  cin>>N;
    string str;
    cin>>str;

    int left = 0;
    int right = N+1;

    pow_table.resize(N, 1LL);
    for(int i = 1; i<N; i++){
        pow_table[i] = (pow_table[i-1] * BASE)%MOD;
    }

    int pos_len = 0;

    while(left < right){
        int mid = (left + right)>>1;
        if(!is_pos_length(str, mid)){
            right = mid;
        }
        else{
            pos_len = mid;
            left = mid + 1;
        }
    }
    cout<<pos_len<<endl;
}


