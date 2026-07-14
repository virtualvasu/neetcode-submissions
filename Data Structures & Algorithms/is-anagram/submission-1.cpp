//2 hashmaps
//maintain frequency of each char
//at end, compare, if not match, false
//else true

class Solution {
public:
    bool isAnagram(string s, string t) {

        unordered_map <char, int> mp1;
        unordered_map <char, int> mp2;

        if(s.length() != t.length()) return false;

        for(int i =0; i<s.length();i++)
        {
            mp1[s[i]] +=1;
            mp2[t[i]] +=1;
        }

        for(auto &it: mp1)
        {
            if(mp1[it.first] != mp2[it.first]) return false;
        }

        return true;
        
    }
};
