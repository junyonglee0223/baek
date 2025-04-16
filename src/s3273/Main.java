package s3273;
//s3273 두 수의 합

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {

    static int m_binary_search_idx(int[] arr, int value){
        int start = 0;
        int end = arr.length - 1;

        while(start < end){
            int mid = (start + end) >> 1;
            if(arr[mid] < value){
                start = mid + 1;
            }
            else{
                end = mid;
            }
        }
        return end;
    }

    static int find_pair(int[] arr, int target){
        int ret = 0;
        for (int j : arr) {
            int idx = Arrays.binarySearch(arr, target - j);
            int tmp_idx = m_binary_search_idx(arr, target - j);
            if (arr[tmp_idx] == target - j){
                ret++;
            }
        }
        return ret/2;
    }

    static void solution_two_nums_sum(BufferedReader br) throws IOException {
        int n = Integer.parseInt(br.readLine());

        StringTokenizer st = new StringTokenizer(br.readLine());
        int[] arr = new int[n];
        for(int i = 0; i<n; i++){
            arr[i] = Integer.parseInt(st.nextToken());
        }

        Arrays.sort(arr);

        int target = Integer.parseInt(br.readLine());
        System.out.println(find_pair(arr, target));
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        solution_two_nums_sum(br);
    }
}
/*
9
5 12 7 10 9 1 2 3 11
13
*/
/*
3
*/
