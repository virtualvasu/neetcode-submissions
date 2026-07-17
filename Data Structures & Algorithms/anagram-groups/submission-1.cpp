//idea: convert each string into a frequency string
// group same frwquncy string together

//algo:

//iterate in the strs array
//for each string, convert into 26 char freq. string
//push back in map at freq key 
//at last iterate in the map and print all groups of strign from key:value pairs


class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {

        unordered_map<string, vector<string>> mp;

        for(string s : strs)
        {
            vector<int> freq(26, 0);

            //create freq vector

            for(int i=0;i<s.length(); i++)
            {
                freq[s[i] - 'a']++;
            }

            //covert freq vector to string

            string key = "";

            for(int i =0;i<freq.size();i++)
            {
                key+= to_string(freq[i]);
                key+=",";
            }

            mp[key].push_back(s);


        }

        vector<vector<string>> ans;

        //get all the groups of anagrams from mp into ans

        for(auto& p: mp)
        {
            ans.push_back(p.second);
        }

        return ans;

        
        
    }
};
