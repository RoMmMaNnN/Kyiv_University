package Task1;

public enum WatchType {
    FLOOR("Digital"),
    TABLE("noDigital"),
    WALL("Modern"),
    WRIST("Classic or Digital");

    private final String dialTypes;

    WatchType(String dialTypes) {
        this.dialTypes = dialTypes;
    }

    public String getDialTypes() {
        return dialTypes;
    }
}
