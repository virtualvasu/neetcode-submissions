//find the row by checking the last elem of each row 
// if found, use binary in that row, if found true, else false


class Solution {
public:

     bool search(vector<int>& nums, int target) {

        int n = nums.size();

        int low=0, high = n-1;

        while(low<=high)
        {
            int mid = low + (high - low)/2;

            if(target == nums[mid]) return true;
            else if(target > nums[mid])
            {
                low = mid + 1;
            } 
            else{
                high = mid-1;
            }
        }

        return false;
        
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {

        int m = matrix.size();
        int n = matrix[0].size();

        int low = 0;
        int high = m-1;
        int mid = low + (high - low)/2;

        while (low <= high)
{
    int mid = low + (high - low) / 2;

    if (target < matrix[mid][0])
    {
        high = mid - 1;
    }
    else if (target > matrix[mid][n-1])
    {
        low = mid + 1;
    }
    else
    {
        // target lies within this row
        return search(matrix[mid], target);
    }
}

return false;




        
    }
};
