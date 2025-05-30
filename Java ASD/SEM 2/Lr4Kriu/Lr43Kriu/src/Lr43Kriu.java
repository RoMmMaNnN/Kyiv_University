import classes_image.ImageHandler;
import java.io.File;
import java.util.Scanner;

public class Lr43Kriu {
    private static final Scanner sc = new Scanner(System.in);
    private static final ImageHandler handler = new ImageHandler();

    public static void main(String[] args) {
        System.out.println("Завантаження трьох тестових наборів даних...");
        handler.addTestData();
        handler.addTestData();
        handler.addTestData();
        System.out.println("Тестові дані додано.");

        while (true) {
            printMenu();
            int choice = getChoice();
            if (choice == 0) break;

            switch (choice) {
                case 1:
                    System.out.println("Завантаження зображень з папки...");
                    handler.loadImagesFromFolder("src/image_set1");
                    handler.loadImagesFromFolder("src/image_set2");
                    handler.loadImagesFromFolder("src/image_set3");
                    break;
                case 2:
                    System.out.println("Список зображень:");
                    System.out.println(handler.getLibrary().getFormattedData());
                    break;
                case 3:
                    searchImage();
                    break;
                case 4:
                    System.out.println("Додавання тестових зображень...");
                    handler.addTestData();
                    break;
                case 5:
                    saveResults();
                    break;
                default:
                    System.out.println("Невірний вибір.");
            }
        }

        System.out.println("Завершення роботи програми...");
    }

    private static void printMenu() {
        System.out.println("\n=== МЕНЮ ===");
        System.out.println("1. Завантажити зображення з папок");
        System.out.println("2. Показати список зображень");
        System.out.println("3. Пошук зображення за ім'ям");
        System.out.println("4. Додати тестові зображення");
        System.out.println("5. Записати список у файл");
        System.out.println("0. Вихід");
    }

    private static int getChoice() {
        int attempts = 3;
        while (attempts-- > 0) {
            System.out.print("Оберіть опцію (0–5): ");
            if (sc.hasNextInt()) {
                int choice = sc.nextInt();
                sc.nextLine();
                if (choice >= 0 && choice <= 5) return choice;
            } else {
                sc.nextLine();
            }
            System.out.println("Неправильне введення. Залишилось спроб: " + attempts);
        }
        return 0;
    }

    private static void searchImage() {
        System.out.print("Введіть ім'я зображення для пошуку: ");
        String name = sc.nextLine();
        var found = handler.getLibrary().searchImageByName(name);
        if (found != null) {
            System.out.println("Знайдено зображення: " + found);
        } else {
            System.out.println("Зображення не знайдено.");
        }
    }

    private static void saveResults() {
        String fileName = "src/output/output.txt";
        File file = new File(fileName);
        handler.saveToFile(file.getAbsolutePath());
        System.out.println("Список зображень записано у файл: " + file.getAbsolutePath());
    }
}
