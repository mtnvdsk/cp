import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter a double: ");
        double number = scanner.nextDouble();
        scanner.close();

        String formattedNumber = String.format("%7.3f", number);
        System.out.println("Formatted number: " + formattedNumber);
    }
}