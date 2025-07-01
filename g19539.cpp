//g19539 사과나무
#include <iostream>
#include <vector>
using namespace std;


void solution_apple_tree_v1(){
    int N; cin>>N;
    vector<long long> h(N);
    for(int i = 0; i<N; i++){
        long long ele; cin>>ele;
        h[i] = ele;
    }

    long long S = 0, halfSum = 0;
    for (int i = 0; i < N; ++i) {
        S += h[i];
        halfSum += h[i] / 2;
    }
    if (S % 3 != 0) {
        cout << "NO\n";
        return;
    }
    long long D = S / 3;
    if (halfSum >= D) cout << "YES\n";
    else            cout << "NO\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solution_apple_tree_v1();

    // int T; cin>>T;
    // while(T--){
    //     solution_apple_tree_v1();
    // }

    return 0;
}

/*
4
1
0
2
4 3
3
10000 1000 100
5
1 3 1 3 1
*/
/*
YES
NO
YES
NO
*/