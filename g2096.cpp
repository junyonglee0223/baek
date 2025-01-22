//g2096 내려가기
#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int N;


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    cin>>N;
    vector<vector<int>>minDp(2, vector<int>(3, INT_MAX));
    vector<vector<int>>maxDp(2, vector<int>(3, 0));


    //initial setting
    for(int i = 0; i<3; i++){
        int ele; cin>>ele;
        minDp[0][i] = ele;
        maxDp[0][i] = ele;
    }

    for(int i = 1; i<N; i++){
        for(int j = 0; j<3; j++){
            int ele; cin>>ele;
            int minV0 = j > 0 ? minDp[(i-1)%2][j-1]: INT_MAX;
            int maxV0 = j > 0 ? maxDp[(i-1)%2][j-1]: 0;

            int minV1 = minDp[(i-1)%2][j];
            int maxV1 = maxDp[(i-1)%2][j];

            int minV2 = j < 2 ? minDp[(i-1)%2][j+1]: INT_MAX;
            int maxV2 = j < 2 ? maxDp[(i-1)%2][j+1]: 0;

            minDp[i%2][j] = min({minV0, minV1, minV2}) + ele;
            maxDp[i%2][j] = max({maxV0, maxV1, maxV2}) + ele;
        }
    }

    int minVal = INT_MAX;
    int maxVal = 0;
    for(int i = 0; i<3; i++){
        minVal = min(minVal, minDp[(N-1)%2][i]);
        maxVal = max(maxVal, maxDp[(N-1)%2][i]);
    }
    cout<<maxVal<<" "<<minVal<<'\n';
}


/*
3
1 2 3
4 5 6
4 9 0



18 6
*/
