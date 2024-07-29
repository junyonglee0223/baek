package programmers_전력망을_둘로_나누기;

import java.util.*;

public class TestSolution {
    public static void main(String[] args) {
        Solution sol = new Solution();

        // 테스트 케이스 1
        int n1 = 9;
        int[][] wires1 = {
                {1, 3},
                {2, 3},
                {3, 4},
                {4, 5},
                {4, 6},
                {4, 7},
                {7, 8},
                {7, 9}
        };
        System.out.println("테스트 1 결과: " + sol.solution(n1, wires1)); // Expected output: 3

        // 테스트 케이스 2
        int n2 = 4;
        int[][] wires2 = {
                {1, 2},
                {2, 3},
                {3, 4}
        };
        System.out.println("테스트 2 결과: " + sol.solution(n2, wires2)); // Expected output: 0

        // 테스트 케이스 3
        int n3 = 7;
        int[][] wires3 = {
                {1, 2},
                {2, 7},
                {3, 7},
                {3, 4},
                {4, 5},
                {6, 7}
        };
        System.out.println("테스트 3 결과: " + sol.solution(n3, wires3)); // Expected output: 1
    }
}
