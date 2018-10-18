import java.util.Scanner;
import java.math.BigDecimal;

class Main {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        while (input.hasNextBigDecimal()) {
            BigDecimal R = input.nextBigDecimal();
            short n = input.nextShort();

            System.out.println(potencia(R, n).toPlainString().replaceFirst("^0\\.", "."));
        }
    }

    public static BigDecimal potencia(BigDecimal R, short n) {
        BigDecimal res = new BigDecimal("1");
        while (n > 0) {
            if (n % 2 == 1) // Si es impar
                res = res.multiply(R);
            n >>= 1;
            R = R.multiply(R);
        }

        return res.stripTrailingZeros();
    }
}