package g3055_탈출;
//:safety_vest: JUN3055_Escape_이준용.java

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.ArrayDeque;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {
    static int[] dx = {1, 0, -1, 0};
    static int[] dy = {0, 1, 0, -1};
    static boolean is_range(int x, int y, int R, int C){
        return x >= 0 && x < R && y >= 0 && y < C;
    }
    static String solution_escape(BufferedReader br) throws Exception{
        StringTokenizer st = new StringTokenizer(br.readLine());
        int R = Integer.parseInt(st.nextToken());
        int C = Integer.parseInt(st.nextToken());

        Character[][] init_board = new Character[R][C];
        int[][]board = new int[R][C];
        int[][] w_board = new int[R][C];
        boolean[][] visited = new boolean[R][C];

        int s_x = 0, s_y = 0, g_x = R-1, g_y = C-1;
        int w_x = 0, w_y = 0;

        Queue<int[]>que = new ArrayDeque<>();

        for(int i = 0; i<R; i++){
            for(int j = 0; j<C; j++){
                w_board[i][j] = -1 * Integer.MAX_VALUE;
            }
        }

        for(int i = 0; i<R; i++){
            String tmp = br.readLine();
            for(int j = 0; j<C; j++){
                init_board[i][j] = tmp.charAt(j);
                if(tmp.charAt(j) == '*'){
                    que.add(new int[]{i, j});
                    w_board[i][j] = 0;
                    visited[i][j] = true;
                }
                else if(tmp.charAt(j) == 'S'){
                    s_x = i;
                    s_y = j;
                }
                else if(tmp.charAt(j) == 'D'){
                    g_x = i;
                    g_y = j;
                }
            }
        }

        while(!que.isEmpty()){
            int cur_x = que.peek()[0];
            int cur_y = que.peek()[1];
            que.poll();
            for(int d = 0; d<4; d++){
                int nxt_x = cur_x + dx[d];
                int nxt_y = cur_y + dy[d];
                if(!is_range(nxt_x, nxt_y, R, C)
                        || visited[nxt_x][nxt_y]
                        || init_board[nxt_x][nxt_y] == 'X')continue;
                if(nxt_x == g_x && nxt_y == g_y)continue;
                visited[nxt_x][nxt_y] = true;
                w_board[nxt_x][nxt_y] = w_board[cur_x][cur_y] - 1;
                que.add(new int[]{nxt_x, nxt_y});
            }
        }

        for(int i = 0; i<R; i++){
            for(int j = 0; j<C; j++){
                visited[i][j] = false;
            }
        }

        visited[s_x][s_y] = true;
        que.add(new int[]{s_x, s_y});
        while(!que.isEmpty()){
            int cur_x = que.peek()[0];
            int cur_y = que.peek()[1];
            que.poll();
            for(int d = 0; d<4; d++){
                int nxt_x = cur_x + dx[d];
                int nxt_y = cur_y + dy[d];
                if(!is_range(nxt_x, nxt_y, R, C)
                        || visited[nxt_x][nxt_y]
                        || init_board[nxt_x][nxt_y] == 'X')continue;

                //비버는 합이 음수인 곳만 이동 가능
                if(board[cur_x][cur_y] + 1 + w_board[nxt_x][nxt_y] >= 0)continue;
                visited[nxt_x][nxt_y] = true;
                board[nxt_x][nxt_y] = board[cur_x][cur_y] + 1;
                que.add(new int[]{nxt_x, nxt_y});
            }
        }
        if(board[g_x][g_y] == 0)return "KAKTUS";
        return Integer.toString(board[g_x][g_y]);

    }
    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        /// /////////////////////////////////////////////////
//        int T = Integer.parseInt(br.readLine());
//
//        for(int test_case = 1; test_case <= T; test_case++)
//        {
//            String ret = solution_escape(br);
//            System.out.println("#" + test_case + " " + ret);
//
//        }

        /// /////////////////////////////////////////////////
        System.out.println(solution_escape(br));


    }
}
/*
이동하는데 물과 동시에 이동하게 된다.
물 먼저 이동 -> 비버 이동
water을 음수로 전체 계산 하고 이후 비버가 이동하는 방식으로 구현
동시에 해도 문제는 없는데 사이즈 크지 않아서 음수 value로 설정
초기화 반드시 해야 물이 오지 않는 경우 해결됨


 */
/*
4
3 3
D.*
...
.S.
3 3
D.*
...
..S
3 6
D...*.
.X.X..
....S.
5 4
.D.*
....
..X.
S.*.
....

 */
/*
3
KAKTUS
6
4
 */