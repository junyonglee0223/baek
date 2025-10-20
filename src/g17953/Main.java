package g17953;


import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    static int solution_disert(BufferedReader br) throws Exception {
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());

        int[][] arr = new int[m][n];
        for (int i = 0; i < m; i++) {
            st = new StringTokenizer(br.readLine());
            for (int j = 0; j < n; j++) {
                arr[i][j] = Integer.parseInt(st.nextToken());
            }
        }

        int[] cache = new int[m];
        for (int i = 0; i < m; i++)
            cache[i] = 0;

        for (int i = 0; i < n; i++) {
            int[] new_cache = new int[m];

            for (int j = 0; j < m; j++) {
                int tmp = 0;
                for (int k = 0; k < m; k++) {
                    tmp = Math.max(tmp, cache[k] + ((j == k && i > 0) ? arr[j][i] / 2 : arr[j][i]));
                }
                new_cache[j] = tmp;
            }
            cache = new_cache;
        }
        int ret = 0;
        for (int i = 0; i < m; i++) {
            ret = Math.max(ret, cache[i]);
        }

        return ret;
    }

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        System.out.println(solution_disert(br));

        // int T = Integer.parseInt(br.readLine());
        // while(T-- > 0){
        //     System.out.println(solution_disert(br));
        // }

    }
}

/*
2
3 2
2 6 7
3 8 5
4 3
8 12 3 8
1 2 6 10
1 5 4 5
 */

/*
 * 
* 17
* 28
* 1-2-1 순으로 2 + 8 + 7 = 17이 최댓값이 된다.
* 1-1-2-1 순으로 8 + (12 / 2) + 6 + 8 = 28이 최댓값이 된다.
* n <= 10^5, m <= 10
 * 
 */