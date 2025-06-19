package g14719;
//g14719 빗물


import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    static void solution_raindrop(BufferedReader br) throws IOException {
        StringTokenizer st = new StringTokenizer(br.readLine());
        int H = Integer.parseInt(st.nextToken());
        int W = Integer.parseInt(st.nextToken());

        int[][] board = new int[H][W];

        for(int i = 0; i<H; i++){
            for(int j = 0; j<W; j++){
                board[i][j] = 0;
            }
        }

        st = new StringTokenizer(br.readLine());
        for(int i = 0; i<W; i++){
            int ele = Integer.parseInt(st.nextToken());
            for(int j = 0; j<ele; j++){
                board[j][i] = 1;
            }
        }

        int answer = 0;
        for(int i = 0; i<H; i++){
            int idx = -1;
            for(int j = 0; j<W; j++){
                if(board[i][j] == 1){
                    if(idx != -1) answer += (j - idx - 1);
                    idx = j;
                }
            }
        }
        System.out.println(answer);
    }
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        solution_raindrop(br);

//        int T = Integer.parseInt(br.readLine());
//        while(T-- > 0){
//            solution_raindrop(br);
//        }
    }
}
/*
3
4 4
3 0 1 4
4 8
3 1 2 3 4 1 1 2
3 5
0 0 0 2 0
*/
/*
5
5
0
*/