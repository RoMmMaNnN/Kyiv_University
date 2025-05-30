import java.io.*;
import java.util.*;

public class Lr41Kriu {
    private static final Scanner sc = new Scanner(System.in);
    private static final MyHashSet[] hash = {new MyHashSet(), new MyHashSet(), new MyHashSet()};

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
                    addBook();
                    break;
                case 2:
                    removeBook();
                    break;
                case 3:
                    for (int i = 0; i < 3; i++) {
                        System.out.println("\nТаблиця " + (i + 1) + ":");
                        hash[i].printTable();
                    }
                    break;
                default:
                    System.out.println("Невірний вибір.");
            }
        }

        for (int i = 0; i < 3; i++) {
            File file = new File(outName[i]);
            String filePath = file.getAbsolutePath();
            if (i < 2) {
                FileHandler.writeToFile(filePath, hash[i].getHashSet());
            } else FileHandler.appendToFile(filePath, hash[i].getHashSet());
            System.out.println("Записано у файл: " + filePath);
        }
    }

    private static void printMenu() {
        System.out.println("\n==== МЕНЮ ====");
        System.out.println("1. Додати книгу");
        System.out.println("2. Видалити книгу");
        System.out.println("3. Вивести всі книги");
        System.out.println("0. Вихід");
    }

    private static int getChoice() {
        int attempts = 3;
        while (attempts > 0) {
            System.out.print("Введіть номер пункту меню (0–3): ");
            if (sc.hasNextInt()) {
                int choice = sc.nextInt();
                sc.nextLine();
                if (choice >= 0 && choice <= 3) {
                    return choice;
                } else {
                    System.out.println("Невірне число. Допустимі значення: 0–3.");
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

    private static void addBook() {
        System.out.print("Введіть назву книги: ");
        String title = sc.nextLine();
        System.out.print("Введіть автора: ");
        String author = sc.nextLine();
        int year = getYear();
        Book book = new Book(title, author, year);

        int target = chooseHashSet();
        if (target == 0) {
            for (int i = 0; i < 3; i++) {
                if (hash[i].contains(book)) {
                    System.out.println("Книга вже є в таблиці " + (i + 1));
                } else {
                    hash[i].add(book);
                    System.out.println("Книгу додано в таблицю " + (i + 1));
                }
            }
        } else {
            if (hash[target - 1].contains(book)) {
                System.out.println("Книга вже існує у вибраній таблиці.");
            } else {
                hash[target - 1].add(book);
                System.out.println("Книгу додано.");
            }
        }
    }


    private static void removeBook() {
        System.out.print("Назва книги для видалення: ");
        String title = sc.nextLine();
        System.out.print("Автор: ");
        String author = sc.nextLine();
        int year = getYear();
        Book book = new Book(title, author, year);

        int target = chooseHashSet();
        boolean found = false;
        if (target == 0) {
            for (int i = 0; i < 3; i++) {
                if (hash[i].contains(book)) {
                    hash[i].remove(book);
                    System.out.println("Книгу видалено з таблиці " + (i + 1));
                    found = true;
                }
            }
        } else {
            if (hash[target - 1].contains(book)) {
                hash[target - 1].remove(book);
                System.out.println("Книгу видалено.");
                found = true;
            }
        }

        if (!found) System.out.println("Книгу не знайдено в жодній таблиці.");
    }


    private static int getYear() {
        int year = -1;
        while (year < 1400 || year > Calendar.getInstance().get(Calendar.YEAR)) {
            System.out.print("Введіть рік (не раніше 1400  не пізніше поточного): ");
            while (!sc.hasNextInt()) {
                System.out.print("Це не рік! Спробуйте ще: ");
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

