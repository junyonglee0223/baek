package g30786;

import java.io.*;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

public class Main {

    static void solution_find_odd_numbers_3000(BufferedReader br, BufferedWriter bw) throws Exception {
        int n = Integer.parseInt(br.readLine());

        int zt = 0, ot = 0;
        List<Integer>z_list = new ArrayList<>();
        List<Integer>o_list = new ArrayList<>();

        StringTokenizer st;
        for(int i = 0; i<n; i++){
            st = new StringTokenizer(br.readLine());
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());
            if((a + b) % 2 == 0){
                z_list.add(i);
                zt++;
            }else{
                o_list.add(i);
                ot++;
            }
        }
        if(zt == 0 || ot == 0){
            System.out.println("NO");
            return;
        }
        StringBuilder sb = new StringBuilder();
        sb.append("YES").append("\n");
        for(int ele : z_list){
            ele++;
            sb.append(ele).append(" ");
        }
        for(int ele : o_list){
            ele++;
            sb.append(ele).append(" ");
        }
        if (sb.length() > 0) {
            sb.setLength(sb.length() - 1);
        }
        sb.append("\n");
        bw.write(sb.toString());
        bw.flush();
        br.close();
        bw.close();
    }

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        solution_find_odd_numbers_3000(br, bw);
    }
    
}
/*
2
3
1 2
2 4
3 1
2
4 4
1 1
 */
/*
YES
NO
 */