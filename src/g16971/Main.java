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

    static int change_value_row(int x1, int x2, int[][] board, int[][] weight, int prev_sum){
        int m = board[0].length;
        int ret = 0;
        for(int i = 0; i<m; i++){
            ret += board[x1][i] * weight[x2][i];
        }
        for(int i = 0; i<m; i++){
            ret += board[x2][i] * weight[x1][i];
        }
        return ret - prev_sum;
    }
    
    static int change_value_col(int y1, int y2, int[][] board, int[][] weight, int prev_sum){
        int n = board.length;
        int ret = 0;
        for(int i = 0; i<n; i++){
            ret += board[i][y1] * weight[i][y2];
        }
        for(int i = 0; i<n; i++){
            ret += board[i][y2] * weight[i][y1];
        }
        return ret - prev_sum;
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

        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                row_val[i] += (board[i][j] * weight[i][j]);
            }
            tot_ret += row_val[i];
        }
        
        for(int i = 0; i<m; i++){
            for(int j = 0; j<n; j++){
                col_val[i] += (board[j][i] * weight[j][i]);
            }
        }

        int ret = tot_ret;
        if(n > 2){
            int row_ret = tot_ret;
            List<Integer>row_list = new ArrayList<>();
            for(int i = 1; i<n-1; i++){
                row_list.add(row_val[i]);
            }
            Collections.sort(row_list);
            int max_side = Math.max(row_val[0], row_val[n-1]);
            if(max_side * 2 > row_list.get(0)){
                row_ret = (tot_ret - row_list.get(0) + (max_side + row_list.get(0) / 2));
            }
            ret = Math.max(ret, row_ret);
        }    

        if(m > 2){
            int col_ret = tot_ret;
            List<Integer>col_list = new ArrayList<>();
            for(int i = 1; i<m-1; i++){
                col_list.add(col_val[i]);
            }
            Collections.sort(col_list);
            int max_side = Math.max(col_val[0], col_val[m-1]);
            if(max_side * 2 > col_list.get(0)){
                col_ret = (tot_ret - col_list.get(0) + (max_side + col_list.get(0) / 2));
            }
            ret = Math.max(ret, col_ret);
        }
        return ret;
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