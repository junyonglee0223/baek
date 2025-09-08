package s2839;
//s2839 설탕 배달

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {

    static int solution_sugar_delivery(BufferedReader br) throws IOException{
        int N = Integer.parseInt(br.readLine());
        int max_5 = N / 5;
        int ret = -1;
        for(int i = max_5; i >= 0; i--){
            int left = N - i * 5;
            if(left % 3 == 0){
                ret = i + left / 3;
                break;
            }
        }
        return ret;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        System.out.println(solution_sugar_delivery(br));


        //        int T = Integer.parseInt(br.readLine());
//        while(T-- > 0){
//            int ret = solution_sugar_delivery(br);
//            System.out.println(ret);
//        }
    }
}

/*
5
18
4
6
9
11


 */