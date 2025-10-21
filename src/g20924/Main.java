package g20924;

import java.io.*;
import java.util.*;

public class Main {
    
    static boolean[] visited;
    static List<List<int[]>>adj;
    static int max_branch;

    static void dfs_tree(int cur, int sum_d){
        for(int[] nxt_n : adj.get(cur)){
            int nxt = nxt_n[0];
            int cost = nxt_n[1];
            if(visited[nxt])continue;
            max_branch = Math.max(max_branch, sum_d + cost);
            dfs_tree(nxt, sum_d + cost);
        }
    }

    static void solution_pillars_and_branchse(BufferedReader br) throws Exception{
        StringTokenizer st = new StringTokenizer(br.readLine());

        int n = Integer.parseInt(st.nextToken());
        int r = Integer.parseInt(st.nextToken());

        adj = new ArrayList<>();
        for(int i = 0; i<=n; i++){
            adj.add(new ArrayList<>());
        }
        for(int i = 0; i<n-1; i++){
            st = new StringTokenizer(br.readLine());
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());
            int c = Integer.parseInt(st.nextToken());
            adj.get(a).add(new int[]{b, c});
            adj.get(b).add(new int[]{a, c});
        }

        visited = new boolean[n+1];
        int start = r;
        int pilar_size = 0;
        visited[start] = true;
        while(true){
            int cur_cnt = 0;
            int[] nxt = {0, 0};
            for(int[] nxt_n : adj.get(start)){
                if(visited[nxt_n[0]])continue;
                cur_cnt++;
                nxt = nxt_n;
            }

            if(cur_cnt > 1 || cur_cnt == 0)break;
            start = nxt[0];
            pilar_size += nxt[1];
            visited[start] = true;
        }

        max_branch = 0;

        Queue<int[]>que = new ArrayDeque<>();
        que.add(new int[]{start, 0});

        while(!que.isEmpty()){
            int[] cur_n = que.poll();
            int cur = cur_n[0];
            int cost = cur_n[1];

            for(int[] nxt_n : adj.get(cur)){
                int nxt = nxt_n[0];
                int nxt_cost = cost + nxt_n[1];
                if(visited[nxt])continue;
                visited[nxt] = true;
                que.add(new int[]{nxt, nxt_cost});
                max_branch = Math.max(max_branch, nxt_cost);
            }
        }



        //dfs_tree(start, 0);
        System.out.println(pilar_size + " " + max_branch);
    }
    
    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        solution_pillars_and_branchse(br);

        // int T = Integer.parseInt(br.readLine());
        // while (T-- > 0) {
        //     solution_pillars_and_branchse(br);
        //     System.out.println("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!");
        // }
        
    }
    
}

/*
4
12 1
1 2 1
2 3 2
3 4 3
4 5 1
5 6 2
6 7 1
5 8 1
4 9 2
4 10 3
10 11 1
10 12 3
9 1
1 2 5
2 3 4
3 4 2
2 5 5
1 6 8
1 7 6
7 8 7
7 9 1
4 1
1 2 100
2 3 10
3 4 1
1 1
*/

/*
6 6
0 13
111 0
0 0
*/