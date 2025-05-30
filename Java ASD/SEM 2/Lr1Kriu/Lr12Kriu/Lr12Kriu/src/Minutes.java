public class Minutes {
    private int minute;

    public Minutes(int minute) {
        if (minute < 0 || minute >= 60) {
            throw new IllegalArgumentException("Invalid minute value");
        }
        this.minute = minute;
    }

    public int getMinute() {
        return minute;
    }

    @Override
    public boolean equals(Object obj) {
        if (this == obj) return true;
        if (obj == null || getClass() != obj.getClass()) return false;
        Minutes minutes = (Minutes) obj;
        return minute == minutes.minute;
    }

    @Override
    public int hashCode() {
        return Integer.hashCode(minute);
    }

    @Override
    public String toString() {
        return String.format("%02d", getMinute());
    }
}
