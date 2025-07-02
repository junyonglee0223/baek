//g1111 IQ Test
#include <iostream>
#include <vector>
using namespace std;

#define endl '\n'

void solution_IQ_Test(){
    int N; cin>>N;
    vector<int>arr(N);

    for(int i = 0; i<N; i++){
        cin>>arr[i];
    }

    if(N == 0 || N == 1){
        cout<<"A"<<endl;
        return;
    }else if(N == 2){
        //A, B 판단하기
        if(arr[0] == arr[1]){
            cout<<arr[0]<<endl;
            return;
        }
        cout<<"A"<<endl;
        return;
    }else{
        if(arr[1] == arr[0]){
            for(int i = 2; i<N; i++){
                if(arr[i] != arr[0]){
                    cout<<"B"<<endl;
                    return;
                }
            }
            cout<<arr[0]<<endl;
            return;
        }

        int a = (arr[2] - arr[1]) / (arr[1] - arr[0]);
        if((arr[2] - arr[1]) % (arr[1] - arr[0]) != 0){
            cout<<"B"<<endl;
            return;
        }
        int b = arr[1] - arr[0] * a;

        for(int i = 3; i<N; i++){
            if(arr[i] != (a * arr[i-1] + b)){
                cout<<"B"<<endl;
                return;
            }
        }
        cout<<(a * arr[N-1] + b)<<endl;
        return;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solution_IQ_Test();

    // int T; cin>>T;
    // while(T--){
    //     solution_IQ_Test();
    // }

    return 0;
}


/*
9
4
1 4 13 40
5
1 2 3 4 5
5
3 6 12 24 48
1
0
2
-1 2
2
57 57
4
16 -8 4 -2
5
6 5 4 3 1
4
-12 12 -36 60
*/

/*
121
6
96
A
A
57
B
B
-132
*/


/*
항상 모든 답은 구하는 규칙은 앞 수*a + b이다. 그리고, a와 b는 정수이다.

수 N개가 주어졌을 때, 규칙에 맞는 다음 수를 구하는 프로그램을 작성하시오.

## 입력

첫째 줄에 N이 주어진다. N은 50보다 작거나 같은 자연수이다. 둘째 줄에는 N개의 수가 주어진다. 
이 수는 모두 절댓값이 100보다 작거나 같은 정수이다.

## 출력

다음 수를 출력한다. 만약 다음 수가 여러 개일 경우에는 A를 출력하고, 
다음 수를 구할 수 없는 경우에는 B를 출력한다.
*/

/*
모든 문제의 규칙 꼴은 *a + b이다. 
선형으로 증가하는 방식이기 때문에 
convexvert hall을 사용해야 할 수 도 있다

주어지는 수는  크기가 100 이하의 정수이다.

---
a, b의 범위를 확인해서 일일히 계산하기에는 시간초과 발생할 수 있다
오름차순이라는 점 확인
후보군 하나 찾아서 a, b 범위 확인하고 
테스트하는 방식으로는 되지 않나?

보통 수가 3개 이상있을 경우
a, b를 특정할 수 있다.
다만 1, 2 개인 경우 A, B가 나올 수 있다.

3개 이상일 경우



3개인데 A, B가 나오는 경우도 생각해야 겠다.
3개인데 A가 나올 수 있는 경우??

B는 나올 수 있다 
a, b가 확정된 상황에서 다음 수가 해당 규칙에 맞지 않다면
B인 상황이다






*/