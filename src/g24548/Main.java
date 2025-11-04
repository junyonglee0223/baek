package g24548;

import java.io.*;

public class Main {
    static int char2int(char c){
        if(c == 'T')return 0;
        if(c == 'G')return 1;
        if(c == 'F')return 2;
        if(c == 'P')return 3;
        return -1;
    }

    static long solution_road_info(BufferedReader br) throws Exception {
        int N = Integer.parseInt(br.readLine());
        String road = br.readLine();

        int[] count = new int[4];
        long[] freq = new long[81];
        int state = 0;
        freq[state] = 1;

        long ret = 0;

        for (int i = 0; i < N; i++) {
            int idx = char2int(road.charAt(i));
            count[idx] = (count[idx] + 1) % 3;
            state = count[0] * 27 + count[1] * 9 + count[2] * 3 + count[3];
            ret += freq[state];
            freq[state]++;
        }

        return ret;
    }

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        System.out.println(solution_road_info(br));
    }
}
