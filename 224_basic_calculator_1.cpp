class Solution {
public:
    int calculate(string s) {
        int res=0;
        int sign=1;
        stack<int> st;
        for(int i=0;i<s.size();i++){
            if(s[i]>='0' && s[i]<='9'){
                int num=0;
                while(s[i]>='0' && s[i]<='9'){
                    num*=10;
                    num+=s[i]-'0';                
                    i++;
                }
                res+=sign*num;
                i--;
            }
            else if(s[i]=='+'){
                sign=1;
            }
            else if(s[i]=='-'){
                sign=-1;
            }
            else if(s[i]=='('){
                st.push(res);
                st.push(sign);
                res=0;
                sign=1;
            }
            else if(s[i]==')'){
                res*=st.top();st.pop();
                res+=st.top();st.pop();
            }
            
        }
        return res;
    }
};
