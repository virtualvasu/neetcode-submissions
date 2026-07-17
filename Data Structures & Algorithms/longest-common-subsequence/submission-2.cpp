//use recursion approach to calc. all pairs
//for each pair, if chars match, res++
//else check for i+1, or j+1
//use memo to check if the dp exists already, if it dopes, return it 
//else call helper again in recorsion

class Solution {
public:

    int helper(string text1, string text2,vector<vector<int>>& memo, int i, int j)
    {
        if(i == text1.size() || j == text2.size()) return 0;

        if(memo[i][j] != -1) return memo[i][j];

        if(text1[i] == text2[j])
        {
            memo[i][j] = 1 + helper(text1,  text2,memo, i+1, j+1);
        } 

        else{
 memo[i][j] = max(helper(text1, text2, memo, i+1, j), helper(text1, text2, memo, i, j+1));

        }
       
        return memo[i][j];
    }
    int longestCommonSubsequence(string text1, string text2) {

        int rows = text1.length();
        int cols = text2.length();

        vector<vector<int>> memo(rows, vector<int>(cols, -1));

        return helper(text1, text2, memo, 0, 0);

        
    }
};
