package g27980;

import java.io.*;
import java.util.*;

public class Main {
    static int n, m;
    static String str1, str2;
    static int[][] dp;

    //i -> origin text, j -> curve text
    static int tracking_string(int cur_i, int cur_j){
        if(dp[cur_i][cur_j] != -1)return dp[cur_i][cur_j];

        dp[cur_i][cur_j] = 0;
        int isMatch = (str1.charAt(cur_i) == str2.charAt(cur_j)) ? 1 : 0;

        int left = 0, right = 0;
        if(cur_i + 1 < n && cur_j + 1 < m){
            left = tracking_string(cur_i + 1, cur_j + 1);
        }
        if(cur_i - 1 >=0 && cur_j + 1 < m){
            right = tracking_string(cur_i - 1, cur_j + 1);
        }
        return dp[cur_i][cur_j] = Math.max(left, right) + isMatch;
    }

    static int solution_string_game(BufferedReader br) throws Exception {
        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());
        str1 = br.readLine();
        str2 = br.readLine();

        dp = new int[n][m];
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                dp[i][j] = -1;
            }
        }

        int ret = 0;
        for(int i = 0; i<n; i++){
            ret = Math.max(ret, tracking_string(i, 0));
        }
        return ret;
    }
    
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        System.out.println(solution_string_game(br));
        
        // int T = Integer.parseInt(br.readLine());
        // while(T-- > 0){
        //     System.out.println(solution_string_game(br));
        // }
    }
    
}
/*
전체 가능한 가짓수를 미리 설정하고 계산하는 것이 가능한지?
모든 탐색을 돌려서 가능한지 의문


dp 활용하면 가능할 듯 하다.
i, j를 매칭시켜서 만들 수 있는 최대 길이를 설정하는 방식
dp[i][j] ?? -> 2.5 * 10^7
 */
/*
3
6 7
KONKUK
KONDUCK
2 7
AB
AAAAAAA
3 10
AAA
HELLOWORLD
 */
/*
4
4
0
 */