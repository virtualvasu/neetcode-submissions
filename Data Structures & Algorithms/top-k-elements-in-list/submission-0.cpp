//create a hash map, in O(n) create fre key value pairs for all elem
//then push all pairs into a max heap
//pop and output top k elem

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {

        priority_queue<pair<int, int>> maxheap;

        unordered_map <int, int> mp;

        for(int i =0;i<nums.size();i++)
        {
            mp[nums[i]] ++;
        }

        for(auto& p: mp)
        {
            maxheap.push({p.second, p.first});
        }

        vector<int> ans;

        for(int i =0;i<k;i++)
        {   

            ans.push_back(maxheap.top().second);
            maxheap.pop();
        }

        return ans;
        
    }
};
