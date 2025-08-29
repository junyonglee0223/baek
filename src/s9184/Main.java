package s9184;

import java.io.*;
import java.util.StringTokenizer;

public class Main {
    static int[][][] dp;
    static String solution_exciting_function_execution(BufferedReader br) throws IOException{
        dp = new int[21][21][21];

        for(int i = 0; i<=20; i++){
            for(int j = 0; j<=20; j++){
                for(int k = 0; k<=20; k++){
                    dp[i][j][k] = Integer.MIN_VALUE;
                }
            }
        }

        StringTokenizer st = new StringTokenizer(br.readLine());
        int a = Integer.parseInt(st.nextToken());
        int b = Integer.parseInt(st.nextToken());
        int c = Integer.parseInt(st.nextToken());

        StringBuilder ret = new StringBuilder();
        while(a != -1 || b != -1 || c != -1){
            int tmp_ret = do_function(a, b, c);
            ret.append(output(a, b, c, tmp_ret));

            st = new StringTokenizer(br.readLine());
            a = Integer.parseInt(st.nextToken());
            b = Integer.parseInt(st.nextToken());
            c = Integer.parseInt(st.nextToken());
        }
        return ret.toString();
    }
    static int do_function(int a, int b, int c){
        if(a <= 0 || b <= 0 || c <= 0)return 1;
        if(a > 20 || b > 20 || c > 20)return do_function(20, 20, 20);

        if(dp[a][b][c] != Integer.MIN_VALUE)return dp[a][b][c];

//w(a-1, b, c) + w(a-1, b-1, c) + w(a-1, b, c-1) - w(a-1, b-1, c-1)
        return dp[a][b][c]
                = do_function(a-1, b, c)
                    + do_function(a-1, b-1, c)
                        + do_function(a-1, b, c-1)
                            - do_function(a-1, b-1, c-1);
    }

    static String output(int a, int b, int c, int ret){
        StringBuilder sb = new StringBuilder();
        sb.append("w(").append(a).append(", ").append(b).append(", ").append(c).append(")")
                .append(" = ").append(ret).append("\n");
        return sb.toString();
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        bw.write(solution_exciting_function_execution(br));
        bw.flush();
        bw.close();
        br.close();
    }
}
/*
조건에서 0이하, 20 초과에 대해서는 1, all 20으로 처리하고 있음
즉 배열이 0 ~ 20 사이로 결정됨
w(a-1, b, c) + w(a-1, b-1, c) + w(a-1, b, c-1) - w(a-1, b-1, c-1)

 */
/*

if a <= 0 or b <= 0 or c <= 0, then w(a, b, c) returns:
    1

if a > 20 or b > 20 or c > 20, then w(a, b, c) returns:
    w(20, 20, 20)

if a < b and b < c, then w(a, b, c) returns:
    w(a, b, c-1) + w(a, b-1, c-1) - w(a, b-1, c)

otherwise it returns:
    w(a-1, b, c) + w(a-1, b-1, c) + w(a-1, b, c-1) - w(a-1, b-1, c-1)

입력
입력은 세 정수 a, b, c로 이루어져 있으며, 한 줄에 하나씩 주어진다. 
입력의 마지막은 -1 -1 -1로 나타내며, 세 정수가 모두 -1인 경우는 입력의 마지막을 제외하면 없다.

출력
입력으로 주어진 각각의 a, b, c에 대해서, w(a, b, c)를 출력한다.

제한
-50 ≤ a, b, c ≤ 50
예제 입력 1
1 1 1
2 2 2
10 4 6
50 50 50
-1 7 18
-1 -1 -1
예제 출력 1
w(1, 1, 1) = 2
w(2, 2, 2) = 4
w(10, 4, 6) = 523
w(50, 50, 50) = 1048576
w(-1, 7, 18) = 1
 */