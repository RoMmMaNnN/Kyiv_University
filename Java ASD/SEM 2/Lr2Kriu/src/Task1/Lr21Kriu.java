package Task1;

import java.util.Scanner;

public class Lr21Kriu {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.println("Enter a season (SPRING, SUMMER, FALL, WINTER): ");
        try {
            Season season = Season.valueOf(scanner.next().toUpperCase());
            System.out.println("Average temperature: " + season.getAverageTemp() + "°C");
        } catch (IllegalArgumentException e) {
            System.out.println("Invalid season entered!");
        }
    }
}
