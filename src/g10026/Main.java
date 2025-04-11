package g10026;

import java.util.Arrays;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

//g10026 적록색약
public class Main {

    static int[] dx = {1, 0, -1, 0};
    static int[] dy = {0, 1, 0, -1};
    static boolean is_range(int x, int y, int n){
        return x >= 0 && x < n && y >= 0 && y < n;
    }
    static void set_bfs_visited(int x, int y, boolean[][] visited, char[][] board){
        int n = board.length;
        char color = board[x][y];

        Queue<int[]>q = new LinkedList<>();
        q.offer(new int[]{x, y});
        visited[x][y] = true;

        while(!q.isEmpty()){
            int[] cur = q.poll();
            int cx = cur[0];
            int cy = cur[1];

            for(int d = 0; d<4; d++){
                int nx = cx + dx[d];
                int ny = cy + dy[d];

                if(!is_range(nx, ny, n))continue;
                if(visited[nx][ny])continue;
                if(board[nx][ny] != color)continue;

                visited[nx][ny] = true;
                q.offer(new int[]{nx, ny});
            }
        }
    }
    static int normal_board_count(char[][] board){
        int ret = 0;
        int n = board.length;
        boolean[][] visited = new boolean[n][n];

        for(int i = 0; i<n; i++){
            for(int j = 0; j<n; j++){
                if(!visited[i][j]){
                    set_bfs_visited(i, j, visited, board);
                    ret++;
                }
            }
        }
        return ret;
    }
    static int blindness_board_count(char[][] board){

        int n = board.length;

        char[][] n_board = new char[n][n];
        for(int i = 0; i<n; i++){
            for(int j = 0; j<n; j++){
                n_board[i][j] = board[i][j];
                if(n_board[i][j] == 'G')
                    n_board[i][j] = 'R';
            }
        }
        return normal_board_count(n_board);
    }

    static void solution_red_green_color_blindness(Scanner sc){
        int N = Integer.parseInt(sc.nextLine());

        char[][] board = new char[N][N];


        for(int i = 0; i<N; i++){
            String line = sc.nextLine();
            for(int j = 0; j<N; j++){
                board[i][j] = line.charAt(j);
            }
        }
        System.out.println(normal_board_count(board) + " " + blindness_board_count(board));
    }
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);

        solution_red_green_color_blindness(sc);
    }
}
/*
5
RRRBB
GGBBB
BBBRR
BBRRR
RRRRR
*/
/*
4 3
*/