//g2565 전깃줄
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int find_max_arr(vector<int>& arr){
    vector<int>m_vec;
    for(int i = 0; i<arr.size(); i++){
        if(m_vec.empty() || m_vec[m_vec.size() - 1] < arr[i]){
            m_vec.push_back(arr[i]);
        }
        else{
            int start = 0;
            int end = m_vec.size() - 1;
            while(start < end){
                int mid = (start + end)/2;
                if(m_vec[mid] < arr[i]){
                    start = mid + 1;
                }
                else{
                    end = mid;
                }
            }
            m_vec[end] = arr[i];
        }
    }
    return m_vec.size();
}

void solution_electronic_line(){
    int n; cin>>n;
    vector<pair<int,int>>tmp_vec;
    for(int i = 0; i<n; i++){
        int a, b; cin>>a>>b;
        tmp_vec.push_back({a, b});
    }

    sort(tmp_vec.begin(), tmp_vec.end());

    vector<int>arr;
    for(int i = 0; i<n; i++){
        arr.push_back(tmp_vec[i].second);
    }

    int answer = n - find_max_arr(arr);
    cout<<answer<<endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solution_electronic_line();

    return 0;
}


/*
8
1 8
3 9
2 2
4 1
6 4
10 10
9 7
7 6
*/
/*
3
*/