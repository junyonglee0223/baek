package g29704;

import java.io.*;
import java.util.*;

public class Main {

    static int[][] dp;
    static int[] days, costs;
    static int N, T;

    static int cramBackTracking(int idx, int time){
       
        if(dp[idx][time] != -1)return dp[idx][time];

        int ret = costs[idx];
        for(int i = idx+1; i<N; i++){
            if(days[i] + time > T)continue;
            ret = Math.max(ret, 
                costs[idx] + cramBackTracking(i, time + days[i]));
        }
        return dp[idx][time] = ret;
    }

    static int solutionCram(BufferedReader br) throws Exception {
        StringTokenizer st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        T = Integer.parseInt(st.nextToken());

        days = new int[N];
        costs = new int[N];

        int totalCost = 0;
        for(int i = 0; i<N; i++){
            st = new StringTokenizer(br.readLine());
            days[i] = Integer.parseInt(st.nextToken());
            costs[i] = Integer.parseInt(st.nextToken());
            totalCost += costs[i];
        }

        dp = new int[N+1][T+1];
        for(int i = 0; i<=N; i++){
            for(int j = 0; j<=T; j++){
                dp[i][j] = -1;
            }
        }

        int ret = 0;

        for(int start = 0; start < N; start++){
            if(days[start] > T)continue;
            ret = Math.max(ret, cramBackTracking(start, days[start]));
        }
        return totalCost - ret;
    }
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        System.out.println(solutionCram(br));
    }
    
}
/*
3 3
2 5000
1 1000
1 2000

4 5
2 5000
2 2000
2 3000
3 1000

3 6
1 1000
2 4000
3 2000
*/
/*
1000
3000
0
*/