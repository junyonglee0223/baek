//두 배열의 합


#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;
ll T;
int NA, NB;
vector<int>A_array;
vector<int>B_array;
ll ans = 0;


vector<ll> partSum(vector<int>arr){
    vector<ll>sum;
    for(int i = 0; i<arr.size(); i++){
        int tmp_sum = 0;
        for(int j = i; j<arr.size(); j++){
            tmp_sum += arr[j];
            sum.push_back(tmp_sum);
        }
    }
    return sum;
}



int main(){
    cin>>T;
    cin>>NA;
    for(int i = 0; i<NA; i++){
        int tmpa; cin>>tmpa;
        A_array.push_back(tmpa);
    }
    
    cin>>NB;
    for(int i = 0; i<NB; i++){
        int tmpb; cin>>tmpb;
        B_array.push_back(tmpb);
    }
    vector<ll>A_partsum_arr = partSum(A_array);
    vector<ll>B_partsum_arr = partSum(B_array);
    sort(A_partsum_arr.begin(), A_partsum_arr.end());
    sort(B_partsum_arr.begin(), B_partsum_arr.end());

    /*
     problem find
     -> it is too long to compute to access to answer

    */

    
    //solved 2 consider same element
    int i = 0, j = B_partsum_arr.size() - 1;
    while(i < A_partsum_arr.size() && j >= 0){
        ll tmp_sum = A_partsum_arr[i] + B_partsum_arr[j];
        if(tmp_sum == T){
            ll tmp_cnt_a = 1, tmp_cnt_b = 1;
            while(i+1 < A_partsum_arr.size() && A_partsum_arr[i] == A_partsum_arr[i+1]){
                i++;
                tmp_cnt_a++;
            }
            while(j-1 >= 0 && B_partsum_arr[j] == B_partsum_arr[j-1]){
                j--;
                tmp_cnt_b++;
            }
            ans += (tmp_cnt_a * tmp_cnt_b);
            i++;
            j--;
        }
        else if(tmp_sum < T){
            i++;
        }
        else{
            j--;
        }
    }




    cout<<ans<<endl;
}



