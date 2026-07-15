//maintain global max
//use sliding window
//keep, left and right
//iterate:
//maintain a hash map
//check in hash map, if char already found:
//if yes: set it to false and left++
//else : set true , right ++ , update max len
class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        if(s.length() == 0 || s.length() == 1) return s.length();
        unordered_map<char, bool> mp;

        int left = 0;
        int right = 1;
        int len=0;

        mp[s[0]] = true;

        while(right < s.length())
        {
            if(!mp[s[right]])
            {
                len = max(len, right - left + 1);
                mp[s[right]] = true;
                right ++;
            }
            else {
                mp[s[left]] = false;
                left++;
            }
        }

        return len;
        
    }
};
