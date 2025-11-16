package s28422;
import java.io.*;
import java.util.*;


public class Main {

    static int solution_xor_card_game(BufferedReader br) throws Exception {
        int n = Integer.parseInt(br.readLine());
        StringTokenizer st = new StringTokenizer(br.readLine());
        int[] arr = new int[n + 1];

        for(int i = 1; i <= n; i++) {
            arr[i] = Integer.parseInt(st.nextToken());
        }

        if (n == 1) return 0; 

        int[] dp = new int[n + 1];
        Arrays.fill(dp, -1);
        dp[0] = 0;
        dp[1] = -1; 

        for(int i = 2; i <= n; i++) {
            if (dp[i-2] != -1) {
                int xor = arr[i-1] ^ arr[i];
                dp[i] = Math.max(dp[i], dp[i-2] + Integer.bitCount(xor));
            }
            if (i >= 3 && dp[i-3] != -1) {
                int xor = arr[i-2] ^ arr[i-1] ^ arr[i];
                dp[i] = Math.max(dp[i], dp[i-3] + Integer.bitCount(xor));
            }
        }

        return dp[n] != -1 ? dp[n] : 0;

    }

    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        System.out.println(solution_xor_card_game(br));
        
        // int T = Integer.parseInt(br.readLine());
        // while(T-- > 0){
        //     System.out.println("answer: "+solution_xor_card_game(br));
        // }
    }
}
/*
3
5
2 1 3 8 4
7
67 351 9 1023 497 261 1001
1
5
 */
/*
6
18
0
 */