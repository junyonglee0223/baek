package g2636;
//g2636 치즈


import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {

    static int[] dx = {1, 0, -1, 0};
    static int[] dy = {0, 1, 0, -1};

    static int cheese_cnt(int[][] board){
        int N = board.length;
        int M = board[0].length;
        int ret = 0;
        for (int[] ints : board) {
            for (int j = 0; j < M; j++) {
                if (ints[j] == 1)
                    ret++;
            }
        }
        return ret;
    }

    static boolean is_range(int x, int y, int N, int M){
        return x >= 0 && x < N && y >= 0 && y < M;
    }

    static void set_air(int[][] board){
        //fill air position value as 2
        int N = board.length;
        int M = board[0].length;

        Queue<int[]> q = new LinkedList<>();
        boolean[][] visited = new boolean[N][M];

        q.offer(new int[]{0, 0});
        visited[0][0] = true;
        board[0][0] = 2;

        while(!q.isEmpty()){
            int[] cur = q.poll();
            int x = cur[0];
            int y = cur[1];
            for(int d = 0; d<4; d++){
                int nx = x + dx[d];
                int ny = y + dy[d];
                if(!is_range(nx, ny, N, M))continue;
                if(visited[nx][ny])continue;
                visited[nx][ny] = true;
                if(board[nx][ny] == 0 || board[nx][ny] == 2){
                    board[nx][ny] = 2;
                    q.offer(new int[]{nx, ny});
                }
            }
        }
    }

    static List<int[]> get_melting_candidates(int[][] board){
        int N = board.length;
        int M = board[0].length;
        List<int[]>ret = new ArrayList<>();

        for(int i = 0; i<N; i++){
            for(int j = 0; j<M; j++){
                if(board[i][j] != 1) continue;
                for(int d = 0; d<4; d++){
                    int nx = i + dx[d];
                    int ny = j + dy[d];
                    if(!is_range(nx, ny ,N, M))continue;
                    if(board[nx][ny] == 2){
                        ret.add(new int[]{i, j});
                        break;
                    }
                }
            }
        }
        return ret;
    }


    static int[] how_much_time(int[][] board){
        int N = board.length;
        int M = board[0].length;

        int T = 0;
        int cnt = cheese_cnt(board);
        int last_cnt = cnt;

        while(cnt > 0){
            //set air
            set_air(board);

            //choose melt cheese positions
            List<int[]> melt_candidates = get_melting_candidates(board);


            //set melting cheese
            for(int[] ele : melt_candidates){
                board[ele[0]][ele[1]] = 2;
            }

            last_cnt = cnt;
            cnt = cnt - melt_candidates.size();
            T++;
        }
        return new int[]{T, last_cnt};
    }
    static void solution_cheese(BufferedReader br) throws IOException {
        StringTokenizer st = new StringTokenizer(br.readLine());
        int N = Integer.parseInt(st.nextToken());
        int M = Integer.parseInt(st.nextToken());

        int[][] board = new int[N][M];

        for(int i = 0; i<N; i++){
            st = new StringTokenizer(br.readLine());
            for(int j = 0; j<M; j++){
                board[i][j] = Integer.parseInt(st.nextToken());
            }
        }
        int[] answer = how_much_time(board);
        System.out.println(answer[0]);
        System.out.println(answer[1]);
    }
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        solution_cheese(br);
    }
}
/*
13 12
0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 1 1 0 0 0
0 1 1 1 0 0 0 1 1 0 0 0
0 1 1 1 1 1 1 0 0 0 0 0
0 1 1 1 1 1 0 1 1 0 0 0
0 1 1 1 1 0 0 1 1 0 0 0
0 0 1 1 0 0 0 1 1 0 0 0
0 0 1 1 1 1 1 1 1 0 0 0
0 0 1 1 1 1 1 1 1 0 0 0
0 0 1 1 1 1 1 1 1 0 0 0
0 0 1 1 1 1 1 1 1 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0
*/
/*
3
5
*/