class Solution {
public:
    bool isOneEditDistance(string s, string t) {
        int ns = s.size();
        int nt = t.size();
        
        if(ns > nt) 
            swap(s,t);
        if(nt - ns > 1)
            return false;
        
        //iterate through the shorter one
        for(int i = 0; i < ns; i++){
            if(s[i] != t[i]){
                if(ns == nt)
                    return s.substr(i+1) == t.substr(i+1);
                else{
                    return s.substr(i) == t.substr(i+1);
                }
            }
        }
        
        //if t = s + one_char, we should also return true
        return ns + 1 == nt;
    }
};
