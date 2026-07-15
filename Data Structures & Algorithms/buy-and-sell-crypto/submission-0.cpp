// keep a global max profit
// check in windows, and update max profit
//update windows
//return max profit 

class Solution {
public:
    int maxProfit(vector<int>& prices) {

        int left=0;
        int right =1;
        int profit=0;

        while(right < prices.size())
        {
            if(prices[left] <= prices[right]) 
            {
                profit = max(profit, prices[right] - prices[left]);
                right ++;
            }

            else left ++;
        }

        return profit;
        
    }
};
