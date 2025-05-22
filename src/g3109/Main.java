package g3109;
//g3109 빵집

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    static int[] dx = {-1, 0, 1};
    static int[] dy = {1, 1, 1};

    static boolean is_range(int x, int y, int n, int m){
        return x >= 0 && x < n && y >= 0 && y < m;
    }

    static boolean is_pos_route(int x, int y, char[][] board, boolean[][] visited){
        int n = board.length;
        int m = board[0].length;
        if(y == m-1){
            return true;
        }

        for(int d = 0; d<3; d++){
            int nx = x + dx[d];
            int ny = y + dy[d];
            if(!is_range(nx, ny, n, m))continue;
            if(visited[nx][ny])continue;
            if(board[nx][ny] == 'x')continue;

            visited[nx][ny] = true;
            if(is_pos_route(nx, ny, board, visited))return true;
        }

        return false;
    }
    static void solution_bread_house(BufferedReader br) throws IOException {
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());

        char[][] board = new char[n][m];
        for(int i = 0; i<n; i++){
            String tmp = br.readLine();
            for(int j = 0; j<m; j++){
                board[i][j] = tmp.charAt(j);
            }
        }

        boolean[][] visited = new boolean[n][m];
        for(int i = 0; i<n; i++)
            for(int j = 0; j<m; j++)
                visited[i][j] = false;


        int answer = 0;
        for(int i = 0; i<n; i++){
            if(is_pos_route(i, 0, board, visited))answer++;
        }
        System.out.println(answer);
    }

    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        solution_bread_house(br);

//        int T = Integer.parseInt(br.readLine());
//        while(T-- > 0){
//            solution_bread_house(br);
//        }
    }
}
/*
2
5 5
.xx..
..x..
.....
...x.
...x.
6 10
..x.......
.....x....
.x....x...
...x...xx.
..........
....x.....
*/
/*
2
5
*/