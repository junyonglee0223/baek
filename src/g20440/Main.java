package g20440;

import java.io.*;
import java.util.*;

public class Main {
    static class RETNODE {
        int start, end, count;
        RETNODE(int start, int end, int count){
            this.start = start;
            this.end = end;
            this.count = count;
        }
    }
    static void solution_i_hate_you_dont_flirt_with_me_1(BufferedReader br) throws Exception{
        TreeMap<Integer, List<Integer>>mp = new TreeMap<>();
        List<Integer>time_key = new ArrayList<>();
        StringTokenizer st;

        int N = Integer.parseInt(br.readLine());
        for(int i = 0; i<N; i++){
            st = new StringTokenizer(br.readLine());
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());
            if(!mp.containsKey(a)){
                mp.put(a, new ArrayList<>());
                time_key.add(a);
            }
            mp.get(a).add(b);
        }
        Collections.sort(time_key);

        PriorityQueue<Integer> pq = new PriorityQueue<>();
        PriorityQueue<RETNODE> result_group = new PriorityQueue<>(new Comparator<RETNODE>() {
            @Override
            public int compare(RETNODE a, RETNODE b){
                if(a.count == b.count)return a.start - b.start;
                return b.count - a.count;
            }
        });

        int start_time = time_key.get(0);
        int count = 0;

        for(int start : time_key){
            //input 값보다 endtime 이 작다면 
            int discount_value = 0;
            if(!pq.isEmpty() && pq.peek() < start){
                result_group.add(new RETNODE(start_time, pq.peek(), count));
                while(!pq.isEmpty() && pq.peek() < start){
                    pq.poll();
                    count--;
                }
                for(int ele : mp.get(start)){
                    pq.add(ele);
                    count++;
                }
                start_time = start;
            }
            else if(!pq.isEmpty() && pq.peek() == start){
                while(!pq.isEmpty() && pq.peek() == start){
                    pq.poll();
                    discount_value++;
                    count--;
                }
                int input_size = mp.get(start).size();
                if(input_size != discount_value){
                    result_group.add(new RETNODE(start_time, start, count));
                    start_time = start;
                }
                for(int ele : mp.get(start)){
                    pq.add(ele);
                    count++;
                }
            }
            else{
                start_time = start;
                for(int ele : mp.get(start)){
                    pq.add(ele);
                    count++;
                }
            }
        }

        if(!pq.isEmpty()){
            result_group.add(new RETNODE(start_time, pq.peek(), pq.size()));
        }

        RETNODE max_ret = result_group.peek();
        System.out.println(max_ret.count);
        System.out.println(max_ret.start + " " + max_ret.end);




        //add ele

        //que size
        //save start time in field
        //input value's start time is bigger then end time 

        //원소 단위로 계산하면 동시 감소, 증가를 제대로 반영하지 못함
        //

    }
    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        solution_i_hate_you_dont_flirt_with_me_1(br);
        
    }
    
}
/*
3
2 16
4 6
6 10
 */
/*
2
4 10
 */