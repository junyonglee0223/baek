package g18430;

import java.io.*;
import java.util.*;

public class Main{

    static int[][][] dir = {
        {{0, 0, 1}, {1, 0, 0}},
        {{0, 0, 1}, {0, 1, 1}},
        {{0, 1, 1}, {1, 1, 0}},
        {{0, 1, 1}, {0, 0, 1}}
    };

    static int N, M;
    static int[][] board;
    static boolean[][] visited;
    static int best = 0;

    

    static boolean isRange(int x, int y){
        return x >= 0 && x < N && y >= 0 && y < M;
    }

    static void dfs(int idx, int value){
        int x = idx / M;
        int y = idx % M;

        if(x == N-1 && y == M-1){
            if(value > best){
                best = value;
            }
            return;
        }

        dfs(idx + 1, value);
        

        for(int d = 0; d < 4; d++){
            int x1 = x + dir[d][0][0];
            int y1 = y + dir[d][1][0];
            
            int x2 = x + dir[d][0][1];
            int y2 = y + dir[d][1][1];
            
            int x3 = x + dir[d][0][2];
            int y3 = y + dir[d][1][2];

            if(isRange(x1, y1) 
                && isRange(x2, y2) 
                    && isRange(x3, y3)){
                if(visited[x1][y1] || visited[x2][y2] || visited[x3][y3])continue;

                
                visited[x1][y1] = true;
                visited[x2][y2] = true;
                visited[x3][y3] = true;

                int addValue = board[x1][y1] + board[x2][y2] * 2 + board[x3][y3];
                dfs(idx+1, value + addValue);

                visited[x1][y1] = false;
                visited[x2][y2] = false;
                visited[x3][y3] = false;
            }
        }
    }


    public static void main(String[] args) throws IOException{
        BufferedReader br 
            = new BufferedReader(new InputStreamReader(System.in));

        StringTokenizer st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());

        board = new int[N][M];
        visited = new boolean[N][M];

        for(int i = 0; i<N; i++){
            st = new StringTokenizer(br.readLine());
            for(int j = 0; j<M ;j++){
                board[i][j] = Integer.parseInt(st.nextToken());
                visited[i][j] = false;
            }
        }

        dfs(0, 0);

        System.out.println(best);
    }
}
/*
3 3
32 83 75
24 96 56
71 88 12
*/
/*632*/

/* 
1 1
7
*/
/*
0
*/