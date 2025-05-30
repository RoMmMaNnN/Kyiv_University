package Task1;

import java.util.Comparator;
import java.util.Map;
import java.util.Scanner;
import java.util.TreeMap;

public class Thee {
    private final Scanner scan = new Scanner(System.in);
    private final TreeMap<Integer, Item> map = new TreeMap<>(Comparator.reverseOrder());

    public void println(String str) {
        System.out.println(str);
    }

    public void print(String str) {
        System.out.print(str);
    }

    private int readInt(String message) {
        while (true) {
            print(message);
            if (scan.hasNextInt()) {
                return scan.nextInt();
            } else {
                println("Invalid input! Please enter an integer.");
                scan.next();
            }
        }
    }

    private String readString(String message) {
        while (true) {
            print(message);
            String input = scan.next();
            if (!input.trim().isEmpty()) {
                return input;
            } else {
                println("Invalid input! String cannot be empty.");
            }
        }
    }

    public void input() {
        int num_item;
        do {
            num_item = readInt("Enter the number of elements you wish to enter: ");
            if (num_item <= 0) println("Number must be greater than 0.");
        } while (num_item <= 0);

        println("Enter the elements (Integer key, String value):");
        for (int i = 0; i < num_item; i++) {
            int key = readInt("Item " + (i + 1) + " -> Key: ");
            String name = readString("Item " + (i + 1) + " -> Value: ");
            map.put(key, new Item(key, name));
        }

        println(num_item + " elements were added to the map.");
    }

    public void output() {
        println("\nMap entries in reverse order:");
        for (Map.Entry<Integer, Item> entry : map.entrySet()) {
            println("Key: " + entry.getKey() + " | Value: " + entry.getValue());
        }
    }
}
