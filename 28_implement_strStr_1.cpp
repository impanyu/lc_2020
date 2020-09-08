class Solution {
public:
    int strStr(string haystack, string needle) {
        int L = needle.size(), N = haystack.size();
        for(int i = 0; i< N-L+1; i++){
            if(haystack.substr(i,L) == needle)
                return i;
        }
        
        return -1;
    }
};
