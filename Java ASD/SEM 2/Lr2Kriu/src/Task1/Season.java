package Task1;

public enum Season {
    SPRING(18), SUMMER(32), FALL(7), WINTER(-10);

    private final int averageTemp;

    Season(int temp) {
        this.averageTemp = temp;
    }

    public int getAverageTemp() {
        return averageTemp;
    }
}
