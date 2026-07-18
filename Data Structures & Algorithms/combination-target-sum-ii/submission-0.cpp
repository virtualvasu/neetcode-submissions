//helper on sorted array to remove duplicates
//base case: if sum == target, add subset to res, return
// boundary condn: if sum > target, if i out of bounds
//take curr. elem, 
//for all other elements too, take ,it if not duplicate as last elem in candidates
// pop current elem = > undo choice
class Solution {
public:
    void helper(vector<int>& candidates, int target,
                vector<vector<int>>& res,
                vector<int>& subset,
                int sum,
                int start)
    {
        // Base case
        if (sum == target)
        {
            res.push_back(subset);
            return;
        }

        for (int j = start; j < candidates.size(); j++)
        {
            // Skip duplicates at the same recursion level
            if (j > start && candidates[j] == candidates[j - 1])
                continue;

            // Since array is sorted, no need to continue further
            if (sum + candidates[j] > target)
                break;

            // Choose
            subset.push_back(candidates[j]);

            // Explore
            helper(candidates, target, res, subset,
                   sum + candidates[j], j + 1);

            // Undo choice (Backtrack)
            subset.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target)
    {
        sort(candidates.begin(), candidates.end());

        vector<vector<int>> res;
        vector<int> subset;

        helper(candidates, target, res, subset, 0, 0);

        return res;
    }
};