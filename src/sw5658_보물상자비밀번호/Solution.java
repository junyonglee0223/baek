package sw5658_보물상자비밀번호;

//:lock: SW5658_TreasureBox_이준용.java

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Solution {
    static int N, K;
    static boolean is_num(char c){
        return c >= '0' && c <= '9';
    }
    static List<String> sorting_str(List<String>str){
        Collections.sort(str, new Comparator<String>() {
            @Override
            public int compare(String o1, String o2) {
                for(int i = 0; i<o1.length(); i++){
                    char o1_c = o1.charAt(i);
                    char o2_c = o2.charAt(i);
                    if(!is_num(o1_c) && !is_num(o2_c)){
                        if(o1_c == o2_c)continue;
                        return o1_c - o2_c;
                    }
                    else if(!is_num(o1_c)){
                        return 1;
                    }
                    else if(!is_num(o2_c)){
                        return -1;
                    }else{
                        if(o1_c == o2_c)continue;
                        return o1_c - o2_c;
                    }
                }
                return 0;
            }
        });
        return str;
    }

    static String make_str(String str, int i, int j){
        String ret = "";
        if(i<=j){
            ret += str.substring(i, j + 1);
            return ret;
        }
        ret += str.substring(i);
        ret += str.substring(0, j + 1);
        return ret;
    }
    static long str2long(String str){
        long ret = 0;
        for(int i = 0; i<str.length(); i++){
            ret *= 16;
            if(!is_num(str.charAt(i))){
                ret += ((str.charAt(i) - 'A') + 10);
            }else{
                ret += (str.charAt(i) - '0');
            }
        }
        return ret;
    }

    static long solution_treasure_password(BufferedReader br) throws IOException{
        StringTokenizer st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        K = Integer.parseInt(st.nextToken());

        Character[] eles = new Character[N];
        Set<String> visited = new HashSet<>();

        String input_str = br.readLine();
        for(int i = 0; i<N; i++){
            eles[i] = input_str.charAt(i);
        }

        List<String>groups = new ArrayList<>();
        int p_size = N / 4;

        for(int i = 0; i<N; i++){
            String s = make_str(input_str, i, (i + p_size - 1) % N);
            if(visited.contains(s))continue;
            visited.add(s);
            groups.add(s);
        }
        groups = sorting_str(groups);
        String get_ret = groups.get(groups.size() - K);

        return str2long(get_ret);
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));


        int T = Integer.parseInt(br.readLine());
        for(int test_case = 1; test_case <= T; test_case++)
        {

            System.out.println("#" + test_case + " " + solution_treasure_password(br));
        }
    }
}
/*
5
12 10
1B3B3B81F75E
16 2
F53586D76286B2D8
 */
/*
8 ~ 28 개수가 많지 않음
시계 회전만 존재 상관없음
시계 방향으로 크다.

 */