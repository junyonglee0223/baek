package s1965;
//s1965 상자 넣기

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

public class Main {

    static int get_max_input_count(int[] arr){
        int n = arr.length;
        List<Integer>ret = new ArrayList<>();

        for(int i = 0; i<n; i++){
            int r_idx = ret.isEmpty() ? 0 : ret.size() - 1;
            if(ret.isEmpty() || ret.get(r_idx) < arr[i]){
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
        return ret.size();
    }
    static void solution_input_box(BufferedReader br) throws IOException {
        int n = Integer.parseInt(br.readLine());
        int[] arr = new int[n];

        StringTokenizer st = new StringTokenizer(br.readLine());
        for(int i = 0; i<n; i++){
            arr[i] = Integer.parseInt(st.nextToken());
        }
        int answer = get_max_input_count(arr);
        System.out.println(answer);
    }
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        solution_input_box(br);

//        int T = Integer.parseInt(br.readLine());
//        while(T-- > 0){
//            solution_input_box(br);
//        }
    }
}

/*
2
8
1 6 2 5 7 3 5 6
10
1 2 3 4 5 6 7 8 9 10
*/
/*
5
10
*/
