import java.io.*;
import java.util.Scanner;

public class Lr42 {
    public static void main(String[] args) throws IOException {
        Scanner fileScanner = new Scanner(new File("src/input.txt"));
        String fileText = "";
        while (fileScanner.hasNextLine()) {
            fileText += fileScanner.nextLine() + "\n";
        }
        fileText = fileText.trim();
        fileScanner.close();

        System.out.println("\nOriginal text from file:\n" + fileText);

        Scanner inputScanner = new Scanner(System.in);
        System.out.print("\nEnter a new line to add: ");
        String userInput = inputScanner.nextLine();

        System.out.println("\n================================================================");
        System.out.println(task2(fileText, userInput));
        System.out.println("\n================================================================");
        System.out.println(task3(fileText, userInput));
    }

    public static String task2(String fileText, String newLine) {
        String combinedText = fileText + "\n" + newLine;

        String[] lines = combinedText.split("\n");

        for (int i = 0; i < lines.length - 1; i += 2) {
            String temp = lines[i];
            lines[i] = lines[i + 1];
            lines[i + 1] = temp;
        }

        String result = "Task 2 Result:\n";
        for (String line : lines) {
            result += line + "\n";
        }
        return result;
    }

    public static String task3(String fileText, String newLine) {
        String combinedText = fileText + "\n" + newLine;

        String[] lines = combinedText.split("\n");

        int count = 0;
        String error = "Is not line without number";
        String result = "Task 3 Result (Lines without numbers):\n";
        for (String line : lines)    {
            if (!line.matches(".*\\d.*")) {
                result += line + "\n";
                count++;
            }
        }
        if (count == 0) return error;
        return result;
    }
}
