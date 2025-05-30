package Task1;

import java.util.Scanner;

public class Lr22Kriu {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.println("Enter FLOOR, TABLE, WALL, WRIST: ");
        try {
            String input = scanner.next().toUpperCase();
            WatchType watchType = WatchType.valueOf(input);
            System.out.println("For " + input + " better will be " + watchType.getDialTypes());
        } catch (IllegalArgumentException e) {
            System.out.println("Invalid input!");
        }
    }
}
