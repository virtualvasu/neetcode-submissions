class Solution {
public:
    bool canJump(vector<int>& nums) {

        int n = nums.size();

        if(n==1) return true;
        if(n==2 && nums[0]>0) return true;

        int goal = n-1;

        int curr = n-2;

        while(curr >=0)
        {
            if(goal - curr > nums[curr])
            {
                curr--;
                
            }
            else{
                goal = curr;
                 curr--;
                
            }       
            
        
        }
        if(goal == 0) return true;
        
        return false;
        
    }
};
