package g30024;

import java.io.*;
import java.util.*;

public class Main {
    static int[] dx = {1, 0, -1, 0};
    static int[] dy = {0, 1, 0, -1};
    static int N, M, K;

    static int[][] board;
    static boolean isRange(int x, int y){
        return x > 0 && x <= N && y > 0 && y <= M;
    }
    
    static class NODE {
        int x, y, value;
        NODE(int x, int y, int value){
            this.x = x;
            this.y = y;
            this.value = value;
        }

    }
    

    static void solutionCornFarm(BufferedReader br) throws Exception {
        StringTokenizer st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
        board = new int[N+1][M+1];

        PriorityQueue<NODE> pq = new PriorityQueue<>(new Comparator<NODE>() {
            @Override
            public int compare(NODE a, NODE b){
                return b.value - a.value;
            }
        });

        boolean[][] visited = new boolean[N+1][M+1];
        for(int i = 1; i<=N; i++){
            st = new StringTokenizer(br.readLine());
            for(int j = 1; j<=M; j++){
                visited[i][j] = false;
                board[i][j] = Integer.parseInt(st.nextToken());
                if(i == 1 || i == N || j == 1 || j == M){
                    visited[i][j] = true;
                    pq.add(new NODE(i, j, board[i][j]));
                }
            }
        }


        K = Integer.parseInt(br.readLine());

        List<int[]>ret = new ArrayList<>();

        int count = 0;
        while(!pq.isEmpty() && count < K){
            count++;
            NODE cur = pq.poll();
            int curX = cur.x;
            int curY = cur.y;
            ret.add(new int[]{curX, curY});
            
            for(int d = 0; d<4; d++){
                int nx = curX + dx[d];
                int ny = curY + dy[d];
                if(!isRange(nx, ny) || visited[nx][ny]) continue;
                visited[nx][ny] = true;
                pq.add(new NODE(nx, ny, board[nx][ny]));
            }
        }

        for(int[] ele : ret){
            System.out.println(ele[0] + " " + ele[1]);
        }
    }
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        solutionCornFarm(br);

    }
}

/*
4 5
1 18 2 3 4
12 17 15 20 5
11 14 19 13 6
10 9 16 8 7
6

3 3
9 8 1
4 5 2
6 3 7
4
*/
/*
1 2
2 2
4 3
3 3
2 3
2 4

1 1
1 2
3 3
3 1

*/