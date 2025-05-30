public class Days {
    private final Hours hour;
    private final Minutes minute;

    public Days(Hours hour, Minutes minute) {
        this.hour = hour;
        this.minute = minute;
    }

    public String displayTime() {
        return toString();
    }

    public String calculateTimeOfDay() {
        int h = hour.getHour();
        if (h >= 6 && h < 12) {
            return "Morning";
        } else if (h >= 12 && h < 18) {
            return "Noon";
        } else if (h >= 18 && h < 24) {
            return "Evening";
        } else {
            return "Night";
        }
    }

    @Override
    public boolean equals(Object obj) {
        if (this == obj) return true;
        if (obj == null || getClass() != obj.getClass()) return false;
        Days day = (Days) obj;
        return hour.equals(day.hour) && minute.equals(day.minute);
    }

    @Override
    public int hashCode() {
        return hour.hashCode() * 31 + minute.hashCode();
    }

    @Override
    public String toString() {
        return hour + ":" + minute;
    }
}
