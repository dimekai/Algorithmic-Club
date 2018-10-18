import java.util.*;
import java.math.BigInteger;

class Main {

    public static void main(String[] args) {
        short N;
        Scanner input = new Scanner(System.in);
        while (input.hasNextShort()) { // Leemos todas las lineas
            N = input.nextShort();
            System.out.println(N + "!");
            System.out.println(factorial(N));
        }

    }

    public static BigInteger factorial(short N) {
        BigInteger fact = BigInteger.ONE;
        for (int i = 1; i <= N; i++)
            fact = fact.multiply(BigInteger.valueOf(i));

        return fact;
    }

}