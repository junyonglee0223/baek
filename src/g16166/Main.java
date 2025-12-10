package g16166;

import java.io.*;
import java.util.*;


public class Main {

    static boolean isConnected(Set<Integer> s1, Set<Integer>s2){
        for(Integer ele : s1){
            if(s2.contains(ele))return true;
        }
        return false;
    }
    static int solutionSeoulSubway(BufferedReader br) throws Exception {
        StringTokenizer st;
        int N = Integer.parseInt(br.readLine());
        List<Set<Integer>> subwayGroup = new ArrayList<>();

        for(int i = 0; i<N; i++){
            subwayGroup.add(new HashSet<>());
        }

        List<Integer>starts = new ArrayList<>();

        for(int i = 0; i<N; i++){
            st = new StringTokenizer(br.readLine());
            int eleSize = Integer.parseInt(st.nextToken());
            for(int j = 0; j<eleSize; j++){
                int ele = Integer.parseInt(st.nextToken());
                if(ele == 0){
                    starts.add(i);
                }
                subwayGroup.get(i).add(ele);
            }
        }
        int endPoint = Integer.parseInt(br.readLine());
        Set<Integer>endPoints = new HashSet<>();
        for(int i = 0; i<N; i++){
            if(subwayGroup.get(i).contains(endPoint)){
                endPoints.add(i);
            }
        }

        List<List<Integer>> adj = new ArrayList<>();
        for(int i = 0; i<N; i++){
            adj.add(new ArrayList<>());
        }

        for(int i = 0; i<N; i++){
            for(int j = i+1; j<N; j++){
                if(isConnected(subwayGroup.get(i), subwayGroup.get(j))){
                    adj.get(i).add(j);
                    adj.get(j).add(i);
                }
            }
        }

        Queue<int[]> que = new ArrayDeque<>();
        boolean[] visited = new boolean[N];
        for(int i = 0; i<N; i++)
            visited[i] = false;
        for(int start : starts){
            visited[start] = true;
            que.add(new int[]{start, 0});
        }

        int ret = Integer.MAX_VALUE;

        while(!que.isEmpty()){
            int[] curNode = que.poll();
            int cur = curNode[0];
            int curCost = curNode[1];

            if(endPoints.contains(cur)){
                ret = curCost;
                break;
            }

            for(int nxt : adj.get(cur)){
                if(visited[nxt])continue;
                visited[nxt] = true;
                que.add(new int[]{nxt, curCost + 1});
            }
        }

        return ret == Integer.MAX_VALUE ? -1 : ret;
    }
    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        System.out.println(solutionSeoulSubway(br));
    }
}
/*
각각의 노선 자체가 연결되는지를 확인하면 된다
N <= 10이기 때문에 N^2으로 탐색해도 문제는 없다
K <= 10 이기 때문에 각 역의 번호는 정수꼴인데 개수만 10개 이하이다.
모든 정류장이 다르게 10개일 수도 있다. 비트마스킹 불가

그렇다고 배열이나 맵에 값을 저장하고 모든 값을 확인하는 최대 100번의 연산을 진행하는 것은
아름답지는 않다.

숫자 배열 두개가 주어졌을 때 공통의 원소가 있는지 확인하는 방법은?
일치 여부가 아님 공통원소가 존재만 하면 됨


*/
/*
3
3 0 2 3
4 2 5 7 10
2 10 8
8

3
4 1 2 3 1
5 0 9 4 7 99
4 8 10 7 9
1
*/

/*
2
-1
*/
