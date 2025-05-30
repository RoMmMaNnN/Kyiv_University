package Task1.utils;

import Task1.*;

public class FloydWarshall {
    public static int[][] run(Graf graph) {
        int size = graph.getSize();
        int[][] dist = new int[size][size];
        int[][] original = graph.getMatrix();

        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                if (i == j) dist[i][j] = 0;
                else dist[i][j] = (original[i][j] == 0 ? Integer.MAX_VALUE : original[i][j]);
            }
        }

        for (int k = 0; k < size; k++) {
            for (int i = 0; i < size; i++) {
                for (int j = 0; j < size; j++) {
                    if (dist[i][k] != Integer.MAX_VALUE && dist[k][j] != Integer.MAX_VALUE) {
                        if (dist[i][i] < 0) throw new IllegalArgumentException("Негативний цикл");
                        dist[i][j] = Math.min(dist[i][j], dist[i][k] + dist[k][j]);
                    }
                }
            }
        }

        return dist;
    }

    public static void printResult(int[][] dist) {
        System.out.print("\t");
        for (int i = 0; i < dist.length; i++) {
            System.out.print("\033[1m" + (i + 1) + "\033[0m" + "\t");
        }
        System.out.println();
        for (int i = 0; i < dist.length; i++) {
            System.out.print("\033[1m" + (i + 1) + "\033[0m" + "\t");
            for (int j = 0; j < dist.length; j++) {
                if (dist[i][j] == Integer.MAX_VALUE) {
                    System.out.print("∞\t");
                } else {
                    System.out.print(dist[i][j] + "\t");
                }
            }
            System.out.println();
        }
        System.out.println("=================================\n");
    }
}

