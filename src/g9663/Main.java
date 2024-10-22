package g9663;
//N-Queen

import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;


public class Main {
    static int N;
    static List<Integer>ascVisited;
    static List<Integer>dscVisited;
    static List<Integer>heiVisited;
    static int answer = 0;


    static void NQueenDFS(int now){
        if(now == N) {
            answer++;
            return;
        }
        for(int i = 0; i<N; i++){
            int tmpDsc = now - i;
            if(now < i)tmpDsc = i - now + N - 1;
            if(heiVisited.get(i) == 0 && ascVisited.get(i + now) == 0
            && dscVisited.get(tmpDsc)==0){
                heiVisited.set(i, 1);
                ascVisited.set(now + i, 1);
                dscVisited.set(tmpDsc, 1);
                NQueenDFS(now+1);
                ascVisited.set(now+i, 0);
                dscVisited.set(tmpDsc, 0);
                heiVisited.set(i, 0);
            }
        }
    }

    public static void main(String[] args){
        Scanner scanner = new Scanner(System.in);
        N = scanner.nextInt();
        ascVisited = new ArrayList<>(2*N-1);
        dscVisited = new ArrayList<>(2*N-1);
        heiVisited = new ArrayList<>(N);
        for(int i = 0; i<N+1; i++)
            heiVisited.add(0);
        for(int i = 0; i<2*N+1; i++)
            ascVisited.add(0);
        for(int i = 0; i<2*N+1; i++)
            dscVisited.add(0);

//        for(int i = 0; i<N; i++){
//            NQueenDFS(i, 0);
//        }
        NQueenDFS(0);
        System.out.println(answer);
    }
}

/*
* 구분하는 방식이 가장 중요할 듯 하다.
* 가로 구분은 기본적으로 가능하고
* 세로 구분은 설정해주면 된다.
* 대각선 체크가 중요한데 (2, 1), (1, 2) -> 두 케이스 경우 합으로 저장하면 된다.
* 1, 1, 2, 2 이거는 차로 계산하면 될 듯 함
* 3, 2   5 ,6 이거는 걸리냐? -> 안걸리겠지 그래서 절댓값 처리가 중요하다.
*
*
* 시작을 0, 0 or 1, 1이거도 중요할 수도?
* 점화식 사용해서 연산으로 들어가는 방식 vs 재귀로 들어가서 leaf node에서 counting 하는 방식
* 둘 중 어떤거 선택하는게 좋을지?
*
*
* */
