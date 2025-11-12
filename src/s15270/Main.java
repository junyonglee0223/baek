package s15270;

import java.io.*;
import java.util.*;

public class Main {

    static int max_size = 0;
    static int[] max_visited;

    static void copy_arr(int[] arr1, int[] arr2){
        int n = arr1.length;
        for(int i = 0; i<n; i++){
            arr1[i] = arr2[i];
        }
    }

    static void dfs_edge(int cur, int count, int[] visited, int[][] edges){
        int m = edges.length;
        if(count > max_size){
            max_size = count;
            copy_arr(max_visited, visited);
        }

        for(int i = cur; i< m; i++){
            int a = edges[i][0];
            int b = edges[i][1];

            if(visited[a] == 0 && visited[b] == 0){
                visited[a] = visited[b] = 1;
                dfs_edge(i + 1, count + 1, visited, edges);
                visited[a] = visited[b] = 0;
            }
        }
    }

    public static int solution_friend_palendrome(BufferedReader br) throws Exception {
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());

        int[][] edges = new int[m][2];
        for(int i = 0; i<m; i++){
            st = new StringTokenizer(br.readLine());
            int a = Integer.parseInt(st.nextToken()) - 1;
            int b = Integer.parseInt(st.nextToken()) - 1;
            edges[i] = new int[]{a, b};
        }

        max_size = 0;
        max_visited = new int[n];

        int[] visited = new int[n];
        dfs_edge(0, 0, visited, edges);

        int ret = max_size * 2;
        for(int i = 0; i<n; i++){
            if(max_visited[i] == 0){
                ret = ret + 1;
                break;
            }
        }

        return ret;
    }
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        System.out.println(solution_friend_palendrome(br));

        // int T = Integer.parseInt(br.readLine());
        // while(T-- > 0){
        //     System.out.println("answer " + solution_friend_palendrome(br));
        // }

    }
    
}
/*
3
3 3
1 2
2 3
3 1
20 0
6 5
1 2
2 3
3 4
4 5
5 6
 */
/*
3
1
6
 */