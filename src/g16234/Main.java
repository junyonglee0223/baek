package g16234;
//g16234 인구 이동


import java.util.*;

public class Main {
    static int[] dx = {1, 0, -1, 0};
    static int[] dy = {0, 1, 0, -1};
    static boolean is_range(int x, int y, int n){
        return x >= 0 && x < n && y >= 0 && y < n;
    }

    /***************************** test *****************************/
    static void print_board(int[][]board){
        int n = board.length;
        for(int i = 0; i<n; i++){
            for(int j = 0; j<n; j++){
                System.out.print(board[i][j] + " ");
            }
            System.out.println();
        }
        System.out.println();
    }

    /***************************** test *****************************/

    static List<int[]> do_set_group(int x, int y, boolean[][] visited,
                                    int[][] board, int l, int r){
        int n = board.length;
        List<int[]>ret = new ArrayList<>();

        Queue<int[]> q = new LinkedList<>();
        visited[x][y] = true;
        ret.add(new int[]{x, y});
        q.offer(new int[]{x, y});

        while(!q.isEmpty()){
            int[] tmp = q.poll();
            int cx = tmp[0];
            int cy = tmp[1];

            for(int d = 0; d<4; d++){
                int nx = cx + dx[d];
                int ny = cy + dy[d];

                if(!is_range(nx, ny, n))continue;
                if(visited[nx][ny])continue;

                int dist = Math.abs(board[cx][cy] - board[nx][ny]);
                if(dist >= l && dist <= r){
                    visited[nx][ny] = true;
                    ret.add(new int[]{nx, ny});
                    q.offer(new int[]{nx, ny});
                }
            }
        }
        return ret;
    }

    static List<List<int[]>> set_group(int[][] board, int l, int r){
        int n = board.length;
        boolean[][] visited = new boolean[n][n];
        List<List<int[]>>ret = new ArrayList<>();

        for(int i = 0; i<n; i++){
            for(int j = 0; j<n; j++){
                if(!visited[i][j]){
                    List<int[]>tmp_list = do_set_group(i, j, visited, board, l, r);
                    ret.add(tmp_list);
                }
            }
        }
        return ret;
    }
    static boolean move_people(List<List<int[]>>group, int[][] board){
        int n = board.length;
        boolean ret = false;

        int g_size = group.size();
        for (List<int[]> e_group : group) {
            if (e_group.size() > 1) {
                ret = true;
            }
            int e_group_people = 0;
            for (int[] value : e_group) {
                int e_g_x = value[0];
                int e_g_y = value[1];
                e_group_people += board[e_g_x][e_g_y];
            }
            int re_group_people = e_group_people / e_group.size();
            for (int[] value : e_group) {
                int e_g_x = value[0];
                int e_g_y = value[1];
                board[e_g_x][e_g_y] = re_group_people;
            }
        }
        return ret;
    }


    static void solution_people_moving(Scanner sc){
        int n = sc.nextInt();
        int l = sc.nextInt();
        int r = sc.nextInt();
        sc.nextLine();

        int[][] board = new int[n][n];
        for(int i = 0; i<n; i++){
            for(int j = 0; j<n; j++){
                int ele = sc.nextInt();
                board[i][j] = ele;
            }
            sc.nextLine();
        }

        List<List<int[]>> set_tmp = set_group(board, l, r);

        int day = 0;
        while(move_people(set_tmp, board)){
            day++;
            set_tmp = set_group(board, l, r);
        }
        System.out.println(day);
        //print_board(board);//test
    }

    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);

        solution_people_moving(sc);
//        int T = Integer.parseInt(sc.nextLine());
//        while(T-- > 0){
//            solution_people_moving(sc);
//        }
    }
}

/*
5
2 20 50
50 30
20 40
2 40 50
50 30
20 40
2 20 50
50 30
30 40
3 5 10
10 15 20
20 30 25
40 22 10
4 10 50
10 100 20 90
80 100 60 70
70 20 30 40
50 20 100 10
*/
/*
1
0
1
2
3
*/

