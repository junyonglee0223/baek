package g12100;

import java.io.*;
import java.util.*;

public class Main {

    static int N;
    static int maxBlock;

    static int[][] rotateBoard(int[][] board) {
        int[][] rotated = new int[N][N];
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                rotated[j][N - 1 - i] = board[i][j]; 
            }
        }
        return rotated;
    }

    static void mergeCompress(int[][] board) {
        for (int i = 0; i < N; i++) {
            int[] line = new int[N];
            int idx = 0;
            for (int j = 0; j < N; j++) {
                int v = board[i][j];
                if (v != 0) line[idx++] = v;
            }

            for (int j = 1; j < idx; j++) {
                if (line[j] == line[j - 1]) {
                    line[j - 1] = line[j - 1] * 2;
                    if (line[j - 1] > maxBlock) maxBlock = line[j - 1];
                    line[j] = 0; 
                }
            }

            int[] merged = new int[N];
            int p = 0;
            for (int j = 0; j < idx; j++) {
                int v = line[j];
                if (v != 0) merged[p++] = v;
            }

            for (int j = 0; j < N; j++) {
                board[i][j] = merged[j];
            }
        }
    }

    static int[][] copyOf(int[][] src) {
        int[][] dst = new int[N][N];
        for (int i = 0; i < N; i++) {
            System.arraycopy(src[i], 0, dst[i], 0, N);
        }
        return dst;
    }

    static void gameProcess(int[][] board, int depth) {
        if (depth == 5) {
            for (int i = 0; i < N; i++) {
                for (int j = 0; j < N; j++) {
                    int v = board[i][j];
                    if (v > maxBlock) maxBlock = v;
                }
            }
            return;
        }

        for (int dir = 0; dir < 4; dir++) {
            int[][] tmp = copyOf(board);

            for (int d = 0; d < dir; d++) tmp = rotateBoard(tmp);
            mergeCompress(tmp);
            int back = (4 - dir) % 4;
            for (int d = 0; d < back; d++) tmp = rotateBoard(tmp);

            gameProcess(tmp, depth + 1);
        }
    }

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        N = Integer.parseInt(br.readLine().trim());
        int[][] board = new int[N][N];

        for (int i = 0; i < N; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            for (int j = 0; j < N; j++) {
                board[i][j] = Integer.parseInt(st.nextToken());
            }
        }

        maxBlock = 0;
        gameProcess(board, 0);
        System.out.println(maxBlock);
    }
}
