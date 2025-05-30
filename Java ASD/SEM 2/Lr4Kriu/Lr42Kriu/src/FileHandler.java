import java.io.*;
import java.util.*;

public class FileHandler {
    public static MyLinkedHashMap readFile(String filePath) {
        MyLinkedHashMap map = new MyLinkedHashMap();
        
        File file = new File(filePath);
        if (!file.exists()) {
            System.out.println("Файл не існує за шляхом: " + filePath);
            return map;
        }

        System.out.println("Читання файлу: " + filePath);

        try (BufferedReader br = new BufferedReader(new FileReader(filePath))) {
            String line;

            for (int i = 0; i < 3; i++) br.readLine();

            while ((line = br.readLine()) != null) {
                if (line.trim().isEmpty()) continue;

                String[] parts = line.split("│");
                List<String> validParts = new ArrayList<>();
                for (String part : parts) {
                    if (!part.trim().isEmpty()) {
                        validParts.add(part.trim());
                    }
                }

                if (validParts.size() < 4) continue;

                String fullName = validParts.get(0);
                int totalBooks, birthYear, booksLast10Years;

                try {
                    totalBooks = Integer.parseInt(validParts.get(1));
                    birthYear = Integer.parseInt(validParts.get(2));
                    booksLast10Years = Integer.parseInt(validParts.get(3));
                } catch (NumberFormatException e) {
                    continue;
                }

                Author author = new Author(totalBooks, birthYear, booksLast10Years);
                map.add(fullName, author);
            }
        } catch (IOException e) {
            System.out.println("Помилка читання файлу: " + filePath);
        }

        System.out.println("Успішно завершено читання файлу: " + filePath);
        return map;
    }

    public static void writeToFile(String filePath, MyLinkedHashMap map) {
        try (BufferedWriter bw = new BufferedWriter(new FileWriter(filePath))) {
            writeTableHeader(bw);
            Node current = map.getHead();
            while (current != null) {
                writeTableRow(bw, current.key, current.value);
                current = current.nextLink;
            }
            writeTableBottom(bw);
        } catch (IOException e) {
            System.out.println("Помилка запису у файл: " + filePath);
        }
    }

    public static void appendToFile(String filePath, MyLinkedHashMap newEntries) {
        try (BufferedWriter bw = new BufferedWriter(new FileWriter(filePath, true))) {
            Node current = newEntries.getHead();
            writeTableHeader(bw);
            while (current != null) {
                writeTableRow(bw, current.key, current.value);
                current = current.nextLink;
            }
            writeTableBottom(bw);
        } catch (IOException e) {
            System.out.println("Помилка дописування у файл: " + filePath);
        }
    }


    private static void writeTableHeader(BufferedWriter bw) throws IOException {
        bw.write("┌────────────────────────────┬──────────────┬──────────────┬────────────────────┐\n");
        bw.write(String.format("│ %-26s │ %-12s │ %-12s │ %-18s │\n",
                "Автор", "Всього книг", "Рік народж.", "Останні 10 років"));
        bw.write("├────────────────────────────┼──────────────┼──────────────┼────────────────────┤\n");
    }

    private static void writeTableRow(BufferedWriter bw, String name, Author author) throws IOException {
        bw.write(String.format("│ %-26s │ %-12d │ %-12d │ %-18d │\n",
                name, author.getTotalBooks(), author.getBirthYear(), author.getRecentBooks()));
    }

    private static void writeTableBottom(BufferedWriter bw) throws IOException {
        bw.write("└────────────────────────────┴──────────────┴──────────────┴────────────────────┘\n");
    }
}
