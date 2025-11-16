import java.io.*;
import java.util.*;

public class Main {

    static class Node {
        int s, l, o; 

        Node(int s, int l, int o) {
            this.s = s;
            this.l = l;
            this.o = o;
        }
    }

    static int N, K;
    static long G;
    static Node[] nodes;
    static long[] temp; 

    static boolean canEat(int day) {
        long total = 0;
        int idx = 0;
        int removable = K;  // K 값을 지역 변수로 복사

        for (int i = 0; i < N; i++) {
            Node cur = nodes[i];
            long mul = Math.max(1L, (long) day - cur.l);
            long bacteria = (long) cur.s * mul;

            if (cur.o == 1) {
                temp[idx++] = bacteria;
            }
            total += bacteria;
        }

        if (total <= G) {
            return true;
        }

        if (removable == 0) {
            return false;
        }

        Arrays.sort(temp, 0, idx);

        for (int i = idx - 1; i >= 0 && removable > 0; i--, removable--) {
            total -= temp[i];
            if (total <= G) {
                return true;
            }
        }

        return total <= G;
    }


    static int solution_seongsipdang_meal_kit(BufferedReader br) throws Exception {
        StringTokenizer st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        G = Long.parseLong(st.nextToken());
        K = Integer.parseInt(st.nextToken());

        nodes = new Node[N];
        temp = new long[N];

        int removableCount = 0;

        for (int i = 0; i < N; i++) {
            st = new StringTokenizer(br.readLine());
            int s = Integer.parseInt(st.nextToken());
            int l = Integer.parseInt(st.nextToken());
            int o = Integer.parseInt(st.nextToken());
            nodes[i] = new Node(s, l, o);
            if (o == 1) removableCount++;
        }

        if (K > removableCount) {
            K = removableCount;
        }

        int left = 0;
        int right = 2000000000;
        int ans = 0;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (canEat(mid)) {
                ans = mid;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        return ans;
    }

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int result = solution_seongsipdang_meal_kit(br);
        System.out.println(result);
    }
}

/*
n,g,k
n은 2*10^5까지 존재한다.
g마리 이하면 가능 상태 10^9 이하
k는 n 미만이고 필요없는 거 최대한 삭제가 가능하다.
k, O(0) 최소 개수가 k로 될 것 같다.

s, l, o
10^9 이하의 정수들이며
s는 속도
l은 증식 시작 직전
max(1, x - L) 형태임

최대 몇일 후까지 가능한지 판단
이진 탐색으로 구할 건데 문제는 각각의 일마다 가능한지
여부를 판단해야 함

더 빠른 방법이 가능한지???
노드로 계속 정렬해야 하는데 
O(lg(N))이 계속 돌아갈 듯힘


 */
/*
3
4 36 0
2 14 1
3 8 1
5 12 1
7 10 0

4 36 1
2 14 1
3 8 1
5 12 1
7 10 0

4 36 2
2 14 1
3 8 1
5 12 1
7 10 0
 */
/*
12
13
14
 */
