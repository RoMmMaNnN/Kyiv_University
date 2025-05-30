package com.Lx5;

public class Lr21 {
    public static void main(String[] args) {
        double m = 0.5, n = 0.2;
        int b1 = -2;
        double[] xValues = {-2.3, 0.6, 4.8};
        double[][] task2Values = {
                {-1, 3.4, -2.3},
                {-3.2, 5.5, 0.6},
                {-5.2, 7.2, 4.8}
        };

        System.out.println("\n***Task 1***\n");
        for (int i = 0; i < xValues.length; i++) {
            double x = xValues[i];
            double y = task1(m, n, b1, x);
            System.out.printf("%d) При х = %.2f ⟹ y = %.4f%n", i + 1, x, y);
        }

        System.out.println("\n***Task 2***\n");
        for (int i = 0; i < task2Values.length; i++) {
            double row[] = task2Values[i];
            double a = row[0];
            double b2 = row[1];
            double x = row[2];
            double z = Math.tan(b2 * Math.pow(x, i + 1));
            double y = task2(a, b2, x, z);
            System.out.printf("%d) При х = %.2f ⟹ y = %.4f%n", i + 1, x, y);
        }
    }

    public static double task1(double m, double n, int b1, double x) {
        double y;

        if (Math.abs(b1* m) > Math.pow(x, 2)) {
            y = Math.sin(b1* m + Math.cos(n * x));
        } else if (Math.abs(b1* m) < Math.pow(x, 2)) {
            y = Math.cos(b1* m - Math.sin(x));
        } else {
            y = Math.sqrt(Math.exp(Math.abs(Math.cos(x))) + Math.sqrt(Math.abs(b1 * m * x)));
        }
        return y;
    }

    public static double task2(double a, double b2, double x, double z) {
        double y;
        int caseNumber;
        if (x <= a) {
            caseNumber = 1;
        } else if (x > a && x <= Math.pow(b2, 3.5)) {
            caseNumber = 2;
        } else {
            caseNumber = 3;
        }

        switch (caseNumber) {
            case 1:
                y = Math.exp(a * x) - 3.5 * Math.pow(Math.cos(z + b2 * x), 2);
                break;
            case 2:
                y = a + Math.log(Math.abs(a + b2 * x)) - (2 * x);
                break;
            case 3:
                y = a + Math.pow(Math.cos(a + b2 * x * z), 3.5);
                break;
            default:
                y = 0;
                break;
        }
        return y;
    }
}