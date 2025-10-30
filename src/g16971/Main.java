package g16971;

import java.io.*;
import java.util.*;

public class Main {
    
    static boolean is_side(int x, int y, int n, int m){
        if(x == 0 && y == 0)return true;
        if(x == 0 && y == m-1)return true;
        if(x == n-1 && y == 0)return true;
        if(x == n-1 && y == m-1)return true;
        return false;
    }

    static int solution_value_of_array_b(BufferedReader br) throws Exception{
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());

        int[][] board = new int[n][m];
        for(int i = 0; i<n; i++){
            st = new StringTokenizer(br.readLine());
            for(int j = 0; j<m; j++){
                board[i][j] = Integer.parseInt(st.nextToken());
            }
        }

        int[][] weight = new int[n][m];
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                weight[i][j] = 4;

                if(is_side(i, j, n, m)){
                    weight[i][j] = 1;
                }
                else if(i == 0 || i == n-1 || j == 0 || j == m-1){
                    weight[i][j] = 2;
                }
            }
        }

        int[] row_val = new int[n];
        int[] col_val = new int[m];
        int tot_ret = 0;
        int row_inside_min = Integer.MAX_VALUE;
        int col_inside_min = Integer.MAX_VALUE;

        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                row_val[i] += (board[i][j] * weight[i][j]);
            }
            tot_ret += row_val[i];
            if(i != 0 && i != n-1){
                row_inside_min = Math.min(row_inside_min, row_val[i]);
            }
        }
        
        for(int i = 0; i<m; i++){
            for(int j = 0; j<n; j++){
                col_val[i] += (board[j][i] * weight[j][i]);
            }
            if(i != 0 && i != m-1){
                col_inside_min = Math.min(col_inside_min, col_val[i]);
            }
        }

        int row_side_max = Math.max(row_val[0], row_val[n-1]);
        int row_change_val = (row_inside_min != Integer.MAX_VALUE ? (row_side_max - row_inside_min / 2):0);

        int col_side_max = Math.max(col_val[0], col_val[m-1]);
        int col_change_val = (col_inside_min != Integer.MAX_VALUE ? (col_side_max - col_inside_min / 2) : 0);

        return tot_ret + Math.max(0, Math.max(col_change_val, row_change_val));
    }


    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        System.out.println(solution_value_of_array_b(br));
        // int T = Integer.parseInt(br.readLine());
        // while(T-- > 0){
        //     System.out.println("answer = " + solution_value_of_array_b(br));
        // }
        
    }
    
}
/*
B의 4방향 합을 구해야 하며
B의 각 원소가 2*2 합으로 구성되어 있음

row 기준으로 다시 생각
i, j를 교환한다고 가정하면
하나의 블록당 8개의 연산이 다시 해야 됨

완전탑색으로 구현하면 -> 10^6 * 2 * 2 -> 시간초과 발생 가능
관심은 B의 배열 합을 구하는 것임

가중치 배열을 따로 만드는 방법
보통 디폴트가 4고 모서리가 2 꼭짓점이 1이다.

시간초과 발생 중
하나씩 골라서 계산하는 과정 불필요
row, col 정렬해서 

row 기준으로 다시 생각
0, n-1 중 큰 값의 2배가
1 ~ n-2 행 의 가장 작은 값보다 크다면 교환하는게 이득

내부 row, col 중 최솟값을 찾는 로직을 정렬하는 과정 대신 처음 입력할 때 traking 하여 저장하면
이후 nlogn의 시간 복잡도가 사라진다.
유의미한 차이가 나지는 않음


 */
/*
3
3 3
9 8 7
3 2 1
6 5 4
3 4
1 2 1 1
2 1 1 2
2 1 1 1
3 3
1 1 1
1 2 1
1 1 1
 */
/*
92
34
20
 */