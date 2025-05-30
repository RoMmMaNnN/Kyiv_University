package com.Lx5;

import java.util.Scanner;

public class Lr22 {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);

        System.out.println("\n*** Task 3 ***");

        System.out.println("Введіть сторону квадрата A: ");
        double A = scan.nextDouble();
        System.out.println("Введіть радіус кола R: ");
        double R = scan.nextDouble();
        Object[] result = task3(A, R);
        double res = (double) result[0];
        String figure = (String) result[1];
        System.out.printf("Площа більшої фігури: %.4f кв. од. і це %s\n", res, figure);

        System.out.println("\n*** Task 4 ***\n");
        double[][] inputValues = {
                {23, 17, 47},
                {9, -8.1, 62},
                {36, 65, 62}
        };

        for (int i = 0; i < inputValues.length; i++) {
            double row[] = inputValues[i];
            double a = row[0];
            double b = row[1];
            double c = row[2];
            double min = task4(a, b, c);
            System.out.printf("%d) Найменше з чисел %.4f, %.4f, %.4f: %.4f%n\n", i + 1, a, b, c, min);
        }
    }

    public static Object[] task3(double A, double R) {
        double squareArea = Math.pow(A, 2);
        double circleArea = Math.PI * Math.pow(R, 2);
        String figure;

        if (squareArea > circleArea) {
            figure = "квадрат";
            return new Object[]{squareArea, figure};
        } else {
            figure = "коло";
            return new Object[]{circleArea, figure};
        }
    }

    public static double task4(double a, double b, double c) {
        return (a < b) ? ((a < c) ? a : c) : ((b < c) ? b : c);
    }
}