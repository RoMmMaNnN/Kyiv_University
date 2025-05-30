package com.rgr;

import java.util.Scanner;

public class RgrTv42Kriu {
    public static void main(String[] args) {
        System.out.printf("\n*******\n Task 1\n*******\n");
        double[][] matrix = {
                {-4, 3, -1, -5, -2, 2},
                {5, -2, 6, -1, 6, 10.4},
                {9, -5, -10, 5, -9, -0.3},
                {9, -8, -3, -6, -7, -69.7},
                {2, 8, 0, -7, 5, 31.6}
        };
        task13("\nПочаткова матриця:", matrix);
        double[][] RREMatrix = task11(matrix);
        task13("\nНормована ступінчата матриця:", RREMatrix);
        double[] solutions = task12(RREMatrix);
        task13("\nВектор розв'зків:", solutions);

        System.out.printf("\n*******\n Task 2\n*******\n\n");
        System.out.println("Введіть ціле число: ");
        Scanner scan = new Scanner(System.in);
        long num = scan.nextLong();
        long newNum = task2(num);
        System.out.printf("Вхідне число: %d, Після заміни: %d%n", num, newNum);
    }

    public static double[][] task11(double[][] matrix) {
        int n = matrix.length;
        int m = matrix[0].length;

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < m; j++) {
                matrix[i][j] /= matrix[i][i];
            }
            matrix[i][i] = 1.0;

            for (int k = i + 1; k < n; k++) {
                double factor = matrix[k][i];
                for (int j = i; j < m; j++) {
                    matrix[k][j] -= factor * matrix[i][j];
                }
            }
        }
        return matrix;
    }

    public static double[] task12(double[][] matrix) {
        int n = matrix.length;
        double[] solutions = new double[n];

        for (int i = n - 1; i >= 0; i--) {
            double sum = matrix[i][n];
            for (int j = i + 1; j < n; j++) {
                sum -= matrix[i][j] * solutions[j];
            }
            solutions[i] = sum / matrix[i][i];
        }
        return solutions;
    }

    public static void task13(String title, double[][] matrix) {
        System.out.println(title);
        int n = matrix.length;
        int m = matrix[0].length;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                System.out.printf("%.3f\t", matrix[i][j]);
            }
            System.out.println();
        }
    }

    public static void task13(String title, double[] solutions) {
        System.out.println(title);
        int n = solutions.length;
        for (int i = 0; i < n; i++) {
            System.out.printf("x%d = %.3f\t", i + 1, solutions[i]);
            System.out.printf("\n");
        }
    }

    public static long task2(long num) {
        String numStr = String.valueOf(num);
        int length = numStr.length();
        char[] chars = numStr.toCharArray();
        if (length > 1) {
            char temp = chars[0];
            chars[0] = chars[length - 1];
            chars[length - 1] = temp;
        } else {
            System.out.println("Менше двох цифр в числі, неможливо змінити крайні цифри місцями");
        }
        return Long.parseLong(new String(chars));
    }
}
