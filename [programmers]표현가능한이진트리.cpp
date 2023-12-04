#include <bits/stdc++.h>
#include <string>
#include <vector>

using namespace std;
#define MAX_IDX 1000


// bool check_tree(string tree, int start, int end){
//     if(start == end)return true;
//     int mid = (start + end) >> 1;
//     int left_mid = (start + mid - 1)>>1;
//     int right_mid = (end + mid + 1)>>1;

//     if(tree[mid] == '0'){
//         if(tree[left_mid] == '1' || tree[right_mid] == '1')
//             return false;
//         else
//             return true;
//     }
//     else{
//         return check_tree(tree, start, mid-1) && check_tree(tree, mid+1, end);
//     }

// }


// bool flag;
// void check_tree(string tree, int start, int end){
//     if(!flag)return;
//     if(start == end)return;
//     int mid = (start + end) >> 1;
   
//     if(tree[mid] == '0'){
//         for(int i = start; i<mid; i++){
//             if(tree[i] == '1'){
//                 flag = false;
//                 break;
//             }
//         }
//         for(int i = mid+1; i<=end; i++){
//             if(tree[i] == '1'){
//                 flag = false;
//                 break;
//             }
//         }
//     }
//     check_tree(tree, start, mid-1);
//     check_tree(tree, mid+1, end);

// }



// vector<int> solution(vector<long long> numbers) {
//     vector<int> answer;

//     for(auto num : numbers){
//         flag = true;
//         int tree_size = 0;
//         vector<int>tree;
//         int tmp_num = num;

//         int i = 0;
//         while(tmp_num >= (1<<i))
//             i++;
//         if(i != 0) i--;

//         string tmp_str;
//         while(i>=0 && tmp_num>=0){
//             if(tmp_num >= (1<<i)){
//                 tmp_str.append("1");
//                 tmp_num -= (1<<i);
//             }
//             else{
//                 tmp_str.append("0");
//             }
//             i--;
//         }
//         cout<<tmp_str<<endl;            //test

//         i = 0;
//         while(tmp_str.size() > ((1<<i)-1))
//             i++;
//         int rest = ((1<<i)-1) - tmp_str.size();
//         string str = "";
//         str.append(rest, '0'); 
//         str += tmp_str;
//         cout<<num<<" "<<str.size()<<" "<<str<<endl;           //test
//         //answer.push_back(check_tree(str, 0, str.size()-1));
//         //cout<<answer.back()<<endl;          //test
//         check_tree(str, 0, str.size()-1);
//         answer.push_back(flag ? 1 : 0);


//     }


//     return answer;
// }





#include <bits/stdc++.h>
using namespace std;

bool check_tree(const string& tree, int start, int end) {
    if (start > end) return true;

    int mid = (start + end) / 2;
    if (tree[mid] == '0') {
        for (int i = start; i < mid; i++) {
            if (tree[i] == '1') return false;
        }
        for (int i = mid + 1; i <= end; i++) {
            if (tree[i] == '1') return false;
        }
    }
    return check_tree(tree, start, mid - 1) && check_tree(tree, mid + 1, end);
}

vector<int> solution(vector<long long> numbers) {
    vector<int> answer;

    for (long long num : numbers) {
        string binary_str = bitset<64>(num).to_string();  
        binary_str.erase(0, binary_str.find('1'));        

        int depth = ceil(log2(binary_str.length() + 1));
        int full_size = (1 << depth) - 1;
        binary_str = string(full_size - binary_str.length(), '0') + binary_str;

        answer.push_back(check_tree(binary_str, 0, binary_str.size() - 1) ? 1 : 0);
    }

    return answer;
}
