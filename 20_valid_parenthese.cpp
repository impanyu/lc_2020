class Solution {
public:    
    bool isValid(string s) {
        unordered_map<char,char> cmap;
        cmap[')']='(';
        cmap[']']='[';
        cmap['}']='{';
        stack<char> stack;
        for(char c:s){
            if(cmap.count(c)){
                if(stack.empty()) return false;
                else if(cmap[c] != stack.top()) return false;
                else stack.pop();
            }
            else
                stack.push(c);
        }
        return stack.empty();
    }
};
