package s21735;

import java.io.*;
import java.util.StringTokenizer;

public class Main {
    static long solution_rolling_snowball(BufferedReader br) throws Exception {
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());
        long[] arr = new long[n+1];
        long[][] dp = new long[n+1][m+1];
        
        st = new StringTokenizer(br.readLine());
        for(int i = 1; i<=n; i++){
            arr[i] = Long.parseLong(st.nextToken());
        }


        for(int i = 0; i<n; i++){
            for(int j = 0 ;j<=m; j++){
                dp[i][j] = -1;
            }
        }
        dp[0][0] = 1;
        for(int t = 1; t <= m; t++){
            for(int i = 1; i<=n; i++){
                long tmp = -1;
                if(dp[i-1][t-1] != -1){
                    tmp = Math.max(tmp, dp[i-1][t-1] + arr[i]);
                }
                if(i > 1 && dp[i-2][t-1] != -1){
                    tmp = Math.max(tmp, dp[i-2][t-1] / 2 + arr[i]);
                }
                if(tmp != -1){
                    dp[i][t] = tmp;
                }
            }
        }

        long ret = 0;
        for(int i = 1; i<=n; i++){
            if(dp[i][m] != -1)
                ret = Math.max(ret, dp[i][m]);
        }

        return ret;
    }

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        System.out.println(solution_rolling_snowball(br));
    }
    
}
/*
10 5
1 3 4 5 6 7 8 10 12 14
 */
/*
28
 */