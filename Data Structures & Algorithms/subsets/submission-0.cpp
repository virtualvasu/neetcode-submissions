//maintain a global res array, a subset array
//i terate in the nums array
//base case: if i reaches end of the nums, i have already taken decision for all the elem (take or not take)
//so add this subset to res
//now in backtrack , for each elem i ave 2 option => take / not take
//if taking, this elem, add to subset
//if not taking, pop from subset

class Solution {
public:

    void helper(vector<int>& nums,
                vector<vector<int>>& res,
                vector<int>& subset,
                int i)
    {
        if (i >= nums.size())
        {
            res.push_back(subset);
            return;
        }

        // Take current element
        subset.push_back(nums[i]);
        helper(nums, res, subset, i + 1);

        // Backtrack
        subset.pop_back();

        // Don't take current element
        helper(nums, res, subset, i + 1);
    }

    vector<vector<int>> subsets(vector<int>& nums)
    {
        vector<vector<int>> res;
        vector<int> subset;

        helper(nums, res, subset, 0);

        return res;
    }
};