package Task2;

import java.util.Scanner;

public class Main {
    private static final Scanner scan = new Scanner(System.in);

    public static void main(String[] args) {
        boolean isValidChoice = true;
        Airline airline = new Airline();
        CompMouse compMouse = new CompMouse();

        do {
            if (isValidChoice) {
                printMenu();
                println("Select an option:");
            }

            int choice = getChoice();

            switch (choice) {
                case 1:
                    isValidChoice = true;
                    addFlight(airline);
                    break;
                case 2:
                    isValidChoice = true;
                    removeFlight(airline);
                    break;
                case 3:
                    isValidChoice = true;
                    searchByDestination(airline);
                    break;
                case 4:
                    isValidChoice = true;
                    searchByDepartureTime(airline);
                    break;
                case 5:
                    isValidChoice = true;
                    searchByAirlineName(airline);
                    break;
                case 6:
                    isValidChoice = true;
                    airline.printFlights();
                    break;
                case 7:
                    isValidChoice = true;
                    addMouse(compMouse);
                    break;
                case 8:
                    isValidChoice = true;
                    removeMouse(compMouse);
                    break;
                case 9:
                    isValidChoice = true;
                    searchByConnectionType(compMouse);
                    break;
                case 10:
                    isValidChoice = true;
                    searchByButtonsCount(compMouse);
                    break;
                case 11:
                    isValidChoice = true;
                    searchByManufacturer(compMouse);
                    break;
                case 12:
                    isValidChoice = true;
                    compMouse.printMouses();
                    break;
                case 13:
                    println("Exiting...");
                    scan.close();
                    return;
                default:
                    println("Invalid choice. Please enter a number between 1 and 13:");
                    isValidChoice = false;
            }
        } while (continueProgram());
    }

    public static void print(String str) {
        System.out.print(str);
    }

    public static void println(String str) {
        System.out.println(str);
    }

    public static String getString() {
        String input = scan.nextLine();
        while (input.trim().isEmpty()) {
            println("Input cannot be empty. Please enter a valid string.");
            input = scan.nextLine();
        }
        return input;
    }

    public static int getChoice() {
        int choice = -1;
        boolean validInput = false;
        while (!validInput) {
            println("Please enter a number between 1 and 13:");
            String input = getString();
            try {
                choice = Integer.parseInt(input);
                if (choice >= 1 && choice <= 13) {
                    validInput = true;
                } else {
                    println("Invalid choice. Please enter a number between 1 and 13.");
                }
            } catch (NumberFormatException e) {
                println("Invalid input. Please enter a valid number.");
            }
        }
        return choice;
    }

    public static String getValidatedText() {
        String input;
        while (true) {
            input = scan.nextLine().trim();
            if (input.matches("[A-Za-zА-Яа-яІіЇїЄє' ]+") && !input.isEmpty()) {
                return input;
            } else {
                println("Invalid input. Please enter valid text (only letters allowed).");
            }
        }
    }

    public static String getValidatedTime() {
        String input;
        while (true) {
            input = scan.nextLine().trim();
            if (input.matches("([01]\\d|2[0-3]):[0-5]\\d")) {
                return input;
            } else {
                println("Invalid time format. Please enter time in HH:MM format (e.g., 14:30).");
            }
        }
    }

    public static boolean getValidatedChoice() {
        String input;
        while (true) {
            input = scan.nextLine().trim();
            if (input.equals("+")) {
                return true;
            } else if (input.equals("-")) {
                return false;
            } else {
                println("Invalid input. Enter '+' to continue or '-' to exit.");
            }
        }
    }

    public static int getValidatedInt() {
        while (true) {
            try {
                return Integer.parseInt(scan.nextLine().trim());
            } catch (NumberFormatException e) {
                println("Invalid input. Please enter a valid number.");
            }
        }
    }

    public static void printMenu() {
        println("Menu:");
        println("1. Airline - Add Flight");
        println("2. Airline - Remove Flight");
        println("3. Airline - Search Flight by Destination");
        println("4. Airline - Search Flight by Departure Time");
        println("5. Airline - Search Flight by Airline Name");
        println("6. Airline - Show All Flights");
        println("7. CompMouse - Add Mouse");
        println("8. CompMouse - Remove Mouse");
        println("9. CompMouse - Search Mouse by Connection Type");
        println("10. CompMouse - Search Mouse by Button Count");
        println("11. CompMouse - Search Mouse by Manufacturer");
        println("12. CompMouse - Show All Mice");
        println("13. Exit");
    }


    public static void addFlight(Airline airline) {
        print("Enter Destination: ");
        String destination = getValidatedText();
        print("Enter Departure Time (HH:MM): ");
        String departureTime = getValidatedTime();
        print("Enter Airline Name: ");
        String airlineName = getValidatedText();
        airline.addFlight(new Flight(destination, departureTime, airlineName));
    }

    public static boolean continueProgram() {
        println("Do you want to continue? (+/-)");
        return getValidatedChoice();
    }

    public static void addMouse(CompMouse compMouse) {
        print("Enter Connection Type (Wired/Wireless): ");
        String connectionType = getValidatedText();
        print("Enter Number of Buttons: ");
        int buttonsCount = getValidatedInt();
        print("Enter Manufacturer: ");
        String manufacturer = getValidatedText();
        compMouse.addMouse(new Mouse(connectionType, buttonsCount, manufacturer));
    }


    public static void searchByDestination(Airline airline) {
        print("Enter Destination to Search: ");
        String searchDestination = getString();
        airline.searchByDestination(searchDestination);
    }

    public static void searchByConnectionType(CompMouse compMouse) {
        print("Enter Connection Type to Search: ");
        String searchConnectionType = getString();
        compMouse.searchByConnectionType(searchConnectionType);
    }

    public static void removeFlight(Airline airline) {
        print("Enter Destination to Remove: ");
        String destination = getString();
        airline.removeFlight(destination);
    }

    public static void removeMouse(CompMouse compMouse) {
        print("Enter Manufacturer to Remove: ");
        String manufacturer = getString();
        compMouse.removeMouse(manufacturer);
    }

    public static void searchByDepartureTime(Airline airline) {
        print("Enter Departure Time to Search: ");
        String departureTime = getValidatedTime();
        airline.searchByDepartureTime(departureTime);
    }

    public static void searchByAirlineName(Airline airline) {
        print("Enter Airline Name to Search: ");
        String airlineName = getValidatedText();
        airline.searchByAirlineName(airlineName);
    }

    public static void searchByButtonsCount(CompMouse compMouse) {
        print("Enter Number of Buttons to Search: ");
        int buttonsCount = getValidatedInt();
        compMouse.searchByButtonsCount(buttonsCount);
    }

    public static void searchByManufacturer(CompMouse compMouse) {
        print("Enter Manufacturer to Search: ");
        String manufacturer = getValidatedText();
        compMouse.searchByManufacturer(manufacturer);
    }

}
