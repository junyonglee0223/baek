package sw2105_디저트카페;

//SW2105_DessertCafe_이준용.java
import java.io.*;
import java.util.HashSet;
import java.util.Set;
import java.util.StringTokenizer;

class Solution
{
    static int answer = -1;
    static int N;
    static int[][] board;

    static int[] dx = {-1, 1, 1, -1};
    static int[] dy = {1, 1, -1, -1};

    static boolean is_range(int x, int y){
        return x >= 0 && x < N && y >= 0 && y < N;
    }
    static int get_count_cafe(int s_x, int s_y, int d1, int d2){
        int ret = 1;
        Set<Integer> visited = new HashSet<>();
        int x = s_x, y = s_y;
        visited.add(board[x][y]);

        for(int d = 1; d <=d1; d++){
            ret++;
            x += dx[0];
            y += dy[0];
            if(visited.contains(board[x][y]))return -1;
            visited.add(board[x][y]);
        }
        for(int d = 1; d <=d2; d++){
            ret++;
            x += dx[1];
            y += dy[1];
            if(visited.contains(board[x][y]))return -1;
            visited.add(board[x][y]);
        }
        for(int d = 1; d <=d1; d++){
            ret++;
            x += dx[2];
            y += dy[2];
            if(visited.contains(board[x][y]))return -1;
            visited.add(board[x][y]);
        }
        for(int d = 1; d < d2; d++){
            ret++;
            x += dx[3];
            y += dy[3];
            if(visited.contains(board[x][y]))return -1;
            visited.add(board[x][y]);
        }
        return ret;
    }
    static void create_rect(int x, int y){
        for(int d1 = 1; d1 < N; d1++){
            if(!is_range(x + dx[0] * d1, y + dy[0] * d1))continue;
            for(int d2 = 1; d2 < N; d2++){
                int x_1 = x + dx[0] * d1;
                int y_1 = y + dy[0] * d1;
                if(!is_range(x_1 + dx[1]*d2, y_1+ dy[1]*d2))continue;
                int x_2 = x_1 + dx[1]*d2;
                int y_2 = y_1 + dy[1]*d2;
                if(!is_range(x_2 + dx[2]*d1, y_2 + dy[2]*d1))continue;
                int ret = get_count_cafe(x, y, d1, d2);

                answer = Math.max(answer, ret);
            }
        }
    }

    static int solution_desert_cafe(BufferedReader br) throws IOException {
        N = Integer.parseInt(br.readLine());
        board = new int[N][N];
        StringTokenizer st;
        for(int i = 0; i<N; i++){
            st = new StringTokenizer(br.readLine());
            for(int j = 0; j<N; j++){
                board[i][j] = Integer.parseInt(st.nextToken());
            }
        }

        for(int i = 0; i<N; i++){
            for(int j = 0; j<N; j++){
                create_rect(i, j);
            }
        }
        return 0;
    }
    public static void main(String args[]) throws Exception
    {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int T = Integer.parseInt(br.readLine());

        for(int test_case = 1; test_case <= T; test_case++)
        {
            answer = -1;
            solution_desert_cafe(br);
            System.out.println("#" + test_case + " " + answer);
        }
    }
}
/*
N 4 - 20
종류 100 이하
무조건 4 dir을 거쳐야 함 무조건 대각선으로 탐색

하강 대각선 합 -> 0 - 2*N - 2
이거중 2개 고르고 

상승 대각선 차이(x, y) -> y - x 음수 일 경우 2N - 1 - 차이 -> 0 - 2*N -2

x + y -> d1
y - x -> d2
y - x -> 2N - 1 + d2

x, y -> ((d1 - d2) / 2 , (d1 + d2) / 2)
x, y -> ((d1 - d2 + 1 - 2N) / 2 , (2N - 1 + d1 + d2) / 2)


아니면 그냥 완전 탐색으로 구현
0, 1, 2, 3
0 - 2
1 - 3
은 이동

 */
/*

10
4
9 8 9 8
4 6 9 4
8 7 7 8
4 5 3 5
5
8 2 9 6 6
1 9 3 3 4
8 2 3 3 6
4 3 4 4 9
7 4 6 3 5

 */