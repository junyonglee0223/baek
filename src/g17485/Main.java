package g17485;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    static int[][][] dp;
    static int[][] board;
    static int N, M;

    static int solution_Jinwoo_Moon_Journey(BufferedReader br) throws IOException{
        StringTokenizer st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());

        board = new int[N][M];
        dp = new int[N][M][3];
        for(int i = 0; i<N; i++){
            st = new StringTokenizer(br.readLine());
            for(int j = 0; j<M; j++){
                board[i][j] = Integer.parseInt(st.nextToken());
                for(int k = 0; k<3; k++){
                    dp[i][j][k] = Integer.MAX_VALUE;
                }
            }
        }
        //0 (좌하), 1(하), 2(우하)
        for(int i = 0; i<M; i++){
            dp[0][i][0] = dp[0][i][1] = dp[0][i][2] = board[0][i];
        }

        for(int i = 1; i<N; i++){
            for(int j = 0; j<M; j++){
                //1 status
                dp[i][j][1] = board[i][j] + Math.min(dp[i-1][j][0], dp[i-1][j][2]);
                //2 status
                if(j > 0){
                    dp[i][j][2] = board[i][j] + Math.min(dp[i-1][j-1][0], dp[i-1][j-1][1]);
                }
                //0 status
                if(j < M - 1){
                    dp[i][j][0] = board[i][j] + Math.min(dp[i-1][j+1][2], dp[i-1][j+1][1]);
                }
            }
        }

        int ret = dp[N-1][0][0];
        for(int i = N-1; i<N; i++){
            for(int j = 0; j<M; j++){
                for(int k = 0; k<3; k++){
                    ret = Math.min(ret, dp[i][j][k]);
                }
            }
        }

        return ret;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        System.out.println(solution_Jinwoo_Moon_Journey(br));
    }
}
/*
6 4
5 8 5 1
3 5 8 4
9 77 65 5
2 1 5 2
5 98 1 5
4 95 67 58
*/
/*
29
 */