//1,2,3 더하기
#include <iostream>
using namespace std;

int cache[12];

int sumOneTwoThree(int n){
    if(cache[n] != 0)return cache[n];

    int ret = 0;
    ret += sumOneTwoThree(n-1);
    ret += sumOneTwoThree(n-2);
    ret += sumOneTwoThree(n-3);
    return ret;
}

int main(){
    for(int i = 0; i<12; i++)
        cache[i] = 0;
    cache[0] = 0;
    cache[1] = 1;
    cache[2] = 2;
    cache[3] = 4;

    int test_case;
    cin>>test_case;
    while(test_case--){
        int num; cin>>num;
        cout<<sumOneTwoThree(num)<<endl;
    }
}


