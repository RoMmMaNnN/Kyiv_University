package Task2.coin;

import java.io.FileWriter;
import java.io.IOException;
import java.util.Random;

public class Generator {
    public static void generateRandomAmount(String filename, int min, int max) {
        Random random = new Random();
        int amount = min + random.nextInt(max - min + 1);

        try (FileWriter writer = new FileWriter(filename)) {
            writer.write(String.valueOf(amount));
            System.out.println("Згенеровано випадкову суму: " + amount + " коп.\nЗаписано у " + filename);
        } catch (IOException e) {
            System.err.println("Помилка при записі файлу: " + e.getMessage());
        }
    }
}
