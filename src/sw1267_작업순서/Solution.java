package sw1267_작업순서;
//SW1267_JobOrder_이준용.java
import java.io.*;
import java.util.*;

public class Solution {

    static String solution_working_order(BufferedReader br)throws IOException{
        StringTokenizer st = new StringTokenizer(br.readLine());
        int V = Integer.parseInt(st.nextToken());
        int E = Integer.parseInt(st.nextToken());

        int[] inorder = new int[V+1];
        List<List<Integer>> adj = new ArrayList<>();
        for(int i = 0; i<=V; i++){
            adj.add(new ArrayList<>());
        }

        st = new StringTokenizer(br.readLine());
        for(int i = 0; i<E; i++){
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());
            inorder[b]++;
            adj.get(a).add(b);
        }

        List<Integer>ret = new ArrayList<>();
        Queue<Integer>que = new ArrayDeque<>();
        for(int i = 1; i<=V; i++){
            if(inorder[i] == 0){
                que.add(i);
            }
        }
        while(!que.isEmpty()){
            int cur = que.poll();
            ret.add(cur);
            for(int nxt : adj.get(cur)){
                if(--inorder[nxt] == 0){
                    que.add(nxt);
                }
            }
        }

        StringBuilder sb = new StringBuilder();
        for(int ele : ret){
            sb.append(ele).append(" ");
        }
        return sb.toString();
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int T = 10;

        for(int test_case = 1; test_case <= T; test_case++)
        {

            System.out.println("#" + test_case + " " + solution_working_order(br));
            //bw.write("#" + test_case + " " + solution_working_order(br) + "\n");
            //bw.flush();

        }
    }
}
/*
9 9
4 1 1 2 2 3 2 7 5 6 7 6 1 5 8 5 8 9
5 4
1 2 2 3 4 1 1 5
 */