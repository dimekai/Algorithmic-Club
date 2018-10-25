import java.util.*;
import java.math.*;

class Main {
    public static void main(String[] args) {
        boolean she_doesnt_love_you = true;
        Scanner input = new Scanner(System.in);
        short n = input.nextShort();

        for (short i = 0; i < n; i++) {

            String number;
            BigDecimal suma = BigDecimal.ZERO;

            while (she_doesnt_love_you) {
                number = input.next();
                if (number.equals("0")) {
                    System.out.println(suma.stripTrailingZeros().toPlainString());
                    break;
                }
                suma = suma.add(new BigDecimal(number));
            }
        }
    }
}