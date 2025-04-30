package g1339;
//g1339 단어 수학

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Comparator;
import java.util.List;

public class Main {

    static class CharNode{
        long weight;
        int idx;
        CharNode(long weight, int idx){
            this.weight = weight;
            this.idx = idx;
        }
    }

    static void init_weight(long [] pow_10){
        pow_10[0] = 1;
        for(int i = 1; i<8; i++){
            pow_10[i] = pow_10[i-1] * 10;
        }
    }
    static int word_2_int(String str, int[] char_weight){
        String tmp = "";
        for(int i = 0; i<str.length(); i++){
            tmp += (char_weight[str.charAt(i)  -'A']);
        }
        return Integer.parseInt(tmp);
    }
    static void solution_word_math(BufferedReader br) throws IOException {

        long[] pow_10 = new long[8];
        init_weight(pow_10);

        int n = Integer.parseInt(br.readLine());

        List<String> words = new ArrayList<>();
        for(int i = 0; i<n; i++){
            String tmp_str = br.readLine();
            words.add(tmp_str);
        }

        int[][] ch_board = new int[26][8];
        for(int i = 0; i<26; i++)
            for(int j = 0; j<8; j++)
                ch_board[i][j] = 0;

        for(int i = 0; i<words.size(); i++){
            int tmp_size = words.get(i).length();
            for(int j = tmp_size - 1; j>=0; j--){
                int j_pow = tmp_size - 1 - j;
                int idx = words.get(i).charAt(j) - 'A';
                ch_board[idx][j_pow]++;
            }
        }

        List<CharNode> list_char = new ArrayList<>();
        for(int i  = 0; i<26; i++){
            long tmp = 0;
            for(int j = 7; j>=0; j--){
                tmp += ch_board[i][j] * pow_10[j];
            }
            list_char.add(new CharNode(tmp, i));
        }
        list_char.sort(Comparator.comparingLong((CharNode c) -> c.weight).reversed());

        int[] char_weight = new int[26];
        for(int i = 0; i<list_char.size(); i++){
            int idx = list_char.get(i).idx;
            char_weight[idx] = 9 - i;
        }

        int answer = 0;
        for(int i = 0; i<words.size(); i++){
            answer += word_2_int(words.get(i), char_weight);
        }
        System.out.println(answer);
    }


    static void solution_word_math_v1(BufferedReader br) throws IOException {
        int n = Integer.parseInt(br.readLine().trim());

        String[] words = new String[n];
        for (int i = 0; i < n; i++) {
            words[i] = br.readLine().trim();
        }

        long[] weight = new long[26];
        for (String w : words) {
            long mul = 1;
            for (int i = w.length() - 1; i >= 0; i--, mul *= 10) {
                weight[w.charAt(i) - 'A'] += mul;
            }
        }

        Integer[] idx = new Integer[26];
        for (int i = 0; i < 26; i++) idx[i] = i;
        Arrays.sort(idx, (i, j) -> Long.compare(weight[j], weight[i]));

        int[] charVal = new int[26];
        for (int i = 0; i < 26; i++) {
            charVal[idx[i]] = 9 - i;
        }

        long answer = 0;
        for (String w : words) {
            long mul = 1;
            for (int i = w.length() - 1; i >= 0; i--, mul *= 10) {
                answer += charVal[w.charAt(i) - 'A'] * mul;
            }
        }

        System.out.println(answer);
    }


    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

//        solution_word_math(br);
        solution_word_math_v1(br);

//        int T = Integer.parseInt(br.readLine());
//        while(T-- > 0){
////            solution_word_math(br);
//            solution_word_math_v1(br);
//        }
    }
}
/*
4
2
AAA
AAA
2
GCF
ACDEB
10
A
B
C
D
E
F
G
H
I
J
2
AB
BA
*/
/*
1998
99437
45
187
*/