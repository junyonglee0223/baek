package s14397;

import java.io.*;
import java.util.StringTokenizer;

public class Main {

    static int[] dx0 = {-1, -1, 0, 0, 1, 1};
    static int[] dy0 = {-1, 0, -1, 1, -1, 0};

    static int[] dx1 = {-1, -1, 0, 0, 1, 1};
    static int[] dy1 = {0, 1, -1, 1, 0, 1};

    static boolean isRange(int x, int y, int n, int m){
        return x >= 0 && x < n && y >= 0 && y < m;
    }
    static int solutionBeach(int n, int m, int[][] board){
        int ret = 0;

        /*        
            i-1 i
            i-1 i+1
            i-1 i
        */
        /*        
            i i+1
            i-1 i+1
            i i+1
        */

        //int[][] resultBoard = new int[n][m];///test

        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                int tmpVal = 0;
                if(board[i][j] == 0){
                    if(i%2 == 0){
                        for(int d = 0; d < 6; d++){
                            int x = i + dx0[d];
                            int y = j + dy0[d];
                            if(!isRange(x, y, n, m))continue;
                            tmpVal += board[x][y];
                        }
                    }
                    else{
                        for(int d = 0; d < 6; d++){
                            int x = i + dx1[d];
                            int y = j + dy1[d];
                            if(!isRange(x, y, n, m))continue;
                            tmpVal += board[x][y];
                        }                        
                    }
                    
                    ret += tmpVal;
                }
                //resultBoard[i][j] = tmpVal;///////////test
            }
        }


        // //////////////////////////////////////////////////
        // System.out.println("result start!!!!!!!");
        // for(int i = 0; i<n; i++){
        //     for(int j = 0; j<m ;j++){
        //         System.out.print(resultBoard[i][j] + " ");
        //     }
        //     System.out.println();
        // }
        // System.out.println("result end!!!!!!!");
        // /////////////////////////////////////////////////
        return ret;
    }


    static int monoMain(BufferedReader br) throws IOException {
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());

        int[][] board = new int[n][m];

        for(int i = 0; i<n; i++){
            String tmp = br.readLine();
            for(int j = 0; j<m; j++){
                char tmpChar = tmp.charAt(j);
                if(tmpChar == '#')board[i][j] = 0;
                else board[i][j] = 1;
            }
        }

        return (solutionBeach(n, m, board));
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        // int T = Integer.parseInt(br.readLine());
        // while(T-- > 0){

        //     System.out.println("answer = " + monoMain(br));
        // }

        System.out.println(monoMain(br));
    }
}
/*
4
1 8
.#...#..
3 6
..#.##
.##.#.
#.#...
2 10
#...#.....
##..#...#.
4 6
....#.
.#....
..#..#
####..
*/
/*
4
19
15
24
*/
/*
0 1 2
x 0 1
0 1 2

i i+1
i-1 i+1
i i+1
총 6가지 방향 확인


*/