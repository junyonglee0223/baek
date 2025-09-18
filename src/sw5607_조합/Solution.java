package sw5607_조합;

import java.io.*;
import java.util.StringTokenizer;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Solution {

    static final int MAX_N = 1000001;
    static long last_N = 0;
    static final long MOD = 1234567891;
    static long[] pacto = new long[MAX_N];
    static long[] rev_pacto = new long[MAX_N];

    static long rev_num(long num){
        long x = MOD -2;
        long a = num;
        long ret = 1;
        while(x > 0){
            if((x & 1) != 0){
                ret = (ret * a)%MOD;
            }
            a = (a * a)%MOD;
            x >>= 1;
        }
        return ret;
    }
    static void global_init(){
        for(int i = 0; i<MAX_N; i++){
            pacto[i] = 1;
            rev_pacto[i] = 1;
        }
    }
    static void init(long n){
        if(last_N >= n)return;
        for(int i = (int)last_N; i<(int)n; i++){
            pacto[i+1] = (pacto[i] * (i+1))%MOD;
            rev_pacto[i+1] = rev_num(pacto[i+1]);
        }
        last_N = n;
    }

    static long solution_combination(BufferedReader br) throws IOException{
        StringTokenizer st = new StringTokenizer(br.readLine());
        long N = Long.parseLong(st.nextToken());
        long R = Long.parseLong(st.nextToken());
        init(N);
        long ret = (rev_pacto[(int)R] * rev_pacto[(int)(N-R)])%MOD;
        ret = (pacto[(int)N] * ret)%MOD;
        return ret;

    }
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        int T = Integer.parseInt(br.readLine());
        global_init();

        StringBuilder sb = new StringBuilder();
        for(int test_case = 1; test_case <= T; test_case++){
            sb.append("#").append(test_case).append(" ").append(solution_combination(br)).append("\n");
        }
        bw.write(sb.toString());
        bw.flush();

    }
}
