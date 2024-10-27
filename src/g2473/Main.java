package g2473;

import java.util.*;

public class Main {

    static int N;
    static List<Long> liquid;

    static Long liquidSum;
    static List<Long> liquidList;

    public static void findCloseIdx(int idx){
        int start = idx + 1;
        int end = N-1;

        while(start < end){
            Long tmpSum = liquid.get(idx) + liquid.get(start) + liquid.get(end);

            if(Math.abs(tmpSum) < Math.abs(liquidSum)){
                liquidSum = tmpSum;
                liquidList.set(0, liquid.get(idx));
                liquidList.set(1, liquid.get(start));
                liquidList.set(2, liquid.get(end));
            }
            if(tmpSum < 0){
                start++;
            }
            else{
                end--;
            }
        }
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        liquid = new ArrayList<>();
        N = scanner.nextInt();

        // 최소 합을 큰 값으로 초기화
        liquidSum = Long.MAX_VALUE;
        liquidList = new ArrayList<>(Arrays.asList(0L, 0L, 0L));  // 크기 3의 리스트 초기화

        for (int i = 0; i < N; i++) {
            long ele = scanner.nextLong();
            liquid.add(ele);
        }
        liquid.sort(Comparator.naturalOrder());

        for (int i = 0; i < N - 2; i++) {
            findCloseIdx(i);
        }

        for (Long ele : liquidList) {
            System.out.print(ele + " ");
        }
    }
}

/*
* 예제 입력 1
5
-2 6 -97 -6 98
예제 출력 1
-97 -2 98
예제 입력 2
7
-2 -3 -24 -6 98 100 61
예제 출력 2
-6 -3 -2
* */

