package Task3;

import java.util.Scanner;
import java.util.TreeSet;

public class MyTreeSet {
    private final TreeSet<Integer> set = new TreeSet<>();
    private final Scanner scanner = new Scanner(System.in);

    public void inputElements() {
        System.out.print("Enter number of elements: ");
        int n = scanner.nextInt();
        System.out.println("Enter integers:");
        for (int i = 0; i < n; i++) {
            set.add(scanner.nextInt());
        }
    }

    public void printSet() {
        System.out.println("TreeSet elements (sorted): " + set);
    }

    public void findFloor() {
        System.out.print("Enter number to find element ≤ it: ");
        int value = scanner.nextInt();
        Integer result = set.floor(value);
        if (result != null) {
            System.out.println("Element ≤ " + value + ": " + result);
        } else {
            System.out.println("No element found ≤ " + value);
        }
    }
}
