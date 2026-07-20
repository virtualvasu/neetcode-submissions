//use recursion to gen all combos
//at each i, we can take/not take an elem
//for each step, update the sum and call helper again
//return 1 if sum == amount
//return 0 if i out of bounds
//use memoization to optimize, in this case memo[i][sum]
//if already stored, return 
//if not calc , store and return 

class Solution {
public:

    int helper(int amount, vector<int>& coins, int i , int sum, vector<vector<int>>& memo)
    {
        if(i >= coins.size() || sum > amount) return 0;
        if(sum == amount) return 1;

        if(memo[i][sum] != -1) return memo[i][sum]; 

        int take = helper(amount, coins, i, sum + coins[i], memo);
        int  pass = helper(amount, coins, i+1, sum, memo);

        return memo[i][sum] =  take + pass;
    }
    int change(int amount, vector<int>& coins) {

        int n = coins.size();

        vector<vector<int>> memo(n, vector<int>(amount + 1, -1));

        return helper(amount, coins, 0, 0, memo);
        
    }
};
