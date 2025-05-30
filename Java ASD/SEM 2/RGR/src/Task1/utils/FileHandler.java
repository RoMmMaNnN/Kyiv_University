package Task1.utils;

import java.io.*;
import java.util.*;

public class FileHandler {
    public static int[][] readMatrixFromFile(String filePath) throws IOException {
        if (isFileEmpty(filePath)) {
            System.out.println("Порожній файл, тому повернено пустий масив.");
            return new int[0][0];
        }

        List<int[]> rows = new ArrayList<>();
        BufferedReader reader = new BufferedReader(new FileReader(filePath));
        String line;
        int expectedLength = -1;
        int rowNumber = 0;

        while ((line = reader.readLine()) != null) {
            rowNumber++;
            line = line.trim();
            if (line.isEmpty()) continue;

            String[] parts = line.split("\\s+");
            if (expectedLength == -1) {
                expectedLength = parts.length;
            } else if (parts.length != expectedLength) {
                reader.close();
                throw new IOException("Невалідна матриця: у рядку " + rowNumber + " неправильна кількість елементів.");
            }

            int[] row = new int[parts.length];
            for (int i = 0; i < parts.length; i++) {
                if (parts[i].equals("∞")) {
                    row[i] = Integer.MAX_VALUE;
                } else {
                    try {
                        row[i] = Integer.parseInt(parts[i]);
                    } catch (NumberFormatException e) {
                        reader.close();
                        throw new IOException("Невалідне значення в рядку " + rowNumber + ": \"" + parts[i] + "\"");
                    }
                }
            }
            rows.add(row);
        }
        reader.close();
        if (rows.isEmpty()) {
            System.out.println("Файл не містить жодного рядка з числовими значеннями.");
            return new int[0][0];
        }
        return rows.toArray(new int[0][0]);
    }


    public static void writeMatrixToFile(int[][] matrix, String filePath) throws IOException {
        BufferedWriter writer = new BufferedWriter(new FileWriter(filePath));
        for (int[] row : matrix) {
            for (int val : row) {
                if (val == Integer.MAX_VALUE)
                    writer.write("∞ ");
                else
                    writer.write(val + " ");
            }
            writer.newLine();
        }
        writer.close();
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
