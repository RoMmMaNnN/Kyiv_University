import java.time.LocalTime;

public class Lr12Kriu {
    public static void main(String[] args) {
        LocalTime time = LocalTime.now();
        Days day = new Days(new Hours(time.getHour()), new Minutes(time.getMinute()));

        Days day1 = new Days(new Hours(22), new Minutes(57));
        Days day2 = new Days(new Hours(11), new Minutes(48));
        Days day3 = new Days(new Hours(22), new Minutes(57));

        System.out.println("\n(Used function displayTime)");
        System.out.println("Local time: " + day.displayTime());

        System.out.println("\n(Used function calculateTimeOfDay)");
        System.out.println("Now is " + day.calculateTimeOfDay());

        System.out.println("\nDisplay other object");
        System.out.println("Day1: " + day1);
        System.out.println("Day2: " + day2);
        System.out.println("Day3: " + day3);

        System.out.println("\n(Used function equals)");
        System.out.println("day1 == day2: " + day1.equals(day2));
        System.out.println("day1 == day3: " + day1.equals(day3));

        System.out.println("\n(Used function hashCode)");
        System.out.println("day1.hashCode(): " + day1.hashCode());
        System.out.println("day2.hashCode(): " + day2.hashCode());
        System.out.println("day3.hashCode(): " + day3.hashCode());
    }
}