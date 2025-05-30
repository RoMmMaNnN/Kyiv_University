package Task2;

import Task2.coin.*;
import java.util.*;
import java.util.logging.Logger;
import java.util.logging.Level;

public class Rgr2Kriu {
    private static final Logger logger = Logger.getLogger(Rgr2Kriu.class.getName());

    public static void main(String[] args) {
        String inputPath = "D:/Kyiv Polytechnic Institute/Java АСД/РГР/2 sem/RGR/src/Task2/input/";
        String outputPath = "D:/Kyiv Polytechnic Institute/Java АСД/РГР/2 sem/RGR/src/Task2/output/";

        List<Integer> coins = Arrays.asList(1, 2, 3, 5, 10, 20, 50);

        String[] inputFiles = {"input1.txt", "input2.txt", "input3.txt"};
        String[] outputFiles = {"output1.txt", "output2.txt", "output3.txt"};

        for (int i = 0; i < inputFiles.length; i++) {
            String inputFile = inputPath + inputFiles[i];
            String outputFile = outputPath + outputFiles[i];

            if(i == 0) {
                int minAmount = 77;
                int maxAmount = 1000;
                Generator.generateRandomAmount(inputFile, minAmount, maxAmount);
            }

            System.out.println("\n===========================================");
            System.out.println("Читання файлу: " + inputFile);
            int amount = FileHandler.readAmount(inputFile);

            if (amount == -1) {
                logger.log(Level.SEVERE, "Помилка під час зчитування суми з файлу");
                continue;
            }
            System.out.println("\nНабір " + (i + 1) + ": Мінімальна кількість монет для суми " + amount);

            CoinResult result = Coin.solve(amount, coins);

            if (result.getMinCount() == -1) {
                System.out.println("Неможливо розміняти суму " + amount + " за допомогою доступних монет.");
                result = new CoinResult(0, "неможливо");
            }

            System.out.println(result);

            String resultText = "Мінімальна кількість монет для суми " + amount + ": " + result.getMinCount() + "\n" +
                    "Використані монети: " + result.getUsedCoins() + "\n";

            FileHandler.appendToFile(outputFile, resultText);

            if (!FileHandler.isFileEmpty(outputFile)) {
                System.out.println("\nРезультати записано у: " + outputFile);
            }
            System.out.println("===========================================");
        }
    }
}
