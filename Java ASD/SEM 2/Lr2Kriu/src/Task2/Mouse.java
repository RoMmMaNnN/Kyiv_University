package Task2;

class Mouse {
    private final String connectionType;
    private final int buttonsCount;
    private final String manufacturer;

    public Mouse(String connectionType, int buttonsCount, String manufacturer) {
        this.connectionType = connectionType;
        this.buttonsCount = buttonsCount;
        this.manufacturer = manufacturer;
    }

    public String getConnectionType() {
        return connectionType;
    }

    public int getButtonsCount() {
        return buttonsCount;
    }

    public String getManufacturer() {
        return manufacturer;
    }

    @Override
    public String toString() {
        return "Mouse [Connection Type: " + connectionType + ", Buttons: " + buttonsCount + ", Manufacturer: " + manufacturer + "]";
    }
}

