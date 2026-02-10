package g23829;

import java.io.*;
import java.util.*;

public class Main {

    static int binarySearchIdx(Long[] arr, Long val){
        int left = 0;
        int right = arr.length;
        while(left < right){
            int mid = (left + right) / 2;
            if(arr[mid] >= val){
                right = mid;
            }
            else{
                left = mid + 1;
            }
        }
        return left;
    }

    static void solutionHumanitiesArtsExploratoinWeek(int n, int q, Long[] roads, Long[] pictures){
        Long[] roadSum = new Long[n+1];
        roadSum[0] = 0L;
        //roadSum[i] = [i-1 , i)
        for(int i = 1; i<=n; i++){
            roadSum[i] = roadSum[i-1] + roads[i-1];
        }

        for(Long px : pictures){
            int pxIdx = binarySearchIdx(roads, px);

            Long ret = (px * pxIdx - roadSum[pxIdx]) 
                + (roadSum[n] - roadSum[pxIdx] - px * (n - pxIdx));

            System.out.println(ret);
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int n = Integer.parseInt(st.nextToken());
        int q = Integer.parseInt(st.nextToken());

        Long[] roads = new Long[n];
        st = new StringTokenizer(br.readLine());

        for(int i = 0; i<n; i++){
            roads[i] = Long.parseLong(st.nextToken());
        }
        
        Arrays.sort(roads);

        Long[] pictures = new Long[q];

        for(int i = 0; i<q; i++){
            pictures[i] = Long.parseLong(br.readLine());
        }

        solutionHumanitiesArtsExploratoinWeek(n, q, roads, pictures);
    }
}
/*
5 2
1 3 7 9 10
4
12
*/
/*
18
30
*/