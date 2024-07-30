package programmers_도넛과_막대_그래프;

import java.util.Arrays;

public class Solution {
    public int[] solution(int[][] edges) {
        int V = 0;
        for (int[] edge : edges) {
            V = Math.max(V, Math.max(edge[0], edge[1]));
        }
        V++;

        int[] incoming = new int[V];
        int[] outgoing = new int[V];
        for (int[] edge : edges) {
            incoming[edge[1]]++;
            outgoing[edge[0]]++;
        }

        int createdNode = -1;
        for (int i = 1; i < V; i++) {
            if (incoming[i] == 0 && outgoing[i] >= 2) {
                createdNode = i;
                break;
            }
        }

        int totalGraphs = outgoing[createdNode];
        int stickGraphs = 0, cycleGraphs = 0, eightGraphs = 0;

        Arrays.fill(incoming, 0);
        Arrays.fill(outgoing, 0);
        for (int[] edge : edges) {
            if (edge[0] == createdNode || edge[1] == createdNode) continue;
            incoming[edge[1]]++;
            outgoing[edge[0]]++;
        }

        for (int i = 1; i < V; i++) {
            if (i == createdNode) continue;
            if (outgoing[i] == 0) stickGraphs++;
            if (incoming[i] == 2 && outgoing[i] == 2) eightGraphs++;
        }

        cycleGraphs = totalGraphs - stickGraphs - eightGraphs;

        int[] answer = {createdNode, cycleGraphs, stickGraphs, eightGraphs};
        return answer;
    }
}
