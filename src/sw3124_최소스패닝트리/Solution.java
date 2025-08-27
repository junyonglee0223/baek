package sw3124_최소스패닝트리;
//:mag: SW3124_MST_이준용.java

import java.io.*;
import java.util.*;

public class Solution {
    static int V, E;
    static int[] parents;
    static int[] ranks;

    static class EDGE{
        int src, dst; long weight;
        EDGE(int _src, int _dst, long _weight){
            this.src = _src;
            this.dst = _dst;
            this.weight = _weight;
        }
    }
    static EDGE[] edges;

    static int find(int a){
        if(parents[a] == a){
            return a;
        }
        return parents[a] = find(parents[a]);
    }
    static boolean union(int a, int b){
        int pa = find(a);
        int pb = find(b);

        if(pa == pb)return false;
        if(ranks[pa] < ranks[pb]){
            parents[pa] = pb;
        }else if(ranks[pa] > ranks[pb]){
            parents[pb] = pa;
        }else{
            parents[pb] = pa;
            ranks[pa]++;
        }
        return true;
    }

    static long solution_minimum_spanning_tree_v1(BufferedReader br) throws IOException{
        StringTokenizer st = new StringTokenizer(br.readLine());

        V = Integer.parseInt(st.nextToken());
        E = Integer.parseInt(st.nextToken());
        edges = new EDGE[E];
        parents = new int[V+1];
        ranks = new int[V+1];
        for(int i = 0; i<=V; i++){
            parents[i] = i;
            ranks[i] = 0;
        }

        for(int i = 0; i<E; i++){
            st = new StringTokenizer(br.readLine());
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());
            int w = Integer.parseInt(st.nextToken());
            EDGE e = new EDGE(a, b, w);

            edges[i] = e;
        }

        Arrays.sort(edges, new Comparator<EDGE>() {
            @Override
            public int compare(EDGE o1, EDGE o2) {
                return Long.compare(o1.weight, o2.weight);
            }
        });
        int edgeCount = 0;
        long minValue = 0;

        for (EDGE e : edges){
            int a = e.src;
            int b = e.dst;
            long w = e.weight;

            if(union(a, b)){
                edgeCount++;
                minValue += w;
                if(edgeCount >= V-1)break;
            }
        }
        return minValue;
    }
    static long solution_minimum_spanning_tree_v2(BufferedReader br) throws IOException{
        StringTokenizer st = new StringTokenizer(br.readLine());

        V = Integer.parseInt(st.nextToken());
        E = Integer.parseInt(st.nextToken());
        List<List<int[]>> adj = new ArrayList<>();
        for(int i = 0; i<V; i++){
            adj.add(new ArrayList<>());
        }
        for(int i = 0; i<E; i++){
            st = new StringTokenizer(br.readLine());
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());
            int w = Integer.parseInt(st.nextToken());
            a--; b--;
            adj.get(a).add(new int[]{b, w});
            adj.get(b).add(new int[]{a, w});
        }
        boolean[] visited = new boolean[V];
        long[] minDist = new long[V];
        for(int i = 0; i<V; i++){
            minDist[i] = Long.MAX_VALUE;
        }
        minDist[0] = 0;

        long ret = 0;
        for(int t = 0; t < V; t++){
            long best = Long.MAX_VALUE;
            int idx = -1;
            for(int i = 0; i<V; i++){
                if(visited[i])continue;
                if(minDist[i] < best){
                    best = minDist[i];
                    idx = i;
                }
            }

            visited[idx] = true;
            minDist[idx] = best;
            ret += best;


            for(int[] nxt_node : adj.get(idx)){
                int nxt = nxt_node[0];
                if(visited[nxt])continue;
                minDist[nxt] = Math.min(minDist[nxt], nxt_node[1]);
            }
        }
        return ret;
    }
    static long solution_minimum_spanning_tree(BufferedReader br) throws IOException{
        StringTokenizer st = new StringTokenizer(br.readLine());

        V = Integer.parseInt(st.nextToken());
        E = Integer.parseInt(st.nextToken());
        List<List<int[]>> adj = new ArrayList<>();
        for(int i = 0; i<V; i++){
            adj.add(new ArrayList<>());
        }
        for(int i = 0; i<E; i++){
            st = new StringTokenizer(br.readLine());
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());
            int w = Integer.parseInt(st.nextToken());
            a--; b--;
            adj.get(a).add(new int[]{b, w});
            adj.get(b).add(new int[]{a, w});
        }

        boolean[] visited = new boolean[V];
        long[] minDist = new long[V];

        for(int i = 0; i<V; i++){
            minDist[i] = Long.MAX_VALUE;
        }
        minDist[0] = 0;
        long ret = 0;

        PriorityQueue<int[]>pq = new PriorityQueue<>(new Comparator<int[]>() {
            @Override
            public int compare(int[] o1, int[] o2) {
                return Integer.compare(o1[0], o2[0]);
            }
        });
        pq.add(new int[]{0, 0});
        int loop_cnt = 0;
        while(!pq.isEmpty() && loop_cnt < V){
            int[] cur_node = pq.poll();
            int cur = cur_node[1];
            int cost = cur_node[0];
            if(visited[cur])continue;
            visited[cur] = true;
            ret += cost;
            loop_cnt++;

            for(int[] nxt_node : adj.get(cur)){
                int nxt = nxt_node[0];
                int weight = nxt_node[1];
                if(visited[nxt])continue;
                pq.add(new int[]{weight, nxt});
            }
        }


        return ret;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int T = Integer.parseInt(br.readLine());

        for(int test_case = 1; test_case <= T; test_case++)
        {

            System.out.println("#" + test_case + " " + solution_minimum_spanning_tree(br));
            //bw.write("#" + test_case + " " + solution_working_order(br) + "\n");
            //bw.flush();

        }
    }

}
/*
1
3 3
1 2 1
2 3 2
1 3 3
 */
