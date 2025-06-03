//g17143 낚시왕
#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

struct SHARK{
    int x, y;
    int speed;
    int dir;
    int size;
};
int dx[5] = {0, -1, 1, 0, 0}; // zero, up, down, right, left
int dy[5] = {0, 0, 0, 1, -1};

int find_the_closest_shark(int p_y, vector<SHARK>shark_set){
    int ret = -1;
    int min_val = INT_MAX;
    for(int i = 0; i<shark_set.size(); i++){
        SHARK shark = shark_set[i];
        if(shark.y != p_y) continue;
        if(ret == -1 || min_val > shark.x){
            ret = i;
            min_val = shark.x;
        }
    }
    return ret;
}

SHARK do_update_shark(SHARK shark, int R, int C){
    //consider R up, down
    if(shark.dir == 1 || shark.dir == 2){
        int cur = shark.x;
        int period = 2 * (R - 1);
        int t = shark.speed % period;
        while(t-- > 0){
            if(shark.dir == 1){
                int nxt = cur + dx[1];
                if(nxt < 0){
                    shark.dir = 2;
                    nxt = cur + dx[2];
                }
                cur = nxt;
            }else if(shark.dir == 2){
                int nxt = cur + dx[2];
                if(nxt >= R){
                    shark.dir = 1;
                    nxt = cur + dx[1];
                }
                cur = nxt;
            }
        }
        shark.x = cur;
    }
    //consider C right, left
    else{
        int cur = shark.y;
        int period = 2 * (C - 1);
        int t = shark.speed % period;
        while(t-- > 0){
            if(shark.dir == 3){
                int nxt = cur + dy[3];
                if(nxt >= C){
                    shark.dir = 4;
                    nxt = cur + dy[4];
                }
                cur = nxt;
            }else if(shark.dir == 4){
                int nxt = cur + dy[4];
                if(nxt < 0){
                    shark.dir = 3;
                    nxt = cur + dy[3];
                }
                cur = nxt;
            }
        }
        shark.y = cur;
    }
    return shark;
}

void delete_duplicate_sharks(int R, int C, vector<SHARK>&shark_set){
    vector<vector<int>>shark_board(R, vector<int>(C, -1));
    vector<bool>is_delete_idx(shark_set.size(), false);
    for(int i = 0; i<shark_set.size(); i++){
        SHARK shark = shark_set[i];
        int x = shark.x;
        int y = shark.y;
        if(shark_board[x][y] == -1){
            shark_board[x][y] = i;
        }else{
            int saved_idx = shark_board[x][y];
            if(shark.size < shark_set[saved_idx].size){
                is_delete_idx[i] = true;
            }else{
                is_delete_idx[saved_idx] = true;
                shark_board[x][y] = i;
            }
        }
    }
    vector<SHARK>updated_shark_set;
    for(int i = 0; i<shark_set.size(); i++){
        if(is_delete_idx[i])continue;
        updated_shark_set.push_back(shark_set[i]);
    }
    shark_set = updated_shark_set;
}

void print_sharks(vector<SHARK>shark_set){
    for(auto shark : shark_set){
        cout<<shark.x<<" "<<shark.y<<" "<<shark.dir<<" "<<shark.size<<endl;
    }
}

void solution_fishing_king(){
    int R, C, M; cin>>R>>C>>M;

    vector<SHARK>shark_set;

    //r, c, s(1 위, 2 아래, 3 오른쪽, 4 왼쪽), d(이동방향), z(크기)
    for(int i = 0; i<M; i++){
        int r, c, s, d, z;
        cin>>r>>c>>s>>d>>z;
        r--; c--;
        SHARK tmp_shark;
        tmp_shark.x = r;
        tmp_shark.y = c;
        tmp_shark.speed = s;
        tmp_shark.dir = d;
        tmp_shark.size = z;
        
        shark_set.push_back(tmp_shark);
    }

    int person_pos = 0;
    int catching_fish = 0;
    while(person_pos < C){
        //catch the closest shark
        int delete_shark_idx = find_the_closest_shark(person_pos, shark_set);
        if(delete_shark_idx != -1){
            catching_fish += shark_set[delete_shark_idx].size;
            shark_set.erase(shark_set.begin() + delete_shark_idx);
        }
        //moving sharks
        for(int i = 0; i<shark_set.size(); i++){
            SHARK shark = shark_set[i];
            shark_set[i] = do_update_shark(shark, R, C);
        }
        //delete duplicate sharks
        delete_duplicate_sharks(R, C, shark_set);
        person_pos++;
        // ////////////////////////
        // print_sharks(shark_set);
        //  cout<<"-----------------------------------------------------------"<<endl;//test

        // ////////////////////////
    }

    int answer = catching_fish;
    cout<<answer<<endl;
    //cout<<"-----------------------------------------------------------"<<endl;//test

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solution_fishing_king();


    // int T; cin>>T;
    // while(T--){
    //     solution_fishing_king();
    // }


    return 0;
}



/*
4
4 6 8
4 1 3 3 8
1 3 5 2 9
2 4 8 4 1
4 5 0 1 4
3 3 1 2 7
1 5 8 4 3
3 6 2 1 2
2 2 2 3 5
100 100 0
4 5 4
4 1 3 3 8
1 3 5 2 9
2 4 8 4 1
4 5 0 1 4
2 2 4
1 1 1 1 1
2 2 2 2 2
1 2 1 2 3
2 1 2 1 4
*/
/*
22
0
22
4
*/