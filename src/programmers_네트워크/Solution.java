package programmers_네트워크;
import java.util.*;

public class Solution {

    private void dfs(int now, boolean[] visited, int[][] computers) {
        int n = visited.length;
        visited[now] = true;
        for (int i = 0; i < n; i++) {
            if (computers[now][i] == 1 && !visited[i]) {
                visited[i] = true;
                dfs(i, visited, computers);
            }
        }
    }

    private boolean isAllCheck(boolean[] visited) {
        for (boolean v : visited) {
            if (!v)
                return false;
        }
        return true;
    }

    public int solution(int n, int[][] computers) {
        int answer = 0;
        boolean[] visited = new boolean[n];
        while (!isAllCheck(visited)) {
            for (int i = 0; i < n; i++) {
                if (!visited[i]) {
                    answer++;
                    dfs(i, visited, computers);
                }
            }
        }

        System.out.println(answer); // test

        return answer;
    }
}
