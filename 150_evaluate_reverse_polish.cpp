class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for(string s : tokens){
            if(s == "+" || s == "-" || s == "*" || s == "/"){
                int op2 = st.top();
                st.pop();
                int op1 = st.top();
                st.pop();
                int result;
                if(s == "+")
                    result = op1 + op2;
                else if(s == "-")
                    result = op1 - op2;
                else if(s == "/")
                    result = op1 / op2;
                else
                    result = op1 * op2;
                st.push(result);
                
            }
            else
                st.push(stoi(s));
        }
        
        return st.top();
    }
};
