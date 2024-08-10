package programmers_징검다리;

import java.util.Arrays;
import java.util.List;
import java.util.stream.Collectors;

public class Solution {

    boolean isPosDist(int d, List<Integer>rocks, int n){
        int removeDist = 0;
        int prev = 0;
        for (Integer rock : rocks) {
            if (rock - prev < d) {
                removeDist++;
            } else {
                prev = rock;
            }
        }
        return removeDist <= n;
    }

    Long findMinDist(List<Integer> rocks, int distance, int n){
        long left = 1;
        long right = distance;
        while(left <= right){
            long mid = (left + right)/2;
            //파라미터 타입이 다름 수정해야 한다.
            if(isPosDist((int)mid, rocks, n)){
                left = mid + 1;
            }
            else{
                right = mid - 1;
            }
        }
        return right;
    }

    public int solution(int distance, int[] rocks, int n) {
        int answer = 0;
        //Arrays.sort(rocks);
        List<Integer> rockList = Arrays.stream(rocks).sorted().boxed().collect(Collectors.toList());
        rockList.add(distance);
        long answerLong = findMinDist(rockList, distance, n);

        return answer = (int)answerLong;
    }
}