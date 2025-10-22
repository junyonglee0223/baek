package g1765;

import java.io.*;
import java.util.*;

public class Main {

    static int[] parents;
    static int[] ranks;
    
    static int find_parent(int cur){
        if(parents[cur] == cur)return cur;
        return parents[cur] = find_parent(parents[cur]);
    }

    static void union_node(int a, int b){
        int pa = find_parent(a);
        int pb = find_parent(b);
        if(pa == pb)return;
        parents[pa] = pb;
    }

    static void enemy_bfs(int start, List<List<Integer>>e_adj, boolean[] visited){
        
        Queue<int[]>que = new ArrayDeque<>();
        que.add(new int[]{start, 0});
        visited[start] = true;

        while(!que.isEmpty()){
            int[] cur_n = que.poll();
            int cur = cur_n[0];
            int level = cur_n[1];

            for(int nxt : e_adj.get(cur)){
                if(visited[nxt])continue;
                int nxt_level = level + 1;
                visited[nxt] = true;
                if(nxt_level % 2 == 0)union_node(start, nxt);
                que.add(new int[]{nxt, nxt_level});
            }
        }
    }

    
    static int solution_selecting_cockfight_team(BufferedReader br) throws Exception{
        int n = Integer.parseInt(br.readLine());
        int m = Integer.parseInt(br.readLine());

        parents = new int[n+1];
        ranks = new int[n+1];

        for(int i = 1; i<=n; i++){
            parents[i] = i;
            ranks[i] = 0;
        }

        
        List<List<Integer>>enemies = new ArrayList<>();
        for(int i = 0 ;i<=n; i++){
            enemies.add(new ArrayList<>());
        }
        
        List<int[]>init_enemy = new ArrayList<>();
        StringTokenizer st;
        for(int i = 0; i<m; i++){
            st = new StringTokenizer(br.readLine());
            String tmp = st.nextToken();
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());
            if(tmp.equals("E")){
                init_enemy.add(new int[]{a, b});
            }else if(tmp.equals("F")){
                union_node(a, b);
            }
        }

        for(int i = 1; i<=n; i++){
            parents[i] = find_parent(i);
        }
        for(int[] ele : init_enemy){
            int a = find_parent(ele[0]);
            int b = find_parent(ele[1]);
            enemies.get(a).add(b);
            enemies.get(b).add(a);
        }
        
        // for(int i = 1; i<=n; i++){
        //     if(enemies.get(i).size() <= 1) continue;
            
        //     int pr = enemies.get(i).get(0);
        //     for(int j = 1; j<enemies.get(i).size(); j++){
        //         union_node(pr, enemies.get(i).get(j));
        //     }
        // }

        List<List<Integer>>enemy_adj = new ArrayList<>();
        for(int i = 0; i<=n; i++){
            enemy_adj.add(new ArrayList<>());        
        }

        for(int[] e : init_enemy){
            enemy_adj.get(e[0]).add(e[1]);
            enemy_adj.get(e[1]).add(e[0]);
        }

        for(int i = 1; i<=n; i++){
            boolean[] visited = new boolean[n+1];
            enemy_bfs(i, enemy_adj, visited);
        }

        Map<Integer, Integer> mp = new HashMap<>();//value - idx
        List<Integer>count_group = new ArrayList<>();

        for(int i = 1; i<=n; i++){
            parents[i] = find_parent(i);
        }

        for(int i = 1; i<=n; i++){
            int ele = find_parent(i);
            if(!mp.containsKey(ele)){
                mp.put(ele, count_group.size());
                count_group.add(1);
            }
            else{
                count_group.set(mp.get(ele), count_group.get(mp.get(ele)) + 1);
            }
        }

        int answer = count_group.size();

        // for(int i = 1; i<=n; i++){
        //     System.out.print(parents[i] + " ");
        // }
        // System.out.println();

        // for(int ele : count_group){
        //     ///////////////////////////////////////////////////
        //     System.out.print(ele);
        //     answer += ((ele + 1) / 2);
        // }
        // System.out.println();

        return answer;
    }

    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        System.out.println(solution_selecting_cockfight_team(br));
    }
}
/*
1000까지 진행됨

 */

/*
6
4
E 1 4
F 3 5
F 4 6
E 1 2
 */
/*
5
4
E 1 2
E 2 3
F 4 5
E 3 4

 */
/*
3
 */