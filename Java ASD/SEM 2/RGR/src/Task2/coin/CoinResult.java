package Task2.coin;

import java.util.Objects;

public class CoinResult {
    private int minCount;
    private String usedCoins;

    public CoinResult(int minCount, String usedCoins) {
        this.minCount = minCount;
        this.usedCoins = usedCoins;
    }

    public int getMinCount() { return minCount; }
    public void setMinCount(int minCount) { this.minCount = minCount; }
    public String getUsedCoins() { return usedCoins; }
    public void setUsedCoins(String usedCoins) { this.usedCoins = usedCoins; }

    @Override
    public String toString() { return "Мінімальна кількість монет: " + minCount + "\n" + "Використані монети: " + usedCoins; }

    @Override
    public boolean equals(Object obj) {
        if (this == obj) return true;
        if (obj == null || getClass() != obj.getClass()) return false;
        CoinResult that = (CoinResult) obj;
        return minCount == that.minCount && Objects.equals(usedCoins, that.usedCoins);
    }

    @Override
    public int hashCode() {
        return Objects.hash(minCount, usedCoins);
    }
}
