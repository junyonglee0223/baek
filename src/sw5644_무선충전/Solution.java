package sw5644_무선충전;

//SW5644_WirelessCharging_이준용.java
import java.io.*;
import java.util.*;

public class Solution {

    static int[] dx = {0, -1, 0, 1, 0};
    static int[] dy = {0, 0, 1, 0, -1};

    static int solution_wireless_charging(BufferedReader br) throws IOException{
        List<List<Integer>> board = new ArrayList<>();
        for(int i = 0; i < 100; i++){
            board.add(new ArrayList<>());
        }

        int a_x = 0, a_y = 0, b_x = 9, b_y = 9;
        int M, B;
        StringTokenizer st = new StringTokenizer(br.readLine());
        M = Integer.parseInt(st.nextToken());
        B = Integer.parseInt(st.nextToken());

        int[] A_way = new int[M];
        int[] B_way = new int[M];

        st = new StringTokenizer(br.readLine());
        for(int i = 0; i < M; i++){
            A_way[i] = Integer.parseInt(st.nextToken());
        }
        st = new StringTokenizer(br.readLine());
        for(int i = 0; i < M; i++){
            B_way[i] = Integer.parseInt(st.nextToken());
        }

        boolean[] is_active = new boolean[B];
        int[] value = new int[B];

        Queue<int[]> que = new ArrayDeque<>();

        for(int i = 0; i < B; i++){
            st = new StringTokenizer(br.readLine());
            int x = Integer.parseInt(st.nextToken());
            int y = Integer.parseInt(st.nextToken());
            x--; y--;
            int d = Integer.parseInt(st.nextToken());
            is_active[i] = false;
            value[i] = Integer.parseInt(st.nextToken());

            boolean[][] visited = new boolean[10][10];
            que.clear();
            que.add(new int[]{0, y, x});
            visited[y][x] = true;
            board.get(y * 10 + x).add(i);

            while(!que.isEmpty()){
                int[] cur = que.poll();
                int distance = cur[0];
                int cur_x = cur[1];
                int cur_y = cur[2];

                if(distance == d) continue;

                for(int dir = 1; dir <= 4; dir++) {
                    int nxt_x = cur_x + dx[dir];
                    int nxt_y = cur_y + dy[dir];
                    if (nxt_x >= 0 && nxt_x < 10 && nxt_y >= 0 && nxt_y < 10) {
                        if(!visited[nxt_x][nxt_y]){
                            visited[nxt_x][nxt_y] = true;
                            board.get(nxt_x * 10 + nxt_y).add(i);
                            que.add(new int[]{distance + 1, nxt_x, nxt_y});
                        }
                    }
                }
            }
        }

        for(int i = 0; i < 100; i++){
            final int[] valRef = value;
            Collections.sort(board.get(i), new Comparator<Integer>() {
                @Override
                public int compare(Integer o1, Integer o2) {
                    return Integer.compare(valRef[o2], valRef[o1]); // 내림차순
                }
            });
        }

        int answer = 0;

        {
            List<Integer> listA = board.get(a_x * 10 + a_y);
            List<Integer> listB = board.get(b_x * 10 + b_y);
            int best = 0;

            for(int ia = -1; ia < listA.size(); ia++){
                int aBC = -1;
                if(ia >= 0) aBC = listA.get(ia);

                for(int ib = -1; ib < listB.size(); ib++){
                    int bBC = -1;
                    if(ib >= 0) bBC = listB.get(ib);

                    int cur = 0;
                    if(aBC == -1 && bBC == -1) cur = 0;
                    if(aBC != -1 && bBC == -1) cur = value[aBC];
                    if(aBC == -1 && bBC != -1) cur = value[bBC];
                    if(aBC != -1 && bBC != -1){
                        if(aBC == bBC) cur = value[aBC];
                        if(aBC != bBC) cur = value[aBC] + value[bBC];
                    }
                    if(cur > best) best = cur;
                }
            }
            answer += best;
        }

        for(int t = 0; t < M; t++){
            int da = A_way[t];
            int db = B_way[t];

            a_x += dx[da];
            a_y += dy[da];
            b_x += dx[db];
            b_y += dy[db];

            List<Integer> listA = board.get(a_x * 10 + a_y);
            List<Integer> listB = board.get(b_x * 10 + b_y);
            int best = 0;

            for(int ia = -1; ia < listA.size(); ia++){
                int aBC = -1;
                if(ia >= 0) aBC = listA.get(ia);

                for(int ib = -1; ib < listB.size(); ib++){
                    int bBC = -1;
                    if(ib >= 0) bBC = listB.get(ib);

                    int cur = 0;
                    if(aBC == -1 && bBC == -1) cur = 0;
                    if(aBC != -1 && bBC == -1) cur = value[aBC];
                    if(aBC == -1 && bBC != -1) cur = value[bBC];
                    if(aBC != -1 && bBC != -1){
                        if(aBC == bBC) cur = value[aBC];
                        if(aBC != bBC) cur = value[aBC] + value[bBC];
                    }
                    if(cur > best) best = cur;
                }
            }
            answer += best;
        }

        return answer;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int T = Integer.parseInt(br.readLine());

        for(int test_case = 1; test_case <= T; test_case++)
        {
            System.out.println("#" + test_case + " " + solution_wireless_charging(br));
        }
    }
}

/*
경로 다 주어줌
하나의 칸에 여러 가중치가 가능
사용자 2명이 동시에 같은 BC 사용하면 가중치 절반만 가능
가중치 최대인 것으로 sort

 */

/*
*
* */
/*

5
20 3
2 2 3 2 2 2 2 3 3 4 4 3 2 2 3 3 3 2 2 3
4 4 1 4 4 1 4 4 1 1 1 4 1 4 3 3 3 3 3 3
4 4 1 100
7 10 3 40
6 3 2 70
 */
/*

#1 1200
#2 3290
#3 16620
#4 40650
#5 52710
 */