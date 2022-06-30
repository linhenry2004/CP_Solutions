import java.io.*;
 
public class Weird_Algorithm_IO {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        long n = Long.parseLong(br.readLine());
        
        StringBuilder out = new StringBuilder();
        while (n != 1) {
            out.append(n).append(" ");
            if ((n % 2) == 1) {
                n = n * 3 + 1;
            } else {
                n /= 2;
            }
        }
        out.append(1);

        System.out.println(out);
    }
}