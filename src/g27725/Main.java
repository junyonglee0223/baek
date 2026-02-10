package g27725;

import java.io.*;
import java.util.StringTokenizer;

public class Main {

    static Long addExponent(int n, Long[] primes, Long num){
        
        Long ret = 0L;

        for(Long primeNum : primes){
            for(Long ele = primeNum; ele <= num; ele *= primeNum){
                ret += (num / ele);
            }
        }
        return ret;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int n = Integer.parseInt(br.readLine());

        Long[] primes = new Long[n];
        StringTokenizer st = new StringTokenizer(br.readLine());

        for(int i = 0; i<n; i++){
            primes[i] = Long.parseLong(st.nextToken());
        }

        Long num = Long.parseLong(br.readLine());

        System.out.println(addExponent(n, primes, num));        
    }
    
}
/*
2
2 3
100
*/
/*
145
*/