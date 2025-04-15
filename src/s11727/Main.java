package s11727;
//s11727번 2×n 타일링 2


import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {

    static int MOD = 10007;

    static void solution_2_multi_n_tiling(BufferedReader br) throws IOException {
        StringTokenizer st = new StringTokenizer(br.readLine());
        int N = Integer.parseInt(st.nextToken());

        int[] dp = new int[2002];
        for(int i = 0; i<2002; i++)
            dp[i] = -1;

        dp[0] = 0;
        dp[1] = 1;
        dp[2] = 3;
        for(int i = 3; i<=N; i++){
            dp[i] = (dp[i-1] + dp[i-2] * 2) % MOD;
        }
        System.out.println(dp[N]);
    }

    static int[][] multi_arr(int[][] a, int[][] b){
        int[][] ret = new int[][]{{0, 0}, {0, 0}};

        for(int i = 0; i<2; i++){
            for(int j = 0; j<2; j++){
                for(int k = 0; k<2; k++){
                    ret[i][j] += (a[i][k] * b[k][j]) % MOD;
                    ret[i][j] %= MOD;
                }
            }
        }
        return ret;
    }

    static int[][] pow_arr(int[][] x, int n){
        if(n <= 1)return x;
        int[][] ret = new int[][]{{1, 0}, {0, 1}};
//        int[][] tmp = Arrays.copyOf(x, ret.length);
        int[][] tmp = x;

        while(n > 0){
            if(n % 2 == 1){
                ret = multi_arr(ret, tmp);
                n = n-1;
            }
            tmp = multi_arr(tmp, tmp);
            n = n / 2;
        }
        return ret;
    }

    static void solution_2_multi_n_tiling_v1(BufferedReader br) throws IOException {
        int n = Integer.parseInt(br.readLine());

        int[][] init = new int[][]{{3, 1}, {1, 1}};
        int[][] unit = new int[][]{{1, 2}, {1, 0}};

        if(n == 1){
            System.out.println(1);
            return;
        }
        else if(n == 2){
            System.out.println(3);
            return;
        }
        int[][] ret = pow_arr(unit, n-2);

        ret = multi_arr(ret, init);
        System.out.println(ret[0][0]);
    }


    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        //solution_2_multi_n_tiling(br);
        solution_2_multi_n_tiling_v1(br);
//
//        int T = Integer.parseInt(br.readLine());
//        while(T-- > 0){
////            solution_2_multi_n_tiling(br);
//            solution_2_multi_n_tiling_v1(br);
//        }
    }
}


/*
3
2
8
12
*/
/*
3
171
2731
*/
