#include <string>
#include <vector>

#include <iostream>
#include <queue>
using namespace std;

    /*
        0. 
        무조건 둘이 합승하고 시작한다.
        특정 지점에서 분기 후 각자 비용을 합산한다.
        각자 이동한 경우가 최적일 수 있다.
                미리 a,b를 계산하는게 좋을 수 있는 이유?
        불필요한 노드가 존재할 수 있다. 
            dfs로 src로 부터 갈 수 있는 지점을 미리 선정?
        
        1.
        우선순위 큐를 사용할 듯 한데 하나의 큐에서 동시에 가능할지 아니면
        분기 이후에는 큐 2개를 추가로 할당해서 사용할지?
            dist 배열 추가로 만들어서 중복 방문 불가하게 설정

        해당 과정에서 중요한 점은 어느 노드를 분기점으로 잡아야 빠른지에
        관한 부분이다. 이 점이 명확하지 않음.
        
        total node count is less than 200 so hypothesis all each of points
        is seperated point and save results to cache memory.

        solve this first way set comman fares queue and 
        set two seperates queue and update each value.

        2.
        루프나 중복이 허용될 수 있지 않나
            허용되지 않을 듯 필요하면 분기하는 방법을 쓰면 되지 않을까

        3. 
        처음부터 a, b의 최단 경로를 구한 이후
        합승과정으로 병합하는 방식은?
            별로 효과적이지 않다.
            합승해서 이동한 비용을 dc라 하고 a, b가 따로 이동했을 
            때 비용을 ac, bc라고 한다면 
            dc < ac + bc를 만족하는 부분을 찾는 방식으로 바뀐다. 
            이 과정은 기존 문제보다 더 복잡하다고 판단.

        4. 
        calculate all cost from src 
        then choose seperate point and check minimun cost value
            that is most efficiency way!



    */
vector<vector<int>>fareGraph;

int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    int answer = 0;

    /*set 2-demension fareGraph*/
    fareGraph.resize(n+1, vector<int>(n+1, 1e9));
    for(auto v : fares){
        int s = v[0];
        int d = v[1];
        int c = v[2];
        fareGraph[s][d] = c;
        fareGraph[d][s] = c;
        fareGraph[s][s] = 0;
        fareGraph[d][d] = 0;
    }

    /*set initial maximun value carefully*/
    vector<int>costCache(n+1, 1e9);
    for(int k = 1; k<=n; k++){
        for(int i = 1; i<=n; i++){
            for(int j = 1; j<=n; j++){
                if(fareGraph[i][k] == 1e9 || fareGraph[k][j]==1e9)
                    continue;
                fareGraph[i][j] = min(fareGraph[i][j], 
                fareGraph[i][k] + fareGraph[k][j]);
                
                fareGraph[j][i] = fareGraph[i][j];
            }
        }
    }
    int ret = fareGraph[s][a] + fareGraph[s][b];
    for(int i = 1; i<=n; i++){
        if(i == s)continue;
        if(fareGraph[i][a] == 1e9 || fareGraph[i][b] == 1e9)continue;
        ret = min(ret, fareGraph[s][i] 
        + fareGraph[i][a] + fareGraph[i][b]);
    }
    answer = ret;

    return answer;
}
int main() {
    int n[3] = {6, 7, 6};
    int s[3] = {4, 3, 4};
    int a[3] = {6, 4, 5};
    int b[3] = {2, 1, 6};
    vector<vector<int>> fares[3] = {
        {
            {4, 1, 10}, {3, 5, 24}, 
            {5, 6, 2}, {3, 1, 41}, 
            {5, 1, 24}, {4, 6, 50}, 
            {2, 4, 66}, {2, 3, 22}, 
            {1, 6, 25}
        },
        {
            {5, 7, 9}, {4, 6, 4}, 
            {3, 6, 1}, {3, 2, 3}, 
            {2, 1, 6}
        },
        {
            {2, 6, 6}, {6, 3, 7}, 
            {4, 6, 7}, {6, 5, 11}, 
            {2, 5, 12}, {5, 3, 20}, 
            {2, 4, 8}, {4, 3, 9}
        }
    };

    // 테스트 케이스 출력
    for (int i = 0; i < 3; i++) {
        cout << "Test Case " << i + 1 << ":" << endl;
        cout << solution(n[i], s[i], a[i], b[i], fares[i]);
        cout << endl << "-----------------------------------" << endl;
    }

    return 0;
}
/*
n	s	a	b	fares	result

6	4	6	2	[[4, 1, 10], [3, 5, 24], 
[5, 6, 2], [3, 1, 41], 
[5, 1, 24], [4, 6, 50], 
[2, 4, 66], [2, 3, 22], 
[1, 6, 25]]	

82
7	3	4	1	[[5, 7, 9], [4, 6, 4], [3, 6, 1], [3, 2, 3], [2, 1, 6]]	14
6	4	5	6	[[2,6,6], [6,3,7], [4,6,7], [6,5,11], [2,5,12], [5,3,20], [2,4,8], [4,3,9]]	18
*/