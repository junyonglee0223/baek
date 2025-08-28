package sw5656_벽돌깨기;
//:boom: SW5656_BreakingBricks_이준용.java

import java.io.*;
import java.util.*;

public class Solution {
    static int H, W, N;

    static int[] dx = {1, 0, -1, 0};
    static int[] dy = {0, 1, 0, -1};
    static int answer = Integer.MAX_VALUE;

    static boolean is_range(int x, int y){
        return x >= 0 && x < H && y >= 0 && y < W;
    }

    static void explosion_board(int x, int y, int[][] board){
        Queue<int[]> que = new ArrayDeque<>();
        boolean[][] visited = new boolean[H][W];

        visited[x][y] = true;
        que.add(new int[]{x, y});


        while(!que.isEmpty()){
            int[] cur_node = que.poll();
            int c_x = cur_node[0];
            int c_y = cur_node[1];
            int value = board[c_x][c_y] - 1;

            if(board[c_x][c_y] == 0)continue;

            for(int d = 0; d<4; d++){
                int n_x = c_x, n_y = c_y;
                for(int ttc = 0; ttc<value; ttc++){
                    n_x += dx[d];
                    n_y += dy[d];
                    if(!is_range(n_x, n_y))continue;
                    if(visited[n_x][n_y])continue;
                    visited[n_x][n_y] = true;
                    que.add(new int[]{n_x, n_y});
                }
            }
        }

        for(int i = 0; i<H; i++){
            for(int j = 0; j<W; j++){
                if(visited[i][j])board[i][j] = 0;
            }
        }
    }


    static void update_board(int[][] board){

        for(int col = 0; col < W; col++){
            for(int h = H-2; h>= 0; h--){
                if(board[h][col] != 0 && board[h+1][col] == 0){
                    int idx = h;
                    while(idx < H-1 && board[idx+1][col] == 0){
                        idx++;
                    }
                    board[idx][col] = board[h][col];
                    board[h][col] = 0;
                }
            }
        }
    }
    static int count_board(int[][] board){
        int ret = 0;
        for(int j = 0; j<W; j++) {
            for (int i = 0; i < H; i++) {
                if (board[i][j] != 0) ret++;
            }
        }
        return ret;
    }
    static int[][] copy_board(int[][] board){

        int[][] n_board = new int[H][W];

        for(int j = 0; j<W; j++){
            for(int i = 0; i<H; i++){
                n_board[i][j] = board[i][j];
            }
        }
        return n_board;
    }
    static void dfs_board(int[][] board, int cnt){
        if(cnt >= N){
            answer = Math.min(answer, count_board(board));
            //System.out.println(count_board(board));////////////////////////////////
            return;
        }
        for(int j = 0; j<W; j++){
            int c_h = 0;
            while(c_h < H && board[c_h][j] == 0){
                c_h++;
            }
            int i = c_h;
            if(i < H && board[i][j] != 0){
                int[][] n_board = copy_board(board);
                explosion_board(i, j, n_board);
                update_board(n_board);
                dfs_board(n_board, cnt+1);
                //break;
            }
        }
    }

    static int solution_breaking_bricks(BufferedReader br) throws IOException{
        answer = Integer.MAX_VALUE;

        StringTokenizer st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        W = Integer.parseInt(st.nextToken());
        H = Integer.parseInt(st.nextToken());
        int[][] board = new int[H][W];
        for(int i = 0; i<H; i++){
            st = new StringTokenizer(br.readLine());
            for(int j = 0; j<W; j++){
                board[i][j] = Integer.parseInt(st.nextToken());
            }
        }

        dfs_board(board, 0);
        return answer == Integer.MAX_VALUE ? 0 : answer;
    }


    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int T = Integer.parseInt(br.readLine());

        for(int test_case = 1; test_case <= T; test_case++)
        {

            System.out.println("#" + test_case + " " + solution_breaking_bricks(br));
        }
    }

}
/*
5
3 10 10
0 0 0 0 0 0 0 0 0 0
1 0 1 0 1 0 0 0 0 0
1 0 3 0 1 1 0 0 0 1
1 1 1 0 1 2 0 0 0 9
1 1 4 0 1 1 0 0 1 1
1 1 4 1 1 1 2 1 1 1
1 1 5 1 1 1 1 2 1 1
1 1 6 1 1 1 1 1 2 1
1 1 1 1 1 1 1 1 1 5
1 1 7 1 1 1 1 1 1 1
2 9 10
0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0
0 1 0 0 0 0 0 0 0
0 1 0 0 0 0 0 0 0
1 1 0 0 1 0 0 0 0
1 1 0 1 1 1 0 1 0
1 1 0 1 1 1 0 1 0
1 1 1 1 1 1 1 1 0
1 1 3 1 6 1 1 1 1
1 1 1 1 1 1 1 1 1
 */
/*
벽돌깨기
맞은 블록의 value 만큼 이동하면서 범위 만들어서 삭제하고 떨어지는 과정이다.

N - 1 ~ 4 - 구슬 쏘는 개수
W - 2 ~ 12
H - 2 ~ 15
W * H 보드 사이즈이다.

dfs 로 탐색하는 과정인 듯 하다.

 */