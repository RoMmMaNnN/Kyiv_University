package Task2;

import java.util.*;

class CompMouse {
    private final List<Mouse> mice = new ArrayList<>();

    public void addMouse(Mouse mouse) {
        mice.add(mouse);
    }

    public void removeMouse(String manufacturer) {
        List<Mouse> toRemove = new ArrayList<>();
        for (Mouse mouse : mice) {
            if (mouse.getManufacturer().equalsIgnoreCase(manufacturer)) {
                toRemove.add(mouse);
            }
        }
        if (!toRemove.isEmpty()) {
            mice.removeAll(toRemove);
            System.out.println("Mouse(s) removed successfully.");
        } else {
            System.out.println("No mice found from that manufacturer.");
        }
    }


    public void searchByConnectionType(String connectionType) {
        for (Mouse mouse : mice) {
            if (mouse.getConnectionType().equalsIgnoreCase(connectionType)) {
                System.out.println(mouse);
            }
        }
    }

    public void searchByButtonsCount(int buttonsCount) {
        boolean found = false;
        for (Mouse mouse : mice) {
            if (mouse.getButtonsCount() == buttonsCount) {
                System.out.println(mouse);
                found = true;
            }
        }
        if (!found) {
            System.out.println("No mice found with that button count.");
        }
    }

    public void searchByManufacturer(String manufacturer) {
        boolean found = false;
        for (Mouse mouse : mice) {
            if (mouse.getManufacturer().equalsIgnoreCase(manufacturer)) {
                System.out.println(mouse);
                found = true;
            }
        }
        if (!found) {
            System.out.println("No mice found from that manufacturer.");
        }
    }


    public void printMouses() {
        for (Mouse mouse : mice) {
            System.out.println(mouse);
        }
    }
}
