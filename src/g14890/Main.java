package g14890;
//g14890 경사로

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    static boolean is_same_value_position(int[] board, int start, int end){
        int value = board[start];
        for(int i = start + 1; i<=end; i++){
            if(board[i] != value)return false;
        }
        return true;
    }

    static boolean is_pos_ramp(int[] board, int L){
        int N = board.length;
        int end_pnt = N-1;
        int[] set_ramps = new int[N];

        int idx = 0;
        while(idx < end_pnt){
            if(idx+1<=end_pnt && board[idx] == board[idx+1]+1){
                if(idx + L > end_pnt)return false;
                if(!is_same_value_position(board, idx+1, idx+L))return false;
                for(int i = idx+1; i<=idx+L; i++){
                    set_ramps[i] = 1;
                }
                idx = idx + L;
            }
            else if(idx+1<=end_pnt && board[idx]+1 == board[idx+1]){
                int prv_idx = idx - L + 1;
                if(prv_idx < 0)return false;
                if(set_ramps[prv_idx] == 1)return false;
                if(!is_same_value_position(board, prv_idx, idx))return false;
                for(int i = prv_idx; i<=idx; i++){
                    set_ramps[i] = -1;
                }
                idx++;
            }else if(idx+1<=end_pnt && board[idx] == board[idx+1]){
                idx++;
            }else{
                return false;
            }
        }
        return true;
    }

    static void solution_ramp(BufferedReader br) throws IOException {
        StringTokenizer st = new StringTokenizer(br.readLine());
        int N = Integer.parseInt(st.nextToken());
        int L = Integer.parseInt(st.nextToken());

        int[][] board = new int[N][N];
        for(int i = 0; i<N; i++){
            st = new StringTokenizer(br.readLine());
            for(int j = 0; j<N; j++){
                board[i][j] = Integer.parseInt(st.nextToken());
            }
        }
        int answer = 0;
        for(int i = 0; i<N; i++){
            if(is_pos_ramp(board[i], L)) answer++;
        }

        for(int i = 0; i<N; i++){
            int[] tmp_board = new int[N];
            for(int j = 0; j<N; j++){
                tmp_board[j] = board[j][i];
            }
            if(is_pos_ramp(tmp_board, L))answer++;
        }
        System.out.println(answer);

    }
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        solution_ramp(br);

//        int T = Integer.parseInt(br.readLine());
//        while(T-- > 0){
//            solution_ramp(br);
//        }
    }
}

/*
4
6 2
3 3 3 3 3 3
2 3 3 3 3 3
2 2 2 3 2 3
1 1 1 2 2 2
1 1 1 3 3 1
1 1 2 3 3 2
6 2
3 2 1 1 2 3
3 2 2 1 2 3
3 2 2 2 3 3
3 3 3 3 3 3
3 3 3 3 2 2
3 3 3 3 2 2
6 3
3 2 1 1 2 3
3 2 2 1 2 3
3 2 2 2 3 3
3 3 3 3 3 3
3 3 3 3 2 2
3 3 3 3 2 2
6 1
3 2 1 1 2 3
3 2 2 1 2 3
3 2 2 2 3 3
3 3 3 3 3 3
3 3 3 3 2 2
3 3 3 3 2 2
*/
/*
3
7
3
11
*/