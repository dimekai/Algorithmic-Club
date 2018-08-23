/*@author Díaz Medina Jesús Kaimorts*/
import java.io.*;
import java.math.BigInteger;

class main() {
	public static void main(String[] args) {
		try {
            int n;
            String numero, rs = "";
            BufferedReader leer = new BufferedReader(new InputStreamReader(System.in));
            numero = leer.readLine();
            n = numero.length();
            BigInteger r = BigInteger.valueOf((long)( (n * (Math.pow(10, n - 1)) * 45) ));
            System.out.println(r.toString());

        } catch (IOException e) {
            e.getMessage();
        }
	}
}