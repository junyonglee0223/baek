package sw2382_미생물격리;
//:bug: SW2382_MicrobeBlock_이준용.java

import java.io.*;
import java.util.*;

public class Solution {
    static class NODE{
        int x, y, dir, capa;
        boolean isAlive;
        NODE(int x, int y, int dir, int capa){
            this.x = x;
            this.y = y;
            this.dir = dir;
            this.capa = capa;
            this.isAlive = true;
        }
    }

    static int N, K;
    //v, >, ^, <
    static int[] dx = {1, 0, -1, 0};
    static int[] dy = {0, 1, 0, -1};
    static List<NODE> nodes;
    static boolean is_range(int x, int y){
        return x >= 0 && x < N && y >= 0 && y <= N;
    }
    static boolean is_edge(int x, int y){
        return x == 0 || x == N-1 || y == 0 || y == N-1;
    }

    static void update_nodes(){
        for(int i = 0; i<nodes.size(); i++){
            NODE n = nodes.get(i);
            if(!n.isAlive)continue;

            n.x = n.x + dx[n.dir];
            n.y = n.y + dy[n.dir];

            if(is_edge(n.x, n.y)){
                n.dir = (n.dir + 2)%4;
                n.capa = n.capa / 2;
                if(n.capa == 0)n.isAlive = false;
            }
        }
        compress_nodes();
    }
    static void compress_nodes(){
        int size = N;
        List<List<Integer>>board = new ArrayList<>();
        for(int i =0 ; i<size*size; i++)
            board.add(new ArrayList<>());

        for(int i =0  ;i<nodes.size(); i++){
            NODE n = nodes.get(i);
            if(!n.isAlive)continue;
            board.get(n.x * size + n.y).add(i);
        }
        for(int i = 0; i<size*size; i++){
            Collections.sort(board.get(i), new Comparator<Integer>() {
                @Override
                public int compare(Integer o1, Integer o2) {
                    return Integer.compare(nodes.get(o2).capa, nodes.get(o1).capa);
                }
            });
        }
        for(int i = 0; i<size*size; i++){
            if(board.get(i).size() <= 1)continue;
            NODE top_node = nodes.get(board.get(i).get(0));
            for(int j = 1; j<board.get(i).size(); j++){
                NODE n = nodes.get(board.get(i).get(j));
                n.isAlive = false;
                top_node.capa += n.capa;
            }
        }
    }
    static int all_nodes_capa(){
        int ret = 0;
        for(int i = 0; i<nodes.size(); i++){
            if(!nodes.get(i).isAlive)continue;
            ret += nodes.get(i).capa;
        }
        return ret;
    }
    static void print_all_nodes(){
        System.out.println("----------------------------------------");
        for(int i = 0; i<nodes.size(); i++){
            NODE n = nodes.get(i);
            System.out.println(n.x + " " + n.y + " " + n.dir + " " + n.capa + " " + n.isAlive);
        }
        System.out.println("----------------------------------------");
    }


    static int solution_virus_isolation(BufferedReader br) throws IOException{
        StringTokenizer st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        int M = Integer.parseInt(st.nextToken());
        K = Integer.parseInt(st.nextToken());

        int[][] board = new int[N+1][N+1];
        nodes = new ArrayList<>();

        for(int i = 0; i<K; i++){
            st = new StringTokenizer(br.readLine());
            int x = Integer.parseInt(st.nextToken());
            int y = Integer.parseInt(st.nextToken());
            int c = Integer.parseInt(st.nextToken());
            int d = Integer.parseInt(st.nextToken());
            if(d == 1)d = 2;
            else if(d == 2) d = 0;
            else if(d == 3) d = 3;
            else if(d == 4) d = 1;

            nodes.add(new NODE(x, y, d, c));
        }

        //M 동안 이동

        while(M-- > 0){
            update_nodes();
            //print_all_nodes();/////////////////////////////////////test
        }

        return all_nodes_capa();
    }
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int T = Integer.parseInt(br.readLine());

        for(int test_case = 1; test_case <= T; test_case++)
        {

            System.out.println("#" + test_case + " " + solution_virus_isolation(br));
        }
    }
}
/*

10
7 2 9
1 1 7 1
2 1 7 1
5 1 5 4
3 2 8 4
4 3 14 1
3 4 3 3
1 5 8 2
3 5 100 1
5 5 1 1
 */