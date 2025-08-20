package sw7733_치즈도둑;

//:monocle_face: SW7733_CheeseThief_이준용.java
import java.io.*;
import java.util.Scanner;
import java.util.StringTokenizer;


class Solution
{
    static int[] dx = {1, 0, -1, 0};
    static int[] dy = {0, 1, 0, -1};
    static boolean is_range(int x, int y, int N){
        return x >= 0 && x < N && y >= 0 && y < N;
    }
    static void eating_cheese(int[][] board, int day){
        int N = board.length;
        for(int i = 0;i<N; i++){
            for(int j  = 0; j<N; j++){
                if(board[i][j] <= day){
                    board[i][j] = -1;
                }
            }
        }
    }
    static void dfs_partition(int x, int y, int[][] board, boolean[][] visited){
        int N = board.length;
        visited[x][y] = true;
        for(int d = 0; d<4; d++){
            int nx = x + dx[d];
            int ny = y + dy[d];
            if(!is_range(nx, ny, N) || visited[nx][ny] || board[nx][ny] == -1)continue;
            visited[nx][ny] = true;
            dfs_partition(nx, ny, board, visited);
        }
    }
    static int get_partition_count(int[][] board){
        int N = board.length;
        boolean[][] visited = new boolean[N][N];
        int ret = 0;
        for(int i = 0; i<N; i++){
            for(int j = 0; j<N; j++){
                if(!visited[i][j] && board[i][j] != -1){
                    ret++;
                    dfs_partition(i, j, board, visited);
                }
            }
        }
        return ret;
    }
    static int solution_cheese_thief(BufferedReader br) throws Exception{

        int N = Integer.parseInt(br.readLine());
        int[][] board = new int[N][N];
        StringTokenizer st;

        for(int i = 0; i<N; i++){
            st = new StringTokenizer(br.readLine());
            for(int j = 0; j<N; j++){
                board[i][j] = Integer.parseInt(st.nextToken());
            }
        }

        int ret = 0;
        for(int day = 0; day<=100; day++){
            eating_cheese(board, day);
            int tmp_ret = get_partition_count(board);
            ret = Math.max(ret, tmp_ret);
        }
        return ret;
    }
    public static void main(String args[]) throws Exception
    {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int T = Integer.parseInt(br.readLine());

        for(int test_case = 1; test_case <= T; test_case++)
        {
            int ret = solution_cheese_thief(br);
            System.out.println("#" + test_case + " " + ret);

        }
    }
}
/*
* 치즈 덩어리 개수가 가장 많았을 때를 카운트 하는게 목적임
*
*
* */
/*
2
2
1 2
2 1
5
6 8 2 6 2
3 2 3 4 6
6 7 3 3 2
7 2 5 3 6
8 9 5 2 7
 */
/*
#1 2
#2 5
 */