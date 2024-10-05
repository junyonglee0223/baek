#include <iostream>
#include <vector>
using namespace std;

bool isPalindrome[2001][2001] = {false};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int N; cin>>N;
    vector<int>arr(N, 0);
    for(int i = 0; i<N; i++)
        cin>>arr[i];
    
    
    for(int i = 0; i<arr.size(); i++)
        isPalindrome[i][i] = true;
    for(int i = 0; i<arr.size()-1; i++){
        if(arr[i] == arr[i+1])
            isPalindrome[i][i+1] = true;
    }

    for(int len = 3; len <= arr.size(); len++){
        for(int i = 0; i<arr.size() - len + 1; i++){
            int src = i;
            int dst = i + len - 1;
            if(arr[src] == arr[dst] && isPalindrome[src+1][dst-1]){
                isPalindrome[src][dst] = true;
            }
        }
    }
    
    int Q; cin>>Q;
    for(int i = 0; i<Q; i++){
        int s, d; cin>>s>>d;
        s--, d--;
        cout<<isPalindrome[s][d]<<'\n';
    }
}