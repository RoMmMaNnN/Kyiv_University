public class Task2 {
    public static double task2(double[] setNum) {
        double firstNum = setNum[0];
        double sum = 0;
        int count = 0;
        double result;

        for(int i = 0; i < setNum.length; i++) {
            if (firstNum > setNum[i]) {
                sum += setNum[i];
                count++;
            }
        }
        result = sum/count;

        return result;
    }
}
