class Solution {
public:
    int maxSubArray(vector<int>& nums) {

        //traverse and calc curr sum
        //if curr sum < next elem => curr sum=0

        int n = nums.size();

        int curr = 0;
        int res = INT_MIN;

        for(int i =0;i<n;i++)
        {
            curr = max(curr + nums[i], nums[i]);
            res = max(curr, res);
        }
        return res;

    }
};
