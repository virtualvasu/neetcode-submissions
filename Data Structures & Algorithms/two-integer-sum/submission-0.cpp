class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

        unordered_map<int, int> mp;

        for(int i =0;i<nums.size();i++)
        {
            if(mp.find(target - nums[i]) != mp.end()) //check if key exists
            {
                return {mp[target - nums[i]], i};
            }

            mp[nums[i]] = i;
        }
        
        return {0,0};
    }
};
