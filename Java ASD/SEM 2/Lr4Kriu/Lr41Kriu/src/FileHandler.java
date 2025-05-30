import java.io.*;
import java.util.*;

public class FileHandler {
    public static MyHashSet readFile(String filePath) {
        MyHashSet set = new MyHashSet();
        System.out.println("Читання файлу: " + filePath);
        try (BufferedReader br = new BufferedReader(new FileReader(filePath))) {
            String line;

            for (int i = 0; i < 3; i++) {
                br.readLine();
            }

            while ((line = br.readLine()) != null) {
                if (line.trim().isEmpty()) continue;

                String[] parts = line.split("│");

                List<String> validParts = new ArrayList<>();
                for (String part : parts) {
                    if (!part.trim().isEmpty()) {
                        validParts.add(part.trim());
                    }
                }

                if (validParts.size() < 3) continue;

                String title = validParts.get(0);
                String author = validParts.get(1);
                int year;
                try {
                    year = Integer.parseInt(validParts.get(2));
                } catch (NumberFormatException e) {
                    continue;
                }

                if (year < 1400 || year > Calendar.getInstance().get(Calendar.YEAR)) continue;

                set.add(new Book(title, author, year));
            }
        } catch (IOException e) {
            System.out.println("Помилка читання файлу: " + filePath);
        }
        System.out.println("Успішно завершено читання файлу: " + filePath);
        return set;
    }

    public static void writeToFile(String filePath, Book[] books) {
        try (BufferedWriter bw = new BufferedWriter(new FileWriter(filePath, false))) {
            writeTableHeader(bw);
            for (Book book : books) {
                writeTableRow(bw, book);
            }
            writeTableBottom(bw);
        } catch (IOException e) {
            System.out.println("Помилка запису у файл: " + filePath);
        }
    }

    public static void appendToFile(String filePath, Book[] books) {
        try (BufferedWriter bw = new BufferedWriter(new FileWriter(filePath, true))) {
            writeTableHeader(bw);
            for (Book book : books) {
                writeTableRow(bw, book);
            }
            writeTableBottom(bw);
        } catch (IOException e) {
            System.out.println("Помилка дописування у файл: " + filePath);
        }
    }

    private static void writeTableHeader(BufferedWriter bw) throws IOException {
        bw.write("┌────────────────────────────────┬──────────────────────┬────────┐\n");
        bw.write(String.format("│ %-30s │ %-20s │ %-6s │\n", "Назва книги", "Автор", "Рік"));
        bw.write("├────────────────────────────────┼──────────────────────┼────────┤\n");
    }

    private static void writeTableRow(BufferedWriter bw, Book book) throws IOException {
        bw.write(String.format("│ %-30s │ %-20s │ %-6d │\n", book.getTitle(), book.getAuthor(), book.getYear()));
    }

    private static void writeTableBottom(BufferedWriter bw) throws IOException {
        bw.write("└────────────────────────────────┴──────────────────────┴────────┘");
    }
}
