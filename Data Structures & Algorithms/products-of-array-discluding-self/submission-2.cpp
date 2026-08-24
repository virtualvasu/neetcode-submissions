//wrong approach : maintain global prod and just divide 

//correct: prefix + suffix
// iterate from left -> store prefix prod for each 
// iterate from right -> store suffix prod for each 
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {

        int n = nums.size();

        vector<int> prefix(n, 1);
        vector<int> suffix(n, 1);
        vector<int> output(n, 1);

        // Product of all elements BEFORE i
        for (int i = 1; i < n; i++) {
            prefix[i] = prefix[i - 1] * nums[i - 1];
        }

        // Product of all elements AFTER i
        for (int i = n - 2; i >= 0; i--) {
            suffix[i] = suffix[i + 1] * nums[i + 1];
        }

        // Left product × right product
        for (int i = 0; i < n; i++) {
            output[i] = prefix[i] * suffix[i];
        }

        return output;
    }
};