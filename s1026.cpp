//s1026 보물
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void solution_treaure(){
    int n; cin>>n;
    vector<int>a(n);
    vector<int>b(n);

    for(int i = 0; i<n; i++){
        cin >> a[i];
    }
    for(int i = 0; i<n; i++){
        cin >> b[i];
    }

    sort(a.begin(), a.end());
    sort(b.begin(), b.end(), [](int x1, int x2){
        return x1 > x2;
    });

    int answer = 0;
    for(int i = 0; i<n; i++){
        answer += (a[i] * b[i]);
    }
    cout<<answer<<endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solution_treaure();

    // int T; cin>>T;
    // while(T--){
    //     solution_treaure();
    // }

    return 0;
}


/*
3
5
1 1 1 6 0
2 7 8 3 1
3
1 1 3
10 30 20
9
5 15 100 31 39 0 0 3 26
11 12 13 2 3 4 5 9 1
*/
/*
18
80
528
*/