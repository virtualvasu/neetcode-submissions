//use recursion to get all possible buy/sell combos
// at every elem, two choice, hold OR sell/buy
// calc profit if hold
// if buying possible, buy, return max of hold/buy, 
// if buying not possible, sell, calc profit, return max of hold/sell, call for i+2 for cooldown
//use memoiztion to optimize
class Solution {
public:
    int helper(vector<int>& prices, int i, int canBuy,
               vector<vector<int>>& dp)
    {
        if(i >= prices.size())
            return 0;

        if(dp[i][canBuy] != -1)
            return dp[i][canBuy];

        int hold = helper(prices, i + 1, canBuy, dp);

        if(canBuy)
        {
            int buy = helper(prices, i + 1, 0, dp) - prices[i];
            return dp[i][canBuy] = max(hold, buy);
        }
        else
        {
            int sell = helper(prices, i + 2, 1, dp) + prices[i];
            return dp[i][canBuy] = max(hold, sell);
        }
    }

    int maxProfit(vector<int>& prices) {

        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2, -1));

        return helper(prices, 0, 1, dp);
    }
};