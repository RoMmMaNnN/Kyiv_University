package Task2.coin;

import java.util.Arrays;
import java.util.List;

public class Coin {
    public static CoinResult solve(int amount, List<Integer> coins) {
        int[] dp = new int[amount + 1];
        int[] prev = new int[amount + 1];

        Arrays.fill(dp, amount + 1);
        dp[0] = 0;

        for (int i = 1; i <= amount; i++) {
            for (int coin : coins) {
                if (i >= coin && dp[i - coin] + 1 < dp[i]) {
                    dp[i] = dp[i - coin] + 1;
                    prev[i] = coin;
                }
            }
        }

        if (dp[amount] > amount) return new CoinResult(-1, "неможливо");

        StringBuilder sb = new StringBuilder();
        while (amount > 0) {
            sb.append(prev[amount]).append(" ");
            amount -= prev[amount];
        }

        return new CoinResult(dp[dp.length - 1], sb.toString().trim());
    }
}
