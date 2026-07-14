//two pointers
//one at start, one at end
// if sum of start + end > target, end--
//if sum< target, start++
//do this untill sum = target

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {

        int n = numbers.size();
        int start =0;
        int end= n-1;

        while(start < end && (numbers[start] + numbers[end] != target))
        {
           

            if(numbers[start] + numbers[end] < target) start ++;
            if(numbers[start] + numbers[end] > target) end--;

        }

        return {start+1, end+1};
        
    }
};
