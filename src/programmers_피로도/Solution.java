package programmers_피로도;

import java.util.*;
public class Solution {

    private int dfs(int k, boolean[] visited, int[][] dungeons, int cnt) {
        int ret = 0;
        boolean flag = false;
        for (int i = 0; i < dungeons.length; i++) {
            if (dungeons[i][0] <= k && !visited[i]) {
                visited[i] = true;
                flag = true;
                ret = Math.max(ret, dfs(k - dungeons[i][1], visited, dungeons, cnt + 1));
                visited[i] = false;
            }
        }
        if (!flag) return cnt;
        return ret;
    }

    public int solution(int k, int[][] dungeons) {
        int answer = -1;
        boolean[] visited = new boolean[dungeons.length];
        answer = dfs(k, visited, dungeons, 0);
        return answer;
    }

//    public static void main(String[] args) {
//        Solution sol = new Solution();
//        int k = 80;
//        int[][] dungeons = {{80, 20}, {50, 40}, {30, 10}};
//        System.out.println(sol.solution(k, dungeons)); // Expected output: 3
//    }
}
