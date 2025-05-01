package s1026;
//s1026 보물

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {
    static void solution_treasure(BufferedReader br) throws IOException {
        StringTokenizer st;
        int n = Integer.parseInt(br.readLine());
        int[] a = new int[n];
        int[] b = new int[n];

        st = new StringTokenizer(br.readLine());
        for(int i = 0; i<n; i++){
            a[i] = Integer.parseInt(st.nextToken());
        }
        st = new StringTokenizer(br.readLine());
        for(int i = 0; i<n; i++){
            b[i] = Integer.parseInt(st.nextToken());
        }

        Arrays.sort(a);
        Arrays.sort(b);
        for(int i = 0; i<n/2; i++){
            int tmp = b[i];
            b[i] = b[n - 1 - i];
            b[n - 1 - i] = tmp;
        }

        int answer = 0;
        for(int i = 0; i<n; i++){
            answer += (a[i] * b[i]);
        }
        System.out.println(answer);
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        solution_treasure(br);
//        int T = Integer.parseInt(br.readLine());
//        while(T-- > 0){
//            solution_treasure(br);
//        }
    }
}
/*
3
5
1 1 1 6 0
2 7 8 3 1
3
1 1 3
10 30 20
9
5 15 100 31 39 0 0 3 26
11 12 13 2 3 4 5 9 1
*/
/*
18
80
528
*/