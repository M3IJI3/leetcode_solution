class Solution {
    public int maxProfit(int[] prices) {
        // int profit = 0;
        // int maxProfit = 0;

        // for(int i = 0 ; i < prices.length - 1 ; i++)
        // {
        // for(int j = i + 1 ; j < prices.length ; j++)
        // {
        // profit = prices[j] - prices[i];

        // if(profit > 0 && maxProfit < profit)
        // {
        // maxProfit = profit;
        // }
        // }
        // }
        // return maxProfit;
        // ---------------------------------------------------
        int buyPrice = prices[0];
        int profit = 0;

        for (int i = 1; i < prices.length; i++) {
            if (prices[i] < buyPrice) {
                buyPrice = prices[i];
            }
            profit = Math.max(profit, prices[i] - buyPrice);
        }
        return profit;
    }
}