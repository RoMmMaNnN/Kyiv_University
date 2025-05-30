public class Hours {
    private int hour;

    public Hours(int hour) {
        if (hour < 0 || hour >= 24) {
            throw new IllegalArgumentException("Invalid hour value");
        }
        this.hour = hour;
    }

    public void setHour(int hour) {
        if (hour < 0 || hour >= 24) {
            System.out.println("Invalid hour value");
        } else this.hour = hour;
    }

    public int getHour() {
        return hour;
    }

    @Override
    public boolean equals(Object obj) {
        if (this == obj) return true;
        if (obj == null || getClass() != obj.getClass()) return false;
        Hours hours = (Hours) obj;
        return hour == hours.hour;
    }

    @Override
    public int hashCode() {
        return Integer.hashCode(hour);
    }

    @Override
    public String toString() {
        return String.format("%02d", hour);
    }
}
