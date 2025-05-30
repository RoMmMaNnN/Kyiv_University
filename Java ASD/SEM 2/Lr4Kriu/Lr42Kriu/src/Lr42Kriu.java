import java.io.*;
import java.util.*;

public class Lr42Kriu {
    private static final Scanner sc = new Scanner(System.in);
    private static final MyLinkedHashMap[] hash = {new MyLinkedHashMap(), new MyLinkedHashMap(), new MyLinkedHashMap()};

    public static void main(String[] args) {
        String[] inName = { "src/input/input1.txt", "src/input/input2.txt", "src/input/input3.txt" };
        String[] outName = { "src/output/output1.txt", "src/output/output2.txt", "src/output/output3.txt" };

        for (int i = 0; i < 3; i++) {
            File file = new File(inName[i]);
            String filePath = file.getAbsolutePath();
            hash[i] = FileHandler.readFile(filePath);
        }

        while (true) {
            printMenu();
            int choice = getChoice();
            if (choice == 0) break;

            switch (choice) {
                case 1:
                    System.out.println("Ви вибрали пукнт меню \"Додати нового автора у таблицю\"");
                    addAuthor();
                    break;
                case 2:
                    System.out.println("Ви вибрали пукнт меню \"Видалити автора з таблиці\"");
                    removeAuthor();
                    break;
                case 3:
                    System.out.println("Ви вибрали пукнт меню \"Вивести усіх авторів\"");
                    for (int i = 0; i < 3; i++) {
                        System.out.println("\nТаблиця " + (i + 1) + ":");
                        hash[i].printTable();
                    }
                    break;
                case 4:
                    System.out.println("Ви вибрали пукнт меню \"Вивести окремо автора інформацію про автора\"");
                    for (int i = 0; i < 3; i++) {
                        System.out.println("\nТаблиця " + (i + 1) + ":");
                        hash[i].findByName();
                    }
                default:
                    System.out.println("Невірний вибір.");
            }
        }

        for (int i = 0; i < 3; i++) {
            File file = new File(outName[i]);
            String filePath = file.getAbsolutePath();
            if (i < 2) FileHandler.writeToFile(filePath, hash[i]);
            else FileHandler.appendToFile(filePath, hash[i]);
            System.out.println("Записано у файл: " + filePath);
        }
    }

    private static void printMenu() {
        System.out.println("\n==== МЕНЮ ====");
        System.out.println("1. Додати нового автора у таблицю");
        System.out.println("2. Видалити автора з таблиці");
        System.out.println("3. Вивести усіх авторів");
        System.out.println("4. Вивести окремо автора інформацію про автора");
        System.out.println("0. Вихід");
    }

    private static int getChoice() {
        int attempts = 3;
        while (attempts > 0) {
            System.out.print("Введіть номер пункту меню (0–4): ");
            if (sc.hasNextInt()) {
                int choice = sc.nextInt();
                sc.nextLine();
                if (choice >= 0 && choice <= 4) {
                    return choice;
                } else {
                    System.out.println("Невірне число. Допустимі значення: 0–4.");
                }
            } else {
                System.out.println("Це не число. Спробуйте ще.");
                sc.nextLine();
            }
            attempts--;
            if (attempts > 0) {
                System.out.println("Залишилось спроб: " + attempts);
            } else {
                System.out.println("Вичерпано кількість спроб. Повернення до головного меню.");
            }
        }
        return 0;
    }

    private static void addAuthor() {
        System.out.print("Введіть ім'я автора: ");
        String name = sc.nextLine();

        System.out.print("Кількість книг: ");
        int totalBooks = Integer.parseInt(sc.nextLine());

        System.out.print("Рік народження: ");
        int birthYear = getYear();

        System.out.print("Кількість книг за останні 10 років: ");
        int recentBooks = Integer.parseInt(sc.nextLine());

        Author newAuthor = new Author(totalBooks, birthYear, recentBooks);

        int target = chooseHashSet();
        if (target == 0) {
            for (int i = 0; i < 3; i++) {
                hash[i].add(name, newAuthor);
            }
            System.out.println("Автора додано у всі таблиці.");
        } else {
            hash[target - 1].add(name, newAuthor);
            System.out.println("Автора додано у таблицю " + target);
        }
    }

    private static void removeAuthor() {
        System.out.print("Введіть ім’я автора для видалення: ");
        String name = sc.nextLine();

        int target = chooseHashSet();
        boolean found = false;

        if (target == 0) {
            for (int i = 0; i < 3; i++) {
                if (hash[i].remove(name)) {
                    System.out.println("Автора видалено з таблиці " + (i + 1));
                    found = true;
                }
            }
        } else {
            if (hash[target - 1].remove(name)) {
                System.out.println("Автора видалено.");
                found = true;
            }
        }
        if (!found) System.out.println("Автора не знайдено в жодній таблиці.");
    }


    private static int getYear() {
        int year = -1;
        while (year < 1400 || year > Calendar.getInstance().get(Calendar.YEAR)) {
            System.out.print("Введіть рік (не раніше 1900 i не пізніше поточного): ");
            while (!sc.hasNextInt()) {
                System.out.print("Це не рік. Спробуйте ще ввести числами: ");
                sc.next();
            }
            year = sc.nextInt();
            sc.nextLine();
        }
        return year;
    }

    private static int chooseHashSet() {
        int choice;
        while (true) {
            System.out.print("Оберіть таблицю (1–3), 0 — всі: ");
            if (sc.hasNextInt()) {
                choice = sc.nextInt();
                sc.nextLine();
                if (choice >= 0 && choice <= 3) {
                    return choice;
                }
            } else {
                System.out.println("Це не число. Спробуйте ще.");
                sc.nextLine();
            }
        }
    }
}
