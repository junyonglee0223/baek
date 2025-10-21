package g14002;

import java.io.*;
import java.util.*;

public class Main {

    static List<Integer>max_trace;

    static void back_tracing(int idx, int[] arr, int[] order, int max_value, 
    List<Integer>trace){
        if(trace.size() == max_value + 1){

            for(int ele : trace){
                max_trace.add(ele);
            }

            //max_trace = trace;
            Collections.reverse(max_trace);
            // for(int ele : max_trace){
            //     System.out.print(ele + " ");
            // }
            // System.out.println();
            // //////////////////////////////////////////////
            // System.out.println(max_trace.size());
            return;
        }
        for(int nxt = idx - 1; nxt >=0; nxt--){
            if(!max_trace.isEmpty())return;

            if((order[nxt] == order[idx] - 1) && (arr[nxt] < arr[idx])){
                trace.add(arr[nxt]);
                back_tracing(nxt, arr, order, max_value, trace);
                trace.remove(trace.size() - 1);
            }
        }
    }


    static void solution_lcs(BufferedReader br) throws Exception{
        max_trace = new ArrayList<>();
        int n = Integer.parseInt(br.readLine());
        StringTokenizer st = new StringTokenizer(br.readLine());

        int[] arr = new int[n];

        for(int i = 0; i<n; i++){
            arr[i] = Integer.parseInt(st.nextToken());
        }

        List<Integer> saved = new ArrayList<>();
        int[] order = new int[n];

        for(int i =0 ; i<n; i++){
            if(saved.isEmpty() || saved.get(saved.size() - 1) < arr[i]){
                saved.add(arr[i]);
                order[i] = saved.size() - 1;
            }else{
                int left = 0; int right = saved.size() - 1;
                while(left < right){
                    int mid = (left + right) / 2;
                    if(saved.get(mid) >= arr[i]){
                        right = mid;
                    }else{
                        left = mid + 1;
                    }
                }
                saved.set(left, arr[i]);
                order[i] = left;
            }
        }


        
        
        int max_length = saved.size();
        int start_idx = n - 1;
        for(int i = n-1; i>=0; i--){
            if(order[i] == max_length-1){
                start_idx = i;
                break;
            }
        }

        List<Integer>trace = new ArrayList<>();
        trace.add(arr[start_idx]);
        
        back_tracing(start_idx, arr, order, max_length-1, trace);

    
        System.out.println(max_trace.size());
        for(int i = 0; i<max_trace.size(); i++){
            System.out.print(max_trace.get(i)+" ");
        }
        System.out.println();
    }


    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        solution_lcs(br);
    }
}

/*
6
10 20 10 30 20 50
*/
/*
4
10 20 30 50
 */