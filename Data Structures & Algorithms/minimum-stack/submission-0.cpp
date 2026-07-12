class MinStack {
public:


        stack<int> st;
        stack <int> prefix;
    MinStack() {

    
        
    }
    
    void push(int val) {

        if(st.empty() && prefix.empty())
        {
            st.push(val);
            prefix.push(val);
        }

    else{

        st.push(val);
        prefix.push(min(val, prefix.top()));
    }
        
    }
     
    void pop() {

        st.pop();
        prefix.pop();
        
    }
    
    int top() {

       return st.top();
        
    }
    
    int getMin() {

        return prefix.top();
        
    }
};
