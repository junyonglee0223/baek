package g1947;
//g1947 선물 전달


import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
    static final long MOD = 1000000000;
    static long[] dp;
    static void set_derangement_init(){
        dp = new long[1000001];
        dp[0] = 0;
        dp[1] = 0;
        dp[2] = 1;
        dp[3] = 2;
        for(int i = 4; i<dp.length; i++){
            dp[i] = (dp[i-1] + dp[i-2]) * (i-1);
            dp[i] %= MOD;
        }
    }
    static void solution_derangement(BufferedReader br) throws IOException {
        int n = Integer.parseInt(br.readLine());
        System.out.println(dp[n]);
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        set_derangement_init();

        solution_derangement(br);

//        int T = Integer.parseInt(br.readLine());
//        while(T-- > 0){
//            solution_derangement(br);
//        }
    }
}


/*
4
5
4
2
21
*/
/*
44
9
2
50944540
*/