package g25606;

import java.io.*;
import java.util.*;

public class Main {

    static String solutionRainySeason(int n, int q, int m, int[] buckets, List<int[]>querys){
        
        int[] declineVal = new int[n];
        int[] declineSum = new int[n];
        int[] bucketSum = new int[n+1];

        for(int i = 0; i<n; i++){
            declineVal[i] = 0;

            if(i == 0) bucketSum[i] = buckets[i];
            else bucketSum[i] = bucketSum[i-1] + buckets[i];
        }

        for(int i = 0; i<n; i++){
            //share, remain
            int shareVal = buckets[i] / m;
            int remainVal = buckets[i] % m;

            if(i + 1 < n)declineVal[i+1] += m;
            if(i + shareVal + 1 < n){
                declineVal[i + 1 + shareVal] -= m;
                declineVal[i + 1 + shareVal] += remainVal;
            }
            if(i + shareVal + 2 < n){
                declineVal[i+2+shareVal] -= remainVal;
            }
        }

        declineSum[0] = declineVal[0];
        for(int i = 1; i<n; i++){
            declineSum[i] = declineSum[i-1] + declineVal[i];
        }

        int[] declineSumSum = new int[n];
        declineSumSum[0] = declineSum[0];
        for(int i = 1; i<n; i++){
            declineSumSum[i] = declineSumSum[i-1] + declineSum[i];
        }

        StringBuilder sb = new StringBuilder();

        for(int[] query : querys){
            int com = query[0];
            int val = query[1] - 1;
            if(com == 1){
                int tmpVal = bucketSum[val] - declineSumSum[val];
                sb.append(tmpVal).append("\n");
            }else{
                int tmpVal = 0;
                if(val == 0) tmpVal = declineSumSum[0];
                else tmpVal = declineSumSum[val] - declineSumSum[val-1];

                sb.append(tmpVal).append("\n");
            }
        }

        return sb.toString();
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

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

        String ret = solutionRainySeason(n, q, m, buckets, querys);
        bw.write(ret);
        bw.flush();

        bw.close();
        br.close();
    }
}