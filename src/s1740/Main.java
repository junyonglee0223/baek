package s1740;

import java.io.*;
import java.util.*;

public class Main {
    static long solution_power(BufferedReader br) throws Exception {
        long n = Long.parseLong(br.readLine());
        long three_pow = 1;
        long sum = 0;
        while(n > 0){

            if((n & 1) != 0)
                sum += three_pow;
            three_pow *= 3;
            n >>= 1;
        }
        return sum;
    }

    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        System.out.println(solution_power(br));
        // int T = Integer.parseInt(br.readLine());
        // while(T-- > 0)
        //     System.out.println(solution_power(br));
    }
    
}

/*
500,000,000,000
앞 원소를 다 합해도 바로 뒤 원소보다 작다는 점
1 3 9 27 81 243 ...
6번째
110(2)

 */

/*
2
4
1
 */
/*
9
1
 */
