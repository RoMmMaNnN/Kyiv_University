public class Task3 {
    public static double task3(double x) {
        double y = 0;
        for (int i = 0; i < 6; i++) {
            double term = Math.pow(-1, i + 1) * Math.pow(x, 2 * i) / task31(2 * i - 1);
            y += term;
        }
        return y;
    }
    public static long task31(int n) {
        if (n <= 1) {
            return 1;
        } else return n * task31(n - 1);
    }
}
