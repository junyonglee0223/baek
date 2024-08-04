package programmers_순위;
import java.util.ArrayList;
import java.util.List;

public class Solution {
    public static int dfsGraph(int now, boolean[] visited, List<List<Integer>> graph) {
        int ret = 0;
        for (int ele : graph.get(now)) {
            if (!visited[ele]) {
                visited[ele] = true;
                ret += (1 + dfsGraph(ele, visited, graph));
            }
        }
        return ret;
    }

    public static int solution(int n, int[][] results) {
        int answer = 0;
        List<List<Integer>> graph = new ArrayList<>();
        List<List<Integer>> revGraph = new ArrayList<>();

        for (int i = 0; i <= n; i++) {
            graph.add(new ArrayList<>());
            revGraph.add(new ArrayList<>());
        }

        for (int[] ele : results) {
            graph.get(ele[0]).add(ele[1]);
            revGraph.get(ele[1]).add(ele[0]);
        }

        for (int i = 1; i <= n; i++) {
            boolean[] visited = new boolean[n + 1];
            int straight = dfsGraph(i, visited, graph);
            visited = new boolean[n + 1];
            int reverse = dfsGraph(i, visited, revGraph);
            if (straight + reverse == n - 1) {
                answer++;
            }
        }

        return answer;
    }
}
