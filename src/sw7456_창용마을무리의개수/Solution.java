package sw7456_창용마을무리의개수;

import java.io.*;
import java.util.HashSet;
import java.util.Set;
import java.util.StringTokenizer;

public class Solution {
    static int N;
    static int[] parents;
    static int[] ranks;

    static int find_parents(int cur){
        if(cur == parents[cur]){
            return cur;
        }
        return parents[cur] = find_parents(parents[cur]);
    }

    static int solution_changyong_country(BufferedReader br)throws IOException{
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        int M = Integer.parseInt(st.nextToken());
        parents = new int[N+1];
        ranks = new int[N+1];
        for(int i = 0; i<=N; i++){
            parents[i] = i;
            ranks[i] = 0;
        }

        for(int i =0 ; i<M; i++){
            st = new StringTokenizer(br.readLine());
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());

            int pa = find_parents(a);
            int pb = find_parents(b);
            if(pa == pb)continue;
            if(ranks[pa] < ranks[pb]){
                parents[pa] = pb;
            }else if(ranks[pa] > ranks[pb]){
                parents[pb] = pa;
            }else{
                ranks[pb]++;
                parents[pa] = pb;
            }
        }

        Set<Integer>groups = new HashSet<>();
        for(int i = 1; i<=N; i++){
            groups.add(find_parents(i));
        }
        return groups.size();
    }
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int T = Integer.parseInt(br.readLine());

        for(int test_case = 1; test_case <= T; test_case++)
        {

            System.out.println("#" + test_case + " " + solution_changyong_country(br));
            //bw.write("#" + test_case + " " + solution_working_order(br) + "\n");
            //bw.flush();

        }
    }
}
/*
2
6 5
1 2
2 5
5 1
3 4
4 6
6 8
1 2
2 5
5 1
3 4
4 6
5 4
2 4
2 3
 */