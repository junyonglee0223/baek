package g3095;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
    static int[][] board;
    static int N;

    static boolean is_range(int x, int y){
        return x >= 0 && x < N && y >= 0 && y < N;
    }
    static boolean is_pos(int x, int y, int size){
        int target_x = x + size / 2;
        int target_y = y + size / 2;

        if(x < 0 || y < 0 || x + size > N || y + size > N) return false;

        for(int i = x; i<x+size; i++){
            for(int j = y; j < y + size; j++){
                if(i == target_x || j == target_y){
                    if(board[i][j] != 1)return false;
                }else {
                    if (board[i][j] != 0) return false;
                }
            }
        }
        return true;
    }
    static int solution_plus_counting(BufferedReader br)throws IOException{
        N = Integer.parseInt(br.readLine());
        board = new int[N][N];

        for(int i = 0; i<N; i++){
            String str = br.readLine();
            for(int j = 0; j<N ;j++){
                if(str.charAt(j) == '1')board[i][j] = 1;
                else board[i][j] = 0;
            }
        }

        int ret = 0;

        for(int i = 0; i<N; i++){
            for(int j = 0; j<N ;j++){
                if(!is_range(i-1, j-1) || !is_range(i+1, j+1))continue;
                if(board[i-1][j] != 1 ||
                        board[i][j+1] != 1 ||
                        board[i][j-1] != 1 ||
                        board[i+1][j] != 1)continue;

                for(int size = 3; size <= N; size += 2){
                    int start_x = i - size / 2;
                    int start_y = j - size / 2;
                        if(!is_pos(start_x, start_y, size)){
                            break;
                        }
                        //System.out.println(i+" "+j+" "+size);
                        ret++;
                }
            }
        }

        return ret;
    }


    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        System.out.println(solution_plus_counting(br));
//        int T = Integer.parseInt(br.readLine());
//        while(T-- > 0){
//            System.out.println(solution_plus_counting(br));
//        }
    }
}

/*
2
5
00100
00100
11111
00100
00100
8
00010000
00010000
00010000
11111111
00010000
00010010
00010111
00010010
 */
/*
2
3
 */