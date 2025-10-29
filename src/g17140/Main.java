package g17140;

import java.io.*;
import java.util.*;

public class Main {
    static final int MAXSIZE = 100;

    static int[][] update_board(int[][] board){
        int n = board.length;
        int m = board[0].length;
        int[][] tmp = new int[MAXSIZE][MAXSIZE];
        for(int i = 0; i<MAXSIZE; i++){
            for(int j = 0; j<MAXSIZE; j++){
                tmp[i][j] = 0;
            }
        }

        int max_m = m;

        for(int i = 0; i<n; i++){
            List<Integer>tmp_list = new ArrayList<>();
            Map<Integer, Integer> mp = new HashMap<>();

            for(int j = 0; j<m; j++){
                int ele = board[i][j];
                if(ele == 0)continue;
                if(!mp.containsKey(ele)){
                    mp.put(ele, 0);
                    tmp_list.add(ele);
                }
                mp.put(ele, mp.get(ele) + 1);
            }

            List<int[]>row_group = new ArrayList<>();
            for(int ele : tmp_list){
                row_group.add(new int[]{ele, mp.get(ele)});
            }
            Collections.sort(row_group, new Comparator<int[]>() {
                @Override
                public int compare(int[] a, int[] b){
                    if(a[1] == b[1])return a[0] - b[0];
                    return a[1] - b[1];
                }
            });

            int row_max_size_double = Math.min(MAXSIZE, row_group.size() * 2);
            max_m = Math.max(max_m, row_max_size_double);

            for(int j = 0; j<row_max_size_double/2; j++){
                tmp[i][j*2] = row_group.get(j)[0];
                tmp[i][j*2 + 1] = row_group.get(j)[1];
            }
        }

        int[][]ret = new int[n][max_m];
        for(int i = 0; i<n; i++){
            for(int j = 0; j<max_m; j++){
                ret[i][j] = tmp[i][j];
            }
        }
        return ret;
    }

    static int[][] rev_board(int[][] board){
        int n = board.length;
        int m = board[0].length;
        int[][] ret = new int[m][n];
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                ret[j][i] = board[i][j];
            }
        }
        return ret;
    }

    static int[][] oper_board(int[][] board){
        int n = board.length;
        int m = board[0].length;
        if(n>=m){
            return update_board(board);
        }else{
            int[][] tmp_board = rev_board(board);
            tmp_board = update_board(tmp_board);
            return rev_board(tmp_board);
        }
    }

    static void print_board(int[][] board){
        int n = board.length;
        int m = board[0].length;
                for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                System.out.print(board[i][j] + " ");
            }
            System.out.println();
        }
    }

    static int solution_two_dimension_and_array(BufferedReader br) throws Exception {
        StringTokenizer st = new StringTokenizer(br.readLine());
        int r = Integer.parseInt(st.nextToken());
        int c = Integer.parseInt(st.nextToken());
        int k = Integer.parseInt(st.nextToken());

        int[][] init_board = new int[3][3];
        for(int i = 0; i<3; i++){
            st = new StringTokenizer(br.readLine());
            for(int j = 0; j<3; j++){
                init_board[i][j] = Integer.parseInt(st.nextToken());
            }
        }

        r--; c--;
        int[][] board = init_board;
        for(int t = 0; t<=MAXSIZE; t++){

            // //////////////////////////////////
            // print_board(board);
            // System.out.println("!");
            int cur_n = board.length;
            int cur_m = board[0].length;

            if((cur_n > r && cur_m > c) && board[r][c] == k){
                //print_board(board);
                //////////////////////////////////////////////
                return t;
            }
            board = oper_board(board);
        }
        return -1;
    }
    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        System.out.println(solution_two_dimension_and_array(br));
        
        // int T = Integer.parseInt(br.readLine());
        // while(T-- > 0){
        //     System.out.println("answer: " + solution_two_dimension_and_array(br));
        // }

        
    }
    
}

/*
5
1 2 2
1 2 1
2 1 3
3 3 3

1 2 1
1 2 1
2 1 3
3 3 3

1 2 3
1 2 1
2 1 3
3 3 3

1 2 4
1 2 1
2 1 3
3 3 3

1 2 5
1 2 1
2 1 3
3 3 3

3 3 3
1 1 1
1 1 1
1 1 1
 */
/*
5
1 2 2
1 2 1
2 1 3
3 3 3
1 2 1
1 2 1
2 1 3
3 3 3
1 2 3
1 2 1
2 1 3
3 3 3
1 2 4
1 2 1
2 1 3
3 3 3
1 2 5
1 2 1
2 1 3
3 3 3
3 3 3
1 1 1
1 1 1
1 1 1
 */
/*
0
1
2
52
-1
2
 */