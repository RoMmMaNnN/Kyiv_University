package Task2;

import java.util.*;

public class Compare {
    private final Scanner scan = new Scanner(System.in);

    public Set<String> inputUserSet() {
        Set<String> userSet = new HashSet<>();
        System.out.println("Enter elements for your set (type 'end' to finish):");
        while (true) {
            System.out.print("Element: ");
            String input = scan.next();
            if (input.equalsIgnoreCase("end")) break;
            userSet.add(input.trim());
        }
        return userSet;
    }

    public String compareSets(Set<String> userSet, Set<String> referenceSet) {
        if (userSet.equals(referenceSet)) {
            return "Sets are identical.";
        } else if (!Collections.disjoint(userSet, referenceSet)) {
            return "Sets have common elements.";
        } else {
            return "Sets have no elements in common.";
        }
    }
}
