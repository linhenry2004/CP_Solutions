import java.util.Scanner;
 
public class Weird_Algorithm {
    public static void main(String []args){
        Scanner scanner = new Scanner(System.in);
        long n = scanner.nextLong();
        System.out.print(n + " ");
        while (n !=  1) {
            if (n % 2 == 0) {
                n /= 2;
                System.out.print(n + " ");
            } else {
                n = n * 3 + 1;
                System.out.print(n + " ");
            }
        }
        scanner.close();
    }
}