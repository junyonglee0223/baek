package s5525;
//s5525 IOIOI

import java.util.Scanner;

public class Main {

    static void solution_IOIOI(Scanner sc){
        int N = Integer.parseInt(sc.nextLine());
        int M = Integer.parseInt(sc.nextLine());
        String str = sc.nextLine();

        int answer = 0;

        int idx = 0;
        int len = 0;
        while(idx < M){
            if(str.charAt(idx) == 'O'){
                idx++;
            }
            else if(str.charAt(idx) == 'I'){
                while(idx + 2 < M){
                    if(str.charAt(idx+1) == 'O' && str.charAt(idx+2) == 'I'){
                        idx += 2;
                        len += 1;
                    }
                    else{
                        break;
                    }
                }

                if(len >= N){
                    answer += (len - N + 1);
                }
                len = 0;
                idx++;
            }
        }
        System.out.println(answer);
    }

    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);

        solution_IOIOI(sc);


//        int T = Integer.parseInt(sc.nextLine());
//        while(T-- > 0){
//            solution_IOIOI(sc);
//        }
    }
}

/*
2
1
13
OOIOIOIOIIOII
2
13
OOIOIOIOIIOII
*/
/*
4
2
*/
