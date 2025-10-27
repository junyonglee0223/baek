package g17182;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {

    static class NODE{
        int cost, cur, status;
        NODE(int cost, int cur, int status){
            this.cost = cost; this.status = status; this.cur = cur;
        }
    }

    static int solution_space_travel(BufferedReader br) throws Exception{
        StringTokenizer st = new StringTokenizer(br.readLine());
        int N = Integer.parseInt(st.nextToken());
        int start = Integer.parseInt(st.nextToken());
        int[][] edges = new int[N][N];

        int[][] dist_cost = new int[N][(1<<N)];
        
        
        
        for(int i = 0 ;i<N; i++){
            for(int j = 0 ;j<(1<<N); j++)
                dist_cost[i][j] = Integer.MAX_VALUE;
        }

        for(int i = 0; i<N; i++){
            st = new StringTokenizer(br.readLine());
            for(int j = 0; j<N; j++){
                edges[i][j] = Integer.parseInt(st.nextToken());
            }
        }

        Queue<NODE>que = new ArrayDeque<>();
        int visit_stat_init = (1 << start);
        dist_cost[start][visit_stat_init] = 0;
        que.add(new NODE(0, start, visit_stat_init));

        int ret = Integer.MAX_VALUE;

        while(!que.isEmpty()){
            NODE cur = que.poll();
            int cur_cur = cur.cur;
            int visit_stat = cur.status;
            int cur_cost = cur.cost;
            if(dist_cost[cur_cur][visit_stat] < cur_cost)continue;

            for(int i = 0; i<N; i++){
                int nxt_cost = cur_cost + edges[cur_cur][i];
                int nxt_visit_stat = (visit_stat | (1 << i));

                
                if(nxt_cost < dist_cost[i][nxt_visit_stat]){
                    dist_cost[i][nxt_visit_stat] = nxt_cost;
                    que.add(new NODE(nxt_cost, i, nxt_visit_stat));
                    if(Integer.bitCount(nxt_visit_stat) == N){
                        ret = Math.min(ret, nxt_cost);
                    }
                }
            }
        }
        return ret;
    }

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        System.out.println(solution_space_travel(br));
        // int T = Integer.parseInt(br.readLine());
        // while(T-- > 0){
        //     System.out.println(solution_space_travel(br));
        // }

        
    }
}
/*
2
3 0
0 30 1
1 0 29
28 1 0
4 1
0 83 38 7
15 0 30 83
67 99 0 44
14 46 81 0
 */
/*
2
74
 */