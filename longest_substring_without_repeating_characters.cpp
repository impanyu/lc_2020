class Solution {
//1.two pointers, propelled by the second one, j
//2.we use a 128 array(or hashmap) to map the char to its positions
//3.if the char mapping is previous stored, its possible the old char will appear [i,j], we just max charpos[s[j]]+1 and current i to shrink the substring if possible 
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> char_to_index;     
        int ans =0;
        for(int i=0,j=0;j<s.size();j++){
            //correct the sliding window if duplications appears
            if(char_to_index.count(s[j])){
                i = max(i,char_to_index[s[j]]+1);
            }
            ans = max(ans,j-i+1);
            char_to_index[s[j]] = j;
        }
        return ans;
    }
};
