/* You are given an integer array prices where prices[i]
 * is the prices of a given stock on the ith day.
 *
 * On each day, you may decide to buy and/or sell the
 * stock. You can only hold at most one share of the stock
 * at any time. However, you can then immediately sell it
 * on the same day.
 *
 * Find and return the maximum profit you can achieve. */
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxProfit = 0, prevMax = 0;
        int dayProfit;
        int min = prices[0];
        bool holding = true;
        for (int i = 0; i < prices.size(); ++i) {
            if (prices[i] < min) {
                min = prices[i];
            }
            dayProfit = prices[i] - min;
            if (dayProfit > prevMax) {
                maxProfit += dayProfit;
            }
        }
        return maxProfit;
    }
};

