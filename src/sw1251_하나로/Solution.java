package sw1251_하나로;
//:building_construction: SW1251_Hanaro_이준용.java

import java.io.*;
import java.util.*;

public class Solution {
    static class VTX{
        int idx, x, y;
        VTX(int idx, int x, int y){
            this.idx = idx;
            this.x = x;
            this.y = y;
        }
    };
    static class ROAD{
        VTX v1, v2;
        long weight;
        ROAD(VTX v1, VTX v2){
            this.v1 = v1;
            this.v2 = v2;
            long dist_x = v1.x - v2.x;
            long dist_y = v1.y - v2.y;
            this.weight = (dist_x * dist_x + dist_y*dist_y);
        }
    };

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
    static int V;
    static double RATE;
    static int[] parents;
    static int[] ranks;

    static VTX[] vertexes;
    static List<ROAD> roads;

    static long solution_Hanaro(BufferedReader br) throws IOException{
        StringTokenizer st;
        V = Integer.parseInt(br.readLine());
        vertexes = new VTX[V];
        parents = new int[V];
        ranks = new int[V];
        roads = new ArrayList<>();

        int[] input_x = new int[V];
        int[] input_y = new int[V];
        st = new StringTokenizer(br.readLine());
        for(int i =0 ; i<V; i++){
            input_x[i] = Integer.parseInt(st.nextToken());
        }
        st = new StringTokenizer(br.readLine());
        for(int i =0 ; i<V; i++){
            input_y[i] = Integer.parseInt(st.nextToken());
        }

        for(int i = 0; i<V; i++){
            int x = input_x[i];
            int y = input_y[i];

            VTX v = new VTX(i, x, y);
            vertexes[i] = v;

            parents[i] = i;
            ranks[i] = 0;
        }
        RATE = Double.parseDouble(br.readLine());

        for(int i = 0; i<V; i++){
            for(int j = i+1; j<V; j++){
                roads.add(new ROAD(vertexes[i], vertexes[j]));
            }
        }
        Collections.sort(roads, new Comparator<ROAD>() {
            @Override
            public int compare(ROAD o1, ROAD o2) {
                return Long.compare(o1.weight, o2.weight);
            }
        });

        int edgeCount = 0;
        long minCost = 0;
        for(ROAD r : roads){
            VTX v1 = r.v1;
            VTX v2 = r.v2;

            if(union(v1.idx, v2.idx)){
                edgeCount++;
                minCost += r.weight;
                if(edgeCount >= V-1)break;
            }
        }
        return Math.round(minCost * RATE);
    }

    /// /////////////////////////////////////////////////////////////////////////////
    static long get_dist(int i, int j){
        long dist_x = pnt[i][0]- pnt[j][0];
        long dist_y = pnt[i][1] - pnt[j][1];
        return (dist_x * dist_x + dist_y*dist_y);
    }
    static long[][] pnt;
    static long solution_Hanaro_v1(BufferedReader br) throws IOException{
        StringTokenizer st;
        V = Integer.parseInt(br.readLine());
        pnt = new long[V][2];

        st = new StringTokenizer(br.readLine());
        for(int i =0 ; i<V; i++){
            pnt[i][0] = Integer.parseInt(st.nextToken());
        }
        st = new StringTokenizer(br.readLine());
        for(int i =0 ; i<V; i++){
            pnt[i][1] = Integer.parseInt(st.nextToken());
        }
        RATE = Double.parseDouble(br.readLine());

        long [] minDist = new long[V];
        for(int i = 0; i<V; i++)
            minDist[i] = Long.MAX_VALUE;
        boolean[] visited = new boolean[V];
        long ret = 0;

        minDist[0] = 0;

        for(int i = 0; i<V; i++){
            long best = Long.MAX_VALUE;
            int idx = -1;

            for(int j = 0; j<V; j++){
                if(visited[j])continue;

                if(minDist[j] < best){
                    best = minDist[j];
                    idx = j;
                }
            }
            visited[idx] = true;
            ret += best;

            for(int j = 0; j<V; j++){
                if(visited[j])continue;
                minDist[j] = Math.min(minDist[j], get_dist(idx, j));
            }
        }
        return Math.round(ret * RATE);
    }
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int T = Integer.parseInt(br.readLine());

        for(int test_case = 1; test_case <= T; test_case++)
        {

            System.out.println("#" + test_case + " " + solution_Hanaro_v1(br));
            //System.out.println("#" + test_case + " " + solution_Hanaro(br));
            //bw.write("#" + test_case + " " + solution_working_order(br) + "\n");
            //bw.flush();

        }
    }
}
/*
10
2
0 0
0 100
1.0
4
0 0 400 400
0 100 0 100
1.0
6
0 0 400 400 1000 2000
0 100 0 100 600 2000
0.3
9
567 5 45674 24 797 29 0 0 0
345352 5464 145346 54764 5875 0 3453 4545 123
0.0005
 */