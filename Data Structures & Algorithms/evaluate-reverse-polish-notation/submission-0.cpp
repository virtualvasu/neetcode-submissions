//maintain stack
//push if number
//if operator found, pop two top elem for stack
//do operation, get result, push to stack
//repeat untill stack has one elem left 
//return top

//time: O(n)
//space: O(n)

class Solution {
public:
    int evalRPN(vector<string>& tokens) {

        stack<int> st;

        for (int i = 0; i < tokens.size(); i++) {

            if (tokens[i] == "+" || tokens[i] == "-" ||
                tokens[i] == "*" || tokens[i] == "/") {

                int a = st.top();
                st.pop();

                int b = st.top();
                st.pop();

                int res;

                if (tokens[i] == "+")
                    res = b + a;
                else if (tokens[i] == "-")
                    res = b - a;
                else if (tokens[i] == "*")
                    res = b * a;
                else
                    res = b / a;

                st.push(res);
            }
            else {
                st.push(stoi(tokens[i]));
            }
        }

        return st.top();
    }
};