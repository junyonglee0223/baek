package g15685;
//g15685 드래곤 커브

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;


public class Main {
    static final Integer MAX_D = 101;
    static int[] dx = {1, 0, -1, 0};
    static int[] dy = {0, -1, 0, 1};

    static int[] update_anticlockwise(int x, int y, int gx, int gy){
        int new_x = x - gx;
        int new_y = y - gy;

        int tmp = new_x;
        new_x = new_y;
        new_y = tmp;

        new_x *= -1;

        new_x += gx;
        new_y += gy;
        return new int[]{new_x, new_y};
    }
    static List<int[]> set_dragon_curve(int x, int y, int d, int g){
        List<int[]> ret = new ArrayList<>();
        ret.add(new int[]{x, y});
        ret.add(new int[]{x+dx[d], y+dy[d]});

        while(g-- > 0){
            int cur_size = ret.size();
            int gx = ret.get(cur_size - 1)[0];
            int gy = ret.get(cur_size - 1)[1];

            for(int i = cur_size - 2; i>=0; i--){
                ret.add(update_anticlockwise(ret.get(i)[0], ret.get(i)[1], gx, gy));
            }
        }
        return ret;
    }

    static void solution_dragon_curve(BufferedReader br) throws IOException {
        int N = Integer.parseInt(br.readLine());
        int[][] board = new int[MAX_D][MAX_D];

        for(int i = 0; i<N; i++){
            StringTokenizer st = new StringTokenizer(br.readLine());
            int x = Integer.parseInt(st.nextToken());
            int y = Integer.parseInt(st.nextToken());
            int d = Integer.parseInt(st.nextToken());
            int g = Integer.parseInt(st.nextToken());

            List<int[]> cur_curve = set_dragon_curve(x, y, d, g);
            for(int[] ele : cur_curve){
                board[ele[0]][ele[1]] = 1;
            }
        }

        int answer = 0;
        for(int i = 0; i<MAX_D-1; i++){
            for(int j = 0; j<MAX_D-1; j++){
                if(board[i][j] == 1 && board[i+1][j] == 1
                        && board[i][j+1] == 1 && board[i+1][j+1] == 1){
                    answer++;
                }
            }
        }
        System.out.println(answer);
    }
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        solution_dragon_curve(br);

//        int T = Integer.parseInt(br.readLine());
//        while(T-- > 0){
//            solution_dragon_curve(br);
//        }
    }
}
/*
4
3
3 3 0 1
4 2 1 3
4 2 2 1
4
3 3 0 1
4 2 1 3
4 2 2 1
2 7 3 4
10
5 5 0 0
5 6 0 0
5 7 0 0
5 8 0 0
5 9 0 0
6 5 0 0
6 6 0 0
6 7 0 0
6 8 0 0
6 9 0 0
4
50 50 0 10
50 50 1 10
50 50 2 10
50 50 3 10
*/
/*
4
11
8
1992
*/