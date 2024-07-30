package programmers_피로도;

public class TestSolution {
    public static void main(String args[]){
        Solution sol = new Solution();
        int k1 = 80;
        int[][] dungeons1 = {
                {80, 20},
                {50, 40},
                {30, 10}
        };
        System.out.println(sol.solution(k1, dungeons1));
    }
}
