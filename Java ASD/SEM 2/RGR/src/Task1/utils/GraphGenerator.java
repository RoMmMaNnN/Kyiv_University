package Task1.utils;

import java.util.*;
import Task1.*;

public class GraphGenerator {
    public static void generateRandomGraph(Graf graf) {
        int size = graf.getSize();
        int edges = graf.getEdges();
        int[][] matrix = new int[size][size];

        Random random = new Random();
        Set<String> addedEdges = new HashSet<>();

        int added = 0;
        while (added < edges) {
            int i = random.nextInt(size);
            int j = random.nextInt(size);

            if (i != j) {
                int u = Math.min(i, j);
                int v = Math.max(i, j);
                String edgeKey = u + "-" + v;

                if (!addedEdges.contains(edgeKey)) {
                    int weight = random.nextInt(10) + 1;
                    matrix[u][v] = weight;
                    matrix[v][u] = weight;
                    addedEdges.add(edgeKey);
                    added++;
                }
            }
        }

        graf.setMatrix(matrix);
    }
}
