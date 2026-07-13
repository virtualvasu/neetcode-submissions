//assume matrix to be an array, stretched out
//play with indices

//low = 0
//high = m*n -1
// mid = low+high / 2
//to map back to matrix:
//row = mid / m
//col = min % n

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {

        int m = matrix.size();
        int n = matrix[0].size();
 
        int low = 0, high = m*n -1;
        while(low <= high)
        {
            int mid = low + (high - low)/2;

            //imp: divide by n in both cases
            int row = mid/n;
            int col = mid%n;

            if(matrix[row][col] == target) return true;

            else if (matrix[row][col] < target)
            low = mid+1;

            else if (matrix[row][col] > target)
            high = mid-1;
        }
        return false;

    }
};
