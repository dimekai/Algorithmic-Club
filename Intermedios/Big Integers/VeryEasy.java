import java.util.Scanner;
import java.math.BigInteger;

class Main {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        while (input.hasNextInt()) {
            int N = input.nextInt();
            int A = input.nextInt();

            System.out.println(suma(N, A));
        }
    }

    public static BigInteger suma(int n, int a) {
        BigInteger N = BigInteger.valueOf(n);
        BigInteger A = BigInteger.valueOf(a);

        if (a == 1)
            return N.multiply(N.add(BigInteger.ONE)).divide(BigInteger.valueOf(2));
        else {
            BigInteger num = (((A.multiply(N)).subtract(N.add(BigInteger.ONE))).multiply(A.pow(n + 1))).add(A);
            BigInteger den = (BigInteger.ONE.subtract(A)).pow(2);
            return num.divide(den);
        }

    }
}