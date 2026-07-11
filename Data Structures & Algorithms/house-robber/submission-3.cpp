class Solution {
public:
    int rob(vector<int>& nums) {

        int n = nums.size();
        if(n==1) return nums[0];

        if (n==2) return max(nums[1], nums[0]);

        int rob1=nums[0], rob2=max(nums[1], nums[0]);

        for(int i =2; i<n;i++)
        {
            int temp = max(rob1 + nums[i], rob2);
            rob1 = rob2;
            rob2=temp;
        }
        return rob2;
    }
};
