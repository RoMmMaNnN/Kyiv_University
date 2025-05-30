package Task1;

public class Item {
    private final int key;
    private final String name;
    public Item(int key, String name) {
        this.key = key;
        this.name = name;
    }
    public int getKey() { return key; }
    public String getName() { return name; }

    @Override
    public String toString() {
        return "Key: " + key + " | Value: " + name;
    }
}
