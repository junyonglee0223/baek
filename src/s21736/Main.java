package s21736;
//s21736 헌내기는 친구가 필요해

import java.util.*;

public class Main {
    static int[] dx = {1, 0, -1, 0};
    static int[] dy = {0, 1, 0, -1};

    static boolean is_range(int x, int y, int n, int m){
        return x >= 0 && x < n && y >= 0 && y < m;
    }

    static void solution_need_friends(Scanner sc){
        //Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int m = sc.nextInt();
        sc.nextLine();

        int[][] board = new int[n][m];

        int start_x = -1;
        int start_y = -1;


        for(int i = 0; i<n; i++){
            String line = sc.nextLine();
            for(int j = 0; j<m; j++){
                char c = line.charAt(j);
                if(c == 'O'){
                    board[i][j] = 0;
                }
                else if(c == 'X'){
                    board[i][j] = -1;
                }
                else if(c == 'P'){
                    board[i][j] = 1;
                }
                else if(c == 'I'){
                    board[i][j] = 0;
                    start_x = i;
                    start_y = j;
                }
            }
        }

        int answer = 0;

        Queue<int[]>queue = new LinkedList<>();
        queue.add(new int[]{start_x, start_y});

        while(!queue.isEmpty()){
            int[] cur = queue.poll();
            int cx = cur[0];
            int cy = cur[1];

            for(int d = 0; d<4; d++){
                int nx = cx + dx[d];
                int ny = cy + dy[d];
                if(!is_range(nx, ny, n , m))continue;
                if(board[nx][ny] < 0)continue;

                if(board[nx][ny] == 1){
                    answer++;
                }
                board[nx][ny] = -1;
                queue.add(new int[]{nx, ny});
            }
        }

        if(answer == 0){
            System.out.println("TT");
        }
        else{
            System.out.println(answer);
        }
    }

    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        solution_need_friends(sc);

//        int T = sc.nextInt();
//        while(T-->0){
//            solution_need_friends(sc);
//        }
    }
}



/*
2
3 5
OOOPO
OIOOX
OOOXP
3 3
IOX
OXP
XPP
*/

/*
1
TT
*/