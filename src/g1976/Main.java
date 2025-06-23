package g1976;
//g1976 여행 가자


import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    static void solution_lets_go_travel(BufferedReader br) throws IOException {
        StringTokenizer st;
        int N = Integer.parseInt(br.readLine());
        int M = Integer.parseInt(br.readLine());

        int[][] board = new int[N][N];
        for(int i = 0; i<N; i++){
            st = new StringTokenizer(br.readLine());
            for(int j = 0; j<N; j++){
                board[i][j] = Integer.parseInt(st.nextToken());
            }
        }
        for(int i = 0; i<N; i++){
            board[i][i] = 1;
        }

        for(int k = 0; k < N; k++){
            for(int i = 0; i<N; i++){
                for(int j = 0; j<N; j++){
                    if(board[i][k] == 1 && board[k][j] == 1){
                        board[i][j] = 1;
                    }
                }
            }
        }

        int[] travel_ele = new int[M];
        st = new StringTokenizer(br.readLine());

        for(int i = 0; i<M; i++){
            travel_ele[i] = Integer.parseInt(st.nextToken()) - 1;
        }

        boolean answer = true;
        int prev = -1;
        for(int i = 0; i<M; i++){
            int cur = travel_ele[i];
            if(i != 0 && board[prev][cur] == 0){
                answer = false;
                break;
            }
            prev = cur;
        }
        if(answer) System.out.println("YES");
        else System.out.println("NO");
    }
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        solution_lets_go_travel(br);
    }
}

/*
3
3
0 1 0
1 0 1
0 1 0
1 2 3
*/
/*
YES
*/