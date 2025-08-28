package g19587;
//g19587 객실 배치

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
    /*
    a0 = 1
    a1 = 3
    a2 = 7
    a3 = 17
    a4 = 41
    a5 = 99
    [7, 3]		[2, 1]
    [3, 1]		[1, 0]

    [17, 10]
    [7, 3]
    */
    static final long MOD = 1000000007;
    static long[][] mat_multiply(long[][] a, long[][] b){
        long[][] ret = {{0, 0}, {0, 0}};
        for(int i = 0; i<2; i++){
            for(int j = 0; j<2; j++){
                for(int k = 0; k<2; k++){
                    ret[i][j] += (a[i][k] * b[k][j]) % MOD;
                    ret[i][j] = (ret[i][j] + MOD)%MOD;
                }
            }
        }
        return ret;
    }

    static long[][] mat_pow(long[][] a, long x){
        long[][] ret = {{1, 0}, {0, 1}};
        while(x > 0){
            if(x % 2 == 1){
                ret = mat_multiply(ret, a);
            }
            a = mat_multiply(a, a);
            x /= 2;
        }
        return ret;
    }
    static long solution_set_room(BufferedReader br) throws IOException{
        long n = Long.parseLong(br.readLine());
        if(n <= 2){
            if(n == 1)return 3;
            if(n == 2)return 7;
        }
        long[][] start = {{7, 3}, {3, 1}};
        long[][] unit = {{2, 1}, {1, 0}};

        long pow_cnt = n - 2;

        unit = mat_pow(unit, pow_cnt);
        start = mat_multiply(start, unit);
        return start[0][0];
    }
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        System.out.println(solution_set_room(br));
    }
}
/*
2
1
5
*/
/*
3
99
*/
/*
dp[i][0] <- dp[i-1][0] + dp[i-1][1] + dp[i-1][2];
dp[i][1] <- dp[i-1][0] + dp[i-1][2]
dp[i][2] <- dp[i-1][0] + dp[i-1][1]
dp[0][1][2] <- 3 * dp[0] + 2 * dp[1] + 2 * dp[2]

ax <- 2 * a(x-1) + dp[x-1][0]
(i, 0) <- (i-1, 0) + (i-2, 0) + (i-2, 2) + (i-2, 0) + (i-2, 1)

(i+1, 0) <- (i, 0) + 2 * (i-1, 0) + (i-1, 1) + (i-1, 2)
(i, 0) <- (i-1, 0) + 2 * (i-2, 0) + (i-2, 1) + (i-2, 2)

(i+1, 0) - (i, 0) <- (i, 0) - (i-1, 0) + 2 * ((i-1, 0) - (i-2, 0)) + 2 * (i-2, 0)
(i+1, 0) <- 2 * (i, 0) + (i-1, 0)
a(x) = 2 * a(x-1) + a(x-2)
*/