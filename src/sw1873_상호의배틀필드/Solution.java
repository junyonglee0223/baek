package sw1873_상호의배틀필드;
import java.io.*;
import java.util.Scanner;
import java.util.StringTokenizer;

class Solution
{
    static int H, W;
    static boolean is_range(int x, int y){
        return x >= 0 && x < H && y >= 0 && y < W;
    }
    static int[] dx = {1, 0, -1, 0};
    static int[] dy = {0, 1, 0, -1};

    static int[] find_tank(Character[][] board){
        int x = 0, y = 0;
        for(int i = 0; i<H; i++){
            for(int j = 0; j<W; j++){
                if(board[i][j] == '^' || board[i][j] == 'v'
                        || board[i][j] == '<' || board[i][j] == '>' ){
                    return new int[] {i, j};
                }
            }
        }
        return new int[] {-1, -1};
    }
    static void shooting_bullet(Character[][] board, int x, int y, int dir){
        int nx = x + dx[dir];
        int ny = y + dy[dir];
        while(is_range(nx, ny)){
            if(board[nx][ny] == '*'){
                board[nx][ny] = '.';
                break;
            }
            else if(board[nx][ny] == '#')break;
            nx = nx + dx[dir];
            ny = ny + dy[dir];
        }
    }


    static void update_board(Character[][] board, char cmd){
        int[] get_tank = find_tank(board);
        int x = get_tank[0];
        int y = get_tank[1];
        if(cmd == 'D'){
            board[x][y] = 'v';
            int nx = x + dx[0];
            int ny = y + dy[0];
            if(is_range(nx, ny) && board[nx][ny] == '.'){
                board[x][y] = '.';
                board[nx][ny] = 'v';
            }
        }
        else if(cmd == 'R'){
            board[x][y] = '>';
            int nx = x + dx[1];
            int ny = y + dy[1];
            if(is_range(nx, ny) && board[nx][ny] == '.'){
                board[x][y] = '.';
                board[nx][ny] = '>';
            }
        }
        else if(cmd == 'U'){
            board[x][y] = '^';
            int nx = x + dx[2];
            int ny = y + dy[2];
            if(is_range(nx, ny) && board[nx][ny] == '.'){
                board[x][y] = '.';
                board[nx][ny] = '^';
            }
        }
        else if(cmd == 'L'){
            board[x][y] = '<';
            int nx = x + dx[3];
            int ny = y + dy[3];
            if(is_range(nx, ny) && board[nx][ny] == '.'){
                board[x][y] = '.';
                board[nx][ny] = '<';
            }
        }
        else if(cmd == 'S'){
            int dir = 0;
            if(board[x][y] == 'v'){
                dir = 0;
            }
            else if(board[x][y] == '>'){
                dir = 1;
            }
            else if(board[x][y] == '^'){
                dir = 2;
            }
            else if(board[x][y] == '<'){
                dir = 3;
            }
            shooting_bullet(board, x, y, dir);
        }
    }
    static String solution_sangho_battlefield(BufferedReader br) throws IOException{
        StringTokenizer st = new StringTokenizer(br.readLine());
        H = Integer.parseInt(st.nextToken());
        W = Integer.parseInt(st.nextToken());

        Character[][] board = new Character[H][W];
        int x, y, dir;
        for(int i = 0; i<H; i++){
            String tmp_str = br.readLine();
            for(int j = 0; j<W; j++){
                board[i][j] = tmp_str.charAt(j);
            }
        }


        int cmd_cnt = Integer.parseInt(br.readLine());
        String commandStr = br.readLine();
        for(int i = 0; i<cmd_cnt; i++){
            update_board(board, commandStr.charAt(i));
        }


        StringBuilder ret = new StringBuilder();
        for(int i = 0; i<H; i++){
            for(int j = 0; j<W; j++){
                ret.append(board[i][j]);
            }
            ret.append("\n");
        }
        return ret.toString();
    }
    public static void main(String args[]) throws Exception
    {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int T = Integer.parseInt(br.readLine());

        for(int test_case = 1; test_case <= T; test_case++)
        {
            System.out.print("#"+test_case + " " + solution_sangho_battlefield(br));
        }
    }
}
/*
.	평지(전차가 들어갈 수 있다.)
*	벽돌로 만들어진 벽
#	강철로 만들어진 벽
-	물(전차는 들어갈 수 없다.)
^	위쪽을 바라보는 전차(아래는 평지이다.)
v	아래쪽을 바라보는 전차(아래는 평지이다.)
<	왼쪽을 바라보는 전차(아래는 평지이다.)
>	오른쪽을 바라보는 전차(아래는 평지이다.)

U	Up : 전차가 바라보는 방향을 위쪽으로 바꾸고, 한 칸 위의 칸이 평지라면 위 그 칸으로 이동한다.
D	Down : 전차가 바라보는 방향을 아래쪽으로 바꾸고, 한 칸 아래의 칸이 평지라면 그 칸으로 이동한다.
L	Left : 전차가 바라보는 방향을 왼쪽으로 바꾸고, 한 칸 왼쪽의 칸이 평지라면 그 칸으로 이동한다.
R	Right : 전차가 바라보는 방향을 오른쪽으로 바꾸고, 한 칸 오른쪽의 칸이 평지라면 그 칸으로 이동한다.
S	Shoot : 전차가 현재 바라보고 있는 방향으로 포탄을 발사한다.
*/
/*
1
3 7
***....
*-..#**
#<.****
23
SURSSSSUSLSRSSSURRDSRDS
 */
/*
#1 **....v
.-..#..
#......
 */