package g17143;
//g17143 낚시왕

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

public class Main {

    static int[] dx = {0, -1, 1, 0, 0};
    static int[] dy = {0, 0, 0, 1, -1};

    static class SHARK{
        int x, y, dir, size, speed;
    }

    static int find_the_closest_shark_idx(int p_pos, List<SHARK>shark_list){
        int ret = -1;
        int min_val = Integer.MAX_VALUE;//how to get max integer value
        for(int i = 0; i<shark_list.size(); i++){
            SHARK cur_shark = shark_list.get(i);
            if(cur_shark.y != p_pos)continue;
            if(ret == -1 || min_val > cur_shark.x){
                ret = i;
                min_val = cur_shark.x;
            }
        }
        return ret;
    }
    static List<SHARK> moving_sharks(List<SHARK>shark_list, int R, int C){
        List<SHARK>new_shark_list = new ArrayList<>();

        for(SHARK shark : shark_list){
            if(shark.dir == 1 || shark.dir == 2){
                int period = 2 * (R - 1);
                int moving_dist = shark.speed % period;
                int cur = shark.x;

                while(moving_dist-- > 0){
                    if(shark.dir == 1){
                        int nxt = cur + dx[1];
                        if(nxt < 0){
                            nxt = cur + dx[2];
                            shark.dir = 2;
                        }
                        cur = nxt;
                    }else if(shark.dir == 2){
                        int nxt = cur + dx[2];
                        if(nxt >= R){
                            nxt = cur + dx[1];
                            shark.dir = 1;
                        }
                        cur = nxt;
                    }
                }
                shark.x = cur;
            }else{
                int period = 2 * (C - 1);
                int moving_dist = shark.speed % period;
                int cur = shark.y;

                while(moving_dist-- > 0){
                    if(shark.dir == 3){
                        int nxt = cur + dy[3];
                        if(nxt >= C){
                            nxt = cur + dy[4];
                            shark.dir = 4;
                        }
                        cur = nxt;
                    }else if(shark.dir == 4){
                        int nxt = cur + dy[4];
                        if(nxt < 0){
                            nxt = cur + dy[3];
                            shark.dir = 3;
                        }
                        cur = nxt;
                    }
                }
                shark.y = cur;
            }
            new_shark_list.add(shark);
        }
        return new_shark_list;
    }
    static List<SHARK> delete_duplicate_sharks(List<SHARK>shark_list, int R, int C){
        int[][] visited_board = new int[R][C];
        for(int i = 0; i<R; i++){
            for(int j = 0; j<C; j++){
                visited_board[i][j] = -1;
            }
        }
        int[] is_deleted = new int[shark_list.size()];
        for(int i = 0; i<shark_list.size(); i++){
            SHARK cur_shark = shark_list.get(i);
            int x = cur_shark.x;
            int y = cur_shark.y;
            if(visited_board[x][y] == -1){
                visited_board[x][y] = i;
            }else{
                int saved_shark_idx = visited_board[x][y];
                if(shark_list.get(saved_shark_idx).size < cur_shark.size){
                    visited_board[x][y] = i;
                    is_deleted[saved_shark_idx] = 1;
                }else{
                    is_deleted[i] = 1;
                }
            }
        }
        List<SHARK>new_shark_list = new ArrayList<>();
        for(int i = 0; i<shark_list.size(); i++){
            SHARK cur_shark = shark_list.get(i);
            if(is_deleted[i] == 1)continue;
            new_shark_list.add(cur_shark);
        }
        return new_shark_list;
    }
    static void solution_fishing_king(BufferedReader br) throws IOException{
        int R, C, M;
        StringTokenizer st = new StringTokenizer(br.readLine());
        R = Integer.parseInt(st.nextToken());
        C = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
        List<SHARK>shark_list = new ArrayList<>();


        //1(up), 2(down), 3(right), 4(left)
        for(int i = 0; i<M; i++){
            st = new StringTokenizer(br.readLine());
            int r, c, s, d, z;
            r = Integer.parseInt(st.nextToken());
            c = Integer.parseInt(st.nextToken());
            s = Integer.parseInt(st.nextToken());
            d = Integer.parseInt(st.nextToken());
            z = Integer.parseInt(st.nextToken());
            r--; c--;

            SHARK tmp_shark = new SHARK();
            tmp_shark.x = r;
            tmp_shark.y = c;
            tmp_shark.speed = s;
            tmp_shark.dir = d;
            tmp_shark.size = z;
            shark_list.add(tmp_shark);
        }

        int person_pos = 0;
        int caught_total_size = 0;
        while(person_pos < C){
            //catch shark
            int caught_shark_idx = find_the_closest_shark_idx(person_pos, shark_list);
            if(caught_shark_idx != -1){
                SHARK caught_shark = shark_list.get(caught_shark_idx);
                caught_total_size += caught_shark.size;
                shark_list.remove(caught_shark_idx);
            }

            //move sharks
            shark_list = moving_sharks(shark_list, R, C);

            //delete duplicate shark
            shark_list = delete_duplicate_sharks(shark_list, R, C);
            person_pos++;
        }
        System.out.println(caught_total_size);
    }
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        solution_fishing_king(br);


//        int T = Integer.parseInt(br.readLine());
//        while(T-- > 0){
//            solution_fishing_king(br);
//        }
    }
}
/*
4
4 6 8
4 1 3 3 8
1 3 5 2 9
2 4 8 4 1
4 5 0 1 4
3 3 1 2 7
1 5 8 4 3
3 6 2 1 2
2 2 2 3 5
100 100 0
4 5 4
4 1 3 3 8
1 3 5 2 9
2 4 8 4 1
4 5 0 1 4
2 2 4
1 1 1 1 1
2 2 2 2 2
1 2 1 2 3
2 1 2 1 4
*/
/*
22
0
22
4
*/