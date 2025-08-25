package sw1868_파핑파핑지뢰찾기;

import java.io.*;
import java.util.ArrayDeque;
import java.util.Queue;

public class Solution {

    static int N;
    static int[] dx = {1, 1, 0, -1, -1, -1, 0, 1};
    static int[] dy = {0, 1, 1, 1, 0, -1, -1, -1};
    static int[][] board;
    static boolean[][] opened;
    static boolean is_range(int nxt_x, int nxt_y){
        return nxt_x >= 0 && nxt_x < N && nxt_y >= 0 && nxt_y < N;
    }
    static void set_board_opened(int x, int y){
        Queue<int[]> que = new ArrayDeque<>();
        if(board[x][y] != 0){
            opened[x][y] = true;
            return;
        }

        que.add(new int[]{x, y});
        opened[x][y] = true;
        while(!que.isEmpty()){
            int[] cur = que.poll();
            int c_x = cur[0];
            int c_y = cur[1];
            for(int d = 0; d<8; d++){
                int n_x = c_x + dx[d];
                int n_y = c_y + dy[d];
                if(!is_range(n_x, n_y))continue;
                if(board[n_x][n_y] == -1)continue;
                if(opened[n_x][n_y])continue;

                opened[n_x][n_y] = true;
                if(board[n_x][n_y] == 0){
                    que.add(new int[]{n_x,n_y});
                }
            }
        }
    }
    static int solution_popping_trap(BufferedReader br) throws IOException{
        N = Integer.parseInt(br.readLine());
        Character[][] c_board = new Character[N][N];
        board = new int[N][N];
        opened = new boolean[N][N];
        for(int i = 0; i<N; i++){
            for(int j = 0; j<N; j++){
                board[i][j] = 0;
                opened[i][j] = false;
            }
        }


        Queue<int[]> que = new ArrayDeque<>();
        for(int i =0 ; i<N; i++){
            String tmp_str = br.readLine();
            for(int j = 0; j<N; j++){
                c_board[i][j] = tmp_str.charAt(j);
                if(c_board[i][j] == '*'){
                    board[i][j] = -1;
                    que.add(new int[] {i, j});
                    opened[i][j] = true;
                }
            }
        }

        while(!que.isEmpty()){
            int cur_x = que.peek()[0];
            int cur_y = que.peek()[1];
            que.poll();
            for(int d= 0; d<8; d++){
                int nxt_x = cur_x + dx[d];
                int nxt_y = cur_y + dy[d];
                if(!is_range(nxt_x, nxt_y))continue;
                if(board[nxt_x][nxt_y] == -1)continue;
                board[nxt_x][nxt_y]++;
            }
        }


        int ret = 0;


        for(int i =0 ; i<N; i++){
            for(int j = 0; j<N; j++){
                if(board[i][j] == 0 && !opened[i][j]){
                    set_board_opened(i, j);
                    ret++;
                }
            }
        }

        for(int i =0 ; i<N; i++){
            for(int j = 0; j<N; j++){
                if(!opened[i][j]){
                    opened[i][j] = true;
                    ret++;
                }
            }
        }
        return  ret;
    }
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int T = Integer.parseInt(br.readLine());

        for(int test_case = 1; test_case <= T; test_case++)
        {

            System.out.println("#" + test_case + " " + solution_popping_trap(br));
            //bw.write("#" + test_case + " " + solution_working_order(br) + "\n");
            //bw.flush();

        }
    }
}
/*2
3
..*
..*
**.
5
..*..
..*..
.*..*
.*...
.*...

 */
/*
0 2 x 2 0
1 3 x 3 2
2 x 3 2 x
3 x 3 1 1
2 x 2 0 0


x x x x x
x x x x x
2 x 3 2 x
3 x x x x
2 x x x x


 */
/*
#1 2
#2 8
 */