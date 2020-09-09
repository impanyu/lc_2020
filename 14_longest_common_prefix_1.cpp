//vertical scanning
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans = "";
        if(strs.size() == 0) return ans;
        int i = 0,j = 0;
        for(;i<strs[0].size();i++){
            char c = strs[0][i];
            for(j=1;j<strs.size();j++){
                if(i >= strs[j].size() || strs[j][i] != c)
                    return ans;
            }
            ans = ans + strs[0][i];
        }
        return ans;
    }
};
