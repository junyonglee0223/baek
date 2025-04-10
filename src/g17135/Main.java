package g17135;
//g17135 캐슬 디펜스

import java.util.Arrays;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

public class Main {
    static int[] dx = {1, 0, -1, 0};
    static int[] dy = {0, -1, 0, 1};

    static boolean is_range(int x, int y, int n, int m){
        return x >= 0 && x < n && y >= 0 && y < m;
    }

    static int[] find_min_pos(int x, int[][] board, int D){
        int n = board.length;
        int m = board[0].length;
        if(board[n-1][x] == 1)return new int[]{n-1, x};

        Queue<int[]>q = new LinkedList<>();
        int[][] dist_board = new int[n][m];
        for(int[] row : dist_board) Arrays.fill(row, -1);

        dist_board[n-1][x] = 1;
        q.offer(new int[]{n-1, x});

        while(!q.isEmpty()){
            int[] cur = q.poll();
            int cx = cur[0];
            int cy = cur[1];

            for(int d = 1; d < 4; d++){
                int nx = cx + dx[d];
                int ny = cy + dy[d];
                if(!is_range(nx, ny, n, m))continue;
                if(dist_board[nx][ny] >= 0)continue;

                dist_board[nx][ny] = dist_board[cx][cy] + 1;
                if(dist_board[nx][ny] > D)continue;

                if(board[nx][ny] == 1){
                    return new int[]{nx, ny};
                }
                q.offer(new int[]{nx, ny});
            }
        }
        return new int[]{-1, -1};
    }
    static int find_max_count(int x, int y, int z, int[][] board, int D){
        int ret = 0;

        int n = board.length;
        int m = board[0].length;
        for(int i = n-1; i>=0; i--){
            int[] px = find_min_pos(x, board, D);
            int[] py = find_min_pos(y, board, D);
            int[] pz = find_min_pos(z, board, D);

            if(px[0] != -1 && board[px[0]][px[1]] == 1){
                board[px[0]][px[1]] = 0;
                ret++;
            }
            if(py[0] != -1 && board[py[0]][py[1]] == 1){
                board[py[0]][py[1]] = 0;
                ret++;
            }
            if(pz[0] != -1 && board[pz[0]][pz[1]] == 1){
                board[pz[0]][pz[1]] = 0;
                ret++;
            }

            for(int r = n-1; r > 0; r--){
                board[r] = Arrays.copyOf(board[r-1], m);
            }
            Arrays.fill(board[0], 0);
        }
        return ret;
    }

    static void solution_castle_defence(Scanner sc){
        int n, m, d;
        n = sc.nextInt();
        m = sc.nextInt();
        d = sc.nextInt();
        sc.nextLine();

        int[][] board = new int[n][m];

        for(int i = 0; i<n; i++){
            String[] line = sc.nextLine().split(" ");
            for(int j = 0; j<m; j++){
                board[i][j] = Integer.parseInt(line[j]);
            }
        }

        int answer = 0;
        for(int i = 0; i<m; i++){
            for(int j = i+1; j<m; j++){
                for(int k = j+1; k<m; k++){
                    int[][] tmp_board = new int[n][m];
                    for(int r = 0; r < n; r++){
                        tmp_board[r] = Arrays.copyOf(board[r], m);
                    }

                    answer = Math.max(answer, find_max_count(i, j, k, tmp_board, d));
                }
            }
        }
        System.out.println(answer);
    }
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);

        solution_castle_defence(sc);

//        int T = Integer.parseInt(sc.nextLine());
//        while(T-- > 0){
//            solution_castle_defence(sc);
//        }
    }
}
/*
6
5 5 1
0 0 0 0 0
0 0 0 0 0
0 0 0 0 0
0 0 0 0 0
1 1 1 1 1
5 5 1
0 0 0 0 0
0 0 0 0 0
0 0 0 0 0
1 1 1 1 1
0 0 0 0 0
5 5 2
0 0 0 0 0
0 0 0 0 0
0 0 0 0 0
1 1 1 1 1
0 0 0 0 0
5 5 5
1 1 1 1 1
1 1 1 1 1
1 1 1 1 1
1 1 1 1 1
1 1 1 1 1
6 5 1
1 0 1 0 1
0 1 0 1 0
1 1 0 0 0
0 0 0 1 1
1 1 0 1 1
0 0 1 0 0
6 5 2
1 0 1 0 1
0 1 0 1 0
1 1 0 0 0
0 0 0 1 1
1 1 0 1 1
0 0 1 0 0
*/
/*
3
3
5
15
9
14
*/