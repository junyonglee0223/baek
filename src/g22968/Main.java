package g22968;
//g22968 균형

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
    static final long MAX_V = 1000000001;
    static final long MAX_H = 43;
    static long[] heights = new long[(int) (MAX_H + 1)];
    static void solution_init(){
        heights[1] = 1;
        heights[2] = 2;
        for(int h = 3; h<=MAX_H; h++){
            long ele = heights[h-1] + heights[h-2] + 1;
            heights[h] = ele;
        }
    }
    static int solution_avl_height(BufferedReader br) throws IOException{
        long V = Long.parseLong(br.readLine());
        int left = 0; int right = (int) MAX_H;
        while(left < right){
            int mid = (left + right) / 2;
            if(V >= heights[mid]){
                left = mid + 1;
            }else{
                right = mid;
            }
        }
        return left - 1;
    }
    public static void main(String[] args) throws IOException {
        solution_init();
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int T = Integer.parseInt(br.readLine());
        while(T-- > 0){
            System.out.println(solution_avl_height(br));
        }

    }
}
/*
5
1
2
5
10
1000000000
 */
