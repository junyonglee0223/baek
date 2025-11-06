package g32628;

import java.io.*;
import java.util.*;

public class Main {

    static long solution_two_stack(BufferedReader br) throws Exception {
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int k = Integer.parseInt(st.nextToken());

        int[] back1 = new int[n];
        int[] back2 = new int[n];

        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < n; i++) {
            back1[i] = Integer.parseInt(st.nextToken());
        }

        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < n; i++) {
            back2[i] = Integer.parseInt(st.nextToken());
        }

        int[] suffix1 = new int[n + 1];
        int[] suffix2 = new int[n + 1];

        for (int i = 1; i <= n; i++) {
            suffix1[i] = suffix1[i - 1] + back1[n - i];
            suffix2[i] = suffix2[i - 1] + back2[n - i];
        }

        int total1 = suffix1[n];
        int total2 = suffix2[n];
        int answer = Integer.MAX_VALUE;

        for (int i = 0; i <= Math.min(n, k); i++) {
            int j = Math.min(n, k - i);
            int rem1 = total1 - suffix1[i];
            int rem2 = total2 - suffix2[j];
            int wonbin = Math.max(rem1, rem2);
            answer = Math.min(answer, wonbin);
        }

        return answer;
    }

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        System.out.println(solution_two_stack(br));
    }
}
