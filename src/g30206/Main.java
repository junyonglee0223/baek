package g30206;

import java.io.*;
import java.util.*;

public class Main {

    static final int MOD = 1000000007;

    static int solution_vehicle_placement(BufferedReader br) throws Exception{

        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());
        
        List<List<Integer>>adj = new ArrayList<>();
        for(int i = 0; i<=n; i++){
            adj.add(new ArrayList<>());
        }

        int[][] edges = new int[m][2];

        for(int i = 0; i<m; i++){
            st = new StringTokenizer(br.readLine());
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());
            if(a > b){
                int tmp = a;
                a = b;
                b = tmp;
            }
            adj.get(a).add(b);
            adj.get(b).add(a);
            edges[i] = new int[] {a, b};
        }

        int[] keys = new int[n+1];
        for(int i = 0; i<=n; i++)
            keys[i] = -1;
        Queue<Integer>que = new ArrayDeque<>();
        que.add(1);
        keys[1] = 0;

        while(!que.isEmpty()){
            int now = que.poll();
            for(int nxt : adj.get(now)){
                if(keys[nxt] != -1)continue;
                keys[nxt] = keys[now] + 1;
                que.add(nxt);
            }
        }
        Map<Integer, Integer>mp = new HashMap<>();
        for(int i = 1; i<=n; i++){
            int key = keys[i];
            if(!mp.containsKey(key)){
                mp.put(key, 0);
            }
            int key_size = mp.get(key);
            mp.put(key, key_size + 1);
        }

        long ret = 1;
        for(int d = 0; d<mp.size(); d++){
            ret = (ret * (mp.get(d) + 1))%MOD;
        }

        ret = (ret -1 + MOD)%MOD;

        return (int)ret;
    }

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        System.out.println(solution_vehicle_placement(br));
        
        // int T = Integer.parseInt(br.readLine());
        // while(T-- > 0){
        //     System.out.println(solution_vehicle_placement(br));
        // }

    }
    
}

/*
2
3 2
1 2
2 3
3 3
1 2
1 3
2 3
 */
/*
7
5
 */