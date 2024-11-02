//최소 스패닝 트리
package g1197;

import java.util.*;

public class Main {

    static List<List<Edge>>graph;
    static int V, E;
    static class Edge{
        private int dst;
        private int dist;
        public Edge(int dst, int dist){
            this.dst = dst;
            this.dist = dist;
        }
    }

    public static void main(String[] args){
        Scanner scanner = new Scanner(System.in);
        V = scanner.nextInt();
        E = scanner.nextInt();

        graph = new ArrayList<>(V+1);
        for(int i = 0; i<=V; i++)
            graph.add(new ArrayList<>());

        for(int i = 0; i<E; i++){
            int a, b, c;
            a = scanner.nextInt();
            b = scanner.nextInt();
            c = scanner.nextInt();
            Edge e1 = new Edge(b, c);
            graph.get(a).add(e1);

            Edge e2 = new Edge(a, c);
            graph.get(b).add(e2);
        }

        //List<Boolean>visited = new ArrayList<>();
        boolean[] visited = new boolean[V+1];
        //edge's dist 기준 오름차순
        //WARN comparator 사용하면 메모리 초과 발생한다.
//        PriorityQueue<Edge>pq = new PriorityQueue<>(
//                Comparator.comparing((Edge e) -> (e.dist))
//        );
        PriorityQueue<Edge>pq = new PriorityQueue<>(
                (e1, e2) -> Integer.compare(e1.dist , e2.dist)
        );

        pq.add(new Edge(1, 0));

        int totalDist = 0;
        int edgeUsed = 0;

        while(!pq.isEmpty() && edgeUsed < V){
            Edge nowEdge = pq.poll();
            int now = nowEdge.dst;
            int nowDist = nowEdge.dist;

            if(visited[now])continue;
            visited[now] = true;
            totalDist += nowDist;
            edgeUsed++;

            for(Edge e : graph.get(now)){
                if(visited[e.dst])continue;
                pq.add(new Edge(e.dst, e.dist));
            }
        }
        System.out.println(totalDist);
    }
}
