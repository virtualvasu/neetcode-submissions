class Solution {
public:

    int dp(vector<int>& vec, int start, int end)
    {
        if(end - start == 0) return vec[start];
        if(end - start ==1) return max(vec[start], vec[start + 1]);

        int n = end - start + 1;
        vector<int> dp(n);
        dp[0] = vec[start];
        dp[1] = max(vec[start], vec[start + 1]);

        for(int i =2; i<n; i++)
        {
            dp[i] = max(dp[i-1], dp[i-2] + vec[start + i]);
        }

        return dp.back();
    }

    int rob(vector<int>& nums) {
        
        int n = nums.size();

        if(n == 1) return nums[0];
        if (n==2) return max(nums[0], nums[1]);
        return max(dp(nums, 0, n-2), dp(nums, 1, n-1));


    }
};
