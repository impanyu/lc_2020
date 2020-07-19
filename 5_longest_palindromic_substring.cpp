class Solution {
public:
    string longestPalindrome(string s) {
        vector<vector<int>> dp(s.size(),vector<int>(s.size(),0));
        int left =0, len=0;
        //pay attention to loop order: j is before i, because we have to make dp[i+1][j-1] before dp[i][j]
        for(int j=0;j<s.size();j++){
            for(int i=0; i<=j;i++){
                dp[i][j]=(s[i] == s[j]) && (j-i<=1 || dp[i+1][j-1]);
                if(dp[i][j] && j-i+1>len){
                    len = j-i+1;
                    left = i;
                }
            }
        }
        return s.substr(left,len);
    }
};
