package s11084;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    static int solution_moving(BufferedReader br) throws IOException{
        StringTokenizer st = new StringTokenizer(br.readLine());

        int N = Integer.parseInt(st.nextToken());
        int M = Integer.parseInt(st.nextToken());

        int[][] board = new int[N][M];
        int[][] dp = new int[N][M];

        for(int i = 0; i<N; i++){
            st = new StringTokenizer(br.readLine());
            for(int j = 0; j<M; j++){
                board[i][j] = Integer.parseInt(st.nextToken());
                dp[i][j] = -1;
            }
        }

        for(int i = 0; i<N; i++){
            for(int j = 0; j<M; j++){
                dp[i][j] = board[i][j];
                if(i > 0){
                    int tmp = board[i][j] + dp[i-1][j];
                    dp[i][j] = Math.max(dp[i][j], tmp);
                }

                if(j > 0){
                    int tmp = board[i][j] + dp[i][j-1];
                    dp[i][j] = Math.max(dp[i][j], tmp);
                }

                if(i > 0 && j > 0){
                    int tmp = board[i][j] + dp[i-1][j - 1];
                    dp[i][j] = Math.max(dp[i][j], tmp);
                }
            }
        }

        return dp[N-1][M-1];
    }
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        System.out.println(solution_moving(br));

//        int T = Integer.parseInt(br.readLine());
//        while (T-- > 0){
//            System.out.println(solution_moving(br));
//        }

    }
}
/*
3
3 4
1 2 3 4
0 0 0 5
9 8 7 6
3 3
1 0 0
0 1 0
0 0 1
4 3
1 2 3
6 5 4
7 8 9
12 11 10
 */
/*
31
3
47
 */
