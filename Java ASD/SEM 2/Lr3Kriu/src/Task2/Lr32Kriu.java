package Task2;

import java.util.*;

public class Lr32Kriu {
    public static void main(String[] args) {
        Compare comparator = new Compare();

        Set<String> defaultSet1 = new HashSet<>(Arrays.asList("bob", "bom", "bib"));
        Set<String> defaultSet2 = new HashSet<>(Arrays.asList("dog", "cat", "mouse"));

        println("Default Set 1: " + defaultSet1);
        println("Default Set 2: " + defaultSet2);

        Set<String> userSet = comparator.inputUserSet();

        println("\nUser Set: " + userSet);

        String result1 = comparator.compareSets(userSet, defaultSet1);
        println("Comparison userSet with Default Set 1: " + result1);

        String result2 = comparator.compareSets(userSet, defaultSet2);
        println("Comparison userSet with Default Set 2: " + result2);
    }

    public static void println(String str) {
        System.out.println(str);
    }
}
