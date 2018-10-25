import java.util.Scanner;
import java.math.BigInteger;

class Main {

    /*
     * Implementación no recursiva.
     * 
     * @param a: representa la base
     * 
     * @param b: representa la potencia
     * 
     * @param n: representa el modulo
     * 
     * La expresion es de la forma a^b % n
     * 
     * @return res: resultado de la exponenciacion binaria
     * 
     * Complejidad: O(log(N))
     */
    public static BigInteger expo_mod_bin(BigInteger a, BigInteger b, BigInteger n) {
        BigInteger res = BigInteger.ONE;
        BigInteger dos = BigInteger.valueOf(2);

        while (b.compareTo(BigInteger.ZERO) == 1) {
            if (b.mod(dos).compareTo(BigInteger.ONE) == 0)
                res = res.multiply(a).mod(n);
            b = b.divide(dos);
            a = a.multiply(a).mod(n);
        }

        return res;

    }

    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        short t = input.nextShort();
        BigInteger x, y, n;
        for (short i = 0; i < t; i++) {
            x = input.nextBigInteger();
            y = input.nextBigInteger();
            n = input.nextBigInteger();

            System.out.println(expo_mod_bin(x, y, n));
        }
    }
}