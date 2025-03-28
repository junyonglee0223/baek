package g2458;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

public class Main {
    static int N, M;
    static List<List<Integer>> adj;
    static List<List<Integer>> revAdj;
    static List<List<Integer>> parents;
    static List<List<Integer>> children;

    static void dfs_adj(int now, boolean[] visited, List<Integer>trace){
        for(int nxt : adj.get(now)){
            if(visited[nxt]) continue;
            visited[nxt] = true;
            trace.add(nxt);
            dfs_adj(nxt, visited, trace);
        }
    }

    static void solution_height_order(BufferedReader br) throws IOException {
        StringTokenizer st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());

        adj = new ArrayList<>(N);
        revAdj = new ArrayList<>(N);
        parents = new ArrayList<>(N);
        children = new ArrayList<>(N);

        for(int i = 0; i<N; i++){
            adj.add(new ArrayList<>());
            revAdj.add(new ArrayList<>());
            parents.add(new ArrayList<>());
            children.add(new ArrayList<>());
        }

        for(int i = 0; i<M; i++){
            st = new StringTokenizer(br.readLine());
            int a = Integer.parseInt(st.nextToken()) - 1;
            int b = Integer.parseInt(st.nextToken()) - 1;
            adj.get(a).add(b);
            revAdj.get(b).add(a);
        }

        for(int i = 0; i<N; i++){
            boolean[] visited = new boolean[N];
            visited[i] = true;
            dfs_adj(i, visited, children.get(i));
        }

        for(int i = 0; i<N; i++){
            for(int ele : children.get(i)){
                parents.get(ele).add(i);
            }
        }

        int answer = 0;
        for(int i = 0; i<N; i++){
            if(parents.get(i).size() + children.get(i).size() == N-1)
                answer++;
        }
        System.out.println(answer);
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        solution_height_order(br);

//        int T = Integer.parseInt(br.readLine());
//        while(T-- > 0){
//            solution_height_order(br);
//        }
    }
}


/*
3
6 6
1 5
3 4
5 4
4 2
4 6
5 2
6 7
1 3
1 5
3 4
5 4
4 2
4 6
5 2
6 3
1 2
2 3
4 5
*/
/*
1
2
0
*/
