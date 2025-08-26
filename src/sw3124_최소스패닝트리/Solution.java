package sw3124_최소스패닝트리;
//:mag: SW3124_MST_이준용.java

import java.io.*;
import java.util.Arrays;
import java.util.Comparator;
import java.util.StringTokenizer;

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

    static long solution_minimum_spanning_tree(BufferedReader br) throws IOException{
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
