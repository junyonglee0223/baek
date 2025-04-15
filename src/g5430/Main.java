package g5430;

import java.util.*;

public class Main {

    static List<Integer> parse_arr(String input){
        List<Integer>result = new ArrayList<>();
        StringBuilder num = new StringBuilder();

        for(char ch : input.toCharArray()){
            if(Character.isDigit(ch)){
                num.append(ch);
            }
            else if(num.length() > 0){
                result.add(Integer.parseInt(num.toString()));
                num.setLength(0);
            }
        }
        return result;
    }
    static String format_deque(Deque<Integer> deque, boolean reversed){
        StringBuilder sb = new StringBuilder();
        sb.append('[');

        Iterator<Integer> it = reversed ? deque.descendingIterator() : deque.iterator();

        while(it.hasNext()){
            sb.append(it.next());
            if(it.hasNext()){
                sb.append(',');
            }
        }
        sb.append(']');
        return sb.toString();
    }
    static void solution_AC(Scanner sc){
        int T = Integer.parseInt(sc.nextLine());

        while(T-- > 0){
            String cmd = sc.nextLine();
            int N = Integer.parseInt(sc.nextLine());
            String arr = sc.nextLine();

            List<Integer> nums = parse_arr(arr);
            Deque<Integer> deque = new LinkedList<>(nums);

            boolean reversed = false;
            boolean is_error = false;

            for(char c : cmd.toCharArray()){
                if(c == 'R'){
                    reversed = !reversed;
                }
                else if(c == 'D'){
                    if(deque.isEmpty()){
                        is_error = true;
                        break;
                    }
                    if(reversed){
                        deque.removeLast();
                    }
                    else{
                        deque.removeFirst();
                    }
                }
            }

            if(is_error){
                System.out.println("error");
            }
            else{
                System.out.println(format_deque(deque, reversed));
            }
        }
    }

    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);

        solution_AC(sc);
    }
}
/*
4
RDD
4
[1,2,3,4]
DD
1
[42]
RRD
6
[1,1,2,3,5,8]
D
0
[]
*/

/*
[2,1]
error
[1,2,3,5,8]
error
*/