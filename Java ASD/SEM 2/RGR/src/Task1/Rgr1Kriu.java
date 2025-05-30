package Task1;

import Task1.utils.*;
import java.io.*;
import java.util.logging.Logger;
import java.util.logging.Level;

public class Rgr1Kriu {
    private static final Logger logger = Logger.getLogger(Rgr1Kriu.class.getName());

    public static void main(String[] args) {
        int numberOfgraf = 3;
        int size = 8;
        int edges = 12;
        Graf[] grafs = new Graf[numberOfgraf];
        String inputPath = "D:/Kyiv Polytechnic Institute/Java АСД/РГР/2 sem/RGR/src/Task1/data/matrix";
        String outputPath = "D:/Kyiv Polytechnic Institute/Java АСД/РГР/2 sem/RGR/src/Task1/output/graf";
        for (int i = 0; i < numberOfgraf; i++) {
            String filePath = inputPath + (i + 1) + ".txt";
            System.out.println("Читання файлу: " + inputPath);
            try { grafs[i] = new Graf(size, edges, FileHandler.readMatrixFromFile(filePath));
            } catch (IOException e) { logger.log(Level.SEVERE, "Помилка під час зчитування файлу", e); }
        }

        for (int i = 0; i < grafs.length; i++) {
            String filePath = outputPath + (i + 1) + ".txt";
            Graf graf = grafs[i];

            System.out.println("\n============ Граф: " + (i + 1) + " ============");
            if (graf.isGrafEmpty()) GraphGenerator.generateRandomGraph(graf);
            graf.print();

            System.out.println("Обробка графа " + (i + 1) + "... ");
            System.out.println("\n\033[1mГраф є" + (graf.isConnected() ? "" : " не") + " зв'язним\033[0m");
            int[][] dist = FloydWarshall.run(graf);

            System.out.println("\n=== Матриця найкоротших шляхів ===");
            FloydWarshall.printResult(dist);

            try { FileHandler.writeMatrixToFile(dist, filePath);
            } catch (IOException e) { logger.log(Level.SEVERE, "Помилка під час зчитування файлу", e); }

            if (!FileHandler.isFileEmpty(filePath)) System.out.println("Результати записано у: " + filePath);

        }

    }
}
