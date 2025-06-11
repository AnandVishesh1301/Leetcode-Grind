// 121. Best Time to Buy and Sell Stock
// ------------------------------------
// Problem:
// Given an array `prices` where prices[i] is the price of a given stock on the ith day,
// return the **maximum profit** that can be achieved by choosing one day to buy and another future day to sell.
// If no profit can be made, return 0.
//
// --------------------------------------------------------------
// ✅ Approach: Two Pointer Sliding Window
// --------------------------------------------------------------
// - Use two pointers:
//   ➤ `l` represents the **buy day**
//   ➤ `r` represents the **sell day**
// - For each day pointed to by `r`, calculate the profit = prices[r] - prices[l]
//   - If the profit is positive → update `maxProfit`
//   - If the profit is negative or zero → move the `l` pointer forward (since we found a smaller price to buy at)
// - Always ensure `r > l` so we only sell in the future.
//
// Time Complexity:
//   O(n) – Single pass through prices using two pointers
// Space Complexity:
//   O(1) – Only a few integer variables are used
//
// Time Stats (from LeetCode submission):
//   Runtime : 4 ms  
//   Beats   : 18.63 % of C++ users
// Space Stats (from LeetCode submission):
//   Memory Usage : 94.72 MB
//   Beats        : 26.40 % of C++ users
// --------------------------------------------------------------


class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int l = 0;                 // Left pointer → buy day
        int r = l + 1;             // Right pointer → sell day
        int maxProfit = 0;

        while (r < prices.size()) {
            int currentProfit = prices[r] - prices[l]; // Check today's sell profit

            if (currentProfit > 0) {
                maxProfit = max(maxProfit, currentProfit); // Update maxProfit if current profit is better
                r++; // Try to find an even better sell day
            } else {
                l++; // Buy at a lower price if found
                if (l == r) r++; // Ensure r is always ahead
            }
        }

        return maxProfit;
    }
};
