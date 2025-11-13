package s14231;

import java.io.*;
import java.util.*;

public class Main {
    static int n;
    static int[] arr;
    static int[] dp;

    static int backtracing_box_v1(int cur){
        if(dp[cur] != -1)return dp[cur];
        dp[cur] = 1;

        for(int nxt = cur+1; nxt < n; nxt++){
            if(arr[cur] < arr[nxt]){
                dp[cur] = Math.max(dp[cur], 1 + backtracing_box(nxt));
            }
        }
        return dp[cur];
    }

    static int backtracing_box(int cur){
        if(dp[cur] != -1)return dp[cur];
        dp[cur] = 1;

        for(int nxt = n-1; nxt >= cur+1; nxt--){
            if(arr[cur] < arr[nxt]){
                dp[cur] = Math.max(dp[cur], 1 + backtracing_box(nxt));
            }
        }
        return dp[cur];
    }

    static int solution_package_box(BufferedReader br) throws Exception {
        n = Integer.parseInt(br.readLine());
        StringTokenizer st = new StringTokenizer(br.readLine());

        arr = new int[n];
        for(int i = 0; i<n; i++){
            arr[i] = Integer.parseInt(st.nextToken());
        }
        dp = new int[n];
        for(int i = 0; i<n; i++){
            dp[i] = -1;
        }

        int ret = 0;
        for(int i = n-1; i>=0; i--){
            ret = Math.max(ret, backtracing_box(i));
        }
        return ret;
    }
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        System.out.println(solution_package_box(br));


    }
    
}
/*
7
1 3 7 6 4 2 9
 */