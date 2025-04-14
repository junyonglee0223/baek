package g1715;

import java.util.PriorityQueue;
import java.util.Scanner;

public class Main {

    static void solution_sort_card_v1(Scanner sc){
        int N = Integer.parseInt(sc.nextLine());
        PriorityQueue<Integer> pq = new PriorityQueue<>();

        for(int i = 0; i<N; i++){
            int ele = Integer.parseInt(sc.nextLine());
            pq.offer(ele);
        }

        int answer = 0;
        while(pq.size() > 1){
            int v1 = pq.poll();
            int v2 = pq.poll();
            int tmp_sum = v1 + v2;

            answer += tmp_sum;
            pq.offer(tmp_sum);
        }
        System.out.println(answer);
    }
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);

        solution_sort_card_v1(sc);
    }
}
/*
3
10
20
40
*/
/*
100
*/