class Solution {
public:
    bool isValid(string s) {

        stack<char> st;

        if(s.length()%2 !=0) return false;

        int i=0;

        st.push(s[i]);i++;
        while(i<s.length())
        {
            if(s[i] == '(' || s[i] == '{' || s[i] == '[')
            {
                st.push(s[i]);
                i++;
            }
            else{

                if (st.empty()) return false;

                char c = st.top();
                //type match
                if(c == '(' && s[i]==')') {
                    st.pop(); i++;
                }
                else if(c == '{' && s[i]=='}') {
                    st.pop(); i++;
                }
                else if(c == '[' && s[i]==']') {
                    st.pop(); i++;
                }
                else{
                    return false;
                }
            }
        }
        
        return (st.empty());
    }
};
