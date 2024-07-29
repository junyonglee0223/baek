package programmers_전력망을_둘로_나누기;

import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;

public class Solution {

    private List<List<Integer>> graph;
    private int N;

    private int calcNodeCnt(int node1, int node2) {
        Queue<Integer> q = new LinkedList<>();
        List<Integer> node1Group = new ArrayList<>();
        List<Integer> node2Group = new ArrayList<>();
        boolean[] visited = new boolean[N + 1];

        visited[node1] = true;
        visited[node2] = true;

        node1Group.add(node1);
        q.offer(node1);

        while (!q.isEmpty()) {
            int cur = q.poll();
            for (int nxt : graph.get(cur)) {
                if (!visited[nxt]) {
                    visited[nxt] = true;
                    q.offer(nxt);
                    node1Group.add(nxt);
                }
            }
        }

        node2Group.add(node2);
        q.offer(node2);
        while (!q.isEmpty()) {
            int cur = q.poll();
            for (int nxt : graph.get(cur)) {
                if (!visited[nxt]) {
                    visited[nxt] = true;
                    q.offer(nxt);
                    node2Group.add(nxt);
                }
            }
        }

        return Math.abs(node1Group.size() - node2Group.size());
    }
    public int solution(int n, int[][] wires) {
        int answer = -1;

        N = n;
        graph = new ArrayList<>(N + 1);
        for (int i = 0; i <= N; i++) {
            graph.add(new ArrayList<>());
        }

        for (int[] wire : wires) {
            int src = wire[0];
            int dst = wire[1];
            graph.get(src).add(dst);
            graph.get(dst).add(src);
        }

        answer = N;

        for (int[] wire : wires) {
            int n1 = wire[0];
            int n2 = wire[1];
            int ret = calcNodeCnt(n1, n2);
            answer = Math.min(answer, ret);
        }

        return answer;
    }
}
