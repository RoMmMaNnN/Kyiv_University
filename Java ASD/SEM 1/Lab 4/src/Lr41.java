import java.util.Scanner;

public class Lr41 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        String str1 = "I do not want to learn English, I want to study Java!! I do not want to learn007* history, 1911 want to study765 Java!! But, 0001 maybe, I do not want to study666 at all=((";
        String str2 = "I want to eat, you want to sleep, I do not want to do too many homework of math, she is want to dream.";
        String str3 = "I want to become SoftWare Devoleper, I want to coding on Java and do not want to code in Python, I want to build projects.";

        System.out.println("\n==========================================================================================================================\n");
        System.out.printf("%-18s: %s\n", "Original String 1", str1);
        System.out.printf("%-18s: %s\n", "Original String 2", str2);
        System.out.printf("%-18s: %s\n", "Original String 3", str3);

        System.out.println("\n==========================================================================================================================\n");
        System.out.printf("\n%-18s: %s\n", "Modified String 1", task1(str1, "want to", "wanna"));
        System.out.printf("\n%-18s: %s\n", "Modified String 2", task1(str2, "want to", "wanna"));
        System.out.printf("\n%-18s: %s\n", "Modified String 3", task1(str3, "want to", "wanna"));

        System.out.println("\n==========================================================================================================================\n");
        System.out.print("\nEnter a custom string: ");
        String userInput = scanner.nextLine();
        System.out.println("\nEnter another target word: ");
        String targetWord = scanner.nextLine();
        System.out.println("\nEnter another replacement word: ");
        String replacementWord = scanner.nextLine();
        String result = task1(userInput, targetWord, replacementWord);
        System.out.printf("\n%-18s: %s\n", "Modified Custom String", result);
    }

    public static String task1(String input, String target, String replacement) {
        if (target.isEmpty()) {
            return input;
        }

        int count = 0;
        String modifiedString = "";

        int i = 0;
        while (i < input.length()) {
            int index = input.indexOf(target, i);
            if (index == -1) {
                modifiedString += input.substring(i);
                break;
            }
            modifiedString += input.substring(i, index);
            count++;
            if (count % 2 == 0) {
                modifiedString += replacement;
            } else {
                modifiedString += target;
            }
            i = index + target.length();
        }
        return  modifiedString;
    }
}
