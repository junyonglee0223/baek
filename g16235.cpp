//g16235 나무 재테크
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define endl '\n'

int dx[8] = {0, 1, 1, 1, 0, -1, -1, -1};
int dy[8] = {1, 1, 0, -1, -1, -1, 0, 1};

bool is_range(int x, int y, int N){
    return x >= 0 && x < N && y >= 0 && y < N;
}

struct TREE_ELE{
    int x, y, age;
    TREE_ELE(){
        x = 0; y = 0; age = 1;
    }
    TREE_ELE(int _x, int _y, int _z){
        x = _x; y = _y; age = _z;
    }
};

void sort_tree_group(vector<vector<vector<TREE_ELE>>>&tree_board){
    int N = tree_board.size();
    for(int i = 0; i<N; i++){
        for(int j = 0; j<N; j++){
            if(tree_board[i][j].size()){
                sort(tree_board[i][j].begin(), tree_board[i][j].end(), 
                [](TREE_ELE const& a, TREE_ELE const& b){
                    return a.age < b.age;
                });
            }
        }
    }
}

void spring_summer(vector<vector<vector<TREE_ELE>>>& tree_board, vector<vector<int>>&board){

    int N = tree_board.size();
    sort_tree_group(tree_board);
    vector<TREE_ELE>dead_trees;

    for(int i = 0; i<N; i++){
        for(int j = 0; j<N; j++){
            if(tree_board[i][j].size() == 0)continue;
            vector<TREE_ELE>survivor;
            for(auto tree : tree_board[i][j]){
                if(tree.age > board[i][j]){
                    dead_trees.push_back(tree);
                    continue;
                }
                board[i][j] -= tree.age;
                tree.age += 1;
                survivor.push_back(tree);
            }
            tree_board[i][j].clear();
            tree_board[i][j] = survivor;
        }
    }

    /////////////////////////////////////////////
    for(TREE_ELE tree : dead_trees){
        board[tree.x][tree.y] += (tree.age / 2);
    }
}

void autumn(vector<vector<vector<TREE_ELE>>>&tree_board, vector<vector<int>>&board){
    int N = board.size();

    vector<vector<vector<TREE_ELE>>>new_tree_board = tree_board;

    for(int i = 0; i<N; i++){
        for(int j = 0; j<N; j++){
            if(tree_board[i][j].size() == 0)continue;
            for(TREE_ELE tree : tree_board[i][j]){
                if(tree.age % 5 != 0)continue;
                for(int d = 0; d<8; d++){
                    int nx = i + dx[d];
                    int ny = j + dy[d];
                    if(!is_range(nx, ny, N))continue;
                    new_tree_board[nx][ny].push_back(TREE_ELE(nx, ny, 1));
                }
            }
        }
    }
    tree_board = new_tree_board;
}

void winter(vector<vector<int>>&board, vector<vector<int>>&add_board){
    int N = board.size();
    for(int i = 0; i<N; i++){
        for(int j = 0; j<N; j++){
            board[i][j] += add_board[i][j];
        }
    }
}

void print_trees(vector<TREE_ELE>&tree_group){
    for(auto tree : tree_group){
        cout<<"("<<tree.x<<", "<<tree.y<<", "<<tree.age<<")\t";
    }
    cout<<endl;
}

void solution_tree_finance_tech(){
    int N, M, K; cin>>N>>M>>K;
    vector<vector<int>>add_board(N, vector<int>(N, 0));
    for(int i = 0; i<N; i++){
        for(int j = 0; j<N; j++){
            cin>>add_board[i][j];
        }
    }

    vector<vector<int>>board(N, vector<int>(N, 5));
    vector<vector<vector<TREE_ELE>>>tree_board(N, vector<vector<TREE_ELE>>(N));


    for(int i = 0; i<M; i++){
        int x, y, z; cin>>x>>y>>z;
        x--; y--;
        tree_board[x][y].push_back(TREE_ELE(x, y, z));
    }

    while(K--){
        //cout<<"START"<<endl;//test
        //print_trees(tree_group);//test
        //cout<<tree_group.size()<<"\t";//test
        spring_summer(tree_board, board);
        //cout<<"after spring summer"<<endl;//test
        //print_trees(tree_group);//test
        autumn(tree_board, board);
        winter(board, add_board);
        //cout<<tree_group.size()<<endl;//test

        // cout<<"after winter"<<endl;//test
        // print_trees(tree_group);//test
        // cout<<"-----------------------------------------"<<endl;
    }
    int answer = 0;
    for(int i = 0; i<N; i++){
        for(int j = 0; j<N; j++){
            answer += tree_board[i][j].size();
        }
    }
    cout<<answer<<endl;
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    solution_tree_finance_tech();
    
    // int T; cin>>T;
    // while(T--){
    //     //cout<<"-----------------------------------------------"<<endl;
    //     solution_tree_finance_tech();
    // }

    return 0;
}


/*
봄 -> 나이먹기 + 1, 나이만큼 못먹으면 바로 죽
여름 -> 봄에 죽은 나무 양분으로 변함 나이/2 만큼 양분
가을 -> 나무 번식 5의 배수만 가능 인접 8칸에 나이 1 나무 생김
겨울 -> 땅에 양분 추가
K년 후 생존 나무 개수
*/

/*
8
1 1 1
1
1 1 1
1 1 4
1
1 1 1
5 2 1
2 3 2 3 2
2 3 2 3 2
2 3 2 3 2
2 3 2 3 2
2 3 2 3 2
2 1 3
3 2 3
5 2 2
2 3 2 3 2
2 3 2 3 2
2 3 2 3 2
2 3 2 3 2
2 3 2 3 2
2 1 3
3 2 3
5 2 3
2 3 2 3 2
2 3 2 3 2
2 3 2 3 2
2 3 2 3 2
2 3 2 3 2
2 1 3
3 2 3
5 2 4
2 3 2 3 2
2 3 2 3 2
2 3 2 3 2
2 3 2 3 2
2 3 2 3 2
2 1 3
3 2 3
5 2 5
2 3 2 3 2
2 3 2 3 2
2 3 2 3 2
2 3 2 3 2
2 3 2 3 2
2 1 3
3 2 3
5 2 6
2 3 2 3 2
2 3 2 3 2
2 3 2 3 2
2 3 2 3 2
2 3 2 3 2
2 1 3
3 2 3
*/
/*
1
0
2
15
13
13
13
85
*/