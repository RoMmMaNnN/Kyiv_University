package Task2;

import java.io.*;
import java.util.*;

public class FileHandler {
    public static int readAmount(String filename) {
        try (BufferedReader reader = new BufferedReader(new FileReader(filename))) {
            String line = reader.readLine().trim();

            if (isLineEmpty(line)) {
                System.err.println("Файл порожній або не містить числа.");
                return -1;
            }

            int amount = parseInteger(line);
            if (amount == -1) {
                return -1;
            }

            if (!isPositive(amount)) {
                System.err.println("Число має бути додатним.");
                return -1;
            }

            return amount;
        } catch (IOException e) {
            System.err.println("Помилка зчитування з файлу " + filename + ": " + e.getMessage());
            return -1;
        }
    }

    public static List<Integer> readCoins(String filename) {
        List<Integer> coins = new ArrayList<>();
        try (BufferedReader reader = new BufferedReader(new FileReader(filename))) {
            String line;
            while ((line = reader.readLine()) != null) {
                line = line.trim();

                if (isLineEmpty(line)) {
                    continue;
                }

                int coin = parseInteger(line);
                if (coin == -1) {
                    return Collections.emptyList();
                }

                if (!isPositive(coin)) {
                    System.err.println("Число в файлі має бути додатнім: " + coin);
                    return Collections.emptyList();
                }

                coins.add(coin);
            }
        } catch (IOException e) {
            System.err.println("Помилка зчитування з файлу " + filename + ": " + e.getMessage());
            return Collections.emptyList();
        }
        return coins;
    }

    public static void appendToFile(String filename, String content) {
        try (BufferedWriter writer = new BufferedWriter(new FileWriter(filename, true))) {
            writer.write(content);
        } catch (IOException e) {
            System.err.println("Помилка запису у файл " + filename + ": " + e.getMessage());
        }
    }

    private static boolean isLineEmpty(String line) {
        return line == null || line.trim().isEmpty();
    }

    private static int parseInteger(String line) {
        try {
            return Integer.parseInt(line);
        } catch (NumberFormatException e) {
            System.err.println("Формат числа некоректний. Очікується ціле число: " + line);
            return -1;
        }
    }

    private static boolean isPositive(int number) {
        return number > 0;
    }

    public static boolean isFileEmpty(String filePath) {
        try (BufferedReader reader = new BufferedReader(new FileReader(filePath))) {
            return reader.readLine() == null;
        } catch (IOException e) {
            System.out.println("Помилка читання файлу " + filePath + ": " + e.getMessage());
            return true;
        }
    }
}
