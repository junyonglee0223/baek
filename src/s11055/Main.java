package s11055;

import java.io.*;
import java.util.HashMap;
import java.util.Map;
import java.util.StringTokenizer;
import java.util.TreeSet;

public class Main {
    static int[] dp;
    static int[] arr;
    static int N;

    static int get_max_arr(int idx){
        if(idx > N)return 0;
        if(dp[idx] != -1)return dp[idx];

        dp[idx] = arr[idx];
        for(int nxt = idx + 1; nxt <= N ; nxt++){
            if(arr[idx] > arr[nxt])continue;
            dp[idx] = Math.max(dp[idx], arr[idx] + get_max_arr(nxt));
        }
        return dp[idx];
    }
    static int solution_partition_arr_v1(BufferedReader br) throws IOException{
        N = Integer.parseInt(br.readLine());

        arr = new int[N+1];
        dp = new int[N+1];

        for(int i = 0; i<=N; i++)
            dp[i] = -1;

        StringTokenizer st = new StringTokenizer(br.readLine());
        arr[0] = 0;
        for(int i = 1; i<=N; i++){
            arr[i] = Integer.parseInt(st.nextToken());
        }

        return get_max_arr(0);
    }
/// ///////////////////////////////////////////////////////////////////////////////////

    static int get_max_arr(){
        for(int i = 0; i<=N; i++){
            dp[i] = arr[i];
        }
        for(int i = 1; i<=N; i++){
            for(int j = 1; j<i; j++){
                if(arr[j] < arr[i]){
                    dp[i] = Math.max(dp[i], arr[i] + dp[j]);
                }
            }
        }
        int ret = 0;
        for(int i = 0; i<=N; i++){
            ret = Math.max(ret, dp[i]);
        }
        return ret;
    }
    static int solution_partition_arr_v2(BufferedReader br) throws IOException{
        N = Integer.parseInt(br.readLine());

        arr = new int[N+1];
        dp = new int[N+1];

        for(int i = 0; i<=N; i++)
            dp[i] = -1;

        StringTokenizer st = new StringTokenizer(br.readLine());
        arr[0] = 0;
        for(int i = 1; i<=N; i++){
            arr[i] = Integer.parseInt(st.nextToken());
        }

        return get_max_arr();
    }
    /// //////////////////////////////////////////////////////////////////////
    ///

    static class SEGTREE {
        int[] seg_tree;

        SEGTREE(int n) {
            seg_tree = new int[4 * n];
        }

        void update(int node, int src, int dst, int idx, int value) {
            if (src > idx || dst < idx) return;
            if (src == dst) {
                seg_tree[node] = Math.max(seg_tree[node], value);
                return;
            }
            int mid = (src + dst) / 2;
            update(node * 2, src, mid, idx, value);
            update(node * 2 + 1, mid + 1, dst, idx, value);
            seg_tree[node] = Math.max(seg_tree[node * 2], seg_tree[node * 2 + 1]);
        }

        int query(int node, int src, int dst, int p, int q) {
            if (q < src || dst < p) return 0;
            if (p <= src && dst <= q) return seg_tree[node];
            int mid = (src + dst) / 2;
            return Math.max(query(node * 2, src, mid, p, q),
                    query(node * 2 + 1, mid + 1, dst, p, q));
        }
    }

    static int solution_partition_arr(BufferedReader br) throws IOException {
        N = Integer.parseInt(br.readLine());

        arr = new int[N];
        StringTokenizer st = new StringTokenizer(br.readLine());
        for(int i = 0; i<N; i++){
            arr[i] = Integer.parseInt(st.nextToken());
        }
        TreeSet<Integer> tst = new TreeSet<>();
        for (int i = 0; i < N; i++) {
            tst.add(arr[i]);
        }

        Map<Integer, Integer> compress = new HashMap<>();
        int idx = 0;
        for (Integer ele : tst) {
            compress.put(ele, idx++);
        }
        SEGTREE sgt = new SEGTREE(compress.size());
        int s_size = compress.size();

        int ret = 0;
        for (int i = 0; i < N; i++) {
            int cur_idx = compress.get(arr[i]);
            int cur_max_v = 0;
            if(cur_idx > 0)
                cur_max_v = sgt.query(1, 0, s_size - 1, 0, cur_idx - 1);
            ret = Math.max(ret, cur_max_v + arr[i]);

            sgt.update(1, 0, s_size - 1, cur_idx, cur_max_v + arr[i]);
        }
        return ret;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        System.out.println(solution_partition_arr(br));
    }
}
/*
10
1 100 2 50 60 3 5 6 7 8
 */
/*
113
 */