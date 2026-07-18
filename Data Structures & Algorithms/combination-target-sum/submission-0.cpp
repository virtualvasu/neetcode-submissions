//maintain global, res and subset arrays, and sum for current subset
//boundary conditions: if i out of bounds, if sum > target
//base case : sum == target
//backtracking:
//take current elem: add to subset, call again for this elem
// do not take this elem , pop back, call for next elem 

class Solution {
public:

    void helper(vector<int>& nums, int target, vector<vector<int>>& res, vector<int>& subset, int sum, int i )
    {
        if(sum == target)
        {
            res.push_back(subset);
            return;
        }
        if(i >= nums.size() || sum > target) return;

        //take elem
        subset.push_back(nums[i]);
        sum+=nums[i];
        helper(nums, target, res, subset, sum, i);

        //dont take
        subset.pop_back(); sum-=nums[i];
        helper(nums, target, res, subset, sum, i+1);
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {

        vector<vector<int>> res;
        vector<int> subset;
        int sum=0;

        helper(nums, target, res, subset, sum, 0);
        return res;
    }
};
