package sw1238_Contact;
//:loud_sound: SW1238_Contact_이준용.java

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.*;


class Solution {
    static final int MAX_N = 101;

    static int solution_contact(BufferedReader br) throws Exception {
        int ret = 0;
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int start = Integer.parseInt(st.nextToken());

        int[][] adj = new int[MAX_N][MAX_N];
        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < n / 2; i++) {
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());
            adj[a][b] = 1;
        }

        Queue<int[]> q = new LinkedList<>();
        List<Integer> visited = new ArrayList<>();
        int[] time_cnt = new int[MAX_N];
        int total_cnt = 0;

        q.offer(new int[] { 1, start });
        time_cnt[start] = 1;
        visited.add(start);

        while (!q.isEmpty()) {
            int[] cur_p = q.poll();
            int cur = cur_p[1];
            int cur_cnt = cur_p[0];

            for (int nxt = 1; nxt < MAX_N; nxt++) {
                if (!visited.contains(nxt) && adj[cur][nxt] == 1) {
                    visited.add(nxt);
                    time_cnt[nxt] = cur_cnt + 1;
                    total_cnt = Math.max(total_cnt, time_cnt[nxt]);
                    q.offer(new int[] { cur_cnt + 1, nxt });
                }
            }
        }

        int max_ret = 0;
        for (int i = 1; i < MAX_N; i++) {
            if (time_cnt[i] == total_cnt) {
                max_ret = Math.max(max_ret, i);
            }
        }

        return max_ret;
    }

    public static void main(String args[]) throws Exception {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int T = 10;

        for (int test_case = 1; test_case <= T; test_case++) {

            int ret = solution_contact(br);
            System.out.print("#" + test_case);
            System.out.println(" " + ret);
        }
    }
}