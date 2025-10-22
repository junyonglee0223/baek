package g12892;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.Comparator;
import java.util.StringTokenizer;

public class Main {

    static long solution_birthday_gift(BufferedReader br) throws Exception{

        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        long d = Long.parseLong(st.nextToken());
        
        long[][] gifts = new long[n][2];
        
        for(int i = 0; i<n; i++){
            st = new StringTokenizer(br.readLine());
            gifts[i][0] = Long.parseLong(st.nextToken());
            gifts[i][1] = Long.parseLong(st.nextToken());
        }
        
        Arrays.sort(gifts, new Comparator<long[]>() {
            @Override
            public int compare(long[] a, long[] b){
                if(a[0] == b[0])return (int)(a[1] - b[1]);
                return (int)(a[0] - b[0]);
            }
        });
        
        int left = 0, right = 0;
        
        long answer = 0;

        long tmp = 0;
        for(right = 0; right < n; right++){
            //left manipulating
            while(gifts[left][0] <= gifts[right][0] - d){
                tmp -= gifts[left][1];
                left++;
            }

            tmp += gifts[right][1];
            answer = Math.max(answer, tmp);
        }
        return answer;
    }
    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        System.out.println(solution_birthday_gift(br));

    }
    
}
/*
4 2
13 10
10 20
11 30
12 40
 */
/*
70
 */