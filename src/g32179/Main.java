package g32179;

import java.io.*;
import java.util.*;

public class Main {
    static Map<Integer, Long>comb_mp = new HashMap<>();
    static final long MOD = 1000000007;
    static long calc_comb(int n, int r){
        int key = 101*n+r;
        if(comb_mp.containsKey(key))return comb_mp.get(key);
        long ret = (calc_comb(n-1, r) + calc_comb(n-1, r-1))%MOD;
        comb_mp.put(key, ret);
        return ret;
    }

    static long solution_trace_of_binarysearch(BufferedReader br) throws Exception {
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int k = Integer.parseInt(st.nextToken());
        st = new StringTokenizer(br.readLine());

        List<int[]>group = new ArrayList<>();

        int start = 1, end = n;
        int prev = -1, prev_idx = -1;
        for(int i = 0; i<k; i++){
            int ele = Integer.parseInt(st.nextToken());
            if(prev != -1){
                if(prev > ele){
                    end = prev_idx - 1;
                }
                else{
                    start = prev_idx + 1;
                }
            }
            int idx = (start + end) / 2;
            group.add(new int[]{ele, idx});
            prev = ele; 
            prev_idx = idx;
        }

        Collections.sort(group, new Comparator<int[]>(){
            @Override
            public int compare(int[] a, int[] b){
                return a[0] - b[0];
            }
        });

        int prev_i = 0;
        int prev_v = 0;

        long ret = 1;
        for(int[] ele : group){
            int v = ele[0];
            int idx = ele[1];
            if(prev_i == idx){
                ret *= 1;
                prev_v = v;
                prev_i = idx;
            }
            else{
                int dist_v = v - prev_v - 1;
                int dist_i = idx - prev_i - 1;
                long tmp_ele = calc_comb(dist_v, dist_i);
                //System.out.println("test log : " + tmp_ele + " =  " + (v + " " + idx) + ", "+ (prev_v + " " + prev_i));
                ret *= tmp_ele;
                ret%=MOD;
                prev_v = v;
                prev_i = idx;
            }
        }
        
        if(prev_i < n){
            int dist_v = 100 - prev_v;
            int dist_i = n - prev_i;
            long tmp_ele = calc_comb(dist_v, dist_i);
            ret *= tmp_ele;
            ret%=MOD;
            //System.out.println("test log : " + tmp_ele + " =  " + (100 + " " + n) + ", "+ (prev_v + " " + prev_i));
        }
        
        return ret;
    }
    
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        init();
        System.out.println(solution_trace_of_binarysearch(br));


        // int T = Integer.parseInt(br.readLine());
        // while(T-- > 0){
        //     System.out.println("answer " + solution_trace_of_binarysearch(br));
        // }
    }
    static void init(){
        for(int i = 0; i<=100; i++){
            comb_mp.put(101*i + i, (long)1);
        }
        for(int i = 0; i<=100; i++){
            comb_mp.put(i, (long)1);
        }
        for(int i = 1; i<=100; i++){
            comb_mp.put(101*i, (long)1);
        }
        for(int i = 1; i<=100; i++){
            comb_mp.put(101*i+1, (long)i);
        }
    }
    
}
/*
nCr = n-1Cr + n-1Cr-1

 */
/*
2
3 1
50
5 3
48 21 31
 */
/*
2450
1326
 */