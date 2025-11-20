package g15804;

import java.io.*;
import java.util.*;

public class Main {
    static int N, M;
    static class NODE{
        int pos,  endTime;
        NODE(int pos, int endTime){
            this.pos = pos;
            this.endTime = endTime;
        }
        NODE(){}
    }

    static void updateQueue(Deque<NODE>que, int start){
        while(!que.isEmpty()){
            NODE firstNode = que.getFirst();
            if(firstNode.endTime <= start)que.pollFirst();
            else break;
        }
    }
    static int getPosition(Deque<NODE>que){
        if(que.isEmpty())return 1;
        return que.getLast().pos + 1;
    }
    static int solutionMissTheBusThenLate(BufferedReader br) throws Exception {
        StringTokenizer st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());

        Deque<NODE>que = new ArrayDeque<>();

        int answer = 1;
        int curTime = 0;

        for(int i = 0; i<M; i++){
            st = new StringTokenizer(br.readLine());
            int start = Integer.parseInt(st.nextToken());
            int wait = Integer.parseInt(st.nextToken());

            curTime = Math.max(curTime, start);
            if(start < curTime)start = curTime;
            
            updateQueue(que, start);
            
            int curIdx = getPosition(que);

            if(curIdx > N){
                int maxTime = 1;
                while(!que.isEmpty()){
                    maxTime = Math.max(maxTime, que.pollLast().endTime);
                }
                start = maxTime;
                curTime = maxTime;
                curIdx = getPosition(que);//1이긴 함
            }

            que.add(new NODE(curIdx, start + wait));
            if(i == M-1){
                answer = curIdx;
            }
        }
        return answer;
    }
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        System.out.println(solutionMissTheBusThenLate(br));
        
        // int T = Integer.parseInt(br.readLine());
        // while(T-- > 0){
        //     System.out.println("answer = "+solutionMissTheBusThenLate(br));
        // }
    }
    
}

/*
queue 활용 새로 들어오는 것과 queue front와 비교한다
노드는 현재 위치, 나가는 시간을 저장해둔다. 
N을 초과해야 할 경우 시간 처리

*/
/*
6
2 3
1 1
2 1
3 1
2 3
1 2
2 1
3 1
2 3
1 1
2 2
3 1
2 3
1 2
1 2
3 1
2 3
1 4
2 1
3 1
2 5
1 10
2 10
3 1
4 10
5 1
*/
/*
6

2 3
1 1
2 1
3 1

2 3
1 2
2 1
3 1

2 3
1 1
2 2
3 1

2 3
1 2
1 2
3 1

2 3
1 4
2 1
3 1

2 5
1 10
2 10
3 1
4 10
5 1
*/
/*
1
1
2
1
1
1
*/