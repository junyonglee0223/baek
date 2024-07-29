package programmers_도넛과_막대_그래프;

import java.util.Arrays;

public class TestSolution {
    public static void main(String[] args) {
        Solution sol = new Solution();

        int[][] edges1 = {{2, 3}, {4, 3}, {1, 1}, {2, 1}};
        System.out.println(Arrays.toString(sol.solution(edges1))); // [2, 1, 1, 0]

        int[][] edges2 = {
                {4, 11}, {1, 12}, {8, 3}, {12, 7}, {4, 2}, {7, 11}, {4, 8}, {9, 6}, {10, 11},
                {6, 10}, {3, 5}, {11, 1}, {5, 3}, {11, 9}, {3, 8}
        };
        System.out.println(Arrays.toString(sol.solution(edges2))); // [4, 0, 1, 2]
    }
}
