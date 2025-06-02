//g14891 톱니바퀴
#include <iostream>
#include <vector>
using namespace std;

void set_cogwheel_idx(int pos, int dir, vector<vector<int>>&cogwheel_idx){
    if(dir == 1){
        cogwheel_idx[pos][0] = (cogwheel_idx[pos][0] + 7)%8;
        cogwheel_idx[pos][1] = (cogwheel_idx[pos][1] + 7)%8;
    }else{
        cogwheel_idx[pos][0] = (cogwheel_idx[pos][0] + 1)%8;
        cogwheel_idx[pos][1] = (cogwheel_idx[pos][1] + 1)%8;
    }
}

void set_round_state(int pos, int dir,  
                vector<vector<int>>&cogwheel_idx, vector<string>&cogwheels){
    vector<int>round(4, 0);
    int prv = pos - 1;
    int nxt = pos + 1;
    round[pos] = dir;
    while(prv >= 0){
        int cur_idx = cogwheel_idx[prv+1][0];
        int prv_idx = cogwheel_idx[prv][1];
        if(cogwheels[prv+1][cur_idx] == cogwheels[prv][prv_idx]){
            break;
        }
        round[prv] = (round[prv+1] * -1);
        prv--;
    }
    while(nxt < 4){
        int cur_idx = cogwheel_idx[nxt-1][1];
        int nxt_idx = cogwheel_idx[nxt][0];
        if(cogwheels[nxt-1][cur_idx] == cogwheels[nxt][nxt_idx]){
            break;
        }
        round[nxt] = (round[nxt-1] * -1);
        nxt++;
    }

    for(int i = 0; i<4; i++){
        if(round[i] == 0)continue;
        set_cogwheel_idx(i, round[i], cogwheel_idx);
    }
    // cout<<"-------------------------------------------------"<<endl;
    // for(int i = 0; i<4; i++){
    //     cout<<cogwheel_idx[i][0]<<" "<<cogwheel_idx[i][1]<<endl;
    // }

    // for(int i = 0; i<4; i++){
    //     int idx = (cogwheel_idx[i][1] + 6)%8;
    //     cout<<cogwheels[i][idx]<<" ";
    // }
    // cout<<endl;
    // cout<<"-------------------------------------------------"<<endl;
}

void solution_cogwheel(){
    vector<string>cogwheels(4);
    for(int i = 0; i<4; i++){
        cin >> cogwheels[i];
    }
    vector<vector<int>>cogwheel_idx(4, vector<int>(2, 0));
    for(int i = 0; i<4; i++){
        cogwheel_idx[i][0] = 6;
        cogwheel_idx[i][1] = 2;
    }

    vector<int>round_state(4, 0);
    for(int i = 1; i<4; i++){
        int pre_idx = cogwheel_idx[i-1][1];
        int cur_idx = cogwheel_idx[i][0];
        if(cogwheels[i-1][pre_idx] != cogwheels[i][cur_idx]){
            round_state[i] = (round_state[i-1] + 1)%2;
        }else{
            round_state[i] = round_state[i-1];
        }
    }

    int k; cin >> k;
    for(int cmd = 0; cmd < k; cmd++){
        int cog, dir; cin>>cog>>dir;
        cog--;
        set_round_state(cog, dir, cogwheel_idx, cogwheels);
    }

    int answer = 0;
    for(int i = 0; i<4; i++){
        int idx = (cogwheel_idx[i][1] + 6)%8;
        if(cogwheels[i][idx] == '1'){
            answer += (1 << i);
        }
    }
    cout<<answer<<endl;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solution_cogwheel();

    // int T; cin>>T;
    // while(T--){
    //     solution_cogwheel();
    // }


    return 0;
}

/*
각각 바퀴의 left, right를 지정해서 돌리는 방식이 있을 수 있고 직접 돌리는 방식도 가능할 것 같다
우선 전자로 진행함
*/

/*
- 1번 톱니바퀴의 12시방향이 N극이면 0점, S극이면 1점
- 2번 톱니바퀴의 12시방향이 N극이면 0점, S극이면 2점
- 3번 톱니바퀴의 12시방향이 N극이면 0점, S극이면 4점
- 4번 톱니바퀴의 12시방향이 N극이면 0점, S극이면 8점
*/

/*
4
10101111
01111101
11001110
00000010
2
3 -1
1 1
11111111
11111111
11111111
11111111
3
1 1
2 1
3 1
10001011
10000011
01011011
00111101
5
1 1
2 1
3 1
4 1
1 -1
10010011
01010011
11100011
01010101
8
1 1
2 1
3 1
4 1
1 -1
2 -1
3 -1
4 -1
*/
/*
7
15
6
5
*/