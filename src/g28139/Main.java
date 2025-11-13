package g28139;

import java.io.*;
import java.util.*;

public class Main {
    static double calc_dist(int[] dot1, int[] dot2){
        int dist1 = (dot1[0] - dot2[0]);
        int dist2 = (dot1[1] - dot2[1]);
        return Math.sqrt(dist1*dist1 + dist2*dist2);
    }

    static double solution_get_mean(BufferedReader br) throws Exception {
        int n = Integer.parseInt(br.readLine());
        int[][] arr = new int[n][2];

        StringTokenizer st;
        for(int i = 0; i<n; i++){
            st = new StringTokenizer(br.readLine());
            int e1 = Integer.parseInt(st.nextToken());
            int e2 = Integer.parseInt(st.nextToken());
            arr[i][0] = e1;
            arr[i][1] = e2;
        }

        double sum_dist = 0;
        int count_dist = 0;
        for(int i = 0; i<n; i++){
            for(int j = i+1; j<n; j++){
                if(i == j)continue;
                double tmp = calc_dist(arr[i], arr[j]);
                sum_dist += tmp;
                count_dist++;
            }
        }
        return (sum_dist / count_dist) * (n-1);
    }
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        System.out.println(solution_get_mean(br));
    }
    
}
/*
123
132 
각각의 edge에 대한 count를 생각
12 -> 
23 -> 
13 -> 
그러면 전체 경우의 수를 나눠야 하는 문제가 있음
개별 계산이 가능한지 찾아야 함
5000!은불가능한 상황

12 -> sqrt(2)
13 -> 1
23 -> sqrt(2)

(1+2sqrt(2))*2 + 4
8+4sqrt(2)/6
4+2sqrt(2)/3


((1 +  2 * sqrt(2)) / 2)

 / (n-1)!





 */
/*
3
1 1
1 2
2 1
 */
/*
2.276142375
 */