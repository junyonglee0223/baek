//g2448 별 찍기 - 11
#include <iostream>
#include <string>
#include <vector>
using namespace std;


char board[3072][6144];

void draw_base(int r, int c){
    board[r][c+2] = '*';
    board[r+1][c+1] = '*';
    board[r+1][c+3] = '*';
    for(int i = 0; i<5; i++){
        board[r+2][c+i] = '*';
    }
}

void draw_stars(int x, int y, int size){
    if(size == 3){
        draw_base(x, y);
        return;
    }
    int half = size / 2;
    draw_stars(x, y+half, half);
    draw_stars(x + half, y, half);
    draw_stars(x+half, y+half*2, half);
}

void solution_dot_star_11(){
    int N;
    cin>>N;

    for(int i = 0; i<N; i++){
        for(int j = 0; j<2*N; j++){
            board[i][j] = ' ';
        }
    }
    draw_stars(0, 0, N);

    for(int i=0; i<N; i++){
        for(int j=0; j<2*N; j++){
            cout << board[i][j];
        }
        cout << "\n";
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solution_dot_star_11();
    return 0;
}

/*
각 줄을 3배수로 구분해서 print 하면 된다
가장 easy 구간은 3배수 - 1
주어지는 N의 형태는 3 * 2^x 형태임
빈공간도 구현에 주의해야 함 

가운데 정렬 메소드도 따로 구현하면 편할 거 같기도 하고
구현에 양 옆 빈공간 규칙이 따로 없다면 만들어야 할 거 같음

당연하지만 재귀를 활용해 구현하는게 맞음



*/

/*
24
*/
/*

                       *
                      * *
                     *****
                    *     *
                   * *   * *
                  ***** *****
                 *           *
                * *         * *
               *****       *****
              *     *     *     *
             * *   * *   * *   * *
            ***** ***** ***** *****
           *                       *
          * *                     * *
         *****                   *****
        *     *                 *     *
       * *   * *               * *   * *
      ***** *****             ***** *****
     *           *           *           *
    * *         * *         * *         * *
   *****       *****       *****       *****
  *     *     *     *     *     *     *     *
 * *   * *   * *   * *   * *   * *   * *   * *
***** ***** ***** ***** ***** ***** ***** *****

*/

/*

     *
    * *
   *****
  *     *
 * *   * *
***** *****
*/
