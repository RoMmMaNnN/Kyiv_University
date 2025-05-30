package Task3;

import java.util.*;

public class Lr33Kriu {
    public static void main(String[] args) {
        MyTreeSet obj = new MyTreeSet();

        println("=== Entering elements into TreeSet ===");
        obj.inputElements();

        println("\n=== Sorted elements in TreeSet ===");
        obj.printSet();

        println("\n=== Searching for an element less than or equal to the given one ===");
        obj.findFloor();
    }

    public static void println(String str) {
        System.out.println(str);
    }
}
