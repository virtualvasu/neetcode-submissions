class Solution {
public:

    int helper(uint32_t n)
    {
        int res=0;
        for(int i=0;i<32;i++ )
        {
            if((1 << i) & n) res++;
        }

        return res;
    }
    vector<int> countBits(int n) {

        vector<int> res;
        for(int i =0;i<=n;i++)
        {
            uint32_t x = i;

            res.push_back(helper(x));
        }

        return res;
        
    }
};
