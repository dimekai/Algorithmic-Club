import java.math.*;
import java.util.*;

class Main {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        int N, F, caso = 0;
        for (;;) {
            N = input.nextInt();
            F = input.nextInt();

            if (N + F == 0)
                break;
            BigInteger cost = BigInteger.ZERO;
            BigInteger item = BigInteger.ZERO;
            for (int i = 0; i < N; i++) {
                item = input.nextBigInteger();
                cost = cost.add(item);
            }

            System.out.println("Bill #" + (++caso) + " costs " + cost + ": each friend should pay "
                    + cost.divide(BigInteger.valueOf(F)) + "\n");
        }
    }
}