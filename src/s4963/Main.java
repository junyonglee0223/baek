package s4963;
//s4963 섬의 개수


import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {
    static int[] dx = {1, 1, 0, -1, -1, -1, 0, 1};
    static int[] dy = {0, 1, 1, 1, 0, -1, -1, -1};

    static boolean is_range(int x, int y, int n, int m){
        return x >= 0 && x < n && y >= 0 && y < m;
    }

    static void set_island_visited(int x, int y, boolean[][] visited, int[][] board){
        int n = board.length;
        int m = board[0].length;

        Queue<int[]> q = new LinkedList<>();
        visited[x][y] = true;
        q.offer(new int[]{x, y});

        while(!q.isEmpty()){
            int[] tmp_q = q.poll();
            int cx = tmp_q[0];
            int cy = tmp_q[1];

            for(int d = 0; d<8; d++){
                int nx = cx + dx[d];
                int ny = cy + dy[d];

                if(!is_range(nx, ny, n, m))continue;
                if(visited[nx][ny])continue;
                if(board[nx][ny] == 0)continue;

                visited[nx][ny] = true;
                q.offer(new int[]{nx, ny});
            }
        }
    }

    static int get_island_count(int[][] board){
        int n = board.length;
        int m = board[0].length;

        boolean[][] visited = new boolean[n][m];

        for(int i = 0; i<n; i++)
            for(int j = 0; j<m; j++)
                visited[i][j] = false;

        int ret = 0;
        for(int i = 0; i<n ; i++){
            for(int j = 0; j<m; j++){
                if(!visited[i][j] && board[i][j] == 1){
                    ret++;
                    set_island_visited(i, j, visited, board);
                }
            }
        }

        return ret;
    }
    static void solution_islands_count(BufferedReader br) throws IOException {
        StringTokenizer st = new StringTokenizer(br.readLine());
        int m = Integer.parseInt(st.nextToken());
        int n = Integer.parseInt(st.nextToken());

        while (n != 0 && m != 0){
            int[][] board = new int[n][m];
            for(int i = 0; i<n; i++){
                st = new StringTokenizer(br.readLine());
                for(int j = 0; j < m; j++){
                    board[i][j] = Integer.parseInt(st.nextToken());
                }
            }
            System.out.println(get_island_count(board));

            st = new StringTokenizer(br.readLine());
            m = Integer.parseInt(st.nextToken());
            n = Integer.parseInt(st.nextToken());
        }
    }
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        solution_islands_count(br);
    }
}

/*
1 1
0
2 2
0 1
1 0
3 2
1 1 1
1 1 1
5 4
1 0 1 0 0
1 0 0 0 0
1 0 1 0 1
1 0 0 1 0
5 4
1 1 1 0 1
1 0 1 0 1
1 0 1 0 1
1 0 1 1 1
5 5
1 0 1 0 1
0 0 0 0 0
1 0 1 0 1
0 0 0 0 0
1 0 1 0 1
0 0
*/

/*
0
1
1
3
1
9
*/