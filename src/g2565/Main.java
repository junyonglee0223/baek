package g2565;
//g2565 전깃줄


import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.lang.reflect.Array;
import java.util.*;

public class Main {

    static void solution_electronic_line(BufferedReader br) throws IOException {
        int n = Integer.parseInt(br.readLine());
        int[][] input_arr = new int[n][2];

        StringTokenizer st;
        for(int i = 0; i<n; i++){
            st = new StringTokenizer(br.readLine());
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());

            input_arr[i][0] = a;
            input_arr[i][1] = b;
        }

        //Arrays.sort(input_arr, Comparator.comparingInt(x -> x[0]));
        Arrays.sort(input_arr, (x1, x2) -> Integer.compare(x1[0], x2[0]));


        int[] arr = new int[n];
        for(int i = 0; i<n; i++){
            arr[i] = input_arr[i][1];
        }


        List<Integer> ret = new ArrayList<>();
        for(int i = 0; i<n; i++){
            int r_idx = ret.isEmpty() ? 0 : ret.size() - 1;
            if(ret.isEmpty() || ret.get(r_idx) < arr[i]) {
                ret.add(arr[i]);
            }else{
                int start = 0;
                int end = r_idx;

                while(start <= end){
                    int mid = (start + end) / 2;
                    if(ret.get(mid) >= arr[i]){
                        end = mid - 1;
                    }else{
                        start = mid + 1;
                    }
                }
                ret.set(start, arr[i]);
            }
        }

        int answer = n - ret.size();
        System.out.println(answer);
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        solution_electronic_line(br);

    }

}


/*
8
1 8
3 9
2 2
4 1
6 4
10 10
9 7
7 6
*/
/*
3
*/