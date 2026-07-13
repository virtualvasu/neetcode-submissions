//maintain stack of (temp, index)
//compare top with next elem
//if next > top => pop, update index while stack not empty
//push new elem
//do for full array
//0 remain where none found

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {

        int n = temperatures.size();
        stack<pair<int, int>> st;

        vector<int> res(n,0);

        if(n==0 || n==1) return res;
        st.push({temperatures[0], 0});
        for(int i =1; i<n;i++)
        {
           
            while(!st.empty() && st.top().first < temperatures[i])
            {
                res[st.top().second] = i - st.top().second;
                st.pop();
            }
            
                st.push({temperatures[i], i});
            
        }

        return res;
        
    }
};
