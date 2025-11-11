package g22236;

import java.io.*;
import java.util.*;

public class Main {
    public static int solution_kahi_s_plane(BufferedReader br) throws Exception {
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int mod = Integer.parseInt(st.nextToken());

        long[] dp_2 = new long[(n/2) + 1];
        int dp_l = dp_2.length;
        //0, 1, ..., n/2
        for(int i = 0; i<dp_2.length; i++){
            dp_2[i] = 0;
        }
        dp_2[1] = 1;
        for(int i = 2; i<n; i++){
            long[] nxt_dp = new long[dp_l];
            for(int idx = 1; idx<dp_l; idx++){
                long left = dp_2[idx-1];
                long right = idx == dp_l - 1 ? 0 : dp_2[idx+1];
                nxt_dp[idx] = (left + right)%mod;
            }
            dp_2 = nxt_dp;
        }
        //////
        /// 
        return (int)dp_2[1];
    }
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        System.out.println(solution_kahi_s_plane(br));
        // int T = Integer.parseInt(br.readLine());
        // while(T-- > 0){
        //     System.out.println(solution_kahi_s_plane(br));
        // }
        
    }
}
/*
올바른 괄호가 가능한지 문제와 유사하다.
다만 조건이 추가되어 있다. 0이 되어서는 안됨
4*(10^3) n^2해도 문제가 없다면 dp 사용해서 구현해도 된다.

 */
/*
2
2 1000000007
4 1000000007
 */
/*
1
1
 */