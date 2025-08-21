package sw1227_미로2;
//:bricks: SW1227_Maze2_이준용.java
import java.io.*;
import java.util.ArrayDeque;
import java.util.Queue;
import java.util.Scanner;


class Solution
{
    static int[] dx = {1, 0, -1, 0};
    static int[] dy = {0, 1, 0, -1};

    static boolean is_range(int x, int y){
        return x >= 0 && x < 100 && y >= 0 && y < 100;
    }

    static boolean solution_maze_2(BufferedReader br)throws IOException{
        int N = 100;
        Character[][] board = new Character[100][100];
        br.readLine();//just number input

        int[] s_p = new int[2];
        int[] g_p = new int[2];

        for(int i = 0; i<N; i++){
            String str = br.readLine();
            for(int j = 0; j<N; j++){
                board[i][j] = str.charAt(j);
                if(board[i][j] == '2'){
                    s_p[0] = i;
                    s_p[1] = j;
                }else if(board[i][j] == '3'){
                    g_p[0] = i;
                    g_p[1] = j;
                }
            }
        }
        Queue<int[]>que = new ArrayDeque<>();
        boolean[][] visited = new boolean[N][N];

        que.add(s_p);
        visited[s_p[0]][s_p[1]] = true;

        while (!que.isEmpty()){
            int[] cur = que.poll();
            for(int d = 0; d < 4; d++){
                int nx = cur[0] + dx[d];
                int ny = cur[1] + dy[d];
                if(!is_range(nx, ny) || visited[nx][ny])continue;

                if(board[nx][ny] == '1')continue;
                if(board[nx][ny] == '3')return true;
                visited[nx][ny] = true;
                que.add(new int[]{nx, ny});
            }
        }

        return false;
    }
    public static void main(String args[]) throws Exception
    {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int T = 10;


        for(int test_case = 1; test_case <= T; test_case++)
        {
            int ret = solution_maze_2(br) ? 1 : 0;
            System.out.println("#" + test_case + " " + ret);
        }
    }
}