import java.util.Scanner;

public class Task1 {
    public static void task1() {
        double x, y, z, h, minX, maxX;

        Scanner scan = new Scanner(System.in);

        System.out.println("Введіть мінімальне значення Х функції:");
        minX = scan.nextDouble();
        System.out.println("Введіть максимальне значення Х функції:");
        maxX = scan.nextDouble();
        System.out.println("Введіть крок ходу:");
        h = scan.nextDouble();

        if (minX > maxX) {
            double temp;
            temp = maxX;
            maxX = minX;
            minX = temp;
        }

        if (h > 0) {
            System.out.println("┌───────┬───────────┬───────────┐");
            System.out.println("│   x   │   y(x)    │   z(x)    │");
            System.out.println("├───────┼───────────┼───────────┤");
            for (x = minX; x <= maxX; x += h) {
                y = Math.exp(x);
                z = 1.5 * Math.cos(x - (Math.PI / 4) * Math.exp(x));

                System.out.printf("│%7.2f│%11.4f│%11.4f│\n", x, y, z);
            }
            System.out.println("└───────┴───────────┴───────────┘");
        } else if (h < 0) {
            System.out.println("┌───────┬───────────┬───────────┐");
            System.out.println("│   x   │   y(x)    │   z(x)    │");
            System.out.println("├───────┼───────────┼───────────┤");
            for (x = maxX; x >= minX; x -= h) {
                y = Math.exp(x);
                z = 1.5 * Math.cos(x - (Math.PI / 4) * Math.exp(x));

                System.out.printf("│%7.2f│%11.4f│%11.4f│\n", x, y, z);
            }
            System.out.println("└───────┴───────────┴───────────┘");
        } else System.out.println("Крок ходу не може дорівнювати нулю!");
    }
}
