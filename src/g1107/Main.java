package g1107;

import java.io.*;
import java.util.*;

public class Main {

    static int[] isMatchNum(int ele, int excludeNum){
        if (ele == 0) {
            if ((excludeNum & 1) != 0) return new int[]{0, 0};
            return new int[]{1, 1};
        }

        int tmp = ele;
        int count = 0;
        while(tmp > 0){
            int tNum = tmp%10;
            count++;
            if((excludeNum & (1 << tNum)) != 0)return new int[]{0, 0};
            tmp /= 10;
        }
        return new int[]{1, count};
    }


    static int solutionRemoteControl(BufferedReader br) throws Exception {
        StringTokenizer st;
        int target = Integer.parseInt(br.readLine());
        int eraseSize = Integer.parseInt(br.readLine());

        int excludeNum = 0;
        if(eraseSize != 0){
            st = new StringTokenizer(br.readLine());
            for(int i = 0; i<eraseSize; i++){
                int ele = Integer.parseInt(st.nextToken());
                excludeNum |= (1 << ele);
            }
        }

        int ret = Math.abs(target - 100);


        for(int i = 1000000; i>=0; i--){
            int[] tmpRet = isMatchNum(i, excludeNum);
            if(tmpRet[0] != 1)continue;
            ret = Math.min(ret, tmpRet[1] + Math.abs(target - i));
        }

        return ret;
    }
    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        System.out.println(solutionRemoteControl(br));
    }
    
}
/*
5457
3
6 7 8

100
5
0 1 2 3 4

500000
8
0 2 3 4 6 7 8 9


100
3
1 0 5

14124
0

1
9
1 2 3 4 5 6 7 8 9

80000
2
8 9
 */
/*
6
0
2
11117
0
5
2
2228
 */