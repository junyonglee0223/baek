package g5052;
//g5052 전화번호 목록

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashSet;
import java.util.LinkedList;
import java.util.List;
import java.util.Set;

public class Main {

    static boolean is_consistency(BufferedReader br) throws IOException {
        int n = Integer.parseInt(br.readLine());

        List<String> str_list = new LinkedList<>();
        Set<String> str_set = new HashSet<>();

        for(int i = 0; i<n; i++){
            String str = br.readLine();
            str_list.add(str);
            for(int len = 1; len <= str.length() - 1; len++){
                str_set.add(str.substring(0, len));
            }
        }

        for(String str : str_list){
            if(str_set.contains(str))return false;
        }
        return true;
    }

    static void solution_phone_list(BufferedReader br) throws IOException {
        int T = Integer.parseInt(br.readLine());
        while(T-- > 0){
            if(is_consistency(br)){
                System.out.println("YES");
            }else{
                System.out.println("NO");
            }
        }
    }
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        solution_phone_list(br);
    }
}
/*
2
3
911
97625999
91125426
5
113
12340
123440
12345
98346
*/
/*
NO
YES
*/