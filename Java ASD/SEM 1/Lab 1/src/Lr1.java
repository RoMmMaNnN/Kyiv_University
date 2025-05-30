import java.time.LocalDateTime;
import java.time.format.DateTimeFormatter;
import java.util.Scanner;

public class Lr1 {
    public static double calcF(double m, double t, double c) {
        return Math.cbrt(m * Math.tan(t) + Math.abs(c * Math.sin(t)));
    }

    public static double calcZ(double m, double b, double t, double c) {
        return m * Math.cos(b * t * Math.sin(t)) + c;
    }

    public static void outputDate() {
        LocalDateTime now = LocalDateTime.now();
        DateTimeFormatter formatter = DateTimeFormatter.ofPattern("yyyy-MM-dd HH:mm:ss.SSS");
        System.out.println("Date: " + now.format(formatter));
    }

    public static void main(String[] args) {

        double F = calcF(2, 1.2, -1);
        double Z = calcZ(2, 0.7, 1.2, -1);
        double m = 2, t = 1.2, c = -1, b =  0.7;
        System.out.printf("When m = %.4f, t = %.4f, c = %.4f, b = %.4f \n", m, t, c, b);
        System.out.printf("F = %.4f and Z = %.4f \n", F, Z);

        Scanner scan = new Scanner(System.in);
        System.out.println("Enter new values m, t, c, b in format \"4 1,475 0,3 -7\" (put a ONLY space beetwen a numer)");
        m = scan.nextDouble();
        t = scan.nextDouble();
        c = scan.nextDouble();
        b = scan.nextDouble();
        double F1 = calcF(m, t, c);
        double Z1 = calcZ(m, b, t, c);

        System.out.printf("When m = %.4f, t = %.4f, c = %.4f, b = %.4f \n", m, t, c, b);
        System.out.printf("F = %.4f and Z = %.4f \n", F1, Z1);

        outputDate();
    }
}
