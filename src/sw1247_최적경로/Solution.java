package sw1247_최적경로;// sw1247 최적 경로
//:package: SW1247_OptimalRoute_이준용.java

import java.io.*;
import java.util.*;

public class Solution {

    static class Dot {
        int x, y;
        Dot(int x, int y) { this.x = x; this.y = y; }
    }

    static Dot[] places;
    static int N;
    static int gx, gy;
    static int best;

    static int dist(Dot a, Dot b) {
        return Math.abs(a.x - b.x) + Math.abs(a.y - b.y);
    }

    static void dfs(int visited, int idx, int cur, int cnt) {
        if (cur >= best) return;

        if (cnt == N) {
            int total = cur + Math.abs(places[idx].x - gx) + Math.abs(places[idx].y - gy);
            if (total < best) best = total;
            return;
        }

        for (int i = 1; i <= N; i++) {
            int bit = 1 << i;
            if ((visited & bit) != 0) continue; // 이미 방문
            int nextCost = cur + dist(places[idx], places[i]);
            dfs(visited | bit, i, nextCost, cnt + 1);
        }
    }

    static int solveOne(BufferedReader br) throws IOException {
        // N
        int n = Integer.parseInt(readToken(br));
        N = n;

        int need = 2 * (N + 2);
        int[] vals = new int[need];
        for (int i = 0; i < need; i++) vals[i] = Integer.parseInt(readToken(br));

        int sx = vals[0], sy = vals[1];
        gx = vals[2]; gy = vals[3];

        places = new Dot[N + 1];
        places[0] = new Dot(sx, sy);
        for (int i = 0; i < N; i++) {
            int x = vals[4 + 2 * i];
            int y = vals[5 + 2 * i];
            places[i + 1] = new Dot(x, y);
        }

        best = Integer.MAX_VALUE;
        dfs(0, 0, 0, 0);
        return best;
    }

    static StringTokenizer st;
    static String readToken(BufferedReader br) throws IOException {
        while (st == null || !st.hasMoreTokens()) {
            String line = br.readLine();
            st = new StringTokenizer(line);
        }
        return st.nextToken();
    }

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int T = Integer.parseInt(readToken(br));
        StringBuilder sb = new StringBuilder();

        for (int tc = 1; tc <= T; tc++) {
            int ans = solveOne(br);
            sb.append('#').append(tc).append(' ').append(ans).append('\n');
        }
        System.out.print(sb.toString());
    }
}
