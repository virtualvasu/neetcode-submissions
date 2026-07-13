//memoization approach 

class Solution {
public:

    int memo(vector<vector<int>>& dp, int x , int y)
    {
        if(x==0 && y==0) return 1;
        if(x<0 || y<0) return 0;

        if(dp[x][y]!=-1) return dp[x][y];

        return dp[x][y] = memo(dp, x-1, y) + memo(dp, x, y-1);
    }
    int uniquePaths(int m, int n) {

        vector<vector<int>> dp(m, vector<int> (n, -1));
        return memo(dp, m-1, n-1);
        
    }
};
