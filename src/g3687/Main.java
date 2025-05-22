package g3687;
//g3687 성냥개비


import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
    static String[] max_matchstick;
    static String[] min_matchstick;

    static void init_matchstick(){
        max_matchstick = new String[101];
        min_matchstick = new String[101];

        for(int i = 0; i<101; i++){
            max_matchstick[i] = "";
            min_matchstick[i] = "";
        }

        max_matchstick[2] = "1";
        max_matchstick[3] = "7";

        for(int i = 4; i<max_matchstick.length; i++){
            max_matchstick[i] = max_matchstick[i-2] + "1";
        }

        String[] min_units = {"", "", "1", "7", "4", "2", "0", "8"};

        for(int i = 0; i<min_units.length; i++){
            min_matchstick[i] = min_units[i];
        }
        min_matchstick[6] = "6";

        for(int i = 8; i<min_matchstick.length; i++){
            String cur_str = "";

            for(int j = 2; j<min_units.length; j++){
                if(min_matchstick[i-j].isEmpty())continue;

                String tmp_str = min_matchstick[i - j] + min_units[j];
                if(cur_str.isEmpty() || cur_str.length() > tmp_str.length()
                        || (cur_str.length() == tmp_str.length()
                                && cur_str.compareTo(tmp_str) > 0)){
                    cur_str = tmp_str;
                }
            }
            min_matchstick[i] = cur_str;
        }
    }

    static void solution_matchstick(BufferedReader br) throws IOException {
        int n = Integer.parseInt(br.readLine());
        System.out.println(min_matchstick[n] + " " + max_matchstick[n]);
    }
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        init_matchstick();

        int T = Integer.parseInt(br.readLine());
        while(T-- > 0){
            solution_matchstick(br);
        }
    }
}

/*
4
3
6
7
15
*/
/*
7 7
6 111
8 711
108 7111111
*/