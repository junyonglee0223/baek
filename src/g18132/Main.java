package g18132;

import java.io.*;
import java.util.*;

public class Main {

    static final long MOD = 1_000_000_007;
    static List<Long>dp = new ArrayList<>();

    static void init(){
        dp.add(1L);
        dp.add(2L);
        dp.add(5L);
    }

    static long solution_get_my_binary_tree(BufferedReader br) throws Exception {

        int n = Integer.parseInt(br.readLine());
        while(dp.size() <= n){
            int idx = dp.size() - 1;
            long nxt_num = dp.get(idx) * 2;

            for(int i = 0; i<=idx - 1; i++){
                nxt_num += (dp.get(i) * dp.get(idx - 1 - i)) % MOD;
                nxt_num %= MOD;
            }
            dp.add(nxt_num);
        }
        return dp.get(n);
    }

    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        init();
        int T = Integer.parseInt(br.readLine());
        while(T-- > 0){
            System.out.println(solution_get_my_binary_tree(br));
        }
    }
    
}
/*
1

2
5
10 + 4 = 14
42
132


홀수는 애초에 대칭이 불가능
짝수는 대칭이 가능함
2 * (n-1) + ((n-2, 0) + (n-3, 1) + ... + (n-(n/2), n/2-1))

4 -> (1 ---), (1 ---) -> (0, 2)(1, 1)(2, 0)
10 + 4
28 + 5 + 4 + 5


 */
/*
3
2
4
5
 */

 /*
5
42
132
  */
