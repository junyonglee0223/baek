package s2090;
//s2090 조화평균
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;
import java.math.BigInteger;

public class Main {

    static String solution_harmonic_mean(BufferedReader br) throws IOException {
        int N = Integer.parseInt(br.readLine());
        BigInteger[] arr = new BigInteger[N];

        StringTokenizer st = new StringTokenizer(br.readLine());
        for (int i = 0; i < N; i++) {
            arr[i] = new BigInteger(st.nextToken());
        }

        BigInteger tot_mult = BigInteger.ONE;
        for (int i = 0; i < N; i++) {
            tot_mult = tot_mult.multiply(arr[i]);
        }

        BigInteger tot_parents = BigInteger.ZERO;
        for (int i = 0; i < N; i++) {
            tot_parents = tot_parents.add(tot_mult.divide(arr[i]));
        }

        BigInteger g = tot_mult.gcd(tot_parents);
        BigInteger num = tot_mult.divide(g);
        BigInteger den = tot_parents.divide(g);

        StringBuilder sb = new StringBuilder();
        sb.append(num).append("/").append(den).append("\n");
        return sb.toString();
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        System.out.print(solution_harmonic_mean(br));
    }
}

/*
3
4 1 2
 */
/*
4/7
 */
