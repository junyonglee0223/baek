package g2327;

import java.io.*;
import java.util.*;

public class Main {

    static int N;
    static int H;

    static class NODE{
        int h, s;
        NODE(int h, int s){
            this.h = h;
            this.s = s;
        }
    }

    static int min_speed = Integer.MAX_VALUE;

    static void dfs_malaton(int idx, int sum, boolean[] visited, List<NODE>nodes){
        if(sum == H){
            for(int i = 0; i<N; i++){
                if(visited[i] == true)
                    min_speed = Math.min(min_speed, nodes.get(i).s);
            }

            // for(int i = 0; i<N; i++)
            //     System.out.println(nodes.get(i).h + " " + nodes.get(i).s + " " +  visited[i]);
            // System.out.println();
            return;
        }

        for(int cur = 0; cur < idx; cur++){
            if(min_speed < Integer.MAX_VALUE)return;
            if(visited[cur])continue;

            visited[cur] = true;
            int nxt_sum = sum + nodes.get(cur).h;
            if(nxt_sum <= H){
                dfs_malaton(cur, nxt_sum, visited, nodes);
            }
            visited[cur] = false;
        }
    }

    static int solution_malaton(BufferedReader br) throws Exception{
        StringTokenizer st = new StringTokenizer(br.readLine());
        H = Integer.parseInt(st.nextToken());
        N = Integer.parseInt(st.nextToken());

        List<NODE>nodes = new ArrayList<>();

        for(int i = 0; i<N; i++){
            st = new StringTokenizer(br.readLine());
            int h = Integer.parseInt(st.nextToken());
            int s = Integer.parseInt(st.nextToken());
            nodes.add(new NODE(h, s));
        }

        Collections.sort(nodes, new Comparator<NODE>() {
            @Override
            public int compare(NODE a, NODE b){
                if(b.s == a.s)return a.h - b.h;
                return b.s - a.s;
            }
        });
        boolean[] visited = new boolean[N];
        for(int i = 0; i<N; i++)
            visited[i] = false;
        
        dfs_malaton(N, 0, visited, nodes);

        return min_speed;
    }

    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        System.out.println(solution_malaton(br));
    }
    
}

/*
s: 7 7 6 5 5 4
h: 2 6 3 1 4 1

 */
/*
7 6
4 5
3 6
2 7
1 4
6 7
1 5
 */
/*
5
 */