//goal: calc. how many letters (repeating too) to be converted into the master char?
//keep a hash map, for char frequency
// at any point, in sliding window:
// # of letters to replace = k - max freq in that window
//if good, right ++, count ++
//if not, left ++, 
class Solution {
public:
    int characterReplacement(string s, int k) {

        unordered_map<char, int> mp;

        int res = 0;
        int left = 0;
        int maxfreq = 0;

        for (int right = 0; right < s.length(); right++)
        {
            mp[s[right]]++;
            maxfreq = max(maxfreq, mp[s[right]]);

            while (right - left + 1 - maxfreq > k)
            {
                mp[s[left]]--;
                left++;
            }

            res = max(res, right - left + 1);
        }

        return res;
    }
};