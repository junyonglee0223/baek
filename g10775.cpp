#include <iostream>
#include <vector>
using namespace std;

int G, P;
vector<int>board;

int findPark(int now){
    return board[now] = (board[now] == now ? now : findPark(board[now]));
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    
    cin>>G>>P;
    board.resize(G+1);
    for(int i = 0; i<G+1; i++)
        board[i] = i;

    int parkCnt = 0;
    for(int i = 0; i<P; i++){
        int ele; cin>>ele;
        int park = findPark(ele);
        if(park == 0)break;
        
        board[park] = park-1;
        parkCnt++;
        // cout<<"----------------------"<<endl;
        // cout<<"now : "<<ele<<" set in : "<<park<<endl;
        
    }
    //cout<<"---------------"<<endl;//test
    cout<<parkCnt<<endl;
    return 0;
}

/*
4
3
4
1
1

-> 2
-------
4
6
2
2
3
3
4
4

-> 3

*/
