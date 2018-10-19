import java.util.Scanner;
import java.math.BigInteger;;

class Main {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        BigInteger sum = BigInteger.ZERO;

        while (input.hasNextBigInteger()) {
            BigInteger num = input.nextBigInteger();
            if (num.equals(BigInteger.ZERO))
                break;
            sum = sum.add(num);
        }

        System.out.println(sum);
    }
}