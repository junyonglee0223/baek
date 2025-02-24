//p16287번 Parcel
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define endl '\n'

int N, W;
vector<int>items;
vector<int>best;

void solution_parcel(){
    cin>>W>>N;
    items.resize(N);
    best.resize(400001, -1);

    for(int i = 0; i<N; i++){
        cin>>items[i];
    }
    sort(items.begin(), items.end());

    bool is_pos = false;
    for(int i = 0; i<N-1; i++){
        if(items[i] >= W)break;

        for(int j = i+1; j<N; j++){
            int sum_items = items[i] + items[j];
            if(sum_items > W)continue;

            int needed = W - sum_items;
            if(needed >= 0 && needed <= 400000 && best[needed] != -1 && best[needed] < i){
                is_pos = true;
                break;
            }
            if(sum_items <= 400000){
                if(best[sum_items] == -1 || best[sum_items] > j){
                    best[sum_items] = j;
                }
            }
        }
        if(is_pos)break;
    }
    cout<< (is_pos ? "YES" : "NO")<<endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solution_parcel();
}



/*
```
10 6
5 10 7 3 2 1

```

```
NO

```


```
21 7
10 1 4 6 2 8 5

```
YES
*/