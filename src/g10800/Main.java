package g10800;
//g10800 컬러볼

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Main {
    static class Ball{
        int idx, color, weight;
        Ball(int idx, int color, int weight){
            this.idx = idx;
            this.color = color;
            this.weight = weight;
        }
    }

    static void solution_color_ball(BufferedReader br) throws IOException {
        int n = Integer.parseInt(br.readLine());
        List<Ball> balls = new ArrayList<>();

        int[] color_idx = new int[200001];
        for(int i = 0; i<200001; i++)
            color_idx[i] = -1;
        int color_cnt = 0;

        for(int i = 0; i<n; i++){
            StringTokenizer st = new StringTokenizer(br.readLine());
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());

            if(color_idx[a] == -1){
                color_idx[a] = color_cnt++;
            }

            balls.add(new Ball(i, color_idx[a], b));
        }

        balls.sort(Comparator.comparingInt(b -> b.weight));
//        balls.sort((b1, b2) -> Integer.compare(b1.weight, b2.weight));

        int tot_sum = 0;
        int tot_sum_dup = 0;
        List<Integer> tot_visited = new ArrayList<>();

        int[] color_sum = new int[color_cnt];
        int[] color_sum_dup = new int[color_cnt];
        List<List<Integer>> color_visited = new ArrayList<>();
        for(int i = 0; i<color_cnt; i++){
            color_visited.add(new ArrayList<>());
        }

        int[] ret = new int[n];

        for(int i = 0; i<n; i++){
            int idx = balls.get(i).idx;
            int w = balls.get(i).weight;
            int c = balls.get(i).color;

            if(!tot_visited.isEmpty() && tot_visited.get(tot_visited.size() - 1) == w){
                tot_sum_dup++;
            }else{
                if(tot_sum_dup > 0){
                    tot_sum += (tot_sum_dup) * (tot_visited.get(tot_visited.size() - 1));
                }
                tot_visited.add(w);
                tot_sum_dup = 1;
            }

            int t_w = tot_sum;

            if(!color_visited.get(c).isEmpty() && color_visited.get(c).get(color_visited.get(c).size() - 1) == w){
                color_sum_dup[c]++;
            }else{
                if(color_sum_dup[c] > 0){
                    color_sum[c] += (color_sum_dup[c]) * (color_visited.get(c).get(color_visited.get(c).size() - 1));
                }
                color_visited.get(c).add(w);
                color_sum_dup[c] = 1;
            }
            int c_w = color_sum[c];

            ret[idx] = t_w - c_w;
        }
        for(int i = 0; i<n; i++){
            System.out.println(ret[i]);
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        solution_color_ball(br);

//        int T = Integer.parseInt(br.readLine());
//        while(T-- > 0){
//            solution_color_ball(br);
//        }

    }
}


/*
2
4
1 10
3 15
1 3
4 8
3
2 3
2 5
2 4
*/
/*
8
21
0
3

0
0
0
*/