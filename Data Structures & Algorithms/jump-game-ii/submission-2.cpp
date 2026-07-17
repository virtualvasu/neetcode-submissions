//process till n-1 element
//maintain end, farthest pointers
//at each step calc farthest u can go from current position, update farthest
//if u reach end of this window, jump++
//end = farthest

class Solution {
public:
    int jump(vector<int>& nums) {
        
        int farthest=0, end=0, jumps=0;
        for(int i=0; i<nums.size() -1;i++)
        {
            farthest = max(farthest, i +nums[i]);
            if(i == end)
            {
                jumps++;
                end = farthest;
            }
            
        }

        return jumps;
    }
};
