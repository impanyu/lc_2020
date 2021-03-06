class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char,int> s_count;
        unordered_map<char,int> t_count;
        for(char c : s)
            s_count[c] ++;
        for(char c : t)
            t_count[c] ++;
        
        return s_count == t_count;
    } 
};
