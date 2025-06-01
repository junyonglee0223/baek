package g2580;
//g2580 스도쿠

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

public class Main {
    static final int BOARD_SIZE = 9;
    static int[][] answer_board;

    static boolean make_sudoku(int idx, int[][] board, List<int[]>empty_spot,
                               int[] weight, int[] height, int[] rect, int[][] rect_idx){
        if(idx == empty_spot.size()){
            answer_board = board;
            return true;
        }
        int x = empty_spot.get(idx)[0];
        int y = empty_spot.get(idx)[1];
        int r_idx = rect_idx[x][y];

        for(int num = 0; num < BOARD_SIZE; num++){
            if(((weight[x] & (1 << num)) == 0)
                    && ((height[y] & (1 << num)) == 0)
                    && ((rect[r_idx] & (1 << num)) == 0)){
                board[x][y] = num;
                weight[x] = (weight[x] | (1 << num));
                height[y] = (height[y] | (1 << num));
                rect[r_idx] = (rect[r_idx] | (1 << num));

                boolean end_flag = make_sudoku(idx+1, board, empty_spot, weight, height, rect, rect_idx);
                if(end_flag) return true;

                board[x][y] = -1;
                weight[x] = (weight[x] ^ (1 << num));
                height[y] = (height[y] ^ (1 << num));
                rect[r_idx] = (rect[r_idx] ^ (1 << num));
            }
        }
        return false;
    }
    static void solution_sudoku(BufferedReader br) throws IOException {
        int[][] board = new int[BOARD_SIZE][BOARD_SIZE];
        StringTokenizer st;

        List<int[]>empty_spot = new ArrayList<>();

        for(int i = 0; i<BOARD_SIZE; i++){
            st = new StringTokenizer(br.readLine());
            for(int j = 0; j<BOARD_SIZE; j++){
                int ele = Integer.parseInt(st.nextToken());
                board[i][j] = ele - 1;
                if(ele == 0){
                    empty_spot.add(new int[]{i, j});
                }
            }
        }

        int[] weight = new int[BOARD_SIZE];
        int[] height = new int[BOARD_SIZE];
        int[] rect = new int[BOARD_SIZE];

        int[][] rect_idx = new int[BOARD_SIZE][BOARD_SIZE];

        for(int i = 0; i<BOARD_SIZE; i++){
            for(int j = 0; j<BOARD_SIZE; j++){
                if(i/3==0 && j/3==0){
                    rect_idx[i][j] = 0;
                }else if(i/3==0 && j/3==1){
                    rect_idx[i][j] = 1;
                }else if(i/3==0 && j/3==2){
                    rect_idx[i][j] = 2;
                }else if(i/3==1 && j/3==0){
                    rect_idx[i][j] = 3;
                }else if(i/3==1 && j/3==1){
                    rect_idx[i][j] = 4;
                }else if(i/3==1 && j/3==2){
                    rect_idx[i][j] = 5;
                }else if(i/3==2 && j/3==0){
                    rect_idx[i][j] = 6;
                }else if(i/3==2 && j/3==1){
                    rect_idx[i][j] = 7;
                }else if(i/3==2 && j/3==2){
                    rect_idx[i][j] = 8;
                }
            }
        }

        for(int i = 0; i<BOARD_SIZE; i++){
            for(int j = 0; j<BOARD_SIZE; j++){
                if(board[i][j] == -1)continue;
                weight[i] = (weight[i] | (1 << board[i][j]));
            }
        }
        for(int i = 0; i<BOARD_SIZE; i++){
            for(int j = 0; j<BOARD_SIZE; j++){
                if(board[j][i] == -1)continue;
                height[i] = (height[i] | (1 << board[j][i]));
            }
        }
        for(int i = 0; i<BOARD_SIZE; i++){
            for(int j = 0; j<BOARD_SIZE; j++){
                if(board[i][j] == -1)continue;
                int cur_idx = rect_idx[i][j];
                rect[cur_idx] = (rect[cur_idx] | (1 << board[i][j]));
            }
        }

        make_sudoku(0, board, empty_spot, weight, height, rect, rect_idx);
        for(int i = 0; i<BOARD_SIZE; i++){
            for(int j = 0; j<BOARD_SIZE; j++){
                System.out.print(answer_board[i][j]+1 + " ");
            }
            System.out.println();
        }
    }
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        solution_sudoku(br);
    }
}
/*
0 3 5 4 6 9 2 7 8
7 8 2 1 0 5 6 0 9
0 6 0 2 7 8 1 3 5
3 2 1 0 4 6 8 9 7
8 0 4 9 1 3 5 0 6
5 9 6 8 2 0 4 1 3
9 1 7 6 5 2 0 8 0
6 0 3 7 0 1 9 5 2
2 5 8 3 9 4 7 6 0
*/
/*
1 3 5 4 6 9 2 7 8
7 8 2 1 3 5 6 4 9
4 6 9 2 7 8 1 3 5
3 2 1 5 4 6 8 9 7
8 7 4 9 1 3 5 2 6
5 9 6 8 2 7 4 1 3
9 1 7 6 5 2 3 8 4
6 4 3 7 8 1 9 5 2
2 5 8 3 9 4 7 6 1

*/