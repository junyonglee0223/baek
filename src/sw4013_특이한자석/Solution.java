package sw4013_특이한자석;
//:recycle: SW4013_UniqueMagnet_이준용.java

import java.io.*;
import java.util.StringTokenizer;


public class Solution {
    static int[][] magnets;
    static int[] status;
    static void rotate_clockwise(int[] arr){
        int tmp = arr[7];
        for(int i = 6; i>=0; i--){
            arr[i+1] = arr[i];
        }
        arr[0] = tmp;
    }
    static void rotate_anti_clockwise(int[] arr){
        int tmp = arr[0];
        for(int i = 0; i<7; i++){
            arr[i] = arr[i+1];
        }
        arr[7] = tmp;
    }
    static void rotate_magnets(int[] rotate_dir){
        for(int i = 0; i<4; i++){
            if(rotate_dir[i] == 1){
                rotate_clockwise(magnets[i]);
            }else if(rotate_dir[i] == -1){
                rotate_anti_clockwise(magnets[i]);
            }
        }
    }
    static void update_status(){
        for(int i = 0; i<3; i++){
            if(magnets[i][2] != magnets[i+1][6]){
                status[i] = 1;
            }else{
                status[i] = 0;
            }
        }
    }

    static int solution_unique_magnet(BufferedReader br) throws IOException{
        int cmd = Integer.parseInt(br.readLine());
        StringTokenizer st;
        magnets = new int[4][8];
        status = new int[3];
        for(int i = 0; i<4; i++){
            st = new StringTokenizer(br.readLine());
            for(int j = 0; j<8; j++){
                magnets[i][j] = Integer.parseInt(st.nextToken());
            }
        }
        update_status();

        for(int c = 0; c<cmd; c++){
            st = new StringTokenizer(br.readLine());
            int idx = Integer.parseInt(st.nextToken()) - 1;
            int dir = Integer.parseInt(st.nextToken());
            int[] rotate_dir = new int[4];
            rotate_dir[idx] = dir;
            int left = idx - 1;
            int right = idx + 1;

            while(left >= 0){
                if(status[left] == 0)break;
                rotate_dir[left] = rotate_dir[left+1] * -1;
                left--;
            }
            while(right < 4){
                if(status[right-1] == 0)break;
                rotate_dir[right] = rotate_dir[right - 1] * -1;
                right++;
            }
            rotate_magnets(rotate_dir);
            update_status();
        }

        int ret = 0;
        for(int i = 0; i<4; i++){
            if(magnets[i][0] == 1){
                ret += (1<<i);
            }
        }

        return ret;
    }
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int T = Integer.parseInt(br.readLine());

        for(int test_case = 1; test_case <= T; test_case++)
        {

            System.out.println("#" + test_case + " " + solution_unique_magnet(br));
        }
    }
}
/*

10
2
0 0 1 0 0 1 0 0
1 0 0 1 1 1 0 1
0 0 1 0 1 1 0 0
0 0 1 0 1 1 0 1
1 1
3 -1
 */
/*
magnets -> 4개, 8날
다른 경우만 반대로 1칸

각각 상태확인
2 <-> 6 - 2 <-> 6 ...
이런 구조임
 */