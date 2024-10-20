package g2252;

import java.util.*;
public class Solution {
    static int N, M;
    static List<List<Integer>>graph;

    public static void main(String[] args){
        Scanner scanner = new Scanner(System.in);
        N = scanner.nextInt();
        M = scanner.nextInt();
        List<Integer>inorder = new ArrayList<>(Collections.nCopies(N+1, 0));

        graph = new ArrayList<>();
        for(int i = 0; i<=N; i++)
            graph.add(new ArrayList<>());

        for(int i = 0; i<M; i++){
            int a = scanner.nextInt();
            int b = scanner.nextInt();
            graph.get(a).add(b);
            inorder.set(b, inorder.get(b)+1);
        }
        Queue<Integer>q = new LinkedList<>();
        for(int i = 1; i<=N; i++){
            if(inorder.get(i) == 0)
                q.add(i);
        }

        List<Integer>ret = new ArrayList<>();

        while(!q.isEmpty()){
            int now = q.peek();
            ret.add(now);
            q.remove();
            for(int nxt : graph.get(now)){
                inorder.set(nxt, inorder.get(nxt)-1);
                if(inorder.get(nxt) == 0){
                    q.add(nxt);
                }
            }
        }

        for(int i = 0; i<ret.size(); i++)
            System.out.print(ret.get(i) + " ");
        System.out.println();

    }
}
