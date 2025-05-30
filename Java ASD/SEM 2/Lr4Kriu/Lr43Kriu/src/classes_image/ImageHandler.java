package classes_image;

import javax.imageio.ImageIO;
import java.awt.Image;
import java.awt.image.BufferedImage;
import java.io.*;

public class ImageHandler {
    private final ImageLibrary library;

    public ImageHandler() {
        library = new ImageLibrary();
    }

    public void loadImagesFromFolder(String folderPath) {
        File folder = new File(folderPath);
        if (!folder.exists() || !folder.isDirectory()) {
            System.out.println("Папка не знайдена: " + folderPath);
            return;
        }

        File[] files = folder.listFiles((dir, name) ->
                name.toLowerCase().endsWith(".jpg") ||
                        name.toLowerCase().endsWith(".png") ||
                        name.toLowerCase().endsWith(".jpeg"));

        if (files == null) return;

        for (File file : files) {
            try {
                Image image = ImageIO.read(file);
                if (image != null) {
                    String imageName = file.getName();
                    boolean added = library.addImage(imageName, image);
                    if (added) {
                        System.out.println("Завантажено: " + imageName);
                    } else {
                        System.out.println("Пропущено (вже існує): " + imageName);
                    }
                }
            } catch (IOException e) {
                System.out.println("Помилка читання: " + file.getName());
            }
        }
    }

    public void saveToFile(String filename) {
        try (PrintWriter writer = new PrintWriter(new FileWriter(filename))) {
            writer.println(library.getFormattedData());
            System.out.println("Дані записано у файл: " + filename);
        } catch (IOException e) {
            System.out.println("Помилка запису у файл.");
        }
    }

    public void addTestData() {
        for (int i = 1; i <= 10; i++) {
            String name = "test_img" + i + ".jpg";
            Image image = new BufferedImage(10, 10, BufferedImage.TYPE_INT_RGB);
            library.addImage(name, image);
        }
    }

    public ImageLibrary getLibrary() {
        return library;
    }
}
