package s14425;
//s14425 문자열 집합


import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashSet;
import java.util.Set;
import java.util.StringTokenizer;

public class Main {

    static void solution_string_set(BufferedReader br) throws IOException {
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());

        Set<String>text_set = new HashSet<>();

        for(int i = 0; i<n; i++){
            String tmp_str = br.readLine();
            text_set.add(tmp_str);
        }

        int answer = 0;
        for(int i = 0; i<m; i++){
            String tmp_str = br.readLine();
            if(text_set.contains(tmp_str)) answer++;
        }
        System.out.println(answer);
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        solution_string_set(br);
    }
}
/*
5 11
baekjoononlinejudge
startlink
codeplus
sundaycoding
codingsh
baekjoon
codeplus
codeminus
startlink
starlink
sundaycoding
codingsh
codinghs
sondaycoding
startrink
icerink
*/
/*
4
*/