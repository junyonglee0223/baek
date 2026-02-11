package g25606;

import java.io.*;
import java.util.*;

public class Main {

    static void solutionRainySeason(int n, int q, int m, int[] buckets, List<int[]>querys){
        
        int[] declineVal = new int[n];
        int[] declineSum = new int[n];
        int[] bucketSum = new int[n+1];

        for(int i = 0; i<n; i++){
            declineVal[i] = 0;

            if(i == 0) bucketSum[i] = buckets[i];
            else bucketSum[i] = bucketSum[i-1] + buckets[i];
        }

        for(int i = 0; i<n; i++){

            int decIdx = i + 1;
            //share, remain
            int shareVal = buckets[i] / m;
            int remainVal = buckets[i] % m;

            for(int disNxt = 0; disNxt < shareVal; disNxt++){
                int nxtIdx = decIdx + disNxt;
                if(nxtIdx >= n)break;

                declineVal[nxtIdx] += m;
            }
            if(decIdx + shareVal < n){
                declineVal[decIdx + shareVal] += remainVal;
            }
            if(i == 0)declineSum[i] = declineVal[i];
            else declineSum[i] = declineSum[i-1] + declineVal[i];
        }


    
        for(int[] query : querys){
            int com = query[0];
            int val = query[1] - 1;
            if(com == 1){
                System.out.println(bucketSum[val] - declineSum[val]);
            }else{
                int tmpVal = 0;
                if(val == 0) tmpVal = declineSum[0];
                else tmpVal = declineSum[val] - declineSum[val-1];

                System.out.println(tmpVal);
            }
        }
    }

    
    static void monoMain(BufferedReader br) throws IOException{
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());
        int q = Integer.parseInt(st.nextToken());

        int[] buckets = new int[n];
        List<int[]> querys = new ArrayList<>();

        st = new StringTokenizer(br.readLine());
        for(int i =0 ; i<n; i++){
            buckets[i] = Integer.parseInt(st.nextToken());
        }

        for(int i = 0; i<q; i++){
            st = new StringTokenizer(br.readLine());
            int a = Integer.parseInt(st.nextToken());
            int t = Integer.parseInt(st.nextToken());

            querys.add(new int[]{a, t});
        }

        solutionRainySeason(n, q, m, buckets, querys);
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        // int T = Integer.parseInt(br.readLine());
        // while(T-- > 0){
        //     System.out.println("-------------------------");
        //     monoMain(br);
        // }

        monoMain(br);
    }
}


/*
2

8 3 3
3 5 10 8 7 1 2 7
1 5
1 3
2 6

5 10 5
10 20 5 8 11
1 1
1 3
1 5
2 2
2 4
*/
/*
16
12
9

10
15
11
10
15
*/

/*

문제 이해를 잘못함
매일 ai 만큼이 채워지고
m 만큼 사라짐

상자가 n개라는 의미가 아님
n개의 배열 존재

3 5 10 8 7 1 2 7

3 0 0 0 0 0 0 0
0 5 2 0 0 0 0 0
0 0 10 7 4 1 0 0 
0 0 0 8 5 2 0 0 
0 0 0 0 7 4 1 0 
0 0 0 0 0 1 0 0 
0 0 0 0 0 0 2 0
0 0 0 0 0 0 0 7

증발한 물의 양
현재 남아있는 물의 양
10^5 * 10^5 이라 배열 자체 불가능

시간에 따른 변화량을 최소한으로 저장해야 가능하다.

저장을 하되 어느 단위 기준으로 저장해야 하는지 생각
시간에 따른 변화량 -> n 

0 1 2 3 4 5 6 7 8

3 0 0

배열 자체의 관점으로 본다면 
10^5 * 10^5 연산이 들어가기 때문에 시간초과 가능성

구간 업데이트가 많은 상태
같은 값 업데이트는 아님

티켓 발행이라고 생각하면 됨
더해지는 값은 이미 배열에 존재하니
감소하는 부분에 대해 누적합으로 저장하면 될 듯 하다.
10^5 * 10^4 정도의 시간복잡도가 예상됨

쿼리에 대해서 10^5 * 1로만 잡아줘야 충분할 듯 하다.

*/
