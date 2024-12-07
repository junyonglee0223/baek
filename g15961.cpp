#include <iostream>
#include <vector>
using namespace std;

int N, D, K, C;
vector<int>indexPlate;
vector<int>plates;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin>>N>>D>>K>>C;

    plates.resize(N);
    indexPlate.resize(D+1, 0);

    indexPlate[C] = 1;
    int difKindCnt = 1;

    for(int i =0 ; i<N; i++){
        cin>>plates[i];
        if(i<K){
            if(indexPlate[plates[i]] == 0)
                difKindCnt++;
            indexPlate[plates[i]]++;
        }
    }

    int answer = 0;

    for(int start = 0; start<N; start++){
        int end = (start + K)%N;

        int frontPlate = plates[start];
        indexPlate[frontPlate]--;
        if(indexPlate[frontPlate] == 0)
            difKindCnt--;

        int backPlate = plates[end];
        if(indexPlate[backPlate] == 0)
            difKindCnt++;
        indexPlate[backPlate]++;

        answer = max(answer, difKindCnt);
    }
    cout<<answer<<'\n';

}


