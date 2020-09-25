class Solution {
public:
    string simplifyPath(string path) {
        string ans="/";
        istringstream is(path);
        string s;
        deque<string> st;
        while(getline(is,s,'/')){
            if(s == "" || s == "." )
                continue;
            else if(s==".."){
                if(!st.empty())
                    st.pop_back();
            }
            else
                st.push_back(s);
        }
        while(!st.empty()){
            ans += st.front();
            st.pop_front();
            ans += "/";
        }
        if(ans.size()>1)
            ans.pop_back();
        
        return ans;
    }
};
