class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buyPrice = prices[0];
        int profit = 0;

        for(int& price : prices){
            if(price < buyPrice){
                buyPrice = price; // 更新最低价格
            }
            profit = max(profit, price - buyPrice);
        }

        return profit;
    }
};