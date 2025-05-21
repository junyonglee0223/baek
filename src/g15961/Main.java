package g15961;
//g15961 회전초밥
import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        int N = scanner.nextInt(); // 접시의 수
        int D = scanner.nextInt(); // 초밥의 종류 수
        int K = scanner.nextInt(); // 연속해서 먹는 접시 수
        int C = scanner.nextInt(); // 쿠폰 번호

        List<Integer> plates = new ArrayList<>();
        int[] indexPlate = new int[D + 1];

        for (int i = 0; i < N; i++) {
            plates.add(scanner.nextInt());
        }

        indexPlate[C] = 1; // 쿠폰으로 제공되는 초밥 종류
        int difKindCnt = 1; // 쿠폰 초밥으로 인해 이미 1종류 존재

        // 초기 K개의 접시를 처리
        for (int i = 0; i < K; i++) {
            int plate = plates.get(i);
            if (indexPlate[plate] == 0) {
                difKindCnt++;
            }
            indexPlate[plate]++;
        }

        int answer = difKindCnt;

        // 슬라이딩 윈도우
        for (int start = 0; start < N; start++) {
            int end = (start + K) % N;

            // 윈도우에서 제외되는 접시
            int frontPlate = plates.get(start);
            indexPlate[frontPlate]--;
            if (indexPlate[frontPlate] == 0) {
                difKindCnt--;
            }

            // 윈도우에 추가되는 접시
            int backPlate = plates.get(end);
            if (indexPlate[backPlate] == 0) {
                difKindCnt++;
            }
            indexPlate[backPlate]++;

            // 최대값 갱신
            answer = Math.max(answer, difKindCnt);
        }

        System.out.println(answer);
    }
}

