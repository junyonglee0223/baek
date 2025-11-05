package g17471;

import java.io.*;
import java.util.*;

public class Main {

    static int visited;
    static void dfs_travel(int cur, int state, List<List<Integer>>adj){

        for(int nxt : adj.get(cur)){
            if((state & (1 << nxt)) == 0)continue;
            if((visited & (1 << nxt)) != 0)continue;
            visited = (visited | (1 << nxt));
            dfs_travel(nxt, state, adj);
        }
    }

    static boolean is_dfs(int state, List<List<Integer>>adj){
        visited = 0;
        int start = -1;
        int n = adj.size();
        for(int i = 0; i<n; i++){
            if((state & (1 << i)) != 0){
                visited = (visited | (1 << i));
                start = i;
                break;
            }
        }
        //System.out.println("test!!!!!!!!!!!!!!!!!!!!!!" + start);
        dfs_travel(start, state, adj);
        if(visited == state)return true;
        return false;
    }

    static int anti_state(int state, int n){
        return ((1 << n) - 1) ^ state;
    }

    static int count_people(int state, int[] peoples){
        int n = peoples.length;
        int ret = 0;
        for(int i = 0; i<n; i++){
            if((state & (1 << i)) != 0){
                ret += peoples[i];
            }
        }
        return ret;
    }

    static int solution_gerrymandering(BufferedReader br) throws Exception {

        int n = Integer.parseInt(br.readLine());
        int[] peoples = new int[n];
        List<List<Integer>>adj = new ArrayList<>();
        for(int i = 0; i<n; i++){
            adj.add(new ArrayList<>());
        }
        StringTokenizer st = new StringTokenizer(br.readLine());
        for(int i = 0; i<n; i++){
            peoples[i] = Integer.parseInt(st.nextToken());
        }

        for(int i = 0; i<n; i++){
            st = new StringTokenizer(br.readLine());
            int e_size = Integer.parseInt(st.nextToken());
            for(int j = 0; j<e_size; j++){
                adj.get(i).add(Integer.parseInt(st.nextToken()) - 1);
            }
        }

        Map<Integer, Boolean> mp = new HashMap<>();
        int ret = Integer.MAX_VALUE;

        for(int i = 1; i<(1 << n) - 1; i++){
            int state = i;
            int r_state = anti_state(state, n);
            boolean s_flag = false, r_flag = false;
            if(!mp.containsKey(state)){
                s_flag = is_dfs(state, adj);
                mp.put(state, s_flag);
            }
            if(!mp.containsKey(r_state)){
                r_flag = is_dfs(r_state, adj);
                mp.put(r_state, r_flag);
            }
            if(s_flag && r_flag){
                
                int tmp_ret = Math.abs(count_people(state, peoples) - count_people(r_state, peoples));
                ret = Math.min(ret, 
                tmp_ret);
                //System.out.println("!!!!!!!"+ tmp_ret + " " + state + " " + r_state);
            }
        }

        return ret == Integer.MAX_VALUE ? -1 : ret;
    }
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        System.out.println(solution_gerrymandering(br));


        
    }
    
}
/*
게리멘더링

 */
/*
6
5 2 3 4 1 2
2 2 4
4 1 3 6 5
2 4 2
2 1 3
1 2
1 2
6
1 1 1 1 1 1
2 2 4
4 1 3 6 5
2 4 2
2 1 3
1 2
1 2
6
10 20 10 20 30 40
0
0
0
0
0
0
6
2 3 4 5 6 7
2 2 3
2 1 3
2 1 2
2 5 6
2 4 6
2 4 5
 */
/*
1
0
-1
9
 */