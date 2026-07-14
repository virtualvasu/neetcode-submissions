class Solution {
public:
    bool isPalindrome(string s) {

        
        string clean = "";
        for (char c : s) {
            if (isalnum(c)) {
                clean += tolower(c);
            }
        }

        int n = clean.length();

        int i=0, j=n-1;

        while (i<=j)
        {
            if(clean[i] != clean[j]) return false;
            i++; j--;
        }

        return true;
        
    }
};
