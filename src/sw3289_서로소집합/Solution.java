package sw3289_서로소집합;

import java.io.*;
import java.util.StringTokenizer;

public class Solution {
    static int[] parents;
    static int N;
    static int[] ranks;

    static int find_parents(int cur){
        if(cur == parents[cur]){
            return cur;
        }
        return parents[cur] = find_parents(parents[cur]);
    }
    static String solution_exclude_groups(BufferedReader br) throws IOException{
        StringBuilder ret = new StringBuilder();
        StringTokenizer st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        parents = new int[N+1];
        ranks = new int[N+1];
        for(int i = 0; i<=N; i++){
            parents[i] = i;
            ranks[i] = 0;
        }
        int M = Integer.parseInt(st.nextToken());
        for(int i = 0; i<M ;i++){
            st = new StringTokenizer(br.readLine());
            int cmd = Integer.parseInt(st.nextToken());
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());

            int pa = find_parents(a);
            int pb = find_parents(b);
            if(cmd == 0){
                if(pa == pb)continue;
                if(ranks[pa] < ranks[pb]){
                    parents[pa] = pb;
                }else if(ranks[pa] > ranks[pb]){
                    parents[pb] = pa;
                }else{
                    ranks[pb]++;
                    parents[pa] = pb;
                }
            }else if(cmd == 1){
                if(pa == pb){
                    ret.append(1);
                }else{
                    ret.append(0);
                }
            }
        }
        return ret.toString();
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int T = Integer.parseInt(br.readLine());

        for(int test_case = 1; test_case <= T; test_case++)
        {

            System.out.println("#" + test_case + " " + solution_exclude_groups(br));
            //bw.write("#" + test_case + " " + solution_working_order(br) + "\n");
            //bw.flush();

        }
    }
}
/*
1
7 8
0 1 3
1 1 7
0 7 6
1 7 1
0 3 7
0 4 2
0 1 1
1 1 1

 */