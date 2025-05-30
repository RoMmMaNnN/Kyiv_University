import java.util.Arrays;
import java.util.Scanner;

public class Main {
    public static void main(String arg[]) {
        Task1 obj1 = new Task1();
        Task2 obj2 = new Task2();
        Task3 obj3 = new Task3();
        Scanner scan = new Scanner(System.in);
        double x1, x2, y1, y2;
        double[] setNum1 = {12.0, -8.5, 7.2, -5.0, 15.6, 3.3, -9.9, 8.4, -2.2, 14.0, -6.6, 7.8, 4.5, -3.3, 10.2};
        double[] setNum2 = {-10.5, 20.3, -8.2, 9.7, 5.5, -12.0, 6.6, -3.1, 11.4, -15.2, 8.8, -7.3, 2.0, -4.4, 13.9};

        System.out.println("***Task 1***\n");
        obj1.task1();

        System.out.println("\n***Task 2***\n");
        System.out.println("Початкові дані: " + Arrays.toString(setNum1));
        System.out.printf("Середнє арифметичне для першої послідовності: %.4f%n", obj2.task2(setNum1));
        System.out.println("Початкові дані: " + Arrays.toString(setNum2));
        System.out.printf("Середнє арифметичне для другої послідовності: %.4f%n", obj2.task2(setNum2));

        System.out.println("\n***Task 3***\n");
        System.out.println("Введіть значення для х1:");
        x1 = scan.nextDouble();
        System.out.println("Введіть значення для х2:");
        x2 = scan.nextDouble();
        y1 = obj3.task3(x1);
        y2 = obj3.task3(x2);
        System.out.printf("Початкові дані: \nх1 = %.1f \nx1 = %.1f\n", x1, x2);
        System.out.printf("Результат: \nу1 = %.4f \ny2 = %.4f", y1, y2);
    }
}
