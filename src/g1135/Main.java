package g1135;
//g1135 뉴스 전하기

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {

    static void spread_time(int now, int[] dp, List<List<Integer>>adj){

        dp[now] = 0;
        for(int nxt : adj.get(now)){
            spread_time(nxt, dp, adj);
        }

        Collections.sort(adj.get(now), (a, b) -> dp[b] - dp[a]);

        int tmp = 0;
        int ret = 0;
        for(int nxt : adj.get(now)){
            ret = Math.max(ret, dp[nxt] + tmp + 1);
            tmp++;
        }
        dp[now] = ret;
    }
    static void solution_spread_the_news(BufferedReader br) throws IOException {
        int n = Integer.parseInt(br.readLine());
        int[] parents = new int[n];

        List<List<Integer>>adj = new ArrayList<>();
        for(int i = 0; i<n; i++){
            adj.add(new ArrayList<>());
        }

        StringTokenizer st = new StringTokenizer(br.readLine());
        for(int i = 0; i<n; i++){
            parents[i] = Integer.parseInt(st.nextToken());
            if(parents[i] == -1)continue;
            adj.get(parents[i]).add(i);
        }

        int[] dp = new int[n];
        for(int i = 0; i<n; i++)
            dp[i] = 0;

        spread_time(0, dp, adj);
        System.out.println(dp[0]);
    }
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        solution_spread_the_news(br);

//        int T = Integer.parseInt(br.readLine());
//        while(T-- > 0){
//            solution_spread_the_news(br);
//        }
    }
}
/*
4
3
-1 0 0
5
-1 0 0 2 2
5
-1 0 1 2 3
24
-1 0 0 1 1 1 2 2 3 3 4 4 5 5 6 7 7 8 12 13 14 16 16 16
*/
/*
2
3
4
7
*/