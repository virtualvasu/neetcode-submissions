class Solution {
public:
    int longestConsecutive(vector<int>& nums) {

        unordered_set<int> st(nums.begin(), nums.end());

        int best=0;

        for(int x:st)
        {
            if(st.count(x-1)) continue;

            int len =1;
            while(st.count(x+len))
            {
                len++;
            }

            best = max(best, len);
        }

        return best;
        
    }
};
